/*
 * ex3_advanced_button.c
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

/*
 * USRBP1 definitions
 */
#define USRBP1_PIO  PIOB
#define USRBP1_PIN  PIO_PB3
#define USRBP1_PID  ID_PIOB
#define USRBP1_IRQ  PIOB_IRQn

// Global state variable for LED toggle
static uint32_t ul_toggle=0 ;

/*
 * \brief Initialization of board components.
 *
 */
void hardware_init( void )
{
  // Assign the LED1 pin as OUTPUT
  LED1_PIO->PIO_OER = LED1_PIN ;
  // Clear the LED1 pin level, ie put to 0V -> the pin is connected to the LED cathode, anode is connected to +3.3V.
  LED1_PIO->PIO_CODR = LED1_PIN ;

  // Assign the LED2 pin as OUTPUT
  LED2_PIO->PIO_OER = LED2_PIN ;
  // Set the LED2 pin level, ie put to 3.3V -> the pin is connected to the LED cathode, anode is connected to +3.3V.
  LED2_PIO->PIO_SODR = LED2_PIN ;

  // Assign the USRBP1 pin as INPUT
  USRBP1_PIO->PIO_ODR = USRBP1_PIN ;
  // Clock the USRBP1 associated PIO, to allow input measure
  PMC->PMC_PCER0 = 1 << USRBP1_PID ;

  // Set debouncing filter on USRBP1 pin
  USRBP1_PIO->PIO_IFSCER = USRBP1_PIN ;
  // Enable the filter
  USRBP1_PIO->PIO_IFER = USRBP1_PIN ;
  // Set falling edge detection interrupt on USRBP1 pin (connection to GND by pressing the button)
  USRBP1_PIO->PIO_ESR = USRBP1_PIN ;
  USRBP1_PIO->PIO_FELLSR = USRBP1_PIN ;
  USRBP1_PIO->PIO_AIMER = USRBP1_PIN ;

  // Enable interrupt for USRBP1 associated PIO controller
  NVIC_EnableIRQ( USRBP1_IRQ ) ;
  // Enable interrupt for USRBP1 pin
  USRBP1_PIO->PIO_IER = USRBP1_PIN ;
}

/*
 * \brief Toggle the LED.
 *
 */
void toggle_LED( void )
{
  if ( ul_toggle == 0 )
  {
    // Set the LED1 pin level, ie put to 3.3V -> this light off the LED
    LED1_PIO->PIO_SODR=LED1_PIN ;

    // Clear the LED2 pin level, ie put to 0V -> this light on the LED
    LED2_PIO->PIO_CODR=LED2_PIN ;

    ul_toggle=1 ;
  }
  else
  {
    // Clear the LED1 pin level, ie put to 0V -> this light on the LED
    LED1_PIO->PIO_CODR=LED1_PIN ;

    // Set the LED2 pin level, ie put to 3.3V -> this light off the LED
    LED2_PIO->PIO_SODR=LED2_PIN ;

    ul_toggle=0 ;
  }
}

/**
 * \brief PIOA interrupt handler.
 *
 */
void PIOB_Handler( void )
{
  uint32_t ul_status ;

  /* Read PIO controller status */
  ul_status = USRBP1_PIO->PIO_ISR ;
  ul_status &= USRBP1_PIO->PIO_IMR ;

  /* Check pending events */
  if ( (ul_status & USRBP1_PIN) != 0 )
  {
    toggle_LED() ;
  }
}

/**
 * \brief Application entry point.
 *
 * \return Unused (ANSI-C compatibility).
 */
int main( void )
{
  // Disable watchdog
  WDT->WDT_MR=WDT_MR_WDDIS;

  // Initialize hardware
  hardware_init() ;

  while ( 1 )
  {
  }
}


