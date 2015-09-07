/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2014, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

#ifndef _SAMG55G19_
#define _SAMG55G19_

/** \addtogroup SAMG55G19_definitions SAMG55G19 definitions
  This file defines all structures and symbols for SAMG55G19:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
*/
/*@{*/

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

/* ************************************************************************** */
/*   CMSIS DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */
/** \addtogroup SAMG55G19_cmsis CMSIS Definitions */
/*@{*/

/**< Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M4 Processor Exceptions Numbers ******************************/
  NonMaskableInt_IRQn   = -14, /**<  2 Non Maskable Interrupt                */
  MemoryManagement_IRQn = -12, /**<  4 Cortex-M4 Memory Management Interrupt */
  BusFault_IRQn         = -11, /**<  5 Cortex-M4 Bus Fault Interrupt         */
  UsageFault_IRQn       = -10, /**<  6 Cortex-M4 Usage Fault Interrupt       */
  SVCall_IRQn           = -5,  /**< 11 Cortex-M4 SV Call Interrupt           */
  DebugMonitor_IRQn     = -4,  /**< 12 Cortex-M4 Debug Monitor Interrupt     */
  PendSV_IRQn           = -2,  /**< 14 Cortex-M4 Pend SV Interrupt           */
  SysTick_IRQn          = -1,  /**< 15 Cortex-M4 System Tick Interrupt       */
/******  SAMG55G19 specific Interrupt Numbers *********************************/

 SUPC_IRQn             =  0, /**<  0 SAMG55G19 Supply Controller (SUPC) */
  RSTC_IRQn            =  1, /**<  1 SAMG55G19 Reset Controller (RSTC) */
  RTC_IRQn             =  2, /**<  2 SAMG55G19 Real Time Clock (RTC) */
  RTT_IRQn             =  3, /**<  3 SAMG55G19 Real Time Timer (RTT) */
  WDT_IRQn             =  4, /**<  4 SAMG55G19 Watchdog Timer (WDT) */
  PMC_IRQn             =  5, /**<  5 SAMG55G19 Power Management Controller (PMC) */
  EFC0_IRQn            =  6, /**<  6 SAMG55J19 Enhanced Flash Controller (EFC0) */
  FLEXCOM0_IRQn        =  8, /**<  8 SAMG55G19 FLEXCOM 0 (FLEXCOM0) */
  FLEXCOM1_IRQn        =  9, /**<  9 SAMG55G19 FLEXCOM 1 (FLEXCOM1) */
  PIOA_IRQn            = 11, /**< 11 SAMG55G19 Parallel I/O Controller A (PIOA) */
  PIOB_IRQn            = 12, /**< 12 SAMG55G19 Parallel I/O Controller B (PIOB) */
  PDMIC0_IRQn          = 13, /**< 13 SAMG55G19 PDM 0 (PDMIC0) */
  FLEXCOM2_IRQn        = 14,  /**< 14 SAMG55G19 FLEXCOM2 (FLEXCOM2) */
  MEM2MEM_IRQn         = 15, /**< 15 SAMG55G19 MEM2MEM (MEM2MEM) */
  I2SC0_IRQn           = 16, /**< 16 SAMG55G19 I2SC0 (I2SC0) */
  I2SC1_IRQn           = 17, /**< 17 SAMG55G19 I2SC1 (I2SC1) */
  PDMIC1_IRQn          = 18, /**< 18 SAMG55G19 PDM 1 (PDMIC1) */
  FLEXCOM3_IRQn        = 19, /**< 19 SAMG55G19 FLEXCOM3 (FLEXCOM3) */
  FLEXCOM4_IRQn        = 20, /**< 20 SAMG55G19 FLEXCOM4 (FLEXCOM4) */
  FLEXCOM5_IRQn        = 21, /**< 21 SAMG55G19 FLEXCOM5 (FLEXCOM5) */
  FLEXCOM6_IRQn        = 22, /**< 22 SAMG55G19 FLEXCOM6 (FLEXCOM6) */
  TC0_IRQn             = 23, /**< 23 SAMG55G19 Timer/Counter 0 (TC0) */
  TC1_IRQn             = 24, /**< 24 SAMG55G19 Timer/Counter 1 (TC1) */
  TC2_IRQn             = 25, /**< 25 SAMG55G19 Timer/Counter 2 (TC2) */
  TC3_IRQn             = 26, /**< 26 SAMG55G19 Timer/Counter 3 (TC3) */
  TC4_IRQn             = 27, /**< 27 SAMG55G19 Timer/Counter 4 (TC4) */
  TC5_IRQn             = 28, /**< 28 SAMG55G19 Timer/Counter 5 (TC5) */
  ADC_IRQn             = 29, /**< 29 SAMG55G19 Analog To Digital Converter (ADC) */
  FPU_IRQn             = 30, /**< 30 SAMG55G19 FPU (ARM) */
  WKUP0_IRQn           = 31, /**< 31 SAMG55G19 External interrupt 0 (WKUP0) */
  WKUP1_IRQn           = 32, /**< 32 SAMG55G19 External interrupt 1 (WKUP1) */
  WKUP2_IRQn           = 33, /**< 33 SAMG55G19 External interrupt 2 (WKUP2) */
  WKUP3_IRQn           = 34, /**< 34 SAMG55G19 External interrupt 3 (WKUP3) */
  WKUP4_IRQn           = 35, /**< 35 SAMG55G19 External interrupt 4 (WKUP4) */
  WKUP5_IRQn           = 36, /**< 36 SAMG55G19 External interrupt 5 (WKUP5) */
  WKUP6_IRQn           = 37, /**< 37 SAMG55G19 External interrupt 6 (WKUP6) */
  WKUP7_IRQn           = 38, /**< 38 SAMG55G19 External interrupt 7 (WKUP7) */
  WKUP8_IRQn           = 39, /**< 39 SAMG55G19 External interrupt 8 (WKUP8) */
  WKUP9_IRQn           = 40, /**< 40 SAMG55G19 External interrupt 9 (WKUP9) */
  WKUP10_IRQn          = 41, /**< 41 SAMG55G19 External interrupt 10 (WKUP10) */
  WKUP11_IRQn          = 42, /**< 42 SAMG55G19 External interrupt 11 (WKUP11) */
  WKUP12_IRQn          = 43, /**< 43 SAMG55G19 External interrupt 12 (WKUP12) */
  WKUP13_IRQn          = 44, /**< 44 SAMG55G19 External interrupt 13 (WKUP13) */
  WKUP14_IRQn          = 45, /**< 45 SAMG55G19 External interrupt 14 (WKUP14) */
  WKUP15_IRQn          = 46, /**< 46 SAMG55G19 External interrupt 15 (WKUP15) */
  UHP_IRQn             = 47, /**< 47 SAMG55G19 USB OHCI (UHP) */
  USBDEV_IRQn          = 48, /**< 48 SAMG55G19 USB Device FS (USBDEV) */
  CRCCU_IRQn           = 49, /**< 49 SAMG55G19 CRCCU */
  PERIPH_COUNT_IRQn    = 50  /**< Number of peripheral IDs */
} IRQn_Type;

typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;

  /* Cortex-M handlers */
  void* pfnReset_Handler;
  void* pfnNMI_Handler;
  void* pfnHardFault_Handler;
  void* pfnMemManage_Handler;
  void* pfnBusFault_Handler;
  void* pfnUsageFault_Handler;
  void* pfnReserved1_Handler;
  void* pfnReserved2_Handler;
  void* pfnReserved3_Handler;
  void* pfnReserved4_Handler;
  void* pfnSVC_Handler;
  void* pfnDebugMon_Handler;
  void* pfnReserved5_Handler;
  void* pfnPendSV_Handler;
  void* pfnSysTick_Handler;

  /* Peripheral handlers */
  void* pfnSUPC_Handler;      /*  0 Supply Controller */
  void* pfnRSTC_Handler;      /*  1 Reset Controller */
  void* pfnRTC_Handler;       /*  2 Real Time Clock */
  void* pfnRTT_Handler;       /*  3 Real Time Timer */
  void* pfnWDT_Handler;       /*  4 Watchdog Timer */
  void* pfnPMC_Handler;       /*  5 Power Management Controller */
  void* pfnEFC0_Handler;      /*  6 Enhanced Flash Controller */
  void* pvReserved7;
  void* pfnFLEXCOM0_Handler;  /* 8  FLEXCOM 0 */
  void* pfnFLEXCOM1_Handler;  /* 9  FLEXCOM 1 */
  void* pvReserved10;
  void* pfnPIOA_Handler;      /* 11 Parallel I/O Controller A */
  void* pfnPIOB_Handler;      /* 12 Parallel I/O Controller B */
  void* pfnPDMIC0_Handler;    /* 13 PDM 0 */
  void* pfnFLEXCOM2_Handler;  /* 14  FLEXCOM 2 */
  void* pfnMEM2MEM_Handler;   /* 15 MEM2MEM */
  void* pfnI2SC0_Handler;     /* 16 I2SC0 */
  void* pfnI2SC1_Handler;     /* 17 I2SC1 */
  void* pfnPDMIC1_Handler;    /* 18 PDM 1 */
  void* pfnFLEXCOM3_Handler;  /* 19  FLEXCOM 3 */
  void* pfnFLEXCOM4_Handler;  /* 20  FLEXCOM 4 */
  void* pfnFLEXCOM5_Handler;  /* 21  FLEXCOM 5 */
  void* pfnFLEXCOM6_Handler;  /* 22  FLEXCOM 6 */
  void* pfnTC0_Handler;       /* 23 Timer/Counter 0 */
  void* pfnTC1_Handler;       /* 24 Timer/Counter 1 */
  void* pfnTC2_Handler;       /* 25 Timer/Counter 2 */
  void* pfnTC3_Handler;       /* 26 Timer/Counter 3 */
  void* pfnTC4_Handler;       /* 27 Timer/Counter 4 */
  void* pfnTC5_Handler;       /* 28 Timer/Counter 5 */
  void* pfnADC_Handler;       /* 29 Analog To Digital Converter */
  void* pfnFPU_Handler;       /* 30 FPU */
  void* pvReserved31;
  void* pvReserved32;
  void* pvReserved33;
  void* pvReserved34;
  void* pvReserved35;
  void* pvReserved36;
  void* pvReserved37;
  void* pvReserved38;
  void* pvReserved39;
  void* pvReserved40;
  void* pvReserved41;
  void* pvReserved42;
  void* pvReserved43;
  void* pvReserved44;
  void* pvReserved45;
  void* pvReserved46;
  void* pfnUHP_Handler;       /* 47 USB OHCI */
  void* pfnUSBDEV_Handler;    /* 48 USB Device FS */
  void* pfnCRCCU_Handler;     /* 49 CRCCU Device  */
} DeviceVectors;

