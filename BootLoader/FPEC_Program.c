/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:16/10/2020***********************************/
/***********version:1***************************************/
/*********Description:FLASH DRIVER***********************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "FPEC_Private.h"
#include "FPEC_Interface.h"
#include "FPEC_Config.h"
/***************************************************************************************************************************************************************************************************************************************************************
                                                  *****Functions Definitions********
***********************************************************************************************************************************************************************************************************************************************************/
uint8 FPEC_u8WriteHalfWord( uint32 Copy_uint32Address,                  /*WRITE HALF WORD PROCEDUR STEPS*/
                            uint16 Copy_uint16Data    ) {
															
	while (WAIT_FLASH);   /*MAKE SURE FLASH IS NOT IN OTHER OPERATION*/
																											
   uint8 local_uint8Error ;     /*LOCAL VARIABLE TO RETURN THE RESULT OF ERRO CHECK */
															
	  if (LOCK_IS_SET){        /*CHECK FOR FLSH CR LOCK */
 
           			/*TO UNLOCK FLASH BLOCK , WE MUST APPLY THIS SEQUENCE TO FLASH_KEYR REGISTER*/
		
		    FPEC->FLASH_KEYR = FPEC_KEY1 ;     /*WRITE KEY 1 TO REGISTER*/
		    FPEC->FLASH_KEYR = FPEC_KEY2 ;     /*WRITE KEY 2 TO REGISTER*/
	}											
															
      	SET_BIT((FPEC->FLASH_CR ),PG );			        /*NOW ENABLE FLASH BLOCK TO PROGRAM*/
															
	     (*(uint16*)Copy_uint32Address) = Copy_uint16Data ;   /*LOW 16 BITS OF Copy_uint32Address LOADED BY Copy_u16Data */
	
      	while (WAIT_FLASH);   /*WAIT TILL OPERATION IS FINISHED*/
												
       SET_BIT  (FPEC->FLASH_SR,OP_END);           /*RESET END OF OPERATION BIT BY WRITING ONE*/	
       CLEAR_BIT((FPEC->FLASH_CR ), PER );        /* CLEAR ERASE BIT TO DISABLE IT*/	                                  

	if ( (*(uint16*)Copy_uint32Address) == Copy_uint16Data ){      /*COMPARE BETWEEN THE DATA IN ADDRESS AND INPUT DATA OF FUNCTION*/
		
		  local_uint8Error = WRITE_SUCCES ;
	}
	
	else {
		
		local_uint8Error = WRITE_FAILED ;
		
	}                                               /*END OF IF STATMENT*/
	
	return local_uint8Error ;                         /*RETURN ERROR RETURN CHECK*/
}									
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 
void FPEC_voidErasePage( uint8 Copy_uint8PageNumber ){    /*ERASE A CERTAIN PAGE */
	
	while (WAIT_FLASH);   /*MAKE SURE FLASH IS NOT IN OTHER OPERATION*/
	
	  if (LOCK_IS_SET){        /*CHECK FOR FLSH CR LOCK */

      			/*TO UNLOCK FLASH BLOCK , WE MUST APPLY THIS SEQUENCE TO FLASH_KEYR REGISTER*/
		
		    FPEC->FLASH_KEYR = FPEC_KEY1 ;     /*WRITE KEY 1 TO REGISTER*/
		    FPEC->FLASH_KEYR = FPEC_KEY2 ;     /*WRITE KEY 2 TO REGISTER*/
	}			
	
	     SET_BIT((FPEC->FLASH_CR),PER );    /*ENABLE ERASE OPERATION */
	
    	 FPEC->FLASH_AR = (uint32)(Copy_uint8PageNumber * PAGE_SIZE) + FIRST_PAGE_BASE ;/*LOAD AR REGISTER BY INPUT PAGE ADDRESS */
	
	     SET_BIT ((FPEC->FLASH_CR),STRT );          /*START OPERATION*/

    	while (WAIT_FLASH);   /*WAIT TILL OPERATION IS FINISHED*/
 	
      SET_BIT  (FPEC->FLASH_SR,OP_END);           /*RESET END OF OPERATION BIT BY WRITING ONE*/
     	CLEAR_BIT((FPEC->FLASH_CR ), PER );        /* CLEAR ERASE BIT TO DISABLE IT*/
	
	/*Check the page is erased by
reading all the addresses in
the page*/
	
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 		
void FPEC_voidMassErase(void){           /*ERASE ALL USER PAGES IN FLAG MEMORY*/

	while (WAIT_FLASH);   /*MAKE SURE FLASH IS NOT IN OTHER OPERATION*/

   if (LOCK_IS_SET){        /*CHECK FOR FLSH CR LOCK */

      	  		/*TO UNLOCK FLASH BLOCK , WE MUST APPLY THIS SEQUENCE TO FLASH_KEYR REGISTER*/
				
		    FPEC->FLASH_KEYR = FPEC_KEY1 ;     /*WRITE KEY 1 TO REGISTER*/
		    FPEC->FLASH_KEYR = FPEC_KEY2 ;     /*WRITE KEY 2 TO REGISTER*/
	}			
	
  	SET_BIT((FPEC->FLASH_CR),MER);        /*ENABLE ERASE PAGE BIT */
	
  	SET_BIT((FPEC-> FLASH_CR),STRT);      /*SET BIT TO START ERASE OPERATION*/

   	while (WAIT_FLASH);   /*WAIT TILL OPERATION IS FINISHED*/
	
	/*Check the erase operation by
reading all the addresses in
the user memory*/

}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 		

void FPEC_voidErasPages(uint8 Copy_uint8FirstPage,                /*ERASE FIXED NUMBER OF PAGES */
                        uint8 Copy_uint8LastPage    ) {

													
	uint8 Local_Uint8Counter;			 /*COUNTER TO SELECTED PAGES TO ERASE ONE BU ONE*/					
													
	  for(Local_Uint8Counter =Copy_uint8FirstPage ; Local_Uint8Counter <=  Copy_uint8LastPage;Local_Uint8Counter++ ){
		
		FPEC_voidErasePage(Local_Uint8Counter);
				
	 	}												 /*END OF THE LOOP , ALL PAGES ARE ERASED*/
}													
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 														
void FPEC_voidFlashWrite(uint32  Copy_u32Address, 
                         uint16* Copy_u16Data  , 
                         uint8   Copy_u8Length     ) {
		
  uint8 Data_Counter;
	//volatile uint16 Temp;  
  
	while (WAIT_FLASH);   /*MAKE SURE FLASH IS NOT IN OTHER OPERATION*/

	if (LOCK_IS_SET)        /*CHECK FOR FLSH CR LOCK */
  {
      	  		/*TO UNLOCK FLASH BLOCK , WE MUST APPLY THIS SEQUENCE TO FLASH_KEYR REGISTER*/
				
		    FPEC->FLASH_KEYR = FPEC_KEY1 ;     /*WRITE KEY 1 TO REGISTER*/
		    FPEC->FLASH_KEYR = FPEC_KEY2 ;     /*WRITE KEY 2 TO REGISTER*/
	}													 

	for (Data_Counter = 0; Data_Counter< Copy_u8Length; Data_Counter++)
	{
		
		SET_BIT((FPEC->FLASH_CR ),PG );			        /*NOW ENABLE FLASH BLOCK TO PROGRAM*/


		//Temp = Copy_u16Data[i];
		
		*((volatile uint16*)Copy_u32Address) = Copy_u16Data[Data_Counter]; //Load the Data

		Copy_u32Address += 2 ; //step address by 2

		while (WAIT_FLASH);   /*WAIT TILL OPERATION IS FINISHED*/
 	
     SET_BIT  (FPEC->FLASH_SR,OP_END);           /*RESET END OF OPERATION BIT BY WRITING ONE*/
    	CLEAR_BIT((FPEC->FLASH_CR ), PER );        /* CLEAR ERASE BIT TO DISABLE IT*/
	
	}											 

}								
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 																										 
void FPEC_voidEraseAppArea(void)
{
	uint8 i;
	
	for (i=4;i<64;i++)
	{
		FPEC_voidErasePage(i);
	}
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 																										 
