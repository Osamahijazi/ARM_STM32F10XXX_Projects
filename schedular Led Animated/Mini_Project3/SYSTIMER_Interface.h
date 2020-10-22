/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef SYSTIMER_INTERFACE_H
#define SYSTIMER_INTERFACE_H

#include "STD_TYPES.h"

 #define STK_DEALY_ONE_SECOND   800000      /*Delay for 1 second* & EXternal Crystal = 1MHZ HCAL*/
 
 
 
 void   STK_voidInit(void);   /*Choose Clock*/
 void   STK_voidSetBusyWait(uint32);/*Delay Function Using Pooling*/
 void   STK_voidSetIntervalSingle  ( uint32 copy_DelayValue, void (*Copy_ptr)(void) );
 void   STK_voidSetIntervalPeriodic ( uint32 copy_DelayValue, void (*Copy_ptr)(void) );
 void   STK_voidStopInterval(void);
 uint32 STK_uint32GetElapsedTime(void);
 uint32 STK_uint32GetRemainingTime(void);
 void   SysTick_Handler(void);
 


#endif