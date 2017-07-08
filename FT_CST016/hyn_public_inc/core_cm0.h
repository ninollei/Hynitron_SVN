/*!
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited.
 *
 *            (C) COPYRIGHT 2009-2010 ARM Limited.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited.
 *
 *      SVN Information
 *	  @file	Core_cm0.h
 *	  @brief   define the confidential and proprietary information for ARM Core
 *	  @data  2008-12-31 10:59:44 +0000 (Wed, 31 Dec 2008)
 *	  @revision  Revision: 97564 
 *
 *      Release Information : Cortex-M0-AT510-r0p0-03rel0
 *-----------------------------------------------------------------------------
 */

#ifndef __CM0_CORE_H__
#define __CM0_CORE_H__

#define __CM0_CMSIS_VERSION_MAIN  (0x01)                                                       /*!< [31:16] CMSIS HAL main version */
#define __CM0_CMSIS_VERSION_SUB   (0x10)                                                       /*!< [15:0]  CMSIS HAL sub version  */
#define __CM0_CMSIS_VERSION       ((__CM0_CMSIS_VERSION_MAIN << 16) | __CM0_CMSIS_VERSION_SUB) /*!< CMSIS HAL version number       */
#define __CORTEX_M                (0x00)                                                       /*!< Cortex core                    */

#include <stdint.h>                           /*!<  Include s tandard types */

#if defined (__ICCARM__)
  #include <intrinsics.h>                     /*!<  IAR Intrinsics   */
#endif

#ifndef __NVIC_PRIO_BITS
  #define __NVIC_PRIO_BITS    2               /*!< standard definition for NVIC Priority Bits */
#endif

/*! 
*\name IO definitions
*\brief define access restrictions to peripheral registers
*\{
*/
#define     __I     volatile const            /*!< defines 'read only' permissions      */
#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */
/**\}*/

/*******************************************************************************
 *                 Register Abstraction
 ******************************************************************************/

/*! 
*\name System Reset
*\{
*/
#define NVIC_VECTRESET              0         /*!< Vector Reset Bit             */
#define NVIC_SYSRESETREQ            2         /*!< System Reset Request         */
#define NVIC_AIRCR_VECTKEY    (0x5FA << 16)   /*!< AIRCR Key for write access   */
#define NVIC_AIRCR_ENDIANESS        15        /*!< Endianess                    */
/**\}*/

typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< -14 Non Maskable Interrupt                             */
  HardFault_IRQn	      = -13,    /*!< -13 Cortex-M0 Hard Fault Interrupt                     */
  SVCall_IRQn                 = -5,     /*!< -5 Cortex-M0 SV Call Interrupt                       */
  PendSV_IRQn                 = -2,     /*!< -2 Cortex-M0 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< -1 Cortex-M0 System Tick Interrupt                   */

/******  CM0IKMCU Cortex-M0 specific Interrupt Numbers ********************************************/
  LVD_IRQn                   = 0,	/*!<0  reserved for LVD*/
  SLP_IRQn                   = 1,   /*!<1  interrupt for SLP*/ 
  GPIO_IRQn                  = 2,   /*!<2  interrupt for GPIO*/ 
  VC3_IRQn                   = 3,   /*!<3  interrupt for VC3*/
  CSX_IRQn                   = 4,   /*!<4  interrupt for CSX*/ 
  NSX_IRQn                   = 5,   /*!<5  interrupt for NSX*/ 
  I2C0_IRQn                  = 6,   /*!<6  interrupt for I2C0*/
  SPI0_IRQn                  = 7,   /*!<7  interrupt for SPI0*/
  UART0_IRQn                 = 8,   /*!<8  interrupt for UART0*/

  CM0MCU_IRQ9_IRQn          = 9,
  CM0MCU_IRQ10_IRQn         = 10,
  CM0MCU_IRQ11_IRQn         = 11,
  CM0MCU_IRQ12_IRQn         = 12,
  CM0MCU_IRQ13_IRQn         = 13,
  CM0MCU_IRQ14_IRQn         = 14,
  CM0MCU_IRQ15_IRQn         = 15,
  CM0MCU_IRQ16_IRQn         = 16,
  CM0MCU_IRQ17_IRQn         = 17,
  CM0MCU_IRQ18_IRQn         = 18,
  CM0MCU_IRQ19_IRQn         = 19,
  CM0MCU_IRQ20_IRQn         = 20,
  CM0MCU_IRQ21_IRQn         = 21,
  CM0MCU_IRQ22_IRQn         = 22,
  CM0MCU_IRQ23_IRQn         = 23,
  CM0MCU_IRQ24_IRQn         = 24,
  CM0MCU_IRQ25_IRQn         = 25,
  CM0MCU_IRQ26_IRQn         = 26,
  CM0MCU_IRQ27_IRQn         = 27,
  CM0MCU_IRQ28_IRQn         = 28,
  CM0MCU_IRQ29_IRQn         = 29,
  CM0MCU_IRQ30_IRQn         = 30,
  CM0MCU_IRQ31_IRQn         = 31
} IRQn_Type;


