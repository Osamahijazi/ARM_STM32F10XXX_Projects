/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:18/10/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "BL_Interface.h"
#include "BL_Private.h"
#include "BL_Config.h"
#include "RCC_interface.h"
#include "GPIO_interface2.h"
#include "STK_interface.h"
#include "USART_interface.h"
#include "FPEC_Interface.h"
#include "FEE2_Interface.h"
#include "CRC_Interface.h"
#include "Branch_Interface.h"
volatile u16 Data[100] = {0};
volatile u32 IMAGE_SIZE=0 ;
volatile u32 IMAGE_CRC=0 ;
volatile u32 NODE_ACK = 0 ;
volatile u8  u8RecBuffer[100]   ;
volatile u8  u8RecCounter    = 0;
volatile u32 FIRST_ADDRESS ;
/**************************************************************************************************************************************************************************************************************************************************************/
void BL_VoidInit(void)
{
		RCC_InitysClock();
		RCC_VoidEnableClock(RCC_APB2_EN,RCC_USART1); /* USART1 */
		RCC_VoidEnableClock(RCC_APB2_EN,RCC_GPIOA);  /* PortA  */
		RCC_VoidEnableClock(RCC_AHB_EN,RCC_FLITF);   /* FPEC   */
		RCC_VoidEnableClock(RCC_AHB_EN,RCC_CRC); /* CRC Unit */
		GPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_2MHZ_AFPP);   /* TX AFPP */
		GPIO_VoidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);  /* RC Input Floating */
		USART1_VoidInit(); // Init USART1
		MSTK_voidInit();  // Init STK
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																
void BL_VoidGetSizeAndCrc (void)
{
	USART1_voidTransmitByte(0X50); //send ascii value value of hexa 

  BL_VoidGetNodeAck();// give node only 3 minutes to ack if not report an error
	
  if(NODE_ACK != 0x32){ 

 	BL_VoidDetectWrongAck();
		
 }	
	
	IMAGE_SIZE = USART1_VoidReceiveFourBytes();	 // word numbers of the image
	
	/*SIZE MUST BE LESS THAN a call app number of words*/
								
  IMAGE_CRC = USART1_VoidReceiveFourBytes(); // crc of the image
								
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																
void BL_VoidInitFlags(void)// erase inactive app
{				
		FPEC_voidEraseApp_one_Area(); // erase  app      regoin 
		FEEP_voidUpdateFlag( CORRUPT_ADD_ROLLBACK ,  CORRUPTED_OFF ); // corrupted off
	  FEEP_voidUpdateFlag( CORRUPT_ADD_APP      ,  CORRUPTED_OFF ); // corrupted off
		FEEP_voidUpdateFlag( CRC_ADD_APP          ,  IMAGE_CRC); //save crc
    FEEP_voidUpdateFlag( SIZE_ADD_APP         ,  IMAGE_SIZE); // save size	
	  FEEP_voidUpdateFlag( IDENTICAL_ADD        ,  IDENTICAL_OFF ); // two images are not identical		
		FIRST_ADDRESS  = APP_FIRST_WORD - DATA_STEP ; //first addres of app1
  
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BL_VoidRecImage(void)
{	
 
  BL_VoidGetNodeAck();
	
  if(NODE_ACK != 0X36) //check
	{ 

   BL_VoidDetectWrongAck();
			
  }	 
	
	 USART1_voidTransmitByte(0X74); //send ascii value  of hexa  to send code
                                                          /*begin to receive image from Node*/	
    u8 Local_u8RecStatus;
    MSTK_voidSetIntervalSingle(10000000,BL_VoidDetectPoweroff);//Give 10sec if no Data received report an error to resent the image
		while(1)
		{
			Local_u8RecStatus = MUSART1_uint8Receive( &(u8RecBuffer[u8RecCounter]) );//recieve Bytes
			
			if (Local_u8RecStatus == 1)
			{
		  	MSTK_voidStopInterval();

				if(u8RecBuffer[u8RecCounter] == '\n') // wait until end of the record
				{								
					ParseData(u8RecBuffer); 				   // Parse record  

					USART1_voidTransmit("ok");  // send ok to sent the next record if exist
					u8RecCounter = 0;
					
				}

				else
				{
					u8RecCounter ++ ;
				}

				MSTK_voidSetIntervalSingle(10000000,BL_voidEndRecieve); //if the next record late more 3 sec then data is finished        				
			}

			else
			{

				/*NO data received*/
				
			}


		}


}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
static uint8 AsciToHex(uint8 Copy_u8Asci)
{
	uint8 Result;
	if ( (Copy_u8Asci >= ZERO_HEXA) && (Copy_u8Asci <= NINE_HEXA) )
	{
		/*0 TO 9*/
		Result = Copy_u8Asci - ZERO_HEXA;
	}

	else
	{
		/*A TO F*/
		Result = Copy_u8Asci - HEX_ASCII_DIFF;
	}

	return Result;

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
static void ParseData(uint8* Copy_u8BufData) // flash Data
{
	
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	u8 DataCounter  = 0  ; 
	u8 RECORD_BYTES = 8 ;
  u8 i; // counter to get digits from array
	
	FIRST_ADDRESS  = FIRST_ADDRESS  + DATA_STEP ; // increment the address every record
	
	for (i=0;i<RECORD_BYTES; i++)
	
	{
		DataDigit0 = AsciToHex (Copy_u8BufData[4*i]);
		DataDigit1 = AsciToHex (Copy_u8BufData[4*i+1]);
		DataDigit2 = AsciToHex (Copy_u8BufData[4*i+2]);
		DataDigit3 = AsciToHex (Copy_u8BufData[4*i+3]);

		Data[DataCounter] = (DataDigit3 << 8) | (DataDigit2 << 12) | (DataDigit1) | (DataDigit0<<4);
		
		DataCounter++;
			
	}
	
	   FPEC_voidFlashWrite(FIRST_ADDRESS,Data,RECORD_BYTES); // sent Data to be flashed in first region
	   

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BL_voidEndRecieve(void) // Ack to end the session
{
	
 MSTK_voidStopInterval(); // stop timer
	
  if(u8RecBuffer[0] != 0X04) // node ack to end code
 {

   BL_VoidDetectWrongAck();// report to node to resend te code	

 }	
	
USART1_voidTransmitByte(0X77); //ack to end seesion
	
FEEP_voidUpdateFlag(STATUS_ADD_APP      , STATUS_ON); // app1 on
FEEP_voidUpdateFlag(STATUS_ADD_ROLLBACK , STATUS_OFF); // rollback off
	
FEEP_voidUpdateFlag(SYS_MODE_ADD , APP_MODE); //change to app mode

BR_VoidSoftResetReq();	//Software reset and get bback to branch
	
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/	
static void BL_VoidGetNodeAck(void) 
{

  	MSTK_voidSetIntervalSingle(10000000,BL_VoidDetectPoweroff);//Give 10sec if no ack received report an error to begin new sesion	
    NODE_ACK =USART1_uint8Receive(); // wait node ack
    MSTK_voidStopInterval();
	
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/	
void BL_VoidBeginSession(void) // begin session if there are now images
{	
	  u8 FIRST_NODE_ACK ;
	
    FIRST_NODE_ACK =USART1_uint8Receive(); // wait node ack
	
  if(FIRST_NODE_ACK != 0x33){ 

 	BL_VoidDetectWrongAck();
		
 }		

}	
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BL_VoidSendError(void)  //report an error to node to begin a new session
{
	
USART1_voidTransmitByte(0X70); //ack to report error
	
FEEP_voidFreeFlag(SYS_MODE_ADD); // free flag to begin new session

BR_VoidSoftResetReq();	//Software reset and back to branch
	
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BL_VoidDetectWrongAck(void)  //report an error to node and jump to app
{
	
USART1_voidTransmitByte(0X70); //ack to report error
	
FEEP_voidUpdateFlag(SYS_MODE_ADD , APP_MODE); //change to app mode

BR_VoidSoftResetReq();	//Software reset and back to branch
	
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BL_VoidDetectPoweroff(void)  //report an error to node to begin a new session
{
	
USART1_voidTransmitByte(0X70); //ack to report error
	
FEEP_voidUpdateFlag(SYS_MODE_ADD , APP_MODE); //change to app mode
	
BR_VoidSoftResetReq();	//Software reset and back to branch
	
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BL_VoidDetectCorruptedImages(void)  //report an error to node to begin a new session
{
	
USART1_voidTransmitByte(0X70); //ack to report error
	
FEEP_voidFreeFlag(SYS_MODE_ADD); // free flag to begin new session

BR_VoidSoftResetReq();	//Software reset and back to branch
	
}