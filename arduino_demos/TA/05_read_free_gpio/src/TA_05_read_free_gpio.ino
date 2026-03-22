/*
* ESP32 GPIO State Reader
* Reads the state of 12 free GPIOs (1-Wire interfaces) and prints the results to the serial monitor.
*
* Made by KinCony IoT: https://www.kincony.com
*
* These 12 GPIOs are the 1-Wire interface pins with pull-up resistors on PCB.
*/

#define GPIO_9   9
#define GPIO_11  11
#define GPIO_5   5
#define GPIO_4   4
#define GPIO_7   7
#define GPIO_6   6
#define GPIO_13  13
#define GPIO_40  40
#define GPIO_14  14
#define GPIO_48  48
#define GPIO_21  21
#define GPIO_47  47

void setup() {
    Serial.begin(115200);

    // Set GPIOs as input
    pinMode(GPIO_9, INPUT);
    pinMode(GPIO_11, INPUT);
    pinMode(GPIO_5, INPUT);
    pinMode(GPIO_4, INPUT);
    pinMode(GPIO_7, INPUT);
    pinMode(GPIO_6, INPUT);
    pinMode(GPIO_13, INPUT);
    pinMode(GPIO_40, INPUT);
    pinMode(GPIO_14, INPUT);
    pinMode(GPIO_48, INPUT);
    pinMode(GPIO_21, INPUT);
    pinMode(GPIO_47, INPUT);

    Serial.println("TA Free GPIO State Reader started.");
}

void loop() {
    // Read GPIO states
    int state_9  = digitalRead(GPIO_9);
    int state_11 = digitalRead(GPIO_11);
    int state_5  = digitalRead(GPIO_5);
    int state_4  = digitalRead(GPIO_4);
    int state_7  = digitalRead(GPIO_7);
    int state_6  = digitalRead(GPIO_6);
    int state_13 = digitalRead(GPIO_13);
    int state_40 = digitalRead(GPIO_40);
    int state_14 = digitalRead(GPIO_14);
    int state_48 = digitalRead(GPIO_48);
    int state_21 = digitalRead(GPIO_21);
    int state_47 = digitalRead(GPIO_47);

    // Print GPIO states to the serial monitor
    Serial.printf("GPIO9: %d, GPIO11: %d, GPIO5: %d, GPIO4: %d, GPIO7: %d, GPIO6: %d, GPIO13: %d, GPIO40: %d, GPIO14: %d, GPIO48: %d, GPIO21: %d, GPIO47: %d\n",
                  state_9, state_11, state_5, state_4, state_7, state_6, state_13, state_40, state_14, state_48, state_21, state_47);

    delay(1000);
}