/** memory mapping struct for Nested Vectored Interrupt Controller (NVIC) */
typedef struct
{
  __IO uint32_t ISER[1];                      /*!< Interrupt Set Enable Register            */
       uint32_t RESERVED0[31];
  __IO uint32_t ICER[1];                      /*!< Interrupt Clear Enable Register          */
       uint32_t RSERVED1[31];
  __IO uint32_t ISPR[1];                      /*!< Interrupt Set Pending Register           */
       uint32_t RESERVED2[31];
  __IO uint32_t ICPR[1];                      /*!< Interrupt Clear Pending Register         */
       uint32_t RESERVED3[31];
       uint32_t RESERVED4[64];
  __IO uint32_t IP[8];                        /*!< Interrupt Priority Register              */
}  NVIC_Type;


/** memory mapping struct for System Control Block */
typedef struct
{
  __I  uint32_t CPUID;                        /*!< CPU ID Base Register                                     */
  __IO uint32_t ICSR;                         /*!< Interrupt Control State Register                         */
       uint32_t RESERVED0;
  __IO uint32_t AIRCR;                        /*!< Application Interrupt / Reset Control Register           */
  __IO uint32_t SCR;                          /*!< System Control Register                                  */
  __IO uint32_t CCR;                          /*!< Configuration Control Register                           */
       uint32_t RESERVED1;
  __IO uint32_t SHP[2];                       /*!< System Handlers Priority Registers. [0] is RESERVED      */
  __IO uint32_t SHCSR;                        /*!< System Handler Control and State Register                */
       uint32_t RESERVED2[2];
  __IO uint32_t DFSR;                         /*!< Debug Fault Status Register                              */
} SCB_Type;


/**memory mapping struct for SysTick */
typedef struct
{
  __IO uint32_t CTRL;                         /*!< SysTick Control and Status Register */
  __IO uint32_t LOAD;                         /*!< SysTick Reload Value Register       */
  __IO uint32_t VAL;                          /*!< SysTick Current Value Register      */
  __I  uint32_t CALIB;                        /*!< SysTick Calibration Register        */
} SysTick_Type;

/** Core Debug Register */
typedef struct
{
  __IO uint32_t DHCSR;                        /*!< Debug Halting Control and Status Register       */
  __O  uint32_t DCRSR;                        /*!< Debug Core Register Selector Register           */
  __IO uint32_t DCRDR;                        /*!< Debug Core Register Data Register               */
  __IO uint32_t DEMCR;                        /*!< Debug Exception and Monitor Control Register    */
} CoreDebug_Type;

/*!
 *\name memory mapping
 * \brief
 * Memory mapping of Cortex-M0 Hardware 
 *\{
 */
