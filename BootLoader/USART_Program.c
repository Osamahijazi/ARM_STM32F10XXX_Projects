/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"
#include "GPIO_interface2.h"
/* Define Callback Global Variable */
static void(*USART1_CallBack)(u8);

void USART1_VoidInit(void) {                               /*INIT THE USART CONFIGURATION*/


/**************************************************************************************************************************************************************************************************************************************************************/
                                              /*BRR REGISTER CONFIGURATION*/
#if    BUAD_RATE == SPEED_9600
	     USART1->BRR=SPEED_9600;	   /*9600->8M*/
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
       CLR_BIT(USART1->CR1,PCE);
#endif

	                                                  /*PARITY CONTROL BIT SELECTION*/
#if    PARITY_CONTROL_BIT == ENABLE
       SET_BIT(USART1->CR1,PS);
#elif  PARITY_CONTROL_BIT == DISABLE
       CLR_BIT(USART1->CR1,PS);
#endif

	                                                   /*TRANSMIT COMPLETE INTERRUPT */
#if    TRANS_INTERRUPT_ENABLE == ENABLE
       SET_BIT(USART1->CR1,TCIE);
#elif  TRANS_INTERRUPT_ENABLE == DISABLE
       CLR_BIT(USART1->CR1,TCIE);
#endif
                                                  /*RECEIVE DATA READY TO READ -INTERRUPT */
#if    RECEIVE_INTERRUPT_ENABLE == ENABLE
       SET_BIT(USART1->CR1,RXNEIE)  ;
#elif  RECEIVE_INTERRUPT_ENABLE == DISABLE
       CLR_BIT(USART1->CR1,RXNEIE);
#endif
/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*CR2 REGISTER CONFIGURATION*/

	                                            /*Choose Stop Bit Number */
#if    STOP_BIT_NUMBER == ONE
       CLR_BIT(USART1->CR2,STOP1);
       CLR_BIT(USART1->CR2,STOP2);
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
       CLR_BIT(USART1->CR2,CLHA);
#elif  CLOCK_PHASE == LOW
       SET_BIT(USART1->CR2,CLHA)  ;
#endif
/***********************************************************************************************************************************************************************************************************************************************************/
                                               /*CR2 REGISTER CONFIGURATION*/

                                            				/*DAM RECEIVE*/
#if    DMA_RECEIVER_ENABLE == DISABLE
       CLR_BIT(USART1->CR3,DMAR);
#elif  DMA_RECEIVER_ENABLE == ENABLE
       SET_BIT(USART1->CR3,DMAR)  ;
#endif
	
                                                    /*DAM TRANSMIT*/
#if    DMA_TRANSMIT_ENABLE == DISABLE
       CLR_BIT(USART1->CR3,DMAT);
#elif  DMA_TRANSMIT_ENABLE == ENABLE
       SET_BIT(USART1->CR3,DMAT)  ;
#endif

                                                    /*ERROR INTERRUPT*/
#if    ERROR_INTERRUPT_ENABLE == DISABLE
       CLR_BIT(USART1->CR3,EIE);
#elif  ERROR_INTERRUPT_ENABLE == ENABLE
       SET_BIT(USART1->CR3,EIE)  ;
#endif
/***********************************************************************************************************************************************************************************************************************************************************/
                                                    /*ENABLE USART1 */
#if    USART1_ENABLE == ENABLE
       SET_BIT(USART1->CR1,UE)  ;
#elif  USART1_ENABLE == DISABLE
       CLEAR_BIT(USART1->CR1,UE);
#endif


USART1->SR = 0 ;						/* Clearing status register */

}
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/

void  USART1_voidTransmit( const u8 *Str){                          /*SENT DATA ARRAY*/

	u8 Array_Index = 0	;

	while(Str[Array_Index] != '\0'){    /*LOOP OF DATA BYTE BY BYTE*/

		USART1->DR = Str[Array_Index];   /*LOAD DATA IN DATA REGISTER*/


		while(IS_CLR(USART1->SR,TC));   /*WAIT UNTIL TRANSMION IS COMPLETE*/

		Array_Index++;
	}

}
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/
void  USART1_voidTransmitByte(u8 Copy_u8Data){                          /*SENT DATA */

	USART1 -> DR = Copy_u8Data ;

	while( GET_BIT( USART1 -> SR , TC ) == 0 );

	CLR_BIT( USART1 -> SR , TC );

}
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/
u8 USART1_uint8Receive(void){                                 /*RECEIVE DATA */

	u8  LOC_u8Data  = 0 ;

	CLR_BIT ( USART1 -> SR,RXNE);

	while( ( GET_BIT ( USART1 -> SR, RXNE) == 0 )  );


	LOC_u8Data = USART1 -> DR;


	return LOC_u8Data;

}

/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/
void  USART1_VoidReceive( u8 *Str)     /*receive array of Data*/
{

	u8 Array_Index = 0	;

	Str[Array_Index] = USART1_uint8Receive();  /*GET RECEIVED DATA*/

	while(Str[Array_Index] != '\n')
	{

		Array_Index++;

		Str[Array_Index] = USART1_uint8Receive();

	}

	Str[Array_Index] = '\0';

}
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/
u32  USART1_VoidReceiveFourBytes(void)     /*receive array of Data*/
{
	
	u8 HEX[4] ;
  u32 DATA ;
	u8 Array_Index = 0	;

	for(Array_Index = 0 ; Array_Index < 4 ; Array_Index++)
{
	
	HEX[Array_Index] = USART1_uint8Receive();  /*GET RECEIVED DATA*/
	
	}

DATA = (HEX[3]<<24)|(HEX[2]<<16)|(HEX[1]<<8)|(HEX[0]);
	
	return DATA ;
	
}
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/
u8 MUSART1_uint8Receive(u8* Copy_u8Data)               /*Specfic to BL application*/
{
	u8 Local_u8Result = 1;

	if ( (GET_BIT((USART1 -> SR),RXNE)) == 1 )
	{
		*Copy_u8Data = USART1 -> DR;
	}
	else
	{
		Local_u8Result = 0;
	}

	return (Local_u8Result);

}
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/


void USART1_uint8ReceivAsyn(void(*Copy_ptr)(u8))             /*Receive Data using interupt*/
{

	// Save call back address
	USART1_CallBack = Copy_ptr;

}
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/

void USART1_IRQHandler(void)
{

	if (IS_SET(USART1->SR,RXNE))
	{

		USART1_CallBack((USART1 -> DR) & ONE_BYTE ); // call function and pass Data register value to it as a parameter
	}

//	USART1->SR = 0 ;						/* Clearing status register */


}
/****************************************************  END OF FUNCTION*****************************************************************************************************************************************************/
void USART1_DeInit(void)
{

	USART1->SR = 0 ;						/* Clearing status register */
	USART1->DR = 0 ;						/* Clearing Data register */
	USART1->CR1 = 0 ;
	USART1->CR2 = 0 ;
	USART1_CallBack =  0 ;





}
