// Basic demo for configuring the MCP4728 4-Channel 12-bit I2C DAC
#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;
#define I2C_SDA 8   // SDA pin
#define I2C_SCL 18  // SCL pin

TwoWire MYI2C = TwoWire(0);
void setup(void)
{
 

  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens


  Serial.println("Adafruit MCP4728 test!");

  MYI2C.begin(I2C_SDA, I2C_SCL,100000);

  // Try to initialize!
  if (!mcp.begin(MCP4728_I2CADDR_DEFAULT,&MYI2C)) {
    Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(10);
    }
  }

  mcp.setChannelValue(MCP4728_CHANNEL_A, 4095);
  mcp.setChannelValue(MCP4728_CHANNEL_B, 2048);
  mcp.setChannelValue(MCP4728_CHANNEL_C, 1024);
  mcp.setChannelValue(MCP4728_CHANNEL_D, 0);
}

void loop() { delay(1000); }