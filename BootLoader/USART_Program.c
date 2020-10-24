/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
 
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"
#include "GPIO_interface.h"
#include "SYSTIMER_Interface.h"

void USART1_VoidInit(void) {                               /*INIT THE USART CONFIGURATION*/

	
/**************************************************************************************************************************************************************************************************************************************************************/
                                              /*BRR REGISTER CONFIGURATION*/
#if    BUAD_RATE == SPEED_9600
	     USART1->BRR=SPEED_9600;	  /*BAUD RATE ADJUST*/
#elif  BUAD_RATE == SPEED_4800
	     USART1->BRR=SPEED_4800;	  
#endif

/***************************************************************************************************************************************************************************************************************************************************************/
                                               /*CR1 REGISTER CONFIGURATION*/	 
	                                                 /*TRANSMIT MODE*/
#if    USART1_TRANS_MODE == ENABLE   
       SET_BIT(USART1->CR1,TE);	
#elif  USART1_TRANS_MODE == DISABLE
       CLEAR_BIT(USART1->CR1,TE);	
#endif
	
	                                                  /*RECEIVE MODE*/
#if    USART1_RECEIV_MODE == ENABLE   
       SET_BIT(USART1->CR1,RE);	
#elif  USART1_RECEIV_MODE == DISABLE
       CLEAR_BIT(USART1->CR1,RE);	
#endif  
	
	                                                  /*PARITY CHECK ERROR MODE*/
#if    PARITY_CONTROL_BIT == ENABLE   
       SET_BIT(USART1->CR1,PCE);	
#elif  PARITY_CONTROL_BIT == DISABLE
       CLEAR_BIT(USART1->CR1,PCE);	
#endif  
	
	                                                  /*PARITY CONTROL BIT SELECTION*/
#if    PARITY_CONTROL_BIT == ENABLE   
       SET_BIT(USART1->CR1,PS);	
#elif  PARITY_CONTROL_BIT == DISABLE
       CLEAR_BIT(USART1->CR1,PS);	
#endif   
	
	                                                   /*TRANSMIT COMPLETE INTERRUPT */
#if    PARITY_CONTROL_BIT == ENABLE   
       SET_BIT(USART1->CR1,TCIE);	
#elif  PARITY_CONTROL_BIT == DISABLE
       CLEAR_BIT(USART1->CR1,TCIE);	
#endif   
                                                  /*RECEIVE DATA READY TO READ INTERRUPT */
#if    PARITY_CONTROL_BIT == ENABLE   
       SET_BIT(USART1->CR1,RXNEIE)  ;	
#elif  PARITY_CONTROL_BIT == DISABLE
       CLEAR_BIT(USART1->CR1,RXNEIE);	
#endif    
	
	                                                 /*ENABLE USART1 */
#if    USART1_ENABLE == ENABLE   
       SET_BIT(USART1->CR1,UE)  ;	
#elif  USART1_ENABLE == DISABLE
       CLEAR_BIT(USART1->CR1,UE);	
#endif     
/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*CR2 REGISTER CONFIGURATION*/
																							
	                                            /*Choose Stop Bit Number */
#if    STOP_BIT_NUMBER == ONE   
       CLEAR_BIT(USART1->CR2,STOP1);
       CLEAR_BIT(USART1->CR2,STOP2);	
#elif  STOP_BIT_NUMBER == TWO
       CLEAR_BIT(USART1->CR2,STOP1);
       SET_BIT(USART1->CR2,STOP2)  ;
#endif  	
	
                                                  /*CLOCK ENABLE */
#if    CLOCK_ENABLE == DISABLE   
       CLEAR_BIT(USART1->CR2,CLKEN);
#elif  CLOCK_ENABLE == ENABLE
       SET_BIT(USART1->CR2,CLKEN)  ;
#endif  	 	
	
                                                 /*CLOCK_POLARITY*/
#if    CLOCK_POLARITY == HIGH   
       CLEAR_BIT(USART1->CR2,CPOL);
#elif  CLOCK_POLARITY == LOW
       SET_BIT(USART1->CR2,CPOL)  ;
#endif  	 	
		
                                                  /*CLOCK_PHASE*/
#if    CLOCK_PHASE == HIGH   
       CLEAR_BIT(USART1->CR2,CLHA);
#elif  CLOCK_PHASE == LOW
       SET_BIT(USART1->CR2,CLHA)  ;
#endif  	 		
/***********************************************************************************************************************************************************************************************************************************************************/
                                               /*CR2 REGISTER CONFIGURATION*/

                                            				/*DAM RECEIVE*/
#if    DMA_RECEIVER_ENABLE == DISABLE   
       CLEAR_BIT(USART1->CR3,DMAR);
#elif  DMA_RECEIVER_ENABLE == ENABLE
       SET_BIT(USART1->CR3,DMAR)  ;
#endif  	 		
	
                                                    /*DAM TRANSMIT*/
#if    DMA_TRANSMIT_ENABLE == DISABLE   
       CLEAR_BIT(USART1->CR3,DMAT);
#elif  DMA_TRANSMIT_ENABLE == ENABLE
       SET_BIT(USART1->CR3,DMAT)  ;
#endif  	 		

                                                    /*ERROR INTERRUPT*/
#if    ERROR_INTERRUPT_ENABLE == DISABLE   
       CLEAR_BIT(USART1->CR3,EIE);
#elif  ERROR_INTERRUPT_ENABLE == ENABLE
       SET_BIT(USART1->CR3,EIE)  ;
#endif
}
/***********************************************************************************************************************************************************************************************************************************************************/
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/

void  USART1_voidTransmit(const uint8 *Str){                          /*SENT DATA ARRAY*/
	
uint8 Array_Index = 0	;
	
	 while(Str[Array_Index] != '\0'){    /*LOOP OF DATA BYTE BY BYTE*/
	 
	   USART1->DR = Str[Array_Index];   /*LOAD DATA IN DATA REGISTER*/ 
	  
		// STK_voidSetBusyWait(100000);
		 
		    while(BIT_IS_CLEAR(USART1->SR,TC));   /*WAIT UNTIL TRANSMION IS COMPLETE*/
		 
	      Array_Index++;
	 }
	 
}
/***********************************************************************************************************************************************************************************************************************************************************/
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/

uint8 USART1_uint8Receive(void){                                 /*RECEIVE DATA ARRAY*/
	
	 		 while(BIT_IS_CLEAR(USART1->SR,RXNE));   /*WAIT UNTIL DATA RECEIVED*/
        
	      return ((0XFF)&(USART1->DR));   /*GET RECEIVED DATA*/
	
}

/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/
void  USART1_VoidReceive( uint8 *Str)     /*receive array of Data*/
{

 uint8 Array_Index = 0	;
	
 Str[Array_Index] = USART1_uint8Receive();  /*GET RECEIVED DATA*/
	
     while(Str[Array_Index] != '#')
	{

    Array_Index++;
		
		Str[Array_Index] = USART1_uint8Receive();
 
	}
	
	Str[Array_Index] = '\0';
	
}