#define SCS_BASE            (0xE000E000)                              /*!< System Control Space Base Address    */
#define CoreDebug_BASE      (0xE000EDF0)                              /*!< Core Debug Base Address              */
#define SysTick_BASE        (SCS_BASE +  0x0010)                      /*!< SysTick Base Address                 */
#define NVIC_BASE           (SCS_BASE +  0x0100)                      /*!< NVIC Base Address                    */
#define SCB_BASE            (SCS_BASE +  0x0D00)                      /*!< System Control Block Base Address    */

#define SCB                 ((SCB_Type *)           SCB_BASE)         /*!< SCB configuration struct             */
#define SysTick             ((SysTick_Type *)       SysTick_BASE)     /*!< SysTick configuration struct         */
#define NVIC                ((NVIC_Type *)          NVIC_BASE)        /*!< NVIC configuration struct            */
#define CoreDebug           ((CoreDebug_Type *)     CoreDebug_BASE)   /*!< Core Debug configuration struct      */
/**\}*/


/*******************************************************************************
 *                Hardware Abstraction Layer
 ******************************************************************************/

#if defined ( __CC_ARM   )
  #define __ASM            __asm                                      /*!< asm keyword for ARM Compiler          */
  #define __INLINE         __inline                                   /*!< inline keyword for ARM Compiler       */

#elif defined ( __ICCARM__ )
  #define __ASM           __asm                                       /*!< asm keyword for IAR Compiler           */
  #define __INLINE        inline                                      /*!< inline keyword for IAR Compiler. Only avaiable in High optimization mode! */
  #define __NOP           __no_operation                              /*!< no operation intrinsic in IAR Compiler */

#elif defined   (  __GNUC__  )
  #define __ASM            asm                                        /*!< asm keyword for GNU Compiler          */
  #define __INLINE         inline                                     /*!< inline keyword for GNU Compiler       */

#endif


/* ###################  Compiler specific Intrinsics  ########################### */
#if defined ( __CC_ARM   ) /*------------------RealView Compiler -----------------*/
/* ARM armcc specific functions */

#define __enable_fault_irq                __enable_fiq
#define __disable_fault_irq               __disable_fiq

#define __NOP                             __nop
#define __WFI                             __wfi
#define __WFE                             __wfe
#define __SEV                             __sev
#define __ISB()                           __isb(0)
#define __DSB()                           __dsb(0)
#define __DMB()                           __dmb(0)
#define __REV                             __rev


  /* intrinsic void __enable_irq();     */
  /* intrinsic void __disable_irq();    */


/*! 
 * @brief  Return the Process Stack Pointer
 *
 * @param  none
 * @return uint32_t ProcessStackPointer
 *
 * Return the actual process stack pointer
 */
extern uint32_t __get_PSP(void);

/**
 * @brief  Set the Process Stack Pointer
 *
 * @param  uint32_t Process Stack Pointer
 * @return none
 *
 * Assign the value ProcessStackPointer to the MSP 
 * (process stack pointer) Cortex processor register
 */
extern void __set_PSP(uint32_t topOfProcStack);

/**
 * @brief  Return the Main Stack Pointer
 *
 * @param  none
 * @return uint32_t Main Stack Pointer
 *
 * Return the current value of the MSP (main stack pointer)
 * Cortex processor register
 */
extern uint32_t __get_MSP(void);

/**
 * @brief  Set the Main Stack Pointer
 *
 * @param  uint32_t Main Stack Pointer
 * @return none
 *
 * Assign the value mainStackPointer to the MSP 
 * (main stack pointer) Cortex processor register
 */
extern void __set_MSP(uint32_t topOfMainStack);

/**
 * @brief  Reverse byte order in unsigned short value
 *
 * @param  uint16_t value to reverse
 * @return uint32_t reversed value
 *
 * Reverse byte order in unsigned short value
 */
extern uint32_t __REV16(uint16_t value);

/*
 * @brief  Reverse byte order in signed short value with sign extension to integer
 *
 * @param  int16_t value to reverse
 * @return int32_t reversed value
 *
 * Reverse byte order in signed short value with sign extension to integer
 */
extern int32_t __REVSH(int16_t value);


#if (__ARMCC_VERSION < 400000)

