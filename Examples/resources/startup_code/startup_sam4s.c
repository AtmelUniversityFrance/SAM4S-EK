#include "sam.h"

/* Initialize segments */
extern uint32_t __etext ;
extern uint32_t __data_start__ ;
extern uint32_t __data_end__ ;
extern uint32_t __bss_start__ ;
extern uint32_t __bss_end__ ;
extern uint32_t __StackTop ;

extern int main(void);
extern void __libc_init_array(void);

/* Default empty handler */
void Dummy_Handler(void);

/* Cortex-M4 core handlers */
void NMI_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void HardFault_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void MemManage_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void BusFault_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UsageFault_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SVC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DebugMon_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PendSV_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SysTick_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

/* Peripherals handlers */
void SUPC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RSTC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTT_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void WDT_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PMC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EFC0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef EFC1
void EFC1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* EFC1 */
void UART0_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART1_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOA_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOB_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef PIOC
void PIOC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* PIOC */
void USART0_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef USART1
void USART1_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* USART1 */
#ifdef HSMCI
void HSMCI_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* HSMCI */
void TWI0_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI1_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SSC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef TC1
void TC3_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC4_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC5_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* TC1 */
void ADC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef DACC
void DACC_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* DACC */
void PWM_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void CRCCU_Handler  ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ACC_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USBDEV_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

