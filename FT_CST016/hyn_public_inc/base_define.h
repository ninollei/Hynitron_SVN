#ifndef __BASE_DEFINE_H__
#define __BASE_DEFINE_H__

/*-----------------------------------------------------------------------------*/
/* Including Files											                   */
/*-----------------------------------------------------------------------------*/
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include "core_cm0.c"

/***********************************************************
*Macro define
************************************************************/
#define REG8(x)		     (*(volatile uint8 *)(x))
#define REG16(x)	     (*(volatile uint16 *)(x))
#define REG32(x)	     (*(volatile uint32 *)(x))
#define REG64(x)	     (*(volatile uint64 *)(x))
#define TRUE      	             (1)
#define FALSE      	             (0)

/***********************************************************
*system type define
************************************************************/

typedef unsigned char 		   uint8;  
typedef unsigned short 		   uint16;
typedef unsigned int 		   uint32;
typedef unsigned long long     uint64;
typedef signed char 		   int8;
typedef signed short 		   int16;
typedef signed int 		       int32;
typedef signed long 	       long32;
typedef float 		           float32;
typedef double 		           float64;



#endif 