/**
 * @brief  Return the Priority Mask value
 *
 * @param  none
 * @return uint32_t PriMask
 *
 * Return the state of the priority mask bit from the priority mask
 * register
 */
extern uint32_t __get_PRIMASK(void);

/**
 * @brief  Set the Priority Mask value
 *
 * @param  uint32_t PriMask
 * @return none
 *
 * Set the priority mask bit in the priority mask register
 */
extern void __set_PRIMASK(uint32_t priMask);

/**
 * @brief  Return the Control Register value
 * 
 * @param  none
 * @return uint32_t Control value
 *
 * Return the content of the control register
 */
extern uint32_t __get_CONTROL(void);

/**
 * @brief  Set the Control Register value
 *
 * @param  uint32_t Control value
 * @return none
 *
 * Set the control register
 */
extern void __set_CONTROL(uint32_t control);

#else  /* (__ARMCC_VERSION >= 400000)  */


/**
 * @brief  Return the Priority Mask value
 *
 * @param  none
 * @return uint32_t PriMask
 *
 * Return the state of the priority mask bit from the priority mask
 * register
 */
static __INLINE uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __ASM("primask");
  return(__regPriMask);
}

/**
 * @brief  Set the Priority Mask value
 *
 * @param  uint32_t PriMask
 * @return none
 *
 * Set the priority mask bit in the priority mask register
 */
static __INLINE void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __ASM("primask");
  __regPriMask = (priMask);
}

/**
 * @brief  Return the Control Register value
 * 
 * @param  none
 * @return uint32_t Control value
 *
 * Return the content of the control register
 */
static __INLINE uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __ASM("control");
  return(__regControl);
}

/**
 * @brief  Set the Control Register value
 *
 * @param  uint32_t Control value
 * @return none
 *
 * Set the control register
 */
static __INLINE void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __ASM("control");
  __regControl = control;
}

#endif /* __ARMCC_VERSION  */ 



#elif (defined (__ICCARM__)) /*------------------ ICC Compiler -------------------*/
/* IAR iccarm specific functions */

#define __enable_irq                              __enable_interrupt        /*!< global Interrupt enable */
#define __disable_irq                             __disable_interrupt       /*!< global Interrupt disable */

static __INLINE void __enable_fault_irq()         { __ASM ("cpsie f"); }
static __INLINE void __disable_fault_irq()        { __ASM ("cpsid f"); }

static __INLINE  void __WFI()                     { __ASM ("wfi"); }
static __INLINE  void __WFE()                     { __ASM ("wfe"); }
static __INLINE  void __SEV()                     { __ASM ("sev"); }

//static __INLINE  void __ISB(arg)                  { __ASM ("isb"); }
//static __INLINE  void __DSB(arg)                  { __ASM ("dsb"); }
//static __INLINE  void __DMB(arg)                  { __ASM ("dmb"); }

/**
 * @brief  Return the Process Stack Pointer
 *
 * @param  none
 * @return uint32_t ProcessStackPointer
 *
 * Return the actual process stack pointer
 */
extern uint32_t __get_PSP(void);

/**
 * @brief  Set the Process Stack Pointer
 *
 * @param  uint32_t Process Stack Pointer
 * @return none
 *
 * Assign the value ProcessStackPointer to the MSP 
 * (process stack pointer) Cortex processor register
 */
extern void __set_PSP(uint32_t topOfProcStack);

/**
 * @brief  Return the Main Stack Pointer
 *
 * @param  none
 * @return uint32_t Main Stack Pointer
 *
 * Return the current value of the MSP (main stack pointer)
 * Cortex processor register
 */
extern uint32_t __get_MSP(void);

/**
 * @brief  Set the Main Stack Pointer
 *
 * @param  uint32_t Main Stack Pointer
 * @return none
 *
 * Assign the value mainStackPointer to the MSP 
 * (main stack pointer) Cortex processor register
 */
extern void __set_MSP(uint32_t topOfMainStack);

