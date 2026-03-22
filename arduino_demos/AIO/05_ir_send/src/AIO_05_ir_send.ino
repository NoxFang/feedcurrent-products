/*
* Made by FeedCurrent IoT: https://www.feedcurrent.com
*
* Description:
* This program generates a 38 kHz PWM signal on a specified GPIO pin
* using the ESP32-S3 LEDC hardware peripheral.
* The output can be used to drive an IR LED for infrared signal transmission.
*/

#include <Arduino.h>
#include "driver/ledc.h"

#define IR_SEND_PIN 14  // GPIO pin connected to the IR LED

void setup() {
  Serial.begin(115200);

  // Configure the LEDC timer
  ledc_timer_config_t ledc_timer = {
      .speed_mode = LEDC_LOW_SPEED_MODE,       // Use low-speed mode
      .duty_resolution = LEDC_TIMER_8_BIT,     // 8-bit resolution (0-255)
      .timer_num = LEDC_TIMER_0,               // Select timer 0
      .freq_hz = 38000,                        // Set frequency to 38 kHz
      .clk_cfg = LEDC_AUTO_CLK                 // Automatically select the clock source
  };
  ledc_timer_config(&ledc_timer);

  // Configure the LEDC channel
  ledc_channel_config_t ledc_channel = {
      .gpio_num = IR_SEND_PIN,                 // Output GPIO pin
      .speed_mode = LEDC_LOW_SPEED_MODE,       // Use low-speed mode
      .channel = LEDC_CHANNEL_0,               // Channel 0
      .intr_type = LEDC_INTR_DISABLE,          // Disable interrupts
      .timer_sel = LEDC_TIMER_0,                // Use timer 0
      .duty = 128,                             // 50% duty cycle (128/255)
      .hpoint = 0                              // Start at high point 0
  };
  ledc_channel_config(&ledc_channel);

  Serial.println("38kHz PWM started.");
}

void loop() {
  // Continuously output the carrier wave
}