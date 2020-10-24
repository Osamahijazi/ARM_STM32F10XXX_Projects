/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H
#include "STD_TYPES.h"


void  USART1_VoidInit(void); /*INIT THE USART CONFIGURATION*/
void  USART1_voidTransmit(const uint8 *Str);/*SENT DATA ARRAY*/
uint8 USART1_uint8Receive(void);/*RECEIVE DATA ARRAY*/
void  USART1_VoidReceive (uint8 *Str);/*receive array of Data*/


#endif