/**************************************************************
*
* File name:   ../public_src/interrupt_routine.c   
*
* Description: process irq responding. 
*
* Author:  
*
* Version: V1.0  
*
***************************************************************/

#include "all_includes.h"

void sleep_timer_irq_handler(void)
{
    SLPTIM_CLR = SLPTIM_STAT;
    cnt1ms = cnt1ms + 1; ///REG32(0x20000800) = REG32(0x20000800) + 1;
}

/*void gpio_irq_handler(void)
{

}

void csd_irq_handler(void)
{

}


void iic_irq_handler(void)
{

}*/

