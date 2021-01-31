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
/***********************************************************************************************************************************************************************************************************************************************************/ 
void BR_VoidIinit()
{
    RCC_InitysClock();
		RCC_VoidEnableClock(RCC_AHB_EN,RCC_CRC); /* CRC Unit */
		RCC_VoidEnableClock(RCC_APB2_EN,RCC_USART1); /* USART1 */
	  GPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_2MHZ_AFPP);   /* TX AFPP */
		GPIO_VoidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);  /* RC Input Floating */	
		USART1_VoidInit();  //Init usart1

	  
if(CURRENT_MODE == ERASED_WORD  )   // check if mode flag is erased
{
	/*
	if you are get here that means:
	
	1-its first time to install any images
	2-the two images are corrupted 	
	*/
	
  BL_VoidBeginSession(); // wait here untill session is begin by node
	
	FEEP_voidAddFlag(SYS_MODE_ADD , BL_MODE); // BL mode
	
	  // we shoould wait here to begin session

}	

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_VoidJumpToBL(void)
{
	
	
BL_VoidInit(); //Init BL

BL_VoidGetSizeAndCrc(); //BL Talk to Node

BL_VoidInitFlags(); // BL specify the Image to erase

BL_VoidRecImage();		//BL Receive new Image		
	

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_VoidJumpToApp(void)
{
	
	if( ARE_IMAGES_IDENTICAL == IDENTICAL_ON ) // if the two images are the same
	{
	
   u32 Local_u32CRC ;

	if(*(( u32*)(APP_FIRST_WORD)) != ERASED_WORD)  // check for reset vector
	{

     if(APP_STATUS ==STATUS_ON)	       //check status
	{	
		
		Local_u32CRC =	CRC_CalculateCRC_HW_Rom(APP_FIRST_WORD, APP_WORDS);//get crc value of app1
	
         if(Local_u32CRC == CURRENT_APP_CRC) //CRC CHECK
	{		
		
        BR_VoidStartAPP(); //goto APP 
	
}	
	

else //this image1 is corrupted
 {
 
	 
	   FEEP_voidUpdateFlag(CORRUPT_ADD_APP , CORRUPTED_ON ); // corrupted on
     FEEP_voidUpdateFlag(STATUS_ADD_APP , STATUS_OFF); // app1 off	
	   FEEP_voidUpdateFlag(STATUS_ADD_ROLLBACK , STATUS_ON); // app1 off	
	   BR_VoidJumpToRollback(); // go to rollback

	 
 }
					
}
	
	 /* one check or more are false*/

}
	}
	
	else // if the two images are different 
	{
	
	 u32 Local_u32CRC ;
		
		Local_u32CRC =	CRC_CalculateCRC_HW_Rom(APP_FIRST_WORD, APP_WORDS);//get crc value of app1
	
         if(Local_u32CRC == CURRENT_APP_CRC) //CRC CHECK
      	{		
		
          BR_VoidFlashRollBack(); //copy image 1 to rollback
					FEEP_voidUpdateFlag(CRC_ADD_ROLLBACK     ,  CURRENT_APP_CRC); //save crc of image1 to rolback
          FEEP_voidUpdateFlag(SIZE_ADD_ROLLBACK    ,  APP_WORDS); // save size of image1 to rolback		
					FEEP_voidUpdateFlag(IDENTICAL_ADD        ,  IDENTICAL_ON ); // now two images are identical
				 	BR_VoidSoftResetReq(); // software reset and return to BR
						
       }	
		
	      else
      {  // if image1 is corrupted

				if( *(( u32*)(ROLLBACK_FIRST_WORD)) != ERASED_WORD )  //check if rollback is exist or not
				{	
				BR_VoidFlashApp(); //copy image 1 to rollback
				FEEP_voidUpdateFlag(CRC_ADD_APP     ,  CURRENT_ROLLBACK_CRC); //save crc of rollback to image1
        FEEP_voidUpdateFlag(SIZE_ADD_APP    ,  ROLLBACK_WORDS); // save size of rollback to image 1		
			  FEEP_voidUpdateFlag(IDENTICAL_ADD    ,  IDENTICAL_ON ); // now two images are identical
			  BR_VoidSoftResetReq(); // software reset and return to BR
					
				}
				else		
				{     
				
				BL_VoidDetectCorruptedImages() ; //if image1 is corrupted and rollback doesnt exist send error and back to BR
				
				}
				
      }
	
	
	}
	
}
//****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_VoidJumpToRollback(void)
{
	
	  u32 Local_u32CRC ;
		
	if( *(( u32*)(ROLLBACK_FIRST_WORD)) != ERASED_WORD)  // check if app is exist
	{

     if(ROLLBACK_STATUS == STATUS_ON)	//check status
	{	
			
    Local_u32CRC =	CRC_CalculateCRC_HW_Rom(ROLLBACK_FIRST_WORD, ROLLBACK_WORDS);//get crc value of app1
	
         if(Local_u32CRC == CURRENT_ROLLBACK_CRC) //CRC CHECK
	{		
		
        BR_VoidStartBackup();//goto backup

 }	
	
 else //this image is corrupted
 {	 
	 
	  FEEP_voidUpdateFlag( CORRUPT_ADD_ROLLBACK , CORRUPTED_ON); //corrupted flag on
	  FEEP_voidUpdateFlag(STATUS_ADD_APP , STATUS_ON); // app1 off	
	  FEEP_voidUpdateFlag(STATUS_ADD_ROLLBACK , STATUS_OFF); // app1 off	
    BR_VoidCheckCorruptFlags();	// check if both files is currupted	
			 
 
 }
					
}
	
	 /* one check or more are false*/
	
}
	
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_VoidStartAPP(void){	
	 
	 typedef void (*Function_t)(void);
   Function_t addr_to_call = 0 ;
	 SCB_VTOR = APP_FIRST_WORD; // goto app1
	 addr_to_call = *(Function_t*)(APP_ENTRY_WORD);
	 addr_to_call();
	      
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_VoidStartBackup(void){
	
	   typedef void (*Function_t)(void);
     Function_t addr_to_call = 0 ;
	   SCB_VTOR = ROLLBACK_FIRST_WORD; // goto rollback
	   addr_to_call = *(Function_t*)(ROLLBACK_ENTRY_WORD); 
		 addr_to_call();

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																
void BR_VoidSoftResetReq(void)
{

	SCB_AIRCR =SOFT_RESET ; // key to reset

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	

void BR_VoidCheckCorruptFlags(void)
{

	if((APP_IS_CORRUPTED == CORRUPTED_ON ) & (ROLLBACK_IS_CORRUPTED == CORRUPTED_ON ) ) // if all checks are false
	{	
		
    FEEP_voidFreeFlag(SYS_MODE_ADD); // free flag to begin new session
   		
    BL_VoidDetectCorruptedImages() ; //  report error and reset back to branch 	
				
	}

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 	

u32 BR_CheckAPPCrc(void)
{
u32 Local_u32CRC ;
	
      Local_u32CRC =	CRC_CalculateCRC_HW_Rom(0X08002000, 0x00000240);//get crc value of app1

return  Local_u32CRC ;	

}
u32 BR_CheckBackupCrc(void)
{
u32 Local_u32CRC ;
	
	  	Local_u32CRC =	CRC_CalculateCRC_HW_Rom(0x08009000, 0x00000240);//get crc value of app1

return  Local_u32CRC ;		

}

/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_VoidFlashRollBack(void)  // flash image1 to rollback region
{
	
FPEC_voidEraseBackup_Area (); // erase rollback region
	
u32 Local_u32Data , Local_u32WordCounter ;
	
u32 DIFF_u32WORDS = ROLLBACK_FIRST_WORD -	APP_FIRST_WORD ; // get the difference between first two words in images
	
u32 Local_u32APPLastWord = (APP_FIRST_WORD + ( WORD_BYTES * ( APP_WORDS )) ) ; //last word in image 1 

	 for( Local_u32WordCounter = APP_FIRST_WORD ; Local_u32WordCounter < Local_u32APPLastWord ; )
	
      {
			
				Local_u32Data = *((u32*)(Local_u32WordCounter)); //save values
				
				FPEC_voidFlashWrite( (Local_u32WordCounter + DIFF_u32WORDS) ,  & (Local_u32Data)  , LENGHT ); //save new input Data
			
	  		Local_u32WordCounter = Local_u32WordCounter + WORD_BYTES ; // incerement address

			}	

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void BR_VoidFlashApp(void)  // flash image1 to rollback region
{
	
FPEC_voidEraseApp_one_Area (); // erase image1 region
	
u32 Local_u32Data , Local_u32WordCounter ;
	
u32 DIFF_u32WORDS = ROLLBACK_FIRST_WORD -	APP_FIRST_WORD ; // get the difference between first two words in images
	
u32 Local_u32RollbackLastWord = (ROLLBACK_FIRST_WORD + ( WORD_BYTES * ( ROLLBACK_WORDS )) ) ; //last word of rollback

	 for( Local_u32WordCounter = ROLLBACK_FIRST_WORD ; Local_u32WordCounter < Local_u32RollbackLastWord ; )
	
      {
			
				Local_u32Data = *((u32*)(Local_u32WordCounter)); //save values
				
				FPEC_voidFlashWrite( (Local_u32WordCounter - DIFF_u32WORDS) ,  & (Local_u32Data)  , LENGHT ); //copy data to image 1
			
	  		Local_u32WordCounter = Local_u32WordCounter + WORD_BYTES ; // incerement address

			}
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
