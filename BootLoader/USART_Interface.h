/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H
#include "STD_TYPES.h"

/***********************************************************************************/
                      /***FUNCTIONS PROTOTYPES***/
/***********************************************************************************/						
/************************************************************************************

*Name       :   USART1_VoidInit

*Description: * Function to Init USART1  
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void  USART1_VoidInit(void); /*INIT THE USART CONFIGURATION*/
/***********************************************************************************/
                      /***FUNCTIONS PROTOTYPES***/
/***********************************************************************************/						
/************************************************************************************

*Name       :   USART1_voidTransmit

*Description: * Function to send array of Data  
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : array address of Data

*Output     : void

*Return     : void

****************************************************************************************/
void  USART1_voidTransmit( const u8 *Str);/*SENT DATA ARRAY*/
/************************************************************************************

*Name       :   USART1_uint8Receiv

*Description: * Function to receive one byte  
							
*Pre-Cond   :	usart1 Init				
							
*pos-Cond   : None

*Input      : void

*Output     : byte received

*Return     : byte receive

****************************************************************************************/
u8 USART1_uint8Receiv(void);/*RECEIVE byte*/
/************************************************************************************

*Name       :   USART1_VoidReceive

*Description: * Function to receive one byte  
							
*Pre-Cond   :	USART1 Init				
							
*pos-Cond   : None

*Input      : array address of Data

*Output     : void

*Return     : void

****************************************************************************************/
void  USART1_VoidReceive (u8 *Str);/*receive array of Data*/
/************************************************************************************

*Name       :   USART1_VoidReceiveAsyn

*Description: * Function to receive one byte by interrupt  
							
*Pre-Cond   :	USART1 Init				
							
*pos-Cond   : None

*Input      : array address of function to implement in ISR

*Output     : void

*Return     : void

****************************************************************************************/
void  USART1_VoidReceiveAsyn (u8 *Str);/*receive array of Data using interupt*/
/************************************************************************************

*Name       :   USART1_VoidReceiveAsyn

*Description: * Function to receive one byte BY CHECKS every periodic time 
							
*Pre-Cond   :	USART1 Init				
							
*pos-Cond   : None

*Input      : array address to store Data in it

*Output     : void

*Return     : void

****************************************************************************************/
u8 MUSART1_uint8Receive(u8* Copy_u8Data) ; 
/************************************************************************************

*Name       :   USART1_uint8ReceivAsyn

*Description: * Function to receive one byte BY CHECKS every periodic time 
							
*Pre-Cond   :	USART1 Init				
							
*pos-Cond   : None

*Input      : array address to store Data in it

*Output     : fun to implement in ISR

*Return     : void

****************************************************************************************/
void USART1_uint8ReceivAsyn(void(*Copy_ptr)(u8));/*RECEIVE byte using interupt*/
/************************************************************************************

*Name       :   USART1_VoidReceiveFourBytes

*Description: * Function to receive an array of four bytes   
							
*Pre-Cond   :	USART1 Init , Node is ready to send 				
							
*pos-Cond   : None

*Input      : void

*Output     : all four bytes are masked into oneword by there order

*Return     : one word contain four bytes

****************************************************************************************/
u32  USART1_VoidReceiveFourBytes(void);     /*receive array of Data*/



#endif