/* Cortex-M4 core handlers */
void Reset_Handler      ( void );
void NMI_Handler        ( void );
void HardFault_Handler  ( void );
void MemManage_Handler  ( void );
void BusFault_Handler   ( void );
void UsageFault_Handler ( void );
void SVC_Handler        ( void );
void DebugMon_Handler   ( void );
void PendSV_Handler     ( void );
void SysTick_Handler    ( void );

/* Peripherals handlers */
void ADC_Handler        ( void );
void ARM_Handler        ( void );
void CRCCU_Handler      ( void );
void EFC0_Handler       ( void );
void I2SC0_Handler      ( void );
void I2SC1_Handler      ( void );
void MEM2MEM_Handler    ( void );
void PDMIC0_Handler     ( void );
void PDMIC1_Handler     ( void );
void PIOA_Handler       ( void );
void PIOB_Handler       ( void );
void PMC_Handler        ( void );
void RSTC_Handler       ( void );
void RTC_Handler        ( void );
void RTT_Handler        ( void );
void SUPC_Handler       ( void );
void TC0_Handler        ( void );
void TC1_Handler        ( void );
void TC2_Handler        ( void );
void TC3_Handler        ( void );
void TC4_Handler        ( void );
void TC5_Handler        ( void );
void USBDEV_Handler     ( void );
void UHP_Handler        ( void );
void FLEXCOM0_Handler   ( void );
void FLEXCOM1_Handler   ( void );
void FLEXCOM2_Handler   ( void );
void FLEXCOM3_Handler   ( void );
void FLEXCOM4_Handler   ( void );
void FLEXCOM5_Handler   ( void );
void FLEXCOM6_Handler   ( void );
void WDT_Handler        ( void );
/**
 * \brief Configuration of the Cortex-M4 Processor and Core Peripherals
 */

