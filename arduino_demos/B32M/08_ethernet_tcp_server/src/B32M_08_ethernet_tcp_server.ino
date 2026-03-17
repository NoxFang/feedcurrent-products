/*
 * Made by FeedCurrent IoT: https://www.feedcurrent.com
 *
 * Description:
 * This Arduino program sets up the W5500 Ethernet module on the B32M board
 * as a TCP server on port 4196, echoing back any received data.
 *
 * Pin Definitions:
 * - CLK: GPIO 1
 * - MOSI: GPIO 2
 * - MISO: GPIO 41
 * - CS: GPIO 42
 * - INT: GPIO 43
 * - RST: GPIO 44
 */

#include "Arduino.h"
#include "SPI.h"
#include "Ethernet.h"

// Define Ethernet pins
#define ETH_CLK  1
#define ETH_MOSI 2
#define ETH_MISO 41
#define ETH_CS   42
#define ETH_INT  43
#define ETH_RST  44

// MAC address (must be unique on your network)
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// IP address (modify as needed)
IPAddress ip(192, 168, 1, 100);

// TCP server port
#define SERVER_PORT 4196

// Create server
EthernetServer server(SERVER_PORT);

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("B32M - Ethernet TCP Server");
    Serial.println("Initializing Ethernet...");
    
    // Initialize SPI
    SPI.begin(ETH_CLK, ETH_MISO, ETH_MOSI, ETH_CS);
    
    // Initialize Ethernet with static IP
    Ethernet.init(ETH_CS);
    Ethernet.begin(mac, ip);
    
    // Check for hardware
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
        Serial.println("Ethernet shield not found!");
        while (true) {
            delay(1);
        }
    }
    
    // Check for link
    if (Ethernet.linkStatus() == LinkOFF) {
        Serial.println("Ethernet cable is not connected!");
    }
    
    // Start server
    server.begin();
    
    Serial.print("Server started at ");
    Serial.print(Ethernet.localIP());
    Serial.print(":");
    Serial.println(SERVER_PORT);
    Serial.println("Waiting for connections...\n");
}

void loop() {
    // Check for new clients
    EthernetClient client = server.available();
    
    if (client) {
        Serial.print("New client connected from ");
        Serial.println(client.remoteIP());
        
        while (client.connected()) {
            if (client.available()) {
                // Read data from client
                String received = client.readStringUntil('\n');
                received.trim();
                
                Serial.print("Received: ");
                Serial.println(received);
                
                // Echo back to client
                client.print("Echo: ");
                client.println(received);
                
                // Check for disconnect command
                if (received.equalsIgnoreCase("bye")) {
                    client.println("Goodbye!");
                    break;
                }
            }
        }
        
        // Close connection
        delay(10);
        client.stop();
        Serial.println("Client disconnected\n");
    }
}
