/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:18/10/2020***********************************/
/***********version:1***************************************/
/*********Description:FLASH DRIVER***********************/
/***********************************************************/


#ifndef BL_Interface_H
#define BL_Interface_H

#include "STD_TYPES.h"

#define APP1_FIRST_ADDRESS            0x08002000
#define BACKUP_FIRST_ADDRESS          0x08009000
#define DATA_STEP                     0X10
#define CRC_Init                      0x01
#define SIZE_Init                     0x00
#define ERASED_WORD                   0Xffffffff
#define ZERO_HEXA                     48
#define NINE_HEXA                     57
#define HEX_ASCII_DIFF                55


/***********************************************************************************/
                      /***FUNCTIONS PROTOTYPES***/
/***********************************************************************************/						
/************************************************************************************

*Name       :   AsciToHex

*Description: * Function to concert ascii Data 
                 to hexa format 
							
*Pre-Cond   :	input Data in ascii				
							
*pos-Cond   : None

*Input      : Ascii Bytes

*Output     : Hexa Bytes

*Return     : Hexa Bytes

****************************************************************************************/
static uint8 AsciToHex(uint8 Copy_u8Asci);
/************************************************************************************

*Name       :   ParseData

*Description: * Function to set Data of every record one by one 
							  and flash it to Rom
*Pre-Cond   :	input Data in hexa			
							
*pos-Cond   : record is received

*Input      : record array of hexa

*Output     : void

*Return     : void

****************************************************************************************/
static void ParseData(uint8* Copy_u8BufData);
/************************************************************************************

*Name       :   BL_VoidInit

*Description: * Function to Init all peripheral used in BL operations 
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BL_VoidInit(void);
/************************************************************************************

*Name       :   BL_VoidGetSizeAndCrc

*Description: * Function to ack Node to enter program seesion 
							
*Pre-Cond   :	Node is ready to connect				
							
*pos-Cond   : BL is ready to receive files

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BL_VoidGetSizeAndCrc (void);
/************************************************************************************

*Name       :   BL_VoidRecImage

*Description: * Function to receive hexa file from Node 
							
*Pre-Cond   :	Node is ready to connect				
							
*pos-Cond   : BL is ready to receive files

*Input      : void

*Output     : void

*Return     : void
****************************************************************************************/
void BL_VoidRecImage(void);
/************************************************************************************

*Name       :   BL_Send_Error

*Description: * Function to report an error to Node 
							
*Pre-Cond   :	Node transimmion is disconnected				
							
*pos-Cond   : soft reset and get back to branch

*Input      : void

*Output     : void

*Return     : void
****************************************************************************************/
void BL_VoidSendError(void);
/************************************************************************************

*Name       :   BL_Erase_Inactive_APP

*Description: * Function to erase in active image to be replaced 
							
*Pre-Cond   :	Init BL				
							
*pos-Cond   : BL is ready to receive Image

*Input      : void

*Output     : void

*Return     : void
****************************************************************************************/
void BL_VoidInitFlags(void ); // BL specify the Image to erase	

void BL_voidEndRecieve(void);

static void BL_VoidGetNodeAck(void);

void BL_VoidBeginSession(void);

void BL_VoidDetectWrongAck(void);  //report an error to node to begin a new session

void BL_VoidDetectPoweroff(void);  //report an error to node to begin a new session

void BL_VoidDetectCorruptedImages(void);  //report an error to node to begin a new session















#endif
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/
