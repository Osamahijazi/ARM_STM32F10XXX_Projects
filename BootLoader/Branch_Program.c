/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:29/12/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Branch_Interface.h"
#include "Branch_Private.h"
#include "Branch_Config.h"
#include "RCC_interface.h"
#include "FEE2_Interface.h"
#include "CRC_Interface.h"
#include "BL_Interface.h"
#include "RCC_interface.h"
#include "GPIO_interface2.h"
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;
/***********************************************************************************************************************************************************************************************************************************************************/
void BR_DefResetVect(void)
{	
	 if(STATUS_ON ==STATUS1)	 
	 {
	 
	SCB_VTOR = 0x08002000; // goto app1
	addr_to_call = *(Function_t*)(0x08002004);
	 	 
	 }

   if(STATUS_ON ==STATUS2)	 
	 {
	 
		 SCB_VTOR = 0x08009800; // goto backup
	   addr_to_call = *(Function_t*)(0x08009804); 
	 
	 }
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_Start_APP(void){
	
	addr_to_call();
	      
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_Start_Backup(void){
	
		 addr_to_call();

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_VoidIinit()
{
    RCC_InitysClock();
		RCC_VoidEnableClock(RCC_AHB_EN,RCC_CRC); /* CRC Unit */
		RCC_VoidEnableClock(RCC_APB2_EN,RCC_USART1); /* USART1 */
	  GPIO_VoidSetPinDirection(GPIOA,PIN9,0b1010);   /* TX AFPP */
		GPIO_VoidSetPinDirection(GPIOA,PIN10,0b0100);  /* RC Input Floating */
		
	  
if(MODE == ERASED_WORD  )  // first time to install firmware
{
	
	  FEEP_voidAddFlag(MODE_ADD , BL_MODE); // BL mode

}	

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_Check_Backup_Exist(void)
{
	
	  u32 Local_u32CRC ;
		
	if( SCB_VTOR != ERASED_WORD)  // check for reset vector this condition isalways right
	{

     if(STATUS2 == STATUS_ON)	//check status
	{	
			
      Local_u32CRC =	CRC_CalculateCRC_HW_Rom(BACKUP_FIRST_ADDRESS, BACKUP_WORDS);//get crc value of app1
	
         if(Local_u32CRC == CRC2) //CRC CHECK
	{		
		
        BR_Start_Backup();//goto backup
	
 }	
	
 else //this image is corrupted
 {	 
	 
	  FEEP_voidUpdateFlag( CORRUPT_ADD_APP2 , CORRUPTED_ON); //corrupted flag on
	  FEEP_voidUpdateFlag(STATUS_ADD_APP1 , STATUS_ON); // app1 off	
	  FEEP_voidUpdateFlag(STATUS_ADD_APP2 , STATUS_OFF); // app1 off	
    Soft_Reset_Req();
			 
 
 }
					
}
	
	 /* one check or more are false*/
	
}
	
}

/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_Check_App_Exist(void)
{
	
   u32 Local_u32CRC ;

	if( SCB_VTOR != ERASED_WORD)  // check for reset vector
	{

     if(STATUS1 ==STATUS_ON)	       //check status
	{	
		
		Local_u32CRC =	CRC_CalculateCRC_HW_Rom(APP1_FIRST_ADDRESS, APP_WORDS);//get crc value of app1
	
         if(Local_u32CRC == CRC1) //CRC CHECK
	{		
		
        BR_Start_APP(); //goto APP 
	
}	
	

else //this image is corrupted
 {
 
	 
	   FEEP_voidUpdateFlag(CORRUPT_ADD_APP1 , CORRUPTED_ON ); // corrupted on
     FEEP_voidUpdateFlag(STATUS_ADD_APP1 , STATUS_OFF); // app1 off	
	   FEEP_voidUpdateFlag(STATUS_ADD_APP2 , STATUS_ON); // app1 off	
	 
 }
					
}
	
	 /* one check or more are false*/

}
	
}

/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_Change_Status(u32 Copy_u32Address )
{

if( STATUS_OFF == *(( u32*)(Copy_u32Address)))
{
	
FEEP_voidUpdateFlag(Copy_u32Address , STATUS_ON); // status on	

}
else
{
FEEP_voidUpdateFlag(Copy_u32Address , STATUS_OFF); // status off	

}

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
/*
u32 BR_CheckAPPCrc(void)
{
u32 Local_u32CRC ;
	
      Local_u32CRC =	CRC_CalculateCRC_HW_Rom(0x08002000, 382);//get crc value of app1

return  Local_u32CRC ;	

}
u32 BR_CheckBackupCrc(void)
{
u32 Local_u32CRC ;
	
	  	Local_u32CRC =	CRC_CalculateCRC_HW_Rom(0x08009800, 382);//get crc value of app1

return  Local_u32CRC ;	
	

}

*/

/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void Soft_Reset_Req(void)
{

	SCB_AIRCR =SOFT_RESET ; // key to reset

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	

void BR_CheckCorruptFlags(void)
{

	if((APP1_IS_CORRUPTED == CORRUPTED_ON ) & (APP2_IS_CORRUPTED == CORRUPTED_ON ) )
	{
	                         //erase all apps region and return to init case
		
 	FPEC_voidEraseBackup_Area ();  // erase app1   region
  FPEC_voidEraseApp_one_Area(); //  erase backup region
 	
   BL_Send_Error() ; // if all checks are false report error and reset back to branch to enter BL		
				
	}


}