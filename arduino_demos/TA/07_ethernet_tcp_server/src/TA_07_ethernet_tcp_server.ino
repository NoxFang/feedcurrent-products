/*
 * Made by KinCony IoT: https://www.kincony.com
 *
 * This Arduino program sets up an ESP32-S3 with a W5500 Ethernet module
 * as a TCP server. It listens on port 4196 and echoes back any string
 * received from a client.
 *
 * Hardware connections:
 * - CLK:  GPIO1
 * - MOSI: GPIO2
 * - MISO: GPIO41
 * - CS:   GPIO42
 * - INT:  GPIO43
 * - RST:  GPIO44
 *
 * Static IP address: 192.168.3.55
 * Subnet Mask: 255.255.255.0
 * Gateway: 192.168.3.1
 * DNS: 192.168.3.1
 */

#include <SPI.h>
#include <Ethernet.h>

// W5500 Ethernet module pins
#define W5500_CLK_PIN  1
#define W5500_MOSI_PIN 2
#define W5500_MISO_PIN 41
#define W5500_CS_PIN   42
#define W5500_INT_PIN  43
#define W5500_RST_PIN  44

// MAC address (must be unique on your network)
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Static IP configuration
IPAddress ip(192, 168, 3, 55);
IPAddress subnet(255, 255, 255, 0);
IPAddress gateway(192, 168, 3, 1);
IPAddress dns(192, 168, 3, 1);

EthernetServer server(4196);

void setup() {
  Serial.begin(115200);
  while (!Serial) { ; }

  // Reset W5500
  pinMode(W5500_RST_PIN, OUTPUT);
  pinMode(W5500_INT_PIN, INPUT);
  digitalWrite(W5500_RST_PIN, LOW);
  delay(100);
  digitalWrite(W5500_RST_PIN, HIGH);

  SPI.begin(W5500_CLK_PIN, W5500_MISO_PIN, W5500_MOSI_PIN);
  Ethernet.init(W5500_CS_PIN);
  Ethernet.begin(mac, ip, dns, gateway, subnet);

  Serial.print("IP Address: ");
  Serial.println(Ethernet.localIP());

  server.begin();
  Serial.println("TCP Server started on port 4196");
}

void loop() {
  EthernetClient client = server.available();

  if (client) {
    Serial.println("New client connected");

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        server.write(c);  // Echo back to client
      }
    }

    client.stop();
    Serial.println("Client disconnected");
  }
}
