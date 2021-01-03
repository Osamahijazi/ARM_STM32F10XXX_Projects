/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:29/12/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef BRANCH_INTERFACE_H
#define BRANCH_INTERFACE_H
/*************************************************************APPS MACROS**************************************************************************************************************************************************************************************************************************/																                                  																 																	
#define APP1_FIRST_ADDRESS          0x08002000
#define APP_CRC                     0xD97C1DCA   
#define APP_WORDS_NUMBER              573
#define BACKUP_FIRST_ADDRESS        0x08009800
#define BACKUP_CRC                  0x6EE3481A
#define BACKUP_WORDS_NUMBER            382
#define BACKUP_WORDS_NUMBER_INTERR     594
#define BACKUP_CRC_INERRUPT          0x04F7EDE6


/***********************************************************************************/
                      /***FUNCTIONS PROTOTYPES***/
/***********************************************************************************/						
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

*Name       :   BR_Check_Backup_Exist

*Description: * Function to perform all checks before jump to backup 
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_Check_Backup_Exist(void);
/************************************************************************************

*Name       :   BR_Check_App_Exist

*Description: * Function to perform all checks before jump to app 
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_Check_App_Exist(void);
/************************************************************************************

*Name       :   BR_Change_Status

*Description: * Function to ahange the status of the input app address flag 
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : status flag address

*Output     : void

*Return     : void

****************************************************************************************/
void BR_Change_Status(u32 Copy_u32Address );
/************************************************************************************

*Name       :   BR_CheckBackupCrc

*Description: * Function to get crc of new image of backup 
							
*Pre-Cond   :	new image crc has received				
							
*pos-Cond   : crc checked is performed

*Input      : void

*Output     : crc of new image

*Return     : crc of new image

****************************************************************************************/
u32 BR_CheckBackupCrc(void);
/************************************************************************************

*Name       :   BR_CheckAPPCrc

*Description: * Function to get crc of new image of app 
							
*Pre-Cond   :	new image crc has received				
							
*pos-Cond   : crc checked is performed

*Input      : void

*Output     : crc of new image

*Return     : crc of new image

****************************************************************************************/
u32 BR_CheckAPPCrc(void) ;
/************************************************************************************

*Name       :   Soft_Reset_Req

*Description: * Function to perform soft reset 
							
*Pre-Cond   :	Error - Program seesion is Finished			
							
*pos-Cond   : crc checked is performed

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void Soft_Reset_Req(void);  // Request immediate software reset
/************************************************************************************

*Name       :   BR_Start_APP

*Description: * Function to jump to app1  
							
*Pre-Cond   :	app1 checks are all right				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_Start_APP(void);
/************************************************************************************

*Name       :   BR_Start_Backup

*Description: * Function to jump to backup image  
							
*Pre-Cond   :	backup checks are all right				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void BR_Start_Backup(void);


void BR_DefResetVect(void);

void BR_CheckCorruptFlags(void);

void BR_SwitchApp(void);










#endif
