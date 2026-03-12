# FeedCurrent B16 Arduino Example 11: Digital Input Trigger Output Directly

## Description
*(Example content pending – please check the forum for the correct code.)*
This example should link the 16 digital inputs to the 16 relay outputs via the two PCF8575 chips.

## Expected Behavior (Tentative)
- Input 1 (PCF8575 input pin 0) → Relay 1 (PCF8575 output pin 0), ..., Input 16 (pin 15) → Relay 16 (pin 15).
- Connecting an input to GND will activate its corresponding relay.

## Important Notes
- **Output chip**: address `0x22`, pins 0-15.
- **Input chip**: address `0x24`, pins 0-15.
- Inputs have pull-up resistors; active LOW.