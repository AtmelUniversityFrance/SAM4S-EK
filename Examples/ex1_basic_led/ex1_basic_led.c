/*
 * ex1_basic_led.c
 *  Author: thibaut.viard
 */

#include "sam.h"

/*
 * LED1 definitions (D2/BLUE)
 */
#define LED1_PIO  PIOA
#define LED1_PIN  PIO_PA19

/*
 * LED2 definitions (D3/GREEN)
 */
#define LED2_PIO  PIOA
#define LED2_PIN  PIO_PA20

/**
 * \brief Application entry point.
 *
 * \return Unused (ANSI-C compatibility).
 */
int main(void)
{
  // Disable watchdog
  WDT->WDT_MR=WDT_MR_WDDIS;

  // Assign the LED1 pin as OUTPUT
  LED1_PIO->PIO_OER=LED1_PIN ;
  // Clear the LED1 pin level, ie put to 0V -> the pin is connected to the LED cathode, anode is connected to +3.3V.
  LED1_PIO->PIO_CODR=LED1_PIN ;

  // Assign the LED2 pin as OUTPUT
  LED2_PIO->PIO_OER=LED2_PIN ;
  // Clear the LED2 pin level, ie put to 0V -> the pin is connected to the LED cathode, anode is connected to +3.3V.
  LED2_PIO->PIO_CODR=LED2_PIN ;
}

