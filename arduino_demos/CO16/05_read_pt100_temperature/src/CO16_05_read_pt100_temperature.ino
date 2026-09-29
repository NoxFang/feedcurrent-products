#include <Adafruit_MAX31865.h>

namespace {

// CO16 MAX31865 software-SPI pins.
constexpr int kPt100Sclk = 11;
constexpr int kPt100Mosi = 10;
constexpr int kPt100Miso = 12;
constexpr int kPt100Cs = 14;

// NX3L4051PW channel select pins. S3 is fixed LOW on CO16.
constexpr int kMuxS1 = 7;
constexpr int kMuxS2 = 21;
constexpr uint8_t kPt100ChannelCount = 4;
constexpr uint32_t kMuxSettlingTimeMs = 20;

constexpr float kRtdNominalOhms = 100.0F;
constexpr float kReferenceResistorOhms = 400.0F;

Adafruit_MAX31865 pt100(kPt100Cs, kPt100Mosi, kPt100Miso, kPt100Sclk);

void selectPt100Channel(uint8_t channel) {
  const uint8_t muxAddress = channel - 1;

  // S3 is fixed LOW, so S2/S1 select PT100 channels 1-4.
  digitalWrite(kMuxS1, muxAddress & 0x01);
  digitalWrite(kMuxS2, (muxAddress >> 1) & 0x01);
  delay(kMuxSettlingTimeMs);
}

void printFault(uint8_t fault) {
  Serial.printf(" fault=0x%02X", fault);
  if (fault & MAX31865_FAULT_HIGHTHRESH) {
    Serial.print(" RTD_HIGH_THRESHOLD");
  }
  if (fault & MAX31865_FAULT_LOWTHRESH) {
    Serial.print(" RTD_LOW_THRESHOLD");
  }
  if (fault & MAX31865_FAULT_REFINLOW) {
    Serial.print(" REFIN_HIGH");
  }
  if (fault & MAX31865_FAULT_REFINHIGH) {
    Serial.print(" REFIN_LOW_OR_FORCE_OPEN");
  }
  if (fault & MAX31865_FAULT_RTDINLOW) {
    Serial.print(" RTDIN_LOW_OR_FORCE_OPEN");
  }
  if (fault & MAX31865_FAULT_OVUV) {
    Serial.print(" OVER_UNDERVOLTAGE");
  }
}

}  // namespace

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(kMuxS1, OUTPUT);
  pinMode(kMuxS2, OUTPUT);
  selectPt100Channel(1);

  Serial.println();
  Serial.println("FeedCurrent CO16 four-channel PT100 example");
  Serial.printf("MUX S3=LOW S2=%d S1=%d; SPI SCLK=%d MOSI=%d MISO=%d CS=%d\n",
                kMuxS2, kMuxS1, kPt100Sclk, kPt100Mosi, kPt100Miso,
                kPt100Cs);

  pt100.begin(MAX31865_3WIRE);
  pt100.enable50Hz(true);
}

void loop() {
  for (uint8_t channel = 1; channel <= kPt100ChannelCount; ++channel) {
    selectPt100Channel(channel);

    const uint16_t raw = pt100.readRTD();
    const float resistance =
        static_cast<float>(raw) * kReferenceResistorOhms / 32768.0F;
    const float temperature = pt100.calculateTemperature(
        raw, kRtdNominalOhms, kReferenceResistorOhms);
    const uint8_t fault = pt100.readFault(MAX31865_FAULT_NONE);

    Serial.printf("CH%u raw=%u resistance=%.3f ohm temperature=%.2f C",
                  channel, raw, resistance, temperature);
    if (fault != 0) {
      printFault(fault);
      pt100.clearFault();
    } else {
      Serial.print(" fault=0x00");
    }
    Serial.println();
  }

  Serial.println();
  delay(1000);
}