#define __CM4_REV              0x0001 /**< SAMG55G19 core revision number ([15:8] revision number, [7:0] patch number) */
#define __MPU_PRESENT          1      /**< SAMG55G19 does provide a MPU */
#define __FPU_PRESENT          1      /**< SAMG55G19 does provide a FPU */
#define __NVIC_PRIO_BITS       4      /**< SAMG55G19 uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig 0      /**< Set to 1 if different SysTick Config is used */

/*
 * \brief CMSIS includes
 */

#include <core_cm4.h>
#if !defined DONT_USE_CMSIS_INIT
#include "system_samg55.h"
#endif /* DONT_USE_CMSIS_INIT */

/*@}*/

/* ************************************************************************** */
/**  SOFTWARE PERIPHERAL API DEFINITION FOR SAMG55G19 */
/* ************************************************************************** */
/** \addtogroup SAMG55G19_api Peripheral Software API */
/*@{*/

#include "component/adc.h"
#include "component/chipid.h"
#include "component/cmcc.h"
#include "component/crccu.h"
#include "component/efc.h"
#include "component/flexcom.h"
#include "component/gpbr.h"
#include "component/i2sc.h"
#include "component/matrix.h"
#include "component/mem2mem.h"
#include "component/pdc.h"
#include "component/pdmic.h"
#include "component/pio.h"
#include "component/pmc.h"
#include "component/rstc.h"
#include "component/rtc.h"
#include "component/rtt.h"
#include "component/spi.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/twi.h"
#include "component/usbdev.h"
#include "component/uhp.h"
#include "component/usart.h"
#include "component/wdt.h"
/*@}*/

/* ************************************************************************** */
/*   PERIPHERAL ID DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */
/** \addtogroup SAMG55G19_id Peripheral Ids Definitions */
/*@{*/

#define ID_SUPC      ( 0) /**< \brief Supply Controller (SUPC) */
#define ID_RSTC      ( 1) /**< \brief Reset Controller (RSTC) */
#define ID_RTC       ( 2) /**< \brief Real Time Clock (RTC) */
#define ID_RTT       ( 3) /**< \brief Real Time Timer (RTT) */
#define ID_WDT       ( 4) /**< \brief Watchdog Timer (WDT) */
#define ID_PMC       ( 5) /**< \brief Power Management Controller (PMC) */
#define ID_EFC0      ( 6) /**< \brief Enhanced Flash Controller (EFC0) */
#define ID_FLEXCOM0  ( 8) /**< \brief FLEXCOM0 */
#define ID_FLEXCOM1  ( 9) /**< \brief FLEXCOM1 */
#define ID_PIOA      (11) /**< \brief Parallel I/O Controller A (PIOA) */
#define ID_PIOB      (12) /**< \brief Parallel I/O Controller B (PIOB) */
#define ID_PDMIC0    (13) /**< \brief PDM 0 (PDMIC0) */
#define ID_FLEXCOM2  (14) /**< \brief FLEXCOM2 */
#define ID_MEM2MEM   (15) /**< \brief MEM2MEM (MEM2MEM) */
#define ID_I2SC0     (16) /**< \brief I2SC0 (I2SC0) */
#define ID_I2SC1     (17) /**< \brief I2SC1 (I2SC1) */
#define ID_PDMIC1    (18) /**< \brief PDM 1 (PDMIC1) */
#define ID_FLEXCOM3  (19) /**< \brief FLEXCOM3 */
#define ID_FLEXCOM4  (20) /**< \brief FLEXCOM4 */
#define ID_FLEXCOM5  (21) /**< \brief FLEXCOM5 */
#define ID_FLEXCOM6  (22) /**< \brief FLEXCOM6 */
#define ID_TC0       (23) /**< \brief Timer/Counter 0 (TC0) */
#define ID_TC1       (24) /**< \brief Timer/Counter 1 (TC1) */
#define ID_TC2       (25) /**< \brief Timer/Counter 2 (TC2) */
#define ID_TC3       (26) /**< \brief Timer/Counter 3 (TC3) */
#define ID_TC4       (27) /**< \brief Timer/Counter 4 (TC4) */
#define ID_TC5       (28) /**< \brief Timer/Counter 5 (TC5) */
#define ID_ADC       (29) /**< \brief Analog To Digital Converter (ADC) */
#define ID_ARM       (30) /**< \brief FPU (ARM) */
#define ID_UHP       (47) /**< \brief USB OHCI (UHP) */
#define ID_USBDEV    (48) /**< \brief USB Device FS (USBDEV) */
#define ID_CRCCU     (49) /**< \brief CRCCU (CRCCU) */

