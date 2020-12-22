/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef SYSTIMER_INTERFACE_H
#define SYSTIMER_INTERFACE_H

#include "STD_TYPES.h"
/***********************************************************************************************************************************************************************************************************************************************************
                                                *******STK CLOCK CONFIGUATIONS******
************************************************************************************************************************************************************************************************************************************************************/																			
#define STK_DEALY_ONE_SECOND   1000000       /*Delay for 1 second* & AHB BUS SPEED = 8MHZ HCAL*/
 
 
 
 
 
/***********************************************************************************************************************************************************************************************************************************************************
                                                  *******FUNCTIONS PROTOTYPES******
***********************************************************************************************************************************************************************************************************************************************************/																			
/*
 * Description:adjust all configurations of STK  
 * Input:void
 * Output:void
 */ 
 void   STK_voidInit(void);   
/*
 * Description:SYNCHRONOUS FUNCTION ACT AS ADELAY FOR A CERTAIN AMOUNT TIME 
 * Input: AMOUNT OF DELAY TIME
 * Output:void
 */  
 void   STK_voidSetBusyWait(uint32 );
 /*
 * Description:ASYNCHRONOUS FUNCTION TO SET INTERRUPT FOR ONE SHOT ,DO A CERTEIN FUNCTION 
 * Input:DELAY TIME OF INTERRUPT , ADDRESS OF CALL BACK FUNCTION 
 * Output:void
 */ 
 void   STK_voidSetIntervalSingle  ( uint32 copy_DelayValue,
 	                                   void (*Copy_ptr)(void)  );
/*
 * Description:ASYNCHRONOUS FUNCTION TO SET PERIODIC INTERRUPT OF CERTAIN AMOUNT OF TIME ,DO A CERTEIN FUNCTION 
 * Input:DELAY TIME OF INTERRUPT , ADDRESS OF CALL BACK FUNCTION
 * Output:void
 */  
 void STK_voidSetIntervalPeriodic ( uint32  copy_DelayValue,
 	                                  void (*Copy_ptr)(void)  );
 /*
 * Description:DISABLE INTERRUPT TO STOP SINGLE OR PERIODIC INTERVAL 
 * Input:void
 * Output:void
 */                                    	
 void STK_voidStopInterval(void);
/*
 * Description:GET ELAPSED TIME OF INPUT STK TIME 
 * Input:void
 * Output:ELAPSED TIME
 */   
 uint32 STK_uint32GetElapsedTime(void);
 /*
 * Description:GET REMAINIG TIME OF INPUT STK TIME 
 * Input:void
 * Output:REMANING TIME
 */  
 uint32 STK_uint32GetRemainingTime(void);
 /*
 * Description:STK HANDLER WHEN INTERRUPT IS CALLED 
 * Input:void
 * Output:REMANING TIME
 */
 void   SysTick_Handler(void);
#endif
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/