/* Exception Table */
__attribute__ ((section(".isr_vector")))
const DeviceVectors exception_table =
{
  /* Configure Initial Stack Pointer, using linker-generated symbols */
  .pvStack = (void*) (&__StackTop),

  .pfnReset_Handler      = (void*) Reset_Handler,
  .pfnNMI_Handler        = (void*) NMI_Handler,
  .pfnHardFault_Handler  = (void*) HardFault_Handler,
  .pfnMemManage_Handler  = (void*) MemManage_Handler,
  .pfnBusFault_Handler   = (void*) BusFault_Handler,
  .pfnUsageFault_Handler = (void*) UsageFault_Handler,
  .pfnReserved1_Handler  = (void*) (0UL),          /* Reserved */
  .pfnReserved2_Handler  = (void*) (0UL),          /* Reserved */
  .pfnReserved3_Handler  = (void*) (0UL),          /* Reserved */
  .pfnReserved4_Handler  = (void*) (0UL),          /* Reserved */
  .pfnSVC_Handler        = (void*) SVC_Handler,
  .pfnDebugMon_Handler   = (void*) DebugMon_Handler,
  .pfnReserved5_Handler  = (void*) (0UL),          /* Reserved */
  .pfnPendSV_Handler     = (void*) PendSV_Handler,
  .pfnSysTick_Handler    = (void*) SysTick_Handler,

  /* Configurable interrupts */
  .pfnSUPC_Handler   = (void*) SUPC_Handler,   /* 0  Supply Controller */
  .pfnRSTC_Handler   = (void*) RSTC_Handler,   /* 1  Reset Controller */
  .pfnRTC_Handler    = (void*) RTC_Handler,    /* 2  Real Time Clock */
  .pfnRTT_Handler    = (void*) RTT_Handler,    /* 3  Real Time Timer */
  .pfnWDT_Handler    = (void*) WDT_Handler,    /* 4  Watchdog Timer */
  .pfnPMC_Handler    = (void*) PMC_Handler,    /* 5  Power Management Controller */
  .pfnEFC0_Handler   = (void*) EFC0_Handler,   /* 6  Enhanced Embedded Flash Controller 0 */
#ifdef EFC1
  .pfnEFC1_Handler   = (void*) EFC1_Handler,   /* 7  Enhanced Embedded Flash Controller 1 */
#else
  .pvReserved7       = (void*) (0UL),          /* 7  Reserved */
#endif /* EFC1 */
  .pfnUART0_Handler  = (void*) UART0_Handler,  /* 8  UART 0 */
  .pfnUART1_Handler  = (void*) UART1_Handler,  /* 9  UART 1 */
  .pvReserved10      = (void*) (0UL),          /* 10 Reserved */
  .pfnPIOA_Handler   = (void*) PIOA_Handler,   /* 11 Parallel I/O Controller A */
  .pfnPIOB_Handler   = (void*) PIOB_Handler,   /* 12 Parallel I/O Controller B */
#ifdef PIOC
  .pfnPIOC_Handler   = (void*) PIOC_Handler,   /* 13 Parallel I/O Controller C */
#else
  .pvReserved13      = (void*) (0UL),          /* 13 Reserved */
#endif /* PIOC */
  .pfnUSART0_Handler = (void*) USART0_Handler, /* 14 USART 0 */
#ifdef USART1
  .pfnUSART1_Handler = (void*) USART1_Handler, /* 15 USART 1 */
#else
  .pvReserved15      = (void*) (0UL),          /* 15 Reserved */
#endif /* USART1 */
  .pvReserved16      = (void*) (0UL),          /* 16 Reserved */
  .pvReserved17      = (void*) (0UL),          /* 17 Reserved */
#ifdef HSMCI
  .pfnHSMCI_Handler  = (void*) HSMCI_Handler,  /* 18 Multimedia Card Interface */
#else
  .pvReserved18      = (void*) (0UL),          /* 18 Reserved */
#endif /* HSMCI */
  .pfnTWI0_Handler   = (void*) TWI0_Handler,   /* 19 Two Wire Interface 0 */
  .pfnTWI1_Handler   = (void*) TWI1_Handler,   /* 20 Two Wire Interface 1 */
  .pfnSPI_Handler    = (void*) SPI_Handler,    /* 21 Serial Peripheral Interface */
  .pfnSSC_Handler    = (void*) SSC_Handler,    /* 22 Synchronous Serial Controller */
  .pfnTC0_Handler    = (void*) TC0_Handler,    /* 23 Timer/Counter 0 */
  .pfnTC1_Handler    = (void*) TC1_Handler,    /* 24 Timer/Counter 1 */
  .pfnTC2_Handler    = (void*) TC2_Handler,    /* 25 Timer/Counter 2 */
#ifdef TC1
  .pfnTC3_Handler    = (void*) TC3_Handler,    /* 26 Timer/Counter 3 */
  .pfnTC4_Handler    = (void*) TC4_Handler,    /* 27 Timer/Counter 4 */
  .pfnTC5_Handler    = (void*) TC5_Handler,    /* 28 Timer/Counter 5 */
#else
  .pvReserved26      = (void*) (0UL),          /* 26 Reserved */
  .pvReserved27      = (void*) (0UL),          /* 27 Reserved */
  .pvReserved28      = (void*) (0UL),          /* 28 Reserved */
#endif /* _SAM4S_TC1_INSTANCE_ */
  .pfnADC_Handler    = (void*) ADC_Handler,    /* 29 Analog To Digital Converter */
#ifdef DACC
  .pfnDACC_Handler   = (void*) DACC_Handler,   /* 30 Digital To Analog Converter */
#else
  .pvReserved30      = (void*) (0UL),          /* 30 Reserved */
#endif /* DACC */
  .pfnPWM_Handler    = (void*) PWM_Handler,    /* 31 Pulse Width Modulation */
  .pfnCRCCU_Handler  = (void*) CRCCU_Handler,  /* 32 CRC Calculation Unit */
  .pfnACC_Handler    = (void*) ACC_Handler,    /* 33 Analog Comparator */
  .pfnUSBDEV_Handler = (void*) USBDEV_Handler  /* 34 USB Device Port */
};

/**
 * \brief This is the code that gets called on processor reset.
 * To initialize the device, and call the main() routine.
 */
void Reset_Handler( void )
{
	uint32_t *pSrc, *pDest;

	/* Initialize the initialized data section */
	pSrc = &__etext;
	pDest = &__data_start__;

	if ( (&__data_start__ != &__data_end__) && (pSrc != pDest) )
	{
		for (; pDest < &__data_end__ ; pDest++, pSrc++ )
		{
			*pDest = *pSrc ;
		}
	}

	/* Clear the zero section */
	if ( &__bss_start__ != &__bss_end__ )
	{
		for ( pDest = &__bss_start__ ; pDest < &__bss_end__ ; pDest++ )
		{
			*pDest = 0ul ;
		}
	}

	/* Initialize the C library */
	__libc_init_array() ;

	SystemInit() ;

	/* Branch to main function */
	main() ;

	/* Infinite loop */
	while ( 1 )
	{
	}
}

/**
 * \brief Default interrupt handler for unused IRQs.
 */
void Dummy_Handler( void )
{
  while ( 1 )
  {
  }
}
