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

        INTERRUPT_NAME      POSITION             DEFINITION                                                                                                                                                                                                        */

#define     WWDG	      			0             /*Window Watchdog interrupt*/
#define     PVD		      			1        /*PVD through EXTI Line detectioninterrupt*/
#define     TAMPER	    			2               /*TAMPER INTERRUPT*/
#define     RTC			      		3              /*RTC GLOBAL INTERRUPT*/
#define     FLASH	      			4              /*FLASH GLOBALINTERRUPT*/
#define     RCC	    		     	5              /*RCC global interrupt*/

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
                                              /*DMA  CHANNELS INTERRUPTS*/
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
#define     USB_LP_CAN_RX0   	20     /*USB Low Priority or CAN RX0*/                                 
#define     USB_WALK_UP       42

                                       /*CAN INTERRUPT*/
#define     CAN1_TX   		  	21  
#define     CAN1_RX0		   		22

#define     RTCAlarm          41         /*RTC alarm through EXTI line interrupt*/
#define     FSMC              48         /*FSMC global interrupt*/
#define     SDIO              49        /*SDIO global interrupt*/
/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******ERROR TYPES MACROS**********
													  EACH VALUE REPRESENT ERROR TYPE WHICH INDICATE REASON AND LOCATION OF ITS ERROR
***********************************************************************************************************************************************************************************************************************************************************/																																										 
#define  WRONG_POS_ENABLE_INTERRUPT          1  
#define  WRONG_POS_DISABLE_INTERRUPT         2
#define  WRONG_POS_SET_PEND                  3
#define  WRONG_POS_CLR_PEND                  4
#define  WRONG_POS_GET_ACT                   5
#define  WRONG_POS_SET_PR                    6
/***********************************************************************************************************************************************************************************************************************************************************
                                                *******ERROR CHECK VARIABLE******
***********************************************************************************************************************************************************************************************************************************************************/																			
/*
 VALUE *****  VARIABLE_NAME      ****  FUNCTION_NAME ****  
  0    *****    NO ERRORS        ****    NO ERROR        
  1    *****    IntNumber        **** EnableInterrupt 
  2    *****    IntNumber        **** DisableInterrupt
  3    *****    IntNumber        **** SetPendingFlag
  4    *****    IntNumber        **** ClrPendingFlag
  5    *****    IntNumber        **** GetActiveFlag
	6    *****    IntNumber        **** SetPriority  
*/
/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******PRIORITYIES DEFINITION**********
***********************************************************************************************************************************************************************************************************************************************************/																																										 
#define NVIC_GROUP_4_SUB_0      0X05FA0300        /* 4 BITS for Group (IPR) --> GROUP   */    
#define NVIC_GROUP_3_SUB_1      0X05FA0400        /* 3 BITS for Group & 1 BIT for sub Group*/ 
#define NVIC_GROUP_2_SUB_2      0X05FA0500        /*2 BITS for Group & 2 BIT for sub Group */
#define NVIC_GROUP_1_SUB_3      0X05FA0600        /*1 BITS for Group & 3 BIT for sub Group  */
#define NVIC_GROUP_0_SUB_4      0X05FA0700        /*0 BITS for Group & 4 BIT for sub Group */	
/***********************************************************************************************************************************************************************************************************************************************************
                                                  *******GROUP OR SUB GROUP PRIORITIES******
***********************************************************************************************************************************************************************************************************************************************************/
#define INTERRUPT_PRIOPITY_0       0
#define INTERRUPT_PRIOPITY_1       1
#define INTERRUPT_PRIOPITY_2       2
#define INTERRUPT_PRIOPITY_3       3
#define INTERRUPT_PRIOPITY_4       4
#define INTERRUPT_PRIOPITY_5       5
#define INTERRUPT_PRIOPITY_6       6
#define INTERRUPT_PRIOPITY_7       7
#define INTERRUPT_PRIOPITY_8       8
#define INTERRUPT_PRIOPITY_9       9
#define INTERRUPT_PRIOPITY_10      10
#define INTERRUPT_PRIOPITY_11      11
#define INTERRUPT_PRIOPITY_12      12
#define INTERRUPT_PRIOPITY_13      13
#define INTERRUPT_PRIOPITY_14      14
#define INTERRUPT_PRIOPITY_15      15 
/***********************************************************************************************************************************************************************************************************************************************************
                                                    *******FUNCTIONS PROTOTYPE******
***********************************************************************************************************************************************************************************************************************************************************/
 /*
Description:Enable interrupt of input number 
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
output:Avtive Flag Value
*/ 
uint8 NVIC_voidGetActiveFlag    (uint8 Copy_uint8IntNumber); 
/*
Description: Set Software(Group and Subgroup priorit)of input interrupt
Input: prepiral interrupt position number,choosen Group priority,Sub Priority,Group and Sub Group Distribution of all interrupts                      
output:void
*/
void  NVIC_voidSetPriority      (uint8 Copy_uint8IntID,      
                                 uint8 Copy_uint8GroupPriority ,
                                 uint8 Copy_uint8SubGroupPriority,
                                 uint32 Copy_uint32Group );
/*
Description: Get Software(Group priorit)of input interrupt
Input: prepiral interrupt position number                 
output:Software Group of input Position Number
*/
uint8 NVIC_voidGetGroupPriority  (uint8 Copy_uint8IntID  );      
 /*
Description: Get Software(sub priorit)of input interrupt
Input: prepiral interrupt position number                 
output:Software sub of input Position Number
*/
uint8 NVIC_voidGetSubPriority    (uint8 Copy_uint8IntID  );      
                                	
/*************************************************************************************************************************************************************************************************************************************************************/
#endif
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/
