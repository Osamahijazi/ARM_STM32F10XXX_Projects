/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:25/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#include"STD_TYPES.h"




/* BY DEFULT PINA CHOOSE PINB OR PINC TO CHANGE EXTI PIN*/
																		
																		
																												
#define    LINE_PINA          0X00000000                    
#define    LINE_PINB          0X00000001
#define    LINE_PINC          0X00000002






void  AFIO_VoidSetEXTIConfig( uint8 Copy_uint8Line , uint8 Copy_uint8PortMap);




#endif