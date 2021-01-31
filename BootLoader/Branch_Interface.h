/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:29/12/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef BRANCH_INTERFACE_H
#define BRANCH_INTERFACE_H
/*************************************************************APPS MACROS**************************************************************************************************************************************************************************************************************************/																                                  																 																	
#define APP_FIRST_WORD               0x08002000
#define APP_ENTRY_WORD               0x08002004
#define APP1_CRC                     0xD97C1DCA   
#define APP1_WORDS_NUMBER            0x0000023D

#define ROLLBACK_FIRST_WORD          0x08009000
#define ROLLBACK_ENTRY_WORD          0x08009004
#define APP2_CRC                     0xE8BE9962
#define APP2_WORDS_NUMBER            0x000002A4 

#define APP3_CRC_BLOCK               0xDC3D0367
#define APP3_WORDS_NUMBER            0x00000240 

#define WORD_BYTES                   4
#define LENGHT                       2
/***********************************************************************************/
                      /***FUNCTIONS PROTOTYPES***/						
/************************************************************************************

*Name       :   BR_VoidIinit

*Description: * Function To Init CRC peripheral   
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_VoidIinit();
/************************************************************************************

*Name       :   BR_VoidJumpToRollback

*Description: * Function to perform all checks before jump to backup 
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_VoidJumpToRollback(void);
/************************************************************************************

*Name       :   BR_VoidJumpToApp

*Description: * Function to perform all checks before jump to app 
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_VoidJumpToApp(void);
/************************************************************************************

*Name       :   BR_VoidSoftResetReq

*Description: * Function to perform soft reset 
							
*Pre-Cond   :	Error or Program seesion is Finished			
							
*pos-Cond   : none

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_VoidSoftResetReq(void);  // Request immediate software reset
/************************************************************************************

*Name       :   BR_Start_APP

*Description: * Function to jump to app1  
							
*Pre-Cond   :	app1 checks are all right				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_VoidStartAPP(void);
/************************************************************************************

*Name       :   BR_Start_Backup

*Description: * Function to jump to backup image  
							
*Pre-Cond   :	backup checks are all right				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_VoidStartBackup(void);
/************************************************************************************

*Name       :   BR_VoidCheckCorruptFlags

*Description: * Function to check if the both images arre corrupted  
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : Soft reset

*Return     : void

****************************************************************************************/
void BR_VoidCheckCorruptFlags(void);
/************************************************************************************

*Name       :   BR_VoidJumpToBL

*Description: * Function To begin BL session   
							
*Pre-Cond   :	mode flag is reset 				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_VoidJumpToBL(void);
/************************************************************************************

*Name       :   BR_VoidFlashRollBack

*Description: * Function To copy image1 into image2   
							
*Pre-Cond   :	image 1 crc check is correct 				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_VoidFlashRollBack(void) ;
/************************************************************************************

*Name       :   BR_VoidFlashApp

*Description: * Function To copy image2 into image1   
							
*Pre-Cond   :	image 1 is corrupted 				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_VoidFlashApp(void);  // flash image1 to rollback region





#endif
