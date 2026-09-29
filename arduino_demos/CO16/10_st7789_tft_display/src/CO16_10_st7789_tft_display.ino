#include <Adafruit_GFX.h>
#include <driver/gpio.h>
#include <driver/spi_master.h>
#include <esp_heap_caps.h>

namespace {

// CO16 ST7789 (GMT020-02-7P) pin mapping from kcs_co16.h.
constexpr gpio_num_t kTftSclk = GPIO_NUM_11;
constexpr gpio_num_t kTftMosi = GPIO_NUM_10;
constexpr gpio_num_t kTftMiso = GPIO_NUM_12;
constexpr gpio_num_t kTftCs = GPIO_NUM_4;
constexpr gpio_num_t kTftDc = GPIO_NUM_0;
constexpr gpio_num_t kTftReset = GPIO_NUM_5;
constexpr gpio_num_t kTftBacklight = GPIO_NUM_40;

constexpr int16_t kDisplayWidth = 320;
constexpr int16_t kDisplayHeight = 240;
constexpr int16_t kTransferChunkHeight = 10;
constexpr uint32_t kDisplaySpiFrequency = 20 * 1000 * 1000;
constexpr uint8_t kCo16Madctl = 0x68;  // MX | MV | BGR.

constexpr uint16_t kBlack = 0x0000;
constexpr uint16_t kBlue = 0x001F;
constexpr uint16_t kRed = 0xF800;
constexpr uint16_t kGreen = 0x07E0;
constexpr uint16_t kCyan = 0x07FF;
constexpr uint16_t kMagenta = 0xF81F;
constexpr uint16_t kYellow = 0xFFE0;
constexpr uint16_t kWhite = 0xFFFF;

class Co16St7789 : public Adafruit_GFX {
 public:
  Co16St7789() : Adafruit_GFX(kDisplayWidth, kDisplayHeight) {}

  bool begin() {
    gpio_reset_pin(kTftCs);
    gpio_set_direction(kTftCs, GPIO_MODE_OUTPUT);
    gpio_set_level(kTftCs, 1);

    gpio_reset_pin(kTftDc);
    gpio_set_direction(kTftDc, GPIO_MODE_OUTPUT);
    gpio_set_level(kTftDc, 1);

    gpio_reset_pin(kTftBacklight);
    gpio_set_direction(kTftBacklight, GPIO_MODE_OUTPUT);
    gpio_set_level(kTftBacklight, 0);

    spi_bus_config_t busConfig = {};
    busConfig.sclk_io_num = kTftSclk;
    busConfig.mosi_io_num = kTftMosi;
    busConfig.miso_io_num = kTftMiso;
    busConfig.quadwp_io_num = -1;
    busConfig.quadhd_io_num = -1;
    busConfig.max_transfer_sz =
        kDisplayWidth * kTransferChunkHeight * sizeof(uint16_t);

    esp_err_t err =
        spi_bus_initialize(SPI3_HOST, &busConfig, SPI_DMA_CH_AUTO);
    if (err != ESP_OK) {
      Serial.printf("SPI3 initialization failed: %s\n", esp_err_to_name(err));
      return false;
    }

    spi_device_interface_config_t deviceConfig = {};
    deviceConfig.clock_speed_hz = kDisplaySpiFrequency;
    deviceConfig.mode = 0;
    deviceConfig.spics_io_num = -1;
    deviceConfig.queue_size = 1;

    err = spi_bus_add_device(SPI3_HOST, &deviceConfig, &spiDevice_);
    if (err != ESP_OK) {
      Serial.printf("ST7789 SPI device setup failed: %s\n",
                    esp_err_to_name(err));
      return false;
    }

    drawBuffer_ = static_cast<uint8_t*>(heap_caps_malloc(
        kDisplayWidth * kTransferChunkHeight * sizeof(uint16_t),
        MALLOC_CAP_DMA));
    if (drawBuffer_ == nullptr) {
      Serial.println("ST7789 DMA buffer allocation failed");
      return false;
    }

    // GPIO5 is shared with the optional LoRa module. Match the working KCS
    // firmware and issue one reset pulse before initializing the controller.
    gpio_reset_pin(kTftReset);
    gpio_set_direction(kTftReset, GPIO_MODE_OUTPUT);
    gpio_set_level(kTftReset, 1);
    delay(1);
    gpio_set_level(kTftReset, 0);
    delay(1);
    gpio_set_level(kTftReset, 1);
    delay(10);

    if (!initializeController()) {
      return false;
    }

    fillScreen(kBlack);
    delay(120);
    if (!writeCommand(0x29)) {  // Display on.
      return false;
    }
    delay(120);

    gpio_set_level(kTftBacklight, 1);
    initialized_ = true;
    return true;
  }