/**
 * @brief  Reverse byte order in unsigned short value
 *
 * @param  uint16_t value to reverse
 * @return uint32_t reversed value
 *
 * Reverse byte order in unsigned short value
 */
extern uint32_t __REV16(uint16_t value);



/* intrinsic void __set_PRIMASK();                                    */
/* intrinsic void __get_PRIMASK();                                    */
/* intrinsic uint32_t __REV(uint32_t value);                          */
/* intrinsic uint32_t __REVSH(uint32_t value);                        */


#elif (defined (__GNUC__)) /*------------------ GNU Compiler ---------------------*/
/* GNU gcc specific functions */

static __INLINE void __NOP()                      { __ASM volatile ("nop"); }
static __INLINE void __enable_irq()               { __ASM volatile ("cpsie i"); }
static __INLINE void __disable_irq()              { __ASM volatile ("cpsid i"); }

static __INLINE void __enable_fault_irq()         { __ASM volatile ("cpsie f"); }
static __INLINE void __disable_fault_irq()        { __ASM volatile ("cpsid f"); }

static __INLINE void __WFI()                      { __ASM volatile ("wfi"); }
static __INLINE void __WFE()                      { __ASM volatile ("wfe"); }
static __INLINE void __SEV()                      { __ASM volatile ("sev"); }
static __INLINE void __ISB(arg)                   { __ASM volatile ("isb"); }
static __INLINE void __DSB(arg)                   { __ASM volatile ("dsb"); }
static __INLINE void __DMB(arg)                   { __ASM volatile ("dmb"); }


/**
 * @brief  Return the Process Stack Pointer
 *
 * @param  none
 * @return uint32_t ProcessStackPointer
 *
 * Return the actual process stack pointer
 */
extern uint32_t __get_PSP(void);

/**
 * @brief  Set the Process Stack Pointer
 *
 * @param  uint32_t Process Stack Pointer
 * @return none
 *
 * Assign the value ProcessStackPointer to the MSP 
 * (process stack pointer) Cortex processor register
 */
extern void __set_PSP(uint32_t topOfProcStack);

/**
 * @brief  Return the Main Stack Pointer
 *
 * @param  none
 * @return uint32_t Main Stack Pointer
 *
 * Return the current value of the MSP (main stack pointer)
 * Cortex processor register
 */
extern uint32_t __get_MSP(void);

/**
 * @brief  Set the Main Stack Pointer
 *
 * @param  uint32_t Main Stack Pointer
 * @return none
 *
 * Assign the value mainStackPointer to the MSP 
 * (main stack pointer) Cortex processor register
 */
extern void __set_MSP(uint32_t topOfMainStack);

/**
 * @brief  Return the Priority Mask value
 *
 * @param  none
 * @return uint32_t PriMask
 *
 * Return the state of the priority mask bit from the priority mask
 * register
 */
extern uint32_t  __get_PRIMASK(void);

/**
 * @brief  Set the Priority Mask value
 *
 * @param  uint32_t PriMask
 * @return none
 *
 * Set the priority mask bit in the priority mask register
 */
extern void __set_PRIMASK(uint32_t priMask);

/**
 * @brief  Return the Control Register value 
 * 
 * @param  none
 * @return uint32_t Control value
 *
 * Return the content of the control register
 */
extern uint32_t __get_CONTROL(void);

/**
 * @brief  Set the Control Register value
 *
 * @param  uint32_t Control value
 * @return none
 *
 * Set the control register
 */
extern void __set_CONTROL(uint32_t control);

/**
 * @brief  Reverse byte order in integer value
 *
 * @param  uint32_t value to reverse
 * @return uint32_t reversed value
 *
 * Reverse byte order in integer value
 */
extern uint32_t __REV(uint32_t value);

/**
 * @brief  Reverse byte order in unsigned short value
 *
 * @param  uint16_t value to reverse
 * @return uint32_t reversed value
 *
 * Reverse byte order in unsigned short value
 */
extern uint32_t __REV16(uint16_t value);

