#include "sam.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __SYSTEM_CLOCK_4MHZ  (4000000UL)
#define __SYSTEM_CLOCK_120MHZ (120000000UL)

/* Clock Settings (4MHz) using Internal Fast RC */
uint32_t SystemCoreClock = __SYSTEM_CLOCK_4MHZ ;

/**
 * \brief Setup the microcontroller system.
 *
 * Initialize the System and update the SystemFrequency variable.
 */
void SystemInit( void )
{
{
  /* Set 6 FWS for Embedded Flash Access according to 120MHz configuration */
  EFC0->EEFC_FMR = EEFC_FMR_FWS(5)|EEFC_FMR_CLOE;
#if defined(EFC1) // Only valid for products with two flash banks
  EFC1->EEFC_FMR = EEFC_FMR_FWS(5)|EEFC_FMR_CLOE;
#endif // EFC1

  /*
   * We are coming from a Hard Reset or Backup mode.
   * The core is clocked by Internal Fast RC @ 4MHz.
   * We intend to use the device @120MHz from external Oscillator.
   * Steps are (cf datasheet chapter '29.14 Programming Sequence'):
   * 1- Activation of external oscillator
   * 2- Switch the MAINCK to the main crystal oscillator
   * 3- Wait for the MOSCSELS to be set
   * 4- Check the main clock frequency
   * 5- Set PLLx and Divider
   * 6- Select the master clock and processor clock
   * 7- Select the programmable clocks (optional)
   */

  /* Step 1 - Activation of external oscillator
   * As we are clocking the core from internal Fast RC, we keep the bit CKGR_MOR_MOSCRCEN.
   * Main Crystal Oscillator Start-up Time (CKGR_MOR_MOSCXTST) is set to maximum value.
   * Then, we wait the startup time to be finished by checking PMC_SR_MOSCXTS in PMC_SR.
   */
  PMC->CKGR_MOR = CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCXTST(0xfful) | CKGR_MOR_MOSCRCEN | CKGR_MOR_MOSCXTEN;
  for ( ; (PMC->PMC_SR & PMC_SR_MOSCXTS) != PMC_SR_MOSCXTS ; );

  /* Step 2 - Switch the MAINCK to the main crystal oscillator
   * We add the CKGR_MOR_MOSCSEL bit.
   * Then we wait for the selection to be done by checking PMC_SR_MOSCSELS in PMC_SR.
   */
  PMC->CKGR_MOR = CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCXTST(0xfful) | CKGR_MOR_MOSCRCEN | CKGR_MOR_MOSCXTEN | CKGR_MOR_MOSCSEL;
  /* Step 3 - Wait for the MOSCSELS to be set */
  for ( ; (PMC->PMC_SR & PMC_SR_MOSCSELS) != PMC_SR_MOSCSELS ; );

  /* Step 4 - Check the main clock frequency */
  /* As written in the DS, we could check the MAINF value here (0x18a2) */

  /* Step 5 - Set PLLx and Divider
   * The external oscillator is 12MHz. As we intend to clock the system @120MHz,
   * we need to multiply the oscillator frequency by 10.
   * This can be done by setting MULx to value 9 and DIV to 1.
   * We set the maximum PLL Lock time to maximum in CKGR_PLLAR_PLLACOUNT.
   */
  //PMC->CKGR_PLLAR = CKGR_PLLAR_ONE | (CKGR_PLLAR_MULA(0x1dul) | CKGR_PLLAR_DIVA(3ul) | CKGR_PLLAR_PLLACOUNT(0x1ul));
  PMC->CKGR_PLLAR = CKGR_PLLAR_ONE | (CKGR_PLLAR_MULA(0x9ul) | CKGR_PLLAR_DIVA(1ul) | CKGR_PLLAR_PLLACOUNT(0x3ful));
  for ( ; (PMC->PMC_SR & PMC_SR_LOCKA) != PMC_SR_LOCKA ; );

  /* Step 6 - Select the master clock and processor clock
   * Source for MasterClock will be PLLA output (PMC_MCKR_CSS_PLLA_CLK), without frequency division.
   */
  PMC->PMC_MCKR = PMC_MCKR_PRES_CLK_1 | PMC_MCKR_CSS_PLLA_CLK;
  for ( ; (PMC->PMC_SR & PMC_SR_MCKRDY) != PMC_SR_MCKRDY ; );

  /*
   * Step 7 - Select the programmable clocks
   * *
   * Output MCK on PCK1/pin PA17
   * Used to validate Master Clock settings
   */
//  PMC->PMC_SCER = PMC_SCER_PCK1 ;

  SystemCoreClock=__SYSTEM_CLOCK_120MHZ;
}

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