#define ID_PERIPH_COUNT (50) /**< \brief Number of peripheral IDs */
/*@}*/

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */
/** \addtogroup SAMG55G19_base Peripheral Base Address Definitions */
/*@{*/

#define I2SC0       ((I2sc     *)0x40000000U) /**< \brief (I2SC0      ) Base Address */
#define PDC_I2SC0   ((Pdc      *)0x40000100U) /**< \brief (PDC_I2SC0  ) Base Address */
#define I2SC1       ((I2sc     *)0x40004000U) /**< \brief (I2SC1      ) Base Address */
#define PDC_I2SC1   ((Pdc      *)0x40004100U) /**< \brief (PDC_I2SC1  ) Base Address */
#define FLEXCOM5    ((Flexcom  *)0x40008000U) /**< \brief (FLEXCOM5   ) Base Address */
#define USART5      ((Usart    *)0x40008200U) /**< \brief (USART5     ) Base Address */
#define PDC_USART5  ((Pdc      *)0x40008300U) /**< \brief (PDC_USART5 ) Base Address */
#define SPI5        ((Spi      *)0x40008400U) /**< \brief (SPI5       ) Base Address */
#define PDC_SPI5    ((Pdc      *)0x40008500U) /**< \brief (PDC_SPI5   ) Base Address */
#define TWI5        ((Twi      *)0x40008600U) /**< \brief (TWI5       ) Base Address */
#define PDC_TWI5    ((Pdc      *)0x40008700U) /**< \brief (PDC_TWI5   ) Base Address */
#define FLEXCOM0    ((Flexcom  *)0x4000C000U) /**< \brief (FLEXCOM0   ) Base Address */
#define USART0      ((Usart    *)0x4000C200U) /**< \brief (USART0     ) Base Address */
#define PDC_USART0  ((Pdc      *)0x4000C300U) /**< \brief (PDC_USART0 ) Base Address */
#define SPI0        ((Spi      *)0x4000C400U) /**< \brief (SPI0       ) Base Address */
#define PDC_SPI0    ((Pdc      *)0x4000C500U) /**< \brief (PDC_SPI0   ) Base Address */
#define TWI0        ((Twi      *)0x4000C600U) /**< \brief (TWI0       ) Base Address */
#define PDC_TWI0    ((Pdc      *)0x4000C700U) /**< \brief (PDC_TWI0   ) Base Address */
#define TC0         ((Tc       *)0x40010000U) /**< \brief (TC0        ) Base Address */
#define PDC_TC0     ((Pdc      *)0x40010100U) /**< \brief (PDC_TC0    ) Base Address */
#define TC1         ((Tc       *)0x40014000U) /**< \brief (TC1        ) Base Address */
#define FLEXCOM3    ((Flexcom  *)0x40018000U) /**< \brief (FLEXCOM3   ) Base Address */
#define USART3      ((Usart    *)0x40018200U) /**< \brief (USART3     ) Base Address */
#define PDC_USART3  ((Pdc      *)0x40018300U) /**< \brief (PDC_USART3 ) Base Address */
#define SPI3        ((Spi      *)0x40018400U) /**< \brief (SPI3       ) Base Address */
#define PDC_SPI3    ((Pdc      *)0x40018500U) /**< \brief (PDC_SPI3   ) Base Address */
#define TWI3        ((Twi      *)0x40018600U) /**< \brief (TWI3       ) Base Address */
#define PDC_TWI3    ((Pdc      *)0x40018700U) /**< \brief (PDC_TWI3   ) Base Address */
#define FLEXCOM4    ((Flexcom  *)0x4001C000U) /**< \brief (FLEXCOM4   ) Base Address */
#define USART4      ((Usart    *)0x4001C200U) /**< \brief (USART4     ) Base Address */
#define PDC_USART4  ((Pdc      *)0x4001C300U) /**< \brief (PDC_USART4 ) Base Address */
#define SPI4        ((Spi      *)0x4001C400U) /**< \brief (SPI4       ) Base Address */
#define PDC_SPI4    ((Pdc      *)0x4001C500U) /**< \brief (PDC_SPI4   ) Base Address */
#define TWI4        ((Twi      *)0x4001C600U) /**< \brief (TWI4       ) Base Address */
#define PDC_TWI4    ((Pdc      *)0x4001C700U) /**< \brief (PDC_TWI4   ) Base Address */
#define FLEXCOM1    ((Flexcom  *)0x40020000U) /**< \brief (FLEXCOM1   ) Base Address */
#define USART1      ((Usart    *)0x40020200U) /**< \brief (USART1     ) Base Address */
#define PDC_USART1  ((Pdc      *)0x40020300U) /**< \brief (PDC_USART1 ) Base Address */
#define SPI1        ((Spi      *)0x40020400U) /**< \brief (SPI1       ) Base Address */
#define PDC_SPI1    ((Pdc      *)0x40020500U) /**< \brief (PDC_SPI1   ) Base Address */
#define TWI1        ((Twi      *)0x40020600U) /**< \brief (TWI1       ) Base Address */
#define PDC_TWI1    ((Pdc      *)0x40020700U) /**< \brief (PDC_TWI1   ) Base Address */
#define FLEXCOM2    ((Flexcom  *)0x40024000U) /**< \brief (FLEXCOM2   ) Base Address */
#define USART2      ((Usart    *)0x40024200U) /**< \brief (USART2     ) Base Address */
#define PDC_USART2  ((Pdc      *)0x40024300U) /**< \brief (PDC_USART2 ) Base Address */
#define SPI2        ((Spi      *)0x40024400U) /**< \brief (SPI2       ) Base Address */
#define PDC_SPI2    ((Pdc      *)0x40024500U) /**< \brief (PDC_SPI2   ) Base Address */
#define TWI2        ((Twi      *)0x40024600U) /**< \brief (TWI2       ) Base Address */
#define PDC_TWI2    ((Pdc      *)0x40024700U) /**< \brief (PDC_TWI2   ) Base Address */
#define MEM2MEM     ((Mem2mem  *)0x40028000U) /**< \brief (MEM2MEM    ) Base Address */
#define PDC_MEM2MEM ((Pdc      *)0x40028100U) /**< \brief (PDC_MEM2MEM) Base Address */
#define PDMIC0      ((Pdmic    *)0x4002C000U) /**< \brief (PDMIC0     ) Base Address */
#define PDC_PDMIC0  ((Pdc      *)0x4002C100U) /**< \brief (PDC_PDMIC0 ) Base Address */
#define PDMIC1      ((Pdmic    *)0x40030000U) /**< \brief (PDMIC1     ) Base Address */
#define PDC_PDMIC1  ((Pdc      *)0x40030100U) /**< \brief (PDC_PDMIC1 ) Base Address */
#define ADC         ((Adc      *)0x40038000U) /**< \brief (ADC        ) Base Address */
#define PDC_ADC     ((Pdc      *)0x40038100U) /**< \brief (PDC_ADC    ) Base Address */
#define CMCC        ((Cmcc     *)0x4003C000U) /**< \brief (CMCC       ) Base Address */
#define FLEXCOM6    ((Flexcom  *)0x40040000U) /**< \brief (FLEXCOM6   ) Base Address */
#define USART6      ((Usart    *)0x40040200U) /**< \brief (USART6     ) Base Address */
#define PDC_USART6  ((Pdc      *)0x40040300U) /**< \brief (PDC_USART6 ) Base Address */
#define SPI6        ((Spi      *)0x40040400U) /**< \brief (SPI6       ) Base Address */
#define PDC_SPI6    ((Pdc      *)0x40040500U) /**< \brief (PDC_SPI6   ) Base Address */
#define TWI6        ((Twi      *)0x40040600U) /**< \brief (TWI6       ) Base Address */
#define PDC_TWI6    ((Pdc      *)0x40040700U) /**< \brief (PDC_TWI6   ) Base Address */
#define USBDEV      ((USBDev   *)0x40044000U) /**< \brief (USBDEV     ) Base Address */
#define CRCCU       ((Crccu    *)0x40048000U) /**< \brief (CRCCU      ) Base Address */
#define UHP         ((Uhp      *)0x20400000U) /**< \brief (UHP        ) Base Address */
#define MATRIX      ((Matrix   *)0x400E0200U) /**< \brief (MATRIX     ) Base Address */
#define PMC         ((Pmc      *)0x400E0400U) /**< \brief (PMC        ) Base Address */
#define CHIPID      ((Chipid   *)0x400E0740U) /**< \brief (CHIPID     ) Base Address */
#define EFC0        ((Efc      *)0x400E0A00U) /**< \brief (EFC0       ) Base Address */
#define PIOA        ((Pio      *)0x400E0E00U) /**< \brief (PIOA       ) Base Address */
#define PIOB        ((Pio      *)0x400E1000U) /**< \brief (PIOB       ) Base Address */
#define RSTC        ((Rstc     *)0x400E1400U) /**< \brief (RSTC       ) Base Address */
#define SUPC        ((Supc     *)0x400E1410U) /**< \brief (SUPC       ) Base Address */
#define RTT         ((Rtt      *)0x400E1430U) /**< \brief (RTT        ) Base Address */
#define WDT         ((Wdt      *)0x400E1450U) /**< \brief (WDT        ) Base Address */
#define RTC         ((Rtc      *)0x400E1460U) /**< \brief (RTC        ) Base Address */
#define GPBR        ((Gpbr     *)0x400E1490U) /**< \brief (GPBR       ) Base Address */
/*@}*/

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */
/** \addtogroup SAMG55G19_pio Peripheral Pio Definitions */
/*@{*/

