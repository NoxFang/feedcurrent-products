/*
* Made by KinCony IoT: https://www.kincony.com
*
* DS3231 RTC with Arduino
*
* This program demonstrates how to use the DS3231 RTC (Real-Time Clock) module with the Arduino.
* It includes functionality to:
* - Initialize the DS3231 RTC module
* - Read the current date and time from the RTC
* - Set the RTC time based on a serial command: Command format: DYYYY-MM-DDTHH:MM:SS
*    Set date and time command example: D2024-09-19T11:50:22
*    print current date and time command: current time
*
* Hardware Connections:
* - SDA: GPIO 8
* - SCL: GPIO 18
* - DS3231 I2C Address: 0x68
*/

#include <DS3231.h>
#include <Wire.h>

String serial_cmd_rcv = "";

typedef struct
{
  byte year;
  byte month;
  byte day;
  byte hour;
  byte minute;
  byte second;
} MY_DATE_STR;

MY_DATE_STR my_date_str = {0};

#define SDA_PIN   8
#define SCL_PIN   18

DS3231 rtc;
bool h12Flag;
bool pmFlag;
static bool bCentury = false;

static void PrintfCurTime()
{
  Serial.print("Current time is: ");
  int year = rtc.getYear() + 2000;
  Serial.print(year);
  Serial.print("-");

  Serial.print(rtc.getMonth(bCentury), DEC);
  Serial.print("-");

  Serial.print(rtc.getDate(), DEC);
  Serial.print(" ");

  Serial.print(rtc.getHour(h12Flag, pmFlag), DEC);
  Serial.print(":");
  Serial.print(rtc.getMinute(), DEC);
  Serial.print(":");
  Serial.println(rtc.getSecond(), DEC);
}

static void GetSerialCmd()
{
  if (Serial.available() > 0)
  {
    delay(100);
    int num_read = Serial.available();
    while (num_read--)
      serial_cmd_rcv += char(Serial.read());
  }
  else return;

  serial_cmd_rcv.trim();

  if (serial_cmd_rcv == "current time")
  {
    PrintfCurTime();
    serial_cmd_rcv = "";
    return;
  }

  if (serial_cmd_rcv.length() != 20 ||
      serial_cmd_rcv.substring(0, 1) != "D" ||
      serial_cmd_rcv.substring(11, 12) != "T")
  {
    Serial.println(serial_cmd_rcv);
    serial_cmd_rcv = "";
    return;
  }

  Serial.println("Setting time...");

  my_date_str.year   = (byte)serial_cmd_rcv.substring(3, 5).toInt();
  my_date_str.month  = (byte)serial_cmd_rcv.substring(6, 8).toInt();
  my_date_str.day    = (byte)serial_cmd_rcv.substring(9, 11).toInt();
  my_date_str.hour   = (byte)serial_cmd_rcv.substring(12, 14).toInt();
  my_date_str.minute = (byte)serial_cmd_rcv.substring(15, 17).toInt();
  my_date_str.second = (byte)serial_cmd_rcv.substring(18).toInt();

  rtc.setYear(my_date_str.year);
  rtc.setMonth(my_date_str.month);
  rtc.setDate(my_date_str.day);
  rtc.setHour(my_date_str.hour);
  rtc.setMinute(my_date_str.minute);
  rtc.setSecond(my_date_str.second);

  serial_cmd_rcv = "";
  Serial.println("Time set.");
}

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN, 40000);
  Serial.begin(115200);
  rtc.setClockMode(false); // 24-hour format
  PrintfCurTime();
  while (Serial.read() >= 0) {}
}

void loop() {
  GetSerialCmd();
  delay(1000);
}
