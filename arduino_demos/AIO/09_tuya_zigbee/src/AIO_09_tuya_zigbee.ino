#define TUYA_RXD 15
#define TUYA_TXD 48

void setup() {
  Serial0.begin(115200);  // Serial0
  while (!Serial0);

  Serial2.begin(115200, SERIAL_8N1, TUYA_RXD, TUYA_TXD);
  delay(100);

  byte tuya_cmd[] = {0x55, 0xAA, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04};
  Serial0.println("send data to Tuya module:");
  for (int i = 0; i < sizeof(tuya_cmd); i++) {
    Serial0.printf("%02X ", tuya_cmd[i]);
    Serial2.write(tuya_cmd[i]);
  }
  Serial0.println();
}

void loop() {
  if (Serial2.available()) {
    Serial0.print("received from tuya: ");
    while (Serial2.available()) {
      byte b = Serial2.read();
      Serial0.printf("%02X ", b);
    }
    Serial0.println();
  }

  delay(100);
}