/*
 * Reverse byte order in signed short value with sign extension to integer
 *
 * @param  int16_t value to reverse
 * @return int32_t reversed value
 *
 * @brief  Reverse byte order in signed short value with sign extension to integer
 */
extern int32_t __REVSH(int16_t value);


#endif



/* ##########################   NVIC functions  #################################### */

/* Interrupt Priorities are WORD accessible only under ARMv6M                   */
/* The following MACROS handle generation of the register offset and byte masks */

#define _BIT_SHIFT(IRQn)         (  (((uint32_t)(IRQn)       )    &  0x03) * 8 )
#define _SHP_IDX(IRQn)           ( ((((uint32_t)(IRQn) & 0x0F)-8) >>    2)     )
#define _IP_IDX(IRQn)            (   ((uint32_t)(IRQn)            >>    2)     )



/**
 * @brief  Set the Priority Grouping in NVIC Interrupt Controller
 *
 * @param  uint32_t priority_grouping is priority grouping field
 * @return  
 *
 * Set the priority grouping field using the required unlock sequence.
 * The parameter priority_grouping is assigned to the field 
 * SCB->AIRCR [10:8] PRIGROUP field.
 */
static __INLINE void NVIC_SetPriorityGrouping(uint32_t priority_grouping)
{
  uint32_t reg_value=0;
  
  reg_value  = SCB->AIRCR;                                                                            /* read old register configuration    */
  reg_value &= ~((0xFFFFU << 16) | (0x0F << 8));                                                      /* clear bits to change               */
  reg_value  = ((reg_value | NVIC_AIRCR_VECTKEY | (priority_grouping << 8)));                         /* Insert write key and priorty group */
  SCB->AIRCR = reg_value;
}

/**
 * @brief  Enable Interrupt in NVIC Interrupt Controller
 *
 * @param  IRQn_Type IRQn specifies the interrupt number
 * @return none 
 *
 * Enable a device specific interupt in the NVIC interrupt controller.
 * The interrupt number cannot be a negative value.
 */
static __INLINE void NVIC_EnableIRQ (IRQn_Type IRQn)
{
  NVIC->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));                             /* enable interrupt */
}

/**
 * @brief  Disable the interrupt line for external interrupt specified
 * 
 * @param  IRQn_Type IRQn is the positive number of the external interrupt
 * @return  none
 * 
 * Disable a device specific interupt in the NVIC interrupt controller.
 * The interrupt number cannot be a negative value.
 */
static __INLINE void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  NVIC->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));                             /* disable interrupt */
}

/**
 * @brief  Read the interrupt pending bit for a device specific interrupt source
 * 
 * @param  IRQn_Type IRQn is the number of the device specifc interrupt
 * @return uint32_t
 *
 * Read the pending register in NVIC and return 1 if the specified
 * interrupt is pending, otherwise it returns zero.
 * The interrupt number cannot be a negative value.
 */
static __INLINE uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((NVIC->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));   /* Return 1 if pending else 0 */
}

/**
 * @brief  Set the pending bit for an external interrupt
 * 
 * @param  IRQn_Type IRQn is the Number of the interrupt
 * @return  none
 *
 * Set the pending bit for the specified interrupt.
 * The interrupt number cannot be a negative value.
 */
static __INLINE void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));                             /* set interrupt pending */
}

/**
 * @brief  Clear the pending bit for an external interrupt
 *
 * @param  IRQn_Type IRQn is the Number of the interrupt
 * @return  none
 *
 * Clear the pending bit for the specified interrupt. 
 * The interrupt number cannot be a negative value.
 */
static __INLINE void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));                             /* Clear pending interrupt */
}

/**
 * @brief  Set the priority for an interrupt
 *
 * @param  IRQn_Type IRQn is the Number of the interrupt
 * @param  priority is the priority for the interrupt
 * @return  none
 *
 * Set the priority for the specified interrupt. The interrupt 
 * number can be positive to specify an external (device specific) 
 * interrupt, or negative to specify an internal (core) interrupt. \n
 *
 * Note: The priority cannot be set for every core interrupt.
 */
