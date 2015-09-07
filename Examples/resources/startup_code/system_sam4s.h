#ifndef SYSTEM_SAM4S_H_INCLUDED
#define SYSTEM_SAM4S_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern uint32_t SystemCoreClock ; /* System Clock Frequency (Core Clock) */

/**
 * @brief Setup the microcontroller system.
 * Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit( void ) ;

/**
 * @brief Updates the SystemCoreClock with current core Clock
 * retrieved from cpu registers.
 */
void SystemCoreClockUpdate( void ) ;

/**
 * Initialize flash.
 */
void SystemInitFlash( uint32_t dw_clk ) ;

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_SAM4S_H_INCLUDED */
