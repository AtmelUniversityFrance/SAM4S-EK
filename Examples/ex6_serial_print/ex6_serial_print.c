/*
 * ex6_serial_print.c
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
 * CDC_UART definitions
 *
 * PA9: RX_UART0
 * PA10: TX_UART0
 */

#define UART_PIO        PIOA
#define UART_RX_PIN     PIO_PA9
#define UART_TX_PIN     PIO_PA10
#define UART            UART0
#define UART_PID        ID_UART0
#define UART_IRQn       UART0_IRQn
#define UART_SPEED      (115200ul)

// Global state variable for tick count
static uint32_t ul_tickcount=0 ;

static const char auc_String[] = "Hello from UART0!\r\n" ;

static char* puc_String = (char*)auc_String ;


/**
 * \brief Initialization of board components.
 *
 */
static void hardware_init( void )
{
  // Assign the LED1 pin as OUTPUT
  LED1_PIO->PIO_OER = LED1_PIN ;
  // Clear the LED1 pin level, ie put to 0V -> the pin is connected to the LED cathode, anode is connected to +3.3V.
  //  LED1_PIO->PIO_CODR = LED1_PIN ;
  LED1_PIO->PIO_SODR = LED1_PIN ;

  // Allow direct writing to LED I/O pin
  LED1_PIO->PIO_OWER = LED1_PIN ;

  // Configure Systick to trig every millisecond
  SysTick_Config( SystemCoreClock/1000UL ) ;
  NVIC_EnableIRQ( SysTick_IRQn ) ;

	// Configure UART
	PMC->PMC_PCER0 = (1 << UART_PID) ;
	// Assign UART pins to UART
	UART_PIO->PIO_ABCDSR[0] &= ~(UART_RX_PIN | UART_TX_PIN) ;
	UART_PIO->PIO_ABCDSR[1] &= ~(UART_RX_PIN | UART_TX_PIN) ;
	UART_PIO->PIO_PDR       = (UART_RX_PIN | UART_TX_PIN) ;
	// Configure UART baudrate generator
	UART->UART_BRGR = SystemCoreClock / (UART_SPEED * 16) ;
	// Configure UART parity
	UART->UART_MR = UART_MR_PAR_NO ;
	// Enable UART TX + RX
	UART->UART_CR = UART_CR_TXEN | UART_CR_RXEN ;
	// Enable UART interrupt
	UART->UART_IER = UART_IER_RXRDY ;
	NVIC_EnableIRQ( UART_IRQn ) ;
}

/**
 * \brief Toggle the LED.
 *
 */
static void toggle_LED( void )
{
  LED1_PIO->PIO_ODSR ^= LED1_PIN ;
}

/**
 * \brief Send a string on UART.
 *
 */
static void send_string( void )
{
	if ( (UART->UART_SR & UART_SR_TXRDY) == UART_SR_TXRDY )
	{
  	UART->UART_THR = *puc_String ;
  	puc_String++ ;

    // Detect end of string, then reset pointer to start
  	if ( *puc_String == '\0' )
  	{
    	puc_String = (char*)auc_String ;
  	}
	}
}

/**
* \brief UART receiving handler
*/
void UART0_Handler( void )
{
  volatile uint32_t uc_rx ;

  if ( (UART->UART_SR & UART_SR_RXRDY) == UART_SR_RXRDY )
  {
    uc_rx = UART->UART_RHR ;

    //while(!(UART->UART_SR & UART_SR_TXRDY));

    // Echo on TX
    if ( (UART->UART_SR & UART_SR_TXRDY) == UART_SR_TXRDY )
    {
      UART->UART_THR = uc_rx ;
    }
  }
}

/**
 *  \brief SysTick Interrupt handler.
 */
void SysTick_Handler( void )
{
  ul_tickcount++ ;

  // Toggle LEDs every second (ie 1000ms)
  if ( ul_tickcount % 1000 == 0 )
  {
    toggle_LED() ;
    send_string() ;
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