#include "pio/samg55g19.h"
/*@}*/

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */

#define IFLASH_SIZE             (0x80000u)
#define IFLASH_PAGE_SIZE        (512u)
#define IFLASH_LOCK_REGION_SIZE (8192u)
#define IFLASH_NB_OF_PAGES      (1024u)
#define IFLASH_NB_OF_LOCK_BITS  (64u)
#define IRAM_SIZE               (0x28000u)

#define IFLASH_ADDR (0x00400000u) /**< Internal Flash base address */
#define IROM_ADDR   (0x00800000u) /**< Internal ROM base address */
#define IRAM_ADDR   (0x20000000u) /**< Internal RAM base address */

/* ************************************************************************** */
/*   MISCELLANEOUS DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */

#define CHIP_JTAGID (0x05B3E03FUL)
#define CHIP_CIDR   (0x24470AE0UL)
#define CHIP_EXID   (0x0UL)
#define NB_CH_ADC   (8UL)

/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR SAMG55G19 */
/* ************************************************************************** */

/* Device characteristics */
#define CHIP_FREQ_SLCK_RC_MIN           (20000UL)
#define CHIP_FREQ_SLCK_RC               (32000UL)
#define CHIP_FREQ_SLCK_RC_MAX           (44000UL)
#define CHIP_FREQ_MAINCK_RC_8MHZ        (8000000UL)
#define CHIP_FREQ_MAINCK_RC_16MHZ       (16000000UL)
#define CHIP_FREQ_MAINCK_RC_24MHZ       (24000000UL)
#define CHIP_FREQ_CPU_MAX               (120000000UL)
#define CHIP_FREQ_XTAL_32K              (32768UL)

