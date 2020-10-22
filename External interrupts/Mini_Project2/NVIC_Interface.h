/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/8/2020***********************************/
/***********version:2***************************************/
/***********************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#include "STD_TYPES.h"

/***********************************************************************************************************************************************************************************************************************************************************/

																	              	 /*All Interrupts Could Be Enabled By NVIC
																 

        INTERRUPT_NAME      POSITION                                                                                                                                                                                                                       */

#define     WWDG	      			0             /*Window Watchdog interrupt*/
#define     PVD		      			1        /*PVD through EXTI Line detectioninterrupt*/
#define     TAMPER	    			2               /*TAMPER INTERRUPT*/
#define     RTC			      		3              /*RTC GLOBAL INTERRUPT*/
#define     FLASH	      			4              /*FLASH GLOBALINTERRUPT*/
#define     RCC	    		    	5              /*RCC global interrupt*/

                                       			 /*EXTERNAL INTERRUPT*/ 
#define     EXTI0              6    
#define     EXTI1              7     
#define     EXTI2              8
#define     EXTI3              9
#define     EXTI4              10
#define     EXTI5_9	        	 23         /*EXTI LINE [5:9]   INTERRUPTS*/
#define     EXTI15_10	      	 40         /*EXTI LINE [15:10] INTERRUPTS*/

                                               /*ADC INTERRUPTS*/
#define     ADC1_2    				18
#define     ADC3      				47

                                              /*SPI INTERRUPTS*/
#define     SPI1	     	  		35
#define     SPI2      				36		
#define     SPI3	       			51

                                             /*TIMER INTERRUPTS*/
																						 
#define     TIM1_BRK    			24            /*BREAK INTERRUPT*/
#define     TIM1_UP	    			25             /*UPDATE INTERRUPT*/
#define     TIM1_TRG_COM  		26            /*TRIGGER INTERRUPT*/
#define     TIM1_CC	    			27        /*CAPTURE COMPARE INTERRUPT*/
#define     TIM2      				28
#define     TIM3		      		29
#define     TIM4			      	30
#define     TIM5	      			50
#define     TIM6	      			54
#define     TIM7	      			55
#define     TIM8_BRK          43
#define     TIM8_UP           44
#define     TIM8_TRG_COM      45
#define     TIM8_CC           46

																						 
                                             /*UART INTERRUPTS*/ 
#define     USART1    				37
#define     USART2    				38
#define     USART3		    		39
#define     UART4	      			52
#define     UART5		      		53
                                              /*DMA INTERRUPTS*/
#define     DMA1_CHANNEL1	  	11
#define     DMA1_CHANNEL2	  	12
#define     DMA1_CHANNEL3	  	13
#define     DMA1_CHANNEL4	  	14
#define     DMA1_CHANNEL5	  	15
#define     DMA1_CHANNEL6	  	16
#define     DMA1_CHANNEL7	  	17
#define     DMA2_CHANNEL1	  	56
#define     DMA2_CHANNEL2	  	57
#define     DMA2_CHANNEL3	  	58
#define     DMA2_CHANNEL4_5		59
                                            
                                              /*I2C INTERRUPTS*/
																							
#define     I2C1_EV	  		   	31         /*EVENT INTERRUPT*/
#define     I2C1_ER		    		32         /*ERROR INTERRUPT*/
#define     I2C2_EV	    			33
#define     I2C2_ER			    	34
                                         															 																	
                                           /*USB INTERRUPT*/																		
#define     USB_HP_CAN_TX     19     /*USB High Priority or CAN TX*/
#define     USB_HP_CAN_RX   	20     /*USB Low Priority or CAN RX0*/                                 
#define     USB_WALK_UP       42

                                       /*CAN INTERRUPT*/
#define     CAN1_TX   		  	21
#define     CAN1_RX0		   		22
#define     RTCAlarm          41         /*RTC alarm through EXTI line interrupt*/
#define     FSMC              48         /*FSMC global interrupt*/
#define     SDIO              49     /*SDIO global interrupt*/
/***********************************************************************************************************************************************************************************************************************************************************
                                                  *******FUNCTIONS PROTOTYPE******
***********************************************************************************************************************************************************************************************************************************************************/
 /*
 * Description:Enable interrupt of input number 
   Input:prepiral interrupt position number
	 Output:void
 */
 void  NVIC_voidEnableInterrupt  (uint8 Copy_uint8IntNumber);  
 /*
Description: DISABLE interrupt of input number
Input: prepiral interrupt position number                     
output:void
*/
void  NVIC_voidDisableInterrupt (uint8 Copy_uint8IntNumber); 

 /*
Description: Enable Pending Flag of input number
Input: prepiral interrupt position number                     
output:void
*/ 
void  NVIC_voidSetPendingFlag   (uint8 Copy_uint8IntNumber); 

/*
Description: Disable Pending Flag of input number
Input: prepiral interrupt position number                     
output:void
*/
void  NVIC_voidClearPendingFlag (uint8 Copy_uint8IntNumber);

/*
Description: Get active Flag of input number
Input: prepiral interrupt position number                     
output:Avtive Flag
*/ 
uint8 NVIC_voidGetActiveFlag    (uint8 Copy_uint8IntNumber); 

/*
Description: Set Software priority of input number
Input: prepiral interrupt position number,choosen Group priority,Sub Priority,                     
output:void
*/
 void  NVIC_voidSetPriority      (uint8 Copy_uint8IntID,      
                                	uint8 Copy_uint8GroupPriority ,
                                  uint8 Copy_uint8SubGroupPriority,
                                  uint32 Copy_uint32Group  );







#endif