  void drawPixel(int16_t x, int16_t y, uint16_t color) override {
    fillRect(x, y, 1, 1, color);
  }

  void writePixel(int16_t x, int16_t y, uint16_t color) override {
    fillRect(x, y, 1, 1, color);
  }

  void fillRect(int16_t x, int16_t y, int16_t width, int16_t height,
                uint16_t color) override {
    if (x < 0) {
      width += x;
      x = 0;
    }
    if (y < 0) {
      height += y;
      y = 0;
    }
    if (x + width > kDisplayWidth) {
      width = kDisplayWidth - x;
    }
    if (y + height > kDisplayHeight) {
      height = kDisplayHeight - y;
    }
    if (drawBuffer_ == nullptr || width <= 0 || height <= 0) {
      return;
    }

    const uint8_t high = color >> 8;
    const uint8_t low = color;
    for (int16_t row = y; row < y + height;
         row += kTransferChunkHeight) {
      const int16_t chunkHeight =
          min<int16_t>(kTransferChunkHeight, y + height - row);
      const size_t pixelCount = width * chunkHeight;
      for (size_t index = 0; index < pixelCount; ++index) {
        drawBuffer_[index * 2] = high;
        drawBuffer_[index * 2 + 1] = low;
      }

      if (!setWindow(x, row, x + width, row + chunkHeight) ||
          !writePixels(drawBuffer_, pixelCount * sizeof(uint16_t))) {
        Serial.println("ST7789 pixel transfer failed");
        return;
      }
    }
  }

  void writeFillRect(int16_t x, int16_t y, int16_t width, int16_t height,
                     uint16_t color) override {
    fillRect(x, y, width, height, color);
  }

  bool initialized() const { return initialized_; }

 private:
  bool transmit(const void* data, size_t length, int dcLevel) {
    if (data == nullptr || length == 0) {
      return true;
    }

    gpio_set_level(kTftDc, dcLevel);
    spi_transaction_t transaction = {};
    transaction.length = length * 8;
    transaction.tx_buffer = data;
    const esp_err_t err = spi_device_polling_transmit(spiDevice_, &transaction);
    if (err != ESP_OK) {
      Serial.printf("ST7789 SPI transfer failed: %s\n", esp_err_to_name(err));
      return false;
    }
    return true;
  }

  bool writeCommand(uint8_t command) {
    gpio_set_level(kTftCs, 0);
    const bool success = transmit(&command, sizeof(command), 0);
    gpio_set_level(kTftCs, 1);
    return success;
  }

  bool writeCommandData(uint8_t command, const uint8_t* data, size_t length) {
    gpio_set_level(kTftCs, 0);
    const bool success = transmit(&command, sizeof(command), 0) &&
                         transmit(data, length, 1);
    gpio_set_level(kTftCs, 1);
    return success;
  }

  bool setWindow(int16_t x1, int16_t y1, int16_t x2, int16_t y2) {
    const uint8_t columns[] = {
        static_cast<uint8_t>(x1 >> 8), static_cast<uint8_t>(x1),
        static_cast<uint8_t>((x2 - 1) >> 8), static_cast<uint8_t>(x2 - 1),
    };
    const uint8_t rows[] = {
        static_cast<uint8_t>(y1 >> 8), static_cast<uint8_t>(y1),
        static_cast<uint8_t>((y2 - 1) >> 8), static_cast<uint8_t>(y2 - 1),
    };
    return writeCommandData(0x2A, columns, sizeof(columns)) &&
           writeCommandData(0x2B, rows, sizeof(rows));
  }

  bool writePixels(const uint8_t* data, size_t length) {
    constexpr uint8_t kRamWrite = 0x2C;
    gpio_set_level(kTftCs, 0);
    const bool success = transmit(&kRamWrite, sizeof(kRamWrite), 0) &&
                         transmit(data, length, 1);
    gpio_set_level(kTftCs, 1);
    return success;
  }

