/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program displays text on the SSD1306 OLED display
 * on the B32M board using the U8g2 library.
 *
 * Pin Definitions:
 * - SDA: GPIO 8
 * - SCL: GPIO 18
 * - OLED I2C Address: 0x3C
 */

#include "Arduino.h"
#include "U8g2lib.h"

// Define I2C pins
#define I2C_SDA 8
#define I2C_SCL 18

// Create U8g2 object for SSD1306 128x64
// Using software I2C - can be changed to hardware I2C
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, I2C_SCL, I2C_SDA, U8X8_PIN_NONE);

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - OLED Display Example");
    Serial.println("Initializing OLED...");
    
    // Initialize OLED
    u8g2.begin();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setFontRefHeightExtendedText();
    u8g2.setDrawColor(1);
    u8g2.setFontPosTop();
    u8g2.setFontDirection(0);
    
    Serial.println("OLED initialized!");
    
    // Display welcome screen
    displayWelcome();
    delay(3000);
}

void loop() {
    // Display main info screen
    displayMainInfo();
    delay(3000);
    
    // Display system status
    displaySystemStatus();
    delay(3000);
    
    // Display scrolling text demo
    displayScrollingText();
    delay(3000);
}

void displayWelcome() {
    u8g2.clearBuffer();
    
    // Title
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(10, 10, "KinCony");
    
    // Model
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(35, 30, "B32M");
    
    // Description
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(10, 50, "32CH MOSFET Controller");
    
    u8g2.sendBuffer();
}

void displayMainInfo() {
    u8g2.clearBuffer();
    
    // Title
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(30, 0, "B32M Info");
    
    // Draw line
    u8g2.drawLine(0, 14, 128, 14);
    
    // Info text
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0, 18, "Inputs: 32");
    u8g2.drawStr(0, 30, "Outputs: 32");
    u8g2.drawStr(0, 42, "ADC: 4CH (ADS1115)");
    u8g2.drawStr(0, 54, "Net: ETH + RS485");
    
    u8g2.sendBuffer();
}

void displaySystemStatus() {
    u8g2.clearBuffer();
    
    // Title
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(20, 0, "System Status");
    
    // Draw line
    u8g2.drawLine(0, 14, 128, 14);
    
    // Status indicators
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0, 18, "I2C: OK");
    u8g2.drawStr(0, 30, "Ethernet: Ready");
    u8g2.drawStr(0, 42, "RS485: Ready");
    
    // Uptime
    unsigned long uptime = millis() / 1000;
    char uptimeStr[20];
    sprintf(uptimeStr, "Uptime: %lus", uptime);
    u8g2.drawStr(0, 54, uptimeStr);
    
    u8g2.sendBuffer();
}

void displayScrollingText() {
    const char* message = "  FeedCurrent B32M - 32 Channel MOSFET Controller  ";
    int messageWidth = strlen(message) * 6;  // Approximate width
    int displayWidth = 128;
    
    for (int offset = 0; offset < messageWidth + displayWidth; offset++) {
        u8g2.clearBuffer();
        
        // Title
        u8g2.setFont(u8g2_font_ncenB10_tr);
        u8g2.drawStr(25, 0, "Welcome");
        u8g2.drawLine(0, 14, 128, 14);
        
        // Scrolling text
        u8g2.setFont(u8g2_font_ncenB08_tr);
        u8g2.drawStr(displayWidth - offset, 30, message);
        
        // Static text at bottom
        u8g2.drawStr(15, 50, "Smart Home IoT");
        
        u8g2.sendBuffer();
        delay(20);
    }
}