static __INLINE void NVIC_SetPriority(IRQn_Type IRQn, int32_t priority)
{
  if(IRQn < 0) {
    SCB->SHP[_SHP_IDX(IRQn)] = (SCB->SHP[_SHP_IDX(IRQn)] & ~(0xFF << _BIT_SHIFT(IRQn))) | 
        (((priority << (8 - __NVIC_PRIO_BITS)) & 0xFF) << _BIT_SHIFT(IRQn)); }
  else {
    NVIC->IP[_IP_IDX(IRQn)] =  (NVIC->IP[_IP_IDX(IRQn)]  & ~(0xFF << _BIT_SHIFT(IRQn))) |
        (((priority << (8 - __NVIC_PRIO_BITS)) & 0xFF) << _BIT_SHIFT(IRQn)); }
}

/*!
 * @brief  Read the priority for an interrupt
 *
 * @param  IRQn_Type IRQn is the Number of the interrupt
 * @return priority is the priority for the interrupt
 *
 * Read the priority for the specified interrupt. The interrupt 
 * number can be positive to specify an external (device specific) 
 * interrupt, or negative to specify an internal (core) interrupt.
 *
 * The returned priority value is automatically aligned to the implemented
 * priority bits of the microcontroller.
 *
 * Note: The priority cannot be set for every core interrupt.
 */
static __INLINE uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)((SCB->SHP[_SHP_IDX(IRQn)] >> _BIT_SHIFT(IRQn) ) >> (8 - __NVIC_PRIO_BITS)));  } /*!<get priority for Cortex-M0 system interrupts   */
  else {
    return((uint32_t)((NVIC->IP[_IP_IDX(IRQn)]  >> _BIT_SHIFT(IRQn) ) >> (8 - __NVIC_PRIO_BITS)));  } /* get priority for device specific interrupts    */
}



/* ##################################    SysTick function  ############################################ */

#if (!defined (__Vendor_SysTickConfig)) || (__Vendor_SysTickConfig == 0)

/* SysTick constants */
#define SYSTICK_ENABLE              0                                          /*!< Config-Bit to start or stop the SysTick Timer                         */
#define SYSTICK_TICKINT             1                                          /*!<  Config-Bit to enable or disable the SysTick interrupt                 */
#define SYSTICK_CLKSOURCE           2                                           /*!< Clocksource has the offset 2 in SysTick Control and Status Register   */
#define SYSTICK_MAXCOUNT       ((1<<24) -1)                                     /*!< SysTick MaxCount                                                      */

/**
 * @brief  Initialize and start the SysTick counter and its interrupt.
 *
 * @param  uint32_t ticks is the number of ticks between two interrupts
 * @return  none
 *
 * Initialise the system tick timer and its interrupt and start the
 * system tick timer / counter in free running mode to generate 
 * periodical interrupts.
 */
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > SYSTICK_MAXCOUNT)  return (1);                                                 /*!< Reload value impossible */

  SysTick->LOAD  =  (ticks & SYSTICK_MAXCOUNT) - 1;                                          /*!< set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);                                /*!< set Priority for Cortex-M0 System Interrupts */
  SysTick->VAL   =  (0x00);                                                                  /*!< Load the SysTick Counter Value */
  SysTick->CTRL = (1 << SYSTICK_CLKSOURCE) | (1<<SYSTICK_ENABLE) | (1<<SYSTICK_TICKINT);     /*!< Enable SysTick IRQ and SysTick Timer */
  return (0);                                                                                /*!< Function successful */
}

#endif





/* ##################################    Reset function  ############################################ */

/**
 * @brief  Initiate a system reset request.
 *
 * @param   none
 * @return  none
 *
 * Initialize a system reset request to reset the MCU
 */
static __INLINE void NVIC_SystemReset(void)
{
  SCB->AIRCR  = (NVIC_AIRCR_VECTKEY | (1<<NVIC_SYSRESETREQ));                                /*!< Keep priority group unchanged */
  __DSB(); 
  while(1); 
}


#endif//__CM0_CORE_H__