  bool initializeController() {
    const uint8_t madctl[] = {kCo16Madctl};
    const uint8_t displayFunction[] = {0x0A, 0x82};
    const uint8_t pixelFormat[] = {0x55};
    const uint8_t porchControl[] = {0x0C, 0x0C, 0x00, 0x33, 0x33};
    const uint8_t gateControl[] = {0x35};
    const uint8_t vcom[] = {0x28};
    const uint8_t lcmControl[] = {0x0C};
    const uint8_t vdvVrhEnable[] = {0x01, 0xFF};
    const uint8_t vrh[] = {0x10};
    const uint8_t vdv[] = {0x20};
    const uint8_t frameRate[] = {0x0F};
    const uint8_t powerControl[] = {0xA4, 0xA1};
    const uint8_t positiveGamma[] = {
        0xD0, 0x00, 0x02, 0x07, 0x0A, 0x28, 0x32,
        0x44, 0x42, 0x06, 0x0E, 0x12, 0x14, 0x17,
    };
    const uint8_t negativeGamma[] = {
        0xD0, 0x00, 0x02, 0x07, 0x0A, 0x28, 0x31,
        0x54, 0x47, 0x0E, 0x1C, 0x17, 0x1B, 0x1E,
    };

    if (!writeCommand(0x11)) {  // Sleep out.
      return false;
    }
    delay(120);

    return writeCommand(0x13) &&
           writeCommandData(0x36, madctl, sizeof(madctl)) &&
           writeCommandData(0xB6, displayFunction, sizeof(displayFunction)) &&
           writeCommandData(0x3A, pixelFormat, sizeof(pixelFormat)) &&
           (delay(10), true) &&
           writeCommandData(0xB2, porchControl, sizeof(porchControl)) &&
           writeCommandData(0xB7, gateControl, sizeof(gateControl)) &&
           writeCommandData(0xBB, vcom, sizeof(vcom)) &&
           writeCommandData(0xC0, lcmControl, sizeof(lcmControl)) &&
           writeCommandData(0xC2, vdvVrhEnable, sizeof(vdvVrhEnable)) &&
           writeCommandData(0xC3, vrh, sizeof(vrh)) &&
           writeCommandData(0xC4, vdv, sizeof(vdv)) &&
           writeCommandData(0xC6, frameRate, sizeof(frameRate)) &&
           writeCommandData(0xD0, powerControl, sizeof(powerControl)) &&
           writeCommandData(0xE0, positiveGamma, sizeof(positiveGamma)) &&
           writeCommandData(0xE1, negativeGamma, sizeof(negativeGamma)) &&
           writeCommand(0x21);  // Display inversion on.
  }

  spi_device_handle_t spiDevice_ = nullptr;
  uint8_t* drawBuffer_ = nullptr;
  bool initialized_ = false;
};

Co16St7789 display;
uint32_t frameCount = 0;

void drawColorBars() {
  constexpr uint16_t colors[] = {
      kRed,
      kGreen,
      kBlue,
      kCyan,
      kMagenta,
      kYellow,
  };
  constexpr size_t colorCount = sizeof(colors) / sizeof(colors[0]);
  const int barWidth = kDisplayWidth / colorCount;

  for (size_t index = 0; index < colorCount; ++index) {
    const int x = index * barWidth;
    const int width =
        (index == colorCount - 1) ? kDisplayWidth - x : barWidth;
    display.fillRect(x, 132, width, 44, colors[index]);
  }
}

void drawStaticScreen() {
  display.fillScreen(kBlack);
  display.drawRect(0, 0, kDisplayWidth, kDisplayHeight, kWhite);

  display.setTextWrap(false);
  display.setTextColor(kCyan);
  display.setTextSize(3);
  display.setCursor(34, 20);
  display.print("FeedCurrent CO16");

  display.setTextColor(kWhite);
  display.setTextSize(2);
  display.setCursor(24, 64);
  display.print("ST7789 display test");
  display.setCursor(24, 92);
  display.print("SPI3 native driver");

  drawColorBars();

  display.setTextColor(kGreen);
  display.setCursor(24, 194);
  display.print("Frame:");
}

void updateFrameCounter() {
  display.fillRect(108, 190, 190, 28, kBlack);
  display.setTextColor(kGreen);
  display.setTextSize(2);
  display.setCursor(108, 194);
  display.print(frameCount++);
}

}  // namespace

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("FeedCurrent CO16 standalone ST7789 example");
  Serial.printf("SPI3 SCLK=%d MOSI=%d MISO=%d CS=%d mode=0 clock=%u Hz\n",
                kTftSclk, kTftMosi, kTftMiso, kTftCs,
                kDisplaySpiFrequency);
  Serial.printf("LCD DC=%d RESET=%d BACKLIGHT=%d\n", kTftDc, kTftReset,
                kTftBacklight);

  if (!display.begin()) {
    Serial.println("Display initialization failed");
    while (true) {
      delay(1000);
    }
  }

  drawStaticScreen();
  updateFrameCounter();

  Serial.printf("Display initialized: %dx%d, MADCTL=0x%02X, invert=on\n",
                display.width(), display.height(), kCo16Madctl);
}

void loop() {
  
  updateFrameCounter();
  delay(1000);
}