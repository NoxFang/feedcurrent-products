/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program demonstrates basic SD card operations on the B32M board:
 * mount, read/write files, and list files.
 *
 * Pin Definitions:
 * - CS: GPIO 9
 * - MOSI: GPIO 10
 * - CLK: GPIO 11
 * - MISO: GPIO 12
 */

#include "Arduino.h"
#include "SD_MMC.h"
#include "FS.h"

// Define SD card pins (SPI)
#define SD_CS   9
#define SD_MOSI 10
#define SD_CLK  11
#define SD_MISO 12

SPIClass spi = SPIClass(HSPI);

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - SD Card Operations");
    Serial.println("Initializing SD card...");
    
    // Initialize SPI
    spi.begin(SD_CLK, SD_MISO, SD_MOSI, SD_CS);
    
    // Initialize SD card
    if (!SD_MMC.begin("/sdcard", true)) {
        Serial.println("Failed to mount SD card!");
        Serial.println("Please check:");
        Serial.println("  - SD card is inserted");
        Serial.println("  - SD card is formatted as FAT16/FAT32");
        return;
    }
    
    Serial.println("SD card mounted successfully!");
    
    // Get SD card info
    uint8_t cardType = SD_MMC.cardType();
    uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
    
    Serial.print("Card Type: ");
    switch(cardType) {
        case CARD_MMC:
            Serial.println("MMC");
            break;
        case CARD_SD:
            Serial.println("SDSC");
            break;
        case CARD_SDHC:
            Serial.println("SDHC");
            break;
        default:
            Serial.println("UNKNOWN");
    }
    
    Serial.print("Card Size: ");
    Serial.print(cardSize);
    Serial.println(" MB");
    
    // List files
    Serial.println("\nFiles on SD card:");
    listDir("/", 0);
    
    // Write test file
    Serial.println("\nWriting test file...");
    writeFile("/test.txt", "Hello from FeedCurrent B32M!\n");
    
    // Read test file
    Serial.println("Reading test file:");
    readFile("/test.txt");
    
    // Append to test file
    Serial.println("\nAppending to test file...");
    appendFile("/test.txt", "This is a test of SD card operations.\n");
    
    // Read again
    Serial.println("Reading updated file:");
    readFile("/test.txt");
}

void loop() {
    // Nothing to do here
    delay(10000);
}

void listDir(const char * dirname, uint8_t levels) {
    File root = SD_MMC.open(dirname);
    if (!root) {
        Serial.println("Failed to open directory");
        return;
    }
    if (!root.isDirectory()) {
        Serial.println("Not a directory");
        return;
    }

    File file = root.openNextFile();
    while (file) {
        if (file.isDirectory()) {
            Serial.print("  DIR : ");
            Serial.println(file.name());
            if (levels) {
                listDir(file.name(), levels - 1);
            }
        } else {
            Serial.print("  FILE: ");
            Serial.print(file.name());
            Serial.print("  SIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
}

void readFile(const char * path) {
    File file = SD_MMC.open(path);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }

    Serial.print("Read from file: ");
    Serial.println(path);
    while (file.available()) {
        Serial.write(file.read());
    }
    file.close();
}

void writeFile(const char * path, const char * message) {
    File file = SD_MMC.open(path, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    if (file.print(message)) {
        Serial.println("File written successfully");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void appendFile(const char * path, const char * message) {
    File file = SD_MMC.open(path, FILE_APPEND);
    if (!file) {
        Serial.println("Failed to open file for appending");
        return;
    }
    if (file.print(message)) {
        Serial.println("Message appended successfully");
    } else {
        Serial.println("Append failed");
    }
    file.close();
}
