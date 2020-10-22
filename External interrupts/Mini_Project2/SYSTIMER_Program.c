/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
 
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "SYSTIMER_Interface.h"
#include "SYSTIMER_Config.h"
#include "SYSTIMER_Private.h"



                                           /*choosing the Clock*/

void STK_voidInit(void) {
	
 #if   STK_CLOCK_SOURCE == STK_AHB
	 
	           SET_BIT(STK->CTRL,STK_CLOCK); 
	 
#elif  STK_CLOCK_SOURCE == STK_AHB_DIV_8
	 
	           CLEAR_BIT(STK->CTRL,STK_CLOCK); 
 #endif        
					}
	

					                               /* Delay for aspecific Time */
					
void STK_voidSetBusyWait(uint32 copy_DelayValue){
	                           STK->LOAD  = 0;
								             STK->Value = 0;
	 	              STK->LOAD = copy_DelayValue; /*LOAD THE COUNTER VALUE*/
			            SET_BIT( STK->CTRL,STK_ENABLE); /*ENABLE STK*/
	                while(GET_BIT(STK->CTRL , 16) == 0){}
			            CLEAR_BIT( STK->CTRL,STK_ENABLE); /*DISABLE STK*/
 }

 
 void STK_voidSetIntervalPeriodic(uint32 copy_DelayValue){
 
 
             SET_BIT(STK->CTRL,STK_INTERRUPT_ENABLE); 

 	 	         STK->LOAD = copy_DelayValue; /*LOAD THE COUNTER VALUE*/
	 
             SET_BIT( STK->CTRL,STK_ENABLE); /*ENABLE STK*/

 
 }
 
 
 
 
 

 /*Enable interrupt 0  & 1 */
//	NVIC_voidEnableInterrupt(6);   /*EXTI0*/
//	NVIC_voidEnableInterrupt(7);   /*EXTI1*/
//	NVIC_voidSetPendingFlag (6);    /* SET PENDING FLAG OF EXTI 0*/

 
 
 
 
 
 
 