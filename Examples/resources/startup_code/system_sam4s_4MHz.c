#include "sam.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __SYSTEM_CLOCK_4MHZ  (4000000UL)
#define __SYSTEM_CLOCK_12MHZ (12000000UL)

/* Clock Settings (4MHz) using Internal Fast RC */
uint32_t SystemCoreClock = __SYSTEM_CLOCK_4MHZ ;

/**
 * \brief Setup the microcontroller system.
 *
 * Initialize the System and update the SystemFrequency variable.
 */
void SystemInit( void )
{
  /* Set 1 FWS for Embedded Flash Access */
  EFC0->EEFC_FMR = EEFC_FMR_FWS(1)|EEFC_FMR_CLOE;
#if defined(ID_EFC1)
  EFC1->EEFC_FMR = EEFC_FMR_FWS(1)|EEFC_FMR_CLOE;
#endif
}

/**
 * \brief Get Core Clock Frequency.
 */
void SystemCoreClockUpdate( void )
{
}

#ifdef __cplusplus
}
#endif
