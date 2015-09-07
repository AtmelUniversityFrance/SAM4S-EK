# Basic discovery examples for SAM4S-EK

Prerequisites:
- SAM4S-EK (ATSAMS16C) or SAM4S-EK2 (ATSAMSD32C)
- 5V/2A voltage regulator
- SAM-ICE or J-Link or Atmel-ICE
- optional: RS-232 DB9 to USB Serial Port converter

## Example 1 : Basic LED

This simple example demonstrates how to configure easily General Purpose I/O ports to drive some LEDs.

## Example 2 : Basic button

This simple example demonstrates how to configure easily General Purpose I/O ports to detect if a push button is pressed.

## Example 3 : Advanced button

This example demonstrates how to configure easily General Purpose I/O ports, debouncing filter and pin interrupt to detect if a push button is pressed.

## Example 4 : LED blink

This simple example adds to example 1 the configuration of the Cortex-M Systick timer and the toggling of the LEDs every second.

## Example 5 : Clock (aka LED bling at 120MHz)

This simple example adds to example 5 the system clock setup to max frequency (120MHz).

## Example 6 : Serial print

This simple example demonstrates how to configure easily an UART at 115200bauds and send every second a character.

