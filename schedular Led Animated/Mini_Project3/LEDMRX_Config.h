/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:1/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H
#include "STD_TYPES.h"



                                              /*Registers Macros*/
#define  GPIOA      0
#define  GPIOB      1
#define  GPIOC      2

                                       /* Please WRITE PIN pair PORT,PIN*/



#define LEDMRX_ROW0            GPIOA
#define LEDMRX_ROW1            GPIOA
#define LEDMRX_ROW2            GPIOA
#define LEDMRX_ROW3            GPIOA
#define LEDMRX_ROW4            GPIOA
#define LEDMRX_ROW5            GPIOA
#define LEDMRX_ROW6            GPIOA
#define LEDMRX_ROW7            GPIOA

#define LEDMRX_ROW0_PIN            0
#define LEDMRX_ROW1_PIN            1
#define LEDMRX_ROW2_PIN            2
#define LEDMRX_ROW3_PIN            3
#define LEDMRX_ROW4_PIN            4
#define LEDMRX_ROW5_PIN            5
#define LEDMRX_ROW6_PIN            6
#define LEDMRX_ROW7_PIN            7


uint8 LEDMRX_ROW[]={LEDMRX_ROW0,LEDMRX_ROW1,LEDMRX_ROW2,LEDMRX_ROW3,LEDMRX_ROW4,LEDMRX_ROW5,LEDMRX_ROW6,LEDMRX_ROW7};
uint8 LEDMRX_ROW_PIN[]={LEDMRX_ROW0_PIN,LEDMRX_ROW1_PIN,LEDMRX_ROW2_PIN,LEDMRX_ROW3_PIN,LEDMRX_ROW4_PIN,LEDMRX_ROW5_PIN,LEDMRX_ROW6_PIN,LEDMRX_ROW7_PIN};



                                        /* Please WRITE PIN pair PORT,PIN*/


#define LEDMRX_COL0            GPIOB
#define LEDMRX_COL1            GPIOB
#define LEDMRX_COL2            GPIOB
#define LEDMRX_COL3            GPIOB
#define LEDMRX_COL4            GPIOB
#define LEDMRX_COL5            GPIOB
#define LEDMRX_COL6            GPIOB
#define LEDMRX_COL7            GPIOB

#define LEDMRX_COL0_PIN            0
#define LEDMRX_COL1_PIN            1
#define LEDMRX_COL2_PIN            2
#define LEDMRX_COL3_PIN            3
#define LEDMRX_COL4_PIN            4
#define LEDMRX_COL5_PIN            5
#define LEDMRX_COL6_PIN            6
#define LEDMRX_COL7_PIN            7


uint8 LEDMRX_COL[]={LEDMRX_COL0,LEDMRX_COL1,LEDMRX_COL2,LEDMRX_COL3,LEDMRX_COL4,LEDMRX_COL5,LEDMRX_COL6,LEDMRX_COL7};
uint8 LEDMRX_COL_PIN[]={LEDMRX_COL0_PIN,LEDMRX_COL1_PIN,LEDMRX_COL2_PIN,LEDMRX_COL3_PIN,LEDMRX_COL4_PIN,LEDMRX_COL5_PIN,LEDMRX_COL6_PIN,LEDMRX_COL7_PIN,};
















#endif