/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef SYSTIMER_INTERFACE_H
#define SYSTIMER_INTERFACE_H

#include "STD_TYPES.h"

 #define STK_DEALY_VALUE   800000      /*Delay for 1 second*/
 
 
 
 void STK_voidInit(void);   /*Choose Clock*/
 void STK_voidSetBusyWait(uint32);/*Delay Function Using Pooling*/
 void STK_voidSetIntervalSingle  (uint32);/*interrupt for only once*/
 void STK_voidSetIntervalPeriodic(uint32);/*periodic interrupt */
 void STK_voidStopTimer(void);
 uint32 STK_uint32GetElapsedTime(void);
 uint32 STK_uint32GetRemainingTime(void);
 


#endif