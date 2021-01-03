/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:15/12/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef FEE2_INTERFACE_H
#define FEE2_INTERFACE_H


#define  First_Address     0x0800FC00  // low address  of region
#define  Last_Address      0x0800FC30  // high address of region

                                                      /*flags addresses and  Definitions*/
																										
#define  MODE_ADD             0x0800FC00  // address of mode flag

#define  CRC_ADD_APP1         0x0800FC04  // address of crc of first  app
#define  STATUS_ADD_APP1      0x0800FC08  // address of status of first  app
#define  SIZE_ADD_APP1        0x0800FC0C  // address of WORD NUMBER of first  app
#define  CORRUPT_ADD_APP1     0x0800FC24  // address of Corrupt flag of first  app


#define  CRC_ADD_APP2         0x0800FC14  // address of crc of second  app
#define  STATUS_ADD_APP2      0x0800FC18  // address of status of second  app
#define  SIZE_ADD_APP2        0x0800FC1C  // address of WORD NUMMBER of second  app
#define  CORRUPT_ADD_APP2     0x0800FC20  // address of Corrupt flag of second  app

                                                 

#define  MODE          *(( u32*)(MODE_ADD))     // variable to indicate the current mode (BL OR APP)
#define  CRC1          *(( u32*)(CRC_ADD_APP1))  // variable to store crc address of first  app
#define  CRC2          *(( u32*)(CRC_ADD_APP2))  // variable to store crc address of second app
#define  STATUS1       *(( u32*)(STATUS_ADD_APP1))  // variable to store status address of first app
#define  STATUS2       *(( u32*)(STATUS_ADD_APP2))  // variable to store status address of second app
#define  APP_WORDS     *(( u32*)(SIZE_ADD_APP1))  // variable to store crc address of first  app
#define  BACKUP_WORDS  *(( u32*)(SIZE_ADD_APP2))  // variable to store crc address of second app
#define  APP1_IS_CORRUPTED  *(( u32*)(CORRUPT_ADD_APP1))  // variable to store crc address of second app
#define  APP2_IS_CORRUPTED  *(( u32*)(CORRUPT_ADD_APP2))  // variable to store crc address of second app


                                                            /*general macros*/
																											 
#define  BL_MODE            0X00            //value of bl mode																											 
#define  APP_MODE           0X01            //value of app mode																											 
#define  STATUS_ON          0X01            //value of on mode																											 
#define  STATUS_OFF         0X00            //value of off mode		
#define  CORRUPTED_OFF      0X00            //value of off mode																											 
#define  CORRUPTED_ON       0X01            //value of off mode																											 

/************************************************************************************

*Name       :   FEEP_voidAddFlag

*Description: * Function to save one word for anew flag and store a init value to it 
							
*Pre-Cond   :	FPEC is ON and the input address must be between the first and last address				
							
*pos-Cond   : None

*Input      : address and the fla value

*Output     : void

*Return     : void

****************************************************************************************/
void FEEP_voidAddFlag   (u32 Copy_u32Address , u32 Copy_u32Data); //save a word for new flag
/************************************************************************************

*Name       :   FEEP_voidUpdateFlag

*Description: * Function to change one word flag value 
							
*Pre-Cond   :	FPEC is ON and the input address must be between the first and last address				
							
*pos-Cond   : None

*Input      : address and the flag value

*Output     : void

*Return     : void

****************************************************************************************/
void FEEP_voidUpdateFlag(u32 Copy_u32Address , u32 Copy_u32Data); //change flag value
/************************************************************************************

*Name       :   FEEP_voidFreeFlag

*Description: * Function to erase aspecific word of saved flag 
							
*Pre-Cond   :	FPEC is ON and the input address must be between the first and last address				
							
*pos-Cond   : None

*Input      : address and the fla value

*Output     : void

*Return     : void

****************************************************************************************/
									 	 								 
void FEEP_voidFreeFlag(u32 Copy_u32Address) ; // free a flag 

#endif
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/
