/**************************************************************
*
* File name:   ../public_src/base_boot.c 
*
* Description: Boot (vectors) file for Cortex-M0 Integration Kit.           
*
* Author:  
*
* Version: V1.0  
*
***************************************************************/

#include <stdio.h>
#include <rt_misc.h>
#include <stdint.h>
#include "all_includes.h"

#define STACK_TOP_ADDRESS    (0x200013FC)
/*!
* Build a stand-alone image \n
*

*#pragma import(__use_no_semihosting) \n

* Dummy Interrupt Handlers	\n
*
* The following functions are defined weakly to allow the user \n
* to override them at link time simply by declaring their own \n
* function of the same name. \n
*
* If no user function is provided, the weak function is used. \n

* Interrupt Handlers Declaration \n
*/

extern void hardfault_handler(void) 
{
   NVIC_SystemReset();
}


void sleep_timer_irq_handler(void)
{
    SLPTIM_CLR = SLPTIM_STAT;
    cnt1ms = cnt1ms + 1; ///REG32(0x20000800) = REG32(0x20000800) + 1;
}

/*!
* Reset Handler 
*/

extern int main(void);

void Reset_Handler(void)
{
	main();
}


/*!
* Set up Vector Table 
*/

typedef void (*const vect_t)(void) __irq;

vect_t __Vectors[]
__attribute__ ((section("vectors"))) = 
{
  (vect_t)(STACK_TOP_ADDRESS),      // Top of Stack - 8Kbyte SRAM default 0x20001FFC
  (vect_t)Reset_Handler  ,    		// Reset Handler
  0,                        		// NMI_Handler,      
  (vect_t)hardfault_handler,		//hardfault_handler,
  0,                        // Reserved
  0,                        // Reserved
  0,                        // Reserved
  0,                        // Reserved
  0,                        // Reserved
  0,                        // Reserved
  0,                        // Reserved
  0,                        // SVC_Handler,      
  0,                        // Reserved
  0,                        // Reserved
  0,                        // PendSV_Handler,   
  0,                        // SysTick_Handler,  
 
  0,
  (vect_t)sleep_timer_irq_handler,  //SlpTimer IRQHandler
  0,         //gpio_irq_handler
  0,                                //vc3_irq_handler,

  0,          //csd_irq_handler
  0,                                //NSD_IRQHandler  
  0,          //iic_irq_handler 
  
};

/*!
* Set up initial stack and heap 
*/

__value_in_regs struct __initial_stackheap
__user_initial_stackheap(unsigned hb, unsigned sb, unsigned hl, unsigned sl)
{	
  struct __initial_stackheap s;
	
  s.heap_base   = hb;
  s.stack_base  = sb;
  s.heap_limit  = s.stack_base;
  s.stack_limit = s.heap_base;
  return s;
}
