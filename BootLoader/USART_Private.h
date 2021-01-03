/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#include "STD_TYPES.h"
typedef struct
{

volatile u32 SR   ;
volatile u32 DR   ;
volatile u32 BRR  ;
volatile u32 CR1  ;
volatile u32 CR2  ;
volatile u32 CR3  ;
volatile u32 GRPP ;

}USART_TYPE;


#define 	USART1 	 ((USART_TYPE *) 0x40013800)

/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*SR REGISTER FLAGS*/

#define        TXE                  7            /*Transmit data register empty*/
#define        TC                   6            /*TRANSMISION COMPLETE*/
#define        RXNE                 5            /*Read data register not empty*/
#define        ORE                  3            /*OVERRUN ERROR*/
#define        NE                   2            /*NOISE ERROR*/
#define        FE                   1            /*FRAMING ERROR*/
#define        PE                   1            /*PARITY ERROR*/
#define        FE                   1            /*FRAMING ERROR*/



/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*BRR REGISTER CONFIGURATION*/

#define      SPEED_4800            0x638
#define      SPEED_9600            0x341

/***********************************************************************************************************************************************************************************************************************************************************/
                                                   /*CR1 REGISTER GONFIGURATIONS AND FLAGS*/

#define          UE                  13
#define          ENABLE              1
#define          DISABLE             0
#define          TCIE                6             /*TRANSMIT COMPLETE INTERRUPT ENABLE*/
#define          RXNEIE              5            /*RECEIVED COMPLETE INTERRUPT ENABLE*/
#define          ODD                 0
#define          EVEN                1
#define          TE                  3            /*ENABLE TRANSMIT MODE*/
#define          RE                  2            /*ENABLE RECEIVE MODE*/
#define          PCE                 10           /*ENABLE PARITY MODE*/
#define          PS                  9            /*CHOOOSE PARITY BIT CONTROL*/

/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*CR2 REGISTER CONFIGURATION*/
#define          ONE                 0
#define          TWO                 1
#define          STOP1               12
#define          STOP2               13
#define          LOW                 0
#define          HIGH                1
#define          CLKEN               11
#define          CPOL                10
#define          CLHA                9
/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*CR3 REGISTER CONFIGURATION*/
#define          DMAT               7       /*DMA TRANSMIT BIT*/
#define          DMAR               6       /*DMA RECEIVE BIT*/
#define          EIE                0        /*ERROR INTERRUPT ENABLE*/
#define        ONE_BYTE         0X000000FF




#endif
