/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:14/8/2020***********************************/
/***********version:1***************************************/
/*********Description:GPIOS REGISTERS***********************/
/***********************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include"STD_TYPES.h"
                                 /*Registers Macros*/
#define  GPIOA      0
#define  GPIOB      1
#define  GPIOC      2

                                    /*Pins Macros*/
#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN011      11
#define PIN012      12
#define PIN13       13 
#define PIN14       14
#define PIN15       15
                                       /*PINS MODES*/

/*         CONFIGURATIONS_MODES        VALUE      */



                    /*INPUT MODES*/
										
#define        INPUT_ANALOG              0b0000
#define        INPUT_FLOATING            0b0100
#define        INPUT_PULL_UP_DOWN        0b1000

                    /*OUTPUT MODES*/
										
#define       OUTPUT_10MHZ_PP             0b0001
#define       OUTPUT_10MHZ_OD             0b0101
#define       OUTPUT_10MHZ_AFPP           0b1001
#define       OUTPUT_10MHZ_AFOD           0b0101
 
#define       OUTPUT_2MHZ_PP              0b0010
#define       OUTPUT_2MHZ_OD              0b0110
#define       OUTPUT_2MHZ_AFPP            0b1010
#define       OUTPUT_2MHZ_AFOD            0b0110

#define       OUTPUT_50MHZ_PP             0b0011
#define       OUTPUT_50MHZ_OD             0b0111
#define       OUTPUT_50MHZ_AFPP           0b1011
#define       OUTPUT_50MHZ_AFOD           0b0111

                            /*OUTPUT VALUES */

#define  GPIO_HIGH    1
#define  GPIO_LOW     0

                           /*Macros used for functions*/
													 
# define  VoidSetPinDirection_Bits_Masking     	0X00000001							 
# define Bits_Shifting_number                     4
# define  Max_Reg_Bits                            15										 





                                      /*Functions*/

 
 void GPIO_VoidSetPinDirection(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Mode);
 
 void GPIO_VoidSetPinValue(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Value);

 uint8 GPIO_VoidGetPinValue(uint8 Copy_u8Port,uint8 Copy_u8Pin);


void GPIO_Void_Increment_value(void);
void GPIO_Void_Decrement_value(uint8 Copy_u8Port);
void _delay_ms (uint16 counter);











#endif
