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
/**************************************************************************************************************************************************************************************************************************************************************/
u16 Data[100] = {0};
u32 Address= 0x08000000;
u32 size=0 ;
u32 CRC=0 ;
u32 NODE_ACK = 0 ;
volatile u8  u8RecBuffer[100]   ;
volatile u8  u8RecCounter    = 0;
volatile u8  u8TimeOutFlag   = 0;
volatile u16 u16TimerCounter = 0;
volatile u8  u8BLWriteReq    = 1;
volatile u8  APP_FLAG = 0 ;
volatile u32 FIRST_ADDRESS ;

/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																
void BL_VoidInit(void)
{
		RCC_InitysClock();
		RCC_VoidEnableClock(RCC_APB2_EN,RCC_USART1); /* USART1 */
		RCC_VoidEnableClock(RCC_APB2_EN,RCC_GPIOA);  /* PortA  */
		RCC_VoidEnableClock(RCC_AHB_EN,RCC_FLITF);   /* FPEC   */
		RCC_VoidEnableClock(RCC_AHB_EN,RCC_CRC); /* CRC Unit */
		GPIO_VoidSetPinDirection(GPIOA,PIN9,0b1010);   /* TX AFPP */
		GPIO_VoidSetPinDirection(GPIOA,PIN10,0b0100);  /* RC Input Floating */
		USART1_VoidInit();
		MSTK_voidInit();
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																
void BL_VoidACK (void)
{
	
  USART1_voidTransmitByte(0X50); //send ascii value value of hexa 
								
   NODE_ACK =USART1_uint8Receive(); // wait 0x34
	
  if(NODE_ACK != 0x34){ 

 	BL_Send_Error();
 }	
	
	size = USART1_VoidReceiveFourBytes();	 // word numbers of the image
								
  CRC = USART1_VoidReceiveFourBytes(); // crc of the image
								
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																
void BL_Erase_Inactive_APP(void)// erase inactive app
{
if((STATUS1 == ERASED_WORD)&(STATUS2 == ERASED_WORD)) //if rom is empty put the hexa in first app (Init case)

  {
		
  FEEP_voidUpdateFlag(STATUS_ADD_APP1 , STATUS_OFF); // app1 ff	
  FEEP_voidUpdateFlag(STATUS_ADD_APP2 , STATUS_ON); // backup on	
	FEEP_voidUpdateFlag(CRC_ADD_APP2 ,CRC_Init);// Init crc2
  FEEP_voidUpdateFlag(SIZE_ADD_APP2 , SIZE_Init); // Init size2
  FEEP_voidUpdateFlag(CORRUPT_ADD_APP1 , CORRUPTED_OFF ); // corrupted off
  FEEP_voidUpdateFlag(CORRUPT_ADD_APP2 , CORRUPTED_OFF ); // corrupted off

	
}	
		
  if(STATUS_OFF ==STATUS1)	 
	                             //app1 is off      
	{
		FPEC_voidEraseApp_one_Area(); //erase regoin one
		FEEP_voidUpdateFlag(CRC_ADD_APP1 ,CRC); //save crc
    FEEP_voidUpdateFlag(SIZE_ADD_APP1 , size); // save size	
		FEEP_voidUpdateFlag(CORRUPT_ADD_APP1 , CORRUPTED_OFF ); // corrupted off
		FIRST_ADDRESS = APP1_FIRST_ADDRESS - DATA_STEP; //first addres of app1

	}
 else   
	                         // backup is off
 {
	 
	 FPEC_voidEraseBackup_Area(); //erase region two
	 FEEP_voidUpdateFlag(CRC_ADD_APP2 ,CRC);//save crc
   FEEP_voidUpdateFlag(SIZE_ADD_APP2 , size); // save size	
	 FEEP_voidUpdateFlag(CORRUPT_ADD_APP2 , CORRUPTED_OFF ); // corrupted off
   FIRST_ADDRESS = BACKUP_FIRST_ADDRESS - DATA_STEP; //first address of backup
	 	 
 }
  
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BL_VoidRec(void){	
 
USART1_voidTransmitByte(0X74); //send ascii value  of hexa  to send code

NODE_ACK = USART1_uint8Receive(); // wait for 0x36 to receive code
	
 if(NODE_ACK != 0X36){ //check

 BL_Send_Error();
}	 
                                                          /*begin to receive image from Node*/	
    u8 Local_u8RecStatus;
    MSTK_voidSetIntervalSingle(10000000,BL_Send_Error);//Give 10sec if no Data received report an error to resent the image
		while(u8TimeOutFlag == 0)
		{
			Local_u8RecStatus = MUSART1_uint8Receive( &(u8RecBuffer[u8RecCounter]) );//recieve Bytes
			
			if (Local_u8RecStatus == 1)
			{
		  	MSTK_voidStopInterval();

				if(u8RecBuffer[u8RecCounter] == '\n')
				{			
					
						ParseData(u8RecBuffer); 				   // Parse record  

					USART1_voidTransmit("ok");
					u8RecCounter = 0;
				}

				else
				{
					u8RecCounter ++ ;
				}

				MSTK_voidSetIntervalSingle(3000000,BL_voidEndRecieve); //if the next record late more 3 sec then data is finished 
			}

			else
			{

				/*NO data received*/
				
			}


		}


}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
uint8 AsciToHex(uint8 Copy_u8Asci)
{
	uint8 Result;
	if ( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		/*0 TO 9*/
		Result = Copy_u8Asci - 48;
	}

	else
	{
		/*A TO F*/
		Result = Copy_u8Asci - 55;
	}

	return Result;

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void ParseData(uint8* Copy_u8BufData) // flash Data
{
	
	uint8 DigitLow,DigitHigh,CC,i;
	
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3,DataDigit4,DataDigit5,DataDigit6,DataDigit7;
	
	uint8 DataCounter = 0;

	      /* Get Character Count */
	DigitHigh = AsciToHex (Copy_u8BufData[0]);
	
	DigitLow  = AsciToHex (Copy_u8BufData[1]);
	
	CC        = (DigitHigh<<4) | DigitLow ;

	FIRST_ADDRESS = FIRST_ADDRESS + DATA_STEP ; // increment the address every record
	
	for (i=0;i<CC/2; i++)
	
	{
		DataDigit0 = AsciToHex (Copy_u8BufData[4*i+2]);
		DataDigit1 = AsciToHex (Copy_u8BufData[4*i+3]);
		DataDigit2 = AsciToHex (Copy_u8BufData[4*i+4]);
		DataDigit3 = AsciToHex (Copy_u8BufData[4*i+5]);

		Data[DataCounter] = (DataDigit3 << 8) | (DataDigit2 << 12) | (DataDigit1) | (DataDigit0<<4);
		
		DataCounter++;
			
	}
	
	   FPEC_voidFlashWrite(FIRST_ADDRESS,Data,CC/2); // sent Data to be flashed
     DataCounter = 0;

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BL_voidEndRecieve(void) // Ack to end the session
{
MSTK_voidStopInterval(); // stop timer
	
USART1_voidTransmitByte(0X76); //ack to end seesion
	

 NODE_ACK = USART1_uint8Receive();//wait ack 37 
	
  if(NODE_ACK != 0x37){ //check

 	BL_Send_Error();// reprt to node
  }	
	
USART1_voidTransmitByte(0X77); //ack to end seesion
	
BR_Change_Status(STATUS_ADD_APP1 ); // app1 satus off	
BR_Change_Status(STATUS_ADD_APP2 ); // backup status on	
	
FEEP_voidUpdateFlag(MODE_ADD , 0X01); //change to app mode

Soft_Reset_Req();	//Software reset and get bback to branch
	
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BL_Send_Error(void)  //report an error
{
USART1_voidTransmitByte(0X70); //ack to report error
	
FEEP_voidUpdateFlag(MODE_ADD , 0X00); // bl mode to resent the image

Soft_Reset_Req();	//Software reset and back to branch
	
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	