/* Embedded Flash Write Wait State */
#define CHIP_FLASH_WRITE_WAIT_STATE     (8U)

/* Embedded Flash Read Wait State (VDDIO set at 1.62V, Max value) */
#define CHIP_FREQ_FWS_0                 (14000000UL)  /**< \brief Maximum operating frequency when FWS is 0 */
#define CHIP_FREQ_FWS_1                 (28000000UL)  /**< \brief Maximum operating frequency when FWS is 1 */
#define CHIP_FREQ_FWS_2                 (42000000UL)  /**< \brief Maximum operating frequency when FWS is 2 */
#define CHIP_FREQ_FWS_3                 (56000000UL)  /**< \brief Maximum operating frequency when FWS is 3 */
#define CHIP_FREQ_FWS_4                 (70000000UL)  /**< \brief Maximum operating frequency when FWS is 4 */
#define CHIP_FREQ_FWS_5                 (84000000UL)  /**< \brief Maximum operating frequency when FWS is 5 */
#define CHIP_FREQ_FWS_6                 (96000000UL)  /**< \brief Maximum operating frequency when FWS is 6 */
#define CHIP_FREQ_FWS_7                 (108000000UL)  /**< \brief Maximum operating frequency when FWS is 7 */
#define CHIP_FREQ_FWS_8                 (120000000UL)  /**< \brief Maximum operating frequency when FWS is 8 */

#ifdef __cplusplus
}
#endif

/*@}*/

#endif /* _SAMG55G19_ */
