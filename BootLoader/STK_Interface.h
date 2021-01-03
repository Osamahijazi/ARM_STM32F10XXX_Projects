/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "STD_TYPES.h"
 
/***********************************************************************************/
                      /***FUNCTIONS PROTOTYPES***/
/***********************************************************************************/						
/************************************************************************************

*Name       :   MSTK_voidInit

*Description: * Function to Set STK config
              * Disable STK Enable
              * Disable STK Interrupt 
              * Set input Clk of STK  
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
 void MSTK_voidInit(void);
/****************************************************************************************

*Name       :   MSTK_voidSetIntervalSingle

*Description: * Function to cause interrupt for once
              * Load Counter By Ticks number in micro Second 
              * Start Counter 
              * Save Call Back address to pionter 
              * Enable STK interrrupt
							
*Pre-Cond   : * Callback function should be in main				
	      * Create Void Pionter to save callback fun address
              * Copy_u32Ticks must be in micro seconds

*pos-Cond   :   None

*Input      :   Ticks number to counter in micro , address of call back function

*Output     :   void

*Return     :   void

*******************************************************************************************/ 
 void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
/************************************************************************************

*Name       :   STK_voidStopInterval

*Description: * Function to Stop interval period
              * Disable STK Interrupt
              * Stop timer 
              * Clear LOAD,VAL Register   
							
*Pre-Cond   :  None				
							
*pos-Cond   :  Counter is stopped

*Input      :   void

*Output     :   void

*Return     :   void

****************************************************************************************/                                   	
 void MSTK_voidStopInterval(void);
 /************************************************************************************

*Name       :   SysTick_Handler

*Description: * Handle STK ISR
              * Stop timer 
              * Clear LOAD,VAL Register  
              * Notify call back
							
*Pre-Cond   :	 Value register must reach to zero			
							
*pos-Cond   :  Callback notification

*Input      :   void

*Output     :   void

*Return     :   void

****************************************************************************************/
void SysTick_Handler(void);

#endif
