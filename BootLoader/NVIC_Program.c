/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_Interface.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"
 static uint8 NVIC_ERROR = 0 ;               /*THIS VARIABLE SHOULD HOLD A VALUE THAT INDICATE THE TYPE AND LOCATION OF ERROR */
/***************************************************************************************************************************************************************************************************************************************************************
                                                  *****Functions Definitions********
***********************************************************************************************************************************************************************************************************************************************************/
void NVIC_voidEnableInterrupt(uint8 Copy_uint8IntNumber){               /*ENABLE INTERRUPT OF A CERTAIN POSITION*/

	if (Copy_uint8IntNumber <= (MAX_BIT_POS)){  /*POSITION NUMBER LESS THAN 32*/

		NVIC_ISER0 = (1 <<Copy_uint8IntNumber);  /*SET INTERRUPT BIT IN FIRST REGISTER  */

	}
	
	else if (Copy_uint8IntNumber <= MAX_POS_NUM){  /*POSITION NUMBER LESS THAN 59*/

		Copy_uint8IntNumber = Copy_uint8IntNumber - MAX_REG_BITS ;  /*SUSTRACT 32 TO SET PROPER BIT IN SECOND REGISTER*/

		NVIC_ISER1 = (1 <<Copy_uint8IntNumber );  /*SET INTERRUPT BIT */
	}

	else{                     
                      		   /*IF YOU ARE HERE THEN YOU CHOOSE A WRONG POSITION NUMBER*/

		NVIC_ERROR = WRONG_POS_ENABLE_INTERRUPT ;    /* NVIC_ERROR VALUE INDICATE THE TYPE AND LOCATION OF ERROR */

	}
	
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 
/***********************************************************************************************************************************************************************************************************************************************************/
void NVIC_voidDisableInterrupt(uint8 Copy_uint8IntNumber){      /*DISABLE INTERRUPT OF A CERTAIN POSITION*/

	if (Copy_uint8IntNumber <= MAX_BIT_POS){      /*POSITION NUMBER LESS THAN 32*/

		NVIC_ICER0 = (1 <<Copy_uint8IntNumber);    /*SET INTERRUPT BIT */

	}

	else if (Copy_uint8IntNumber <= MAX_POS_NUM){  /*POSITION NUMBER LESS THAN 59*/

		Copy_uint8IntNumber = Copy_uint8IntNumber - MAX_REG_BITS ;  /*SUSTRACT 32 TO SET PROPER BIT IN SECOND REGISTER*/

		NVIC_ICER1 = (1 <<Copy_uint8IntNumber ); /*SET INTERRUPT BIT */
	}

	else{                    
                      		   /*IF YOU ARE HERE THEN YOU CHOOSE A WRONG POSITION NUMBER*/
 
		NVIC_ERROR = WRONG_POS_DISABLE_INTERRUPT ;    /* NVIC_ERROR VALUE INDICATE THE TYPE AND LOCATION OF ERROR */

	}
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 
/***********************************************************************************************************************************************************************************************************************************************************/

void NVIC_voidSetPendingFlag(uint8 Copy_uint8IntNumber){   /*SET PENDING FLAG OF A CERTAIN POSITION*/

	if (Copy_uint8IntNumber <= MAX_BIT_POS){  /*POSITION NUMBER LESS THAN 32*/
		
		      NVIC_ISPR0 = (1 <<Copy_uint8IntNumber); /*SET INTERRUPT BIT */
	}

	else if (Copy_uint8IntNumber <= MAX_POS_NUM){  /*POSITION NUMBER LESS THAN 59*/

		    Copy_uint8IntNumber = Copy_uint8IntNumber - MAX_REG_BITS ;  /*SUSTRACT 32 TO SET PROPER BIT IN SECOND REGISTER*/

		      NVIC_ISPR1 = (1 <<Copy_uint8IntNumber ); /*SET INTERRUPT BIT */
	}

	else{                 
                      		/*IF YOU ARE HERE THEN YOU CHOOSE A WRONG POSITION NUMBER*/

		NVIC_ERROR = WRONG_POS_SET_PEND ;     /* NVIC_ERROR VALUE INDICATE THE TYPE AND LOCATION OF ERROR */

	}
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 
/***********************************************************************************************************************************************************************************************************************************************************/

void NVIC_voidClearPendingFlag(uint8 Copy_uint8IntNumber){   /*CLEAR PENDING FLAG OF A CERTAIN POSITION NUMBER*/

	if (Copy_uint8IntNumber <= MAX_BIT_POS){   /*POSITION NUMBER LESS THAN 32*/

		NVIC_ICPR0 = (1 <<Copy_uint8IntNumber);   /*SET INTERRUPT BIT */

	}

	else if (Copy_uint8IntNumber <= MAX_POS_NUM){  /*POSITION NUMBER LESS THAN 59*/

		Copy_uint8IntNumber = Copy_uint8IntNumber - MAX_REG_BITS ; /*SUSTRACT 32 TO SET PROPER BIT IN SECOND REGISTER*/

		NVIC_ICPR1 = (1 <<Copy_uint8IntNumber );   /*SET INTERRUPT BIT */
	}

	else{                     /*IF YOU ARE HERE THEN YOU CHOOSE A WRONG POSITION NUMBER*/

		NVIC_ERROR = WRONG_POS_CLR_PEND ;       /* NVIC_ERROR VALUE INDICATE THE TYPE AND LOCATION OF ERROR */

	}
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 
/***********************************************************************************************************************************************************************************************************************************************************/

uint8 NVIC_voidGetActiveFlag(uint8 Copy_uint8IntNumber){      /*GET ACTIVE FLAG VALUE OF A CERAIN POSITION NUMBER */

	uint8 Local_uint8LocalResult ;                                     /*LOCAL VAR TO SAVE FLAG VALUE*/

	if (Copy_uint8IntNumber <= MAX_BIT_POS){         /*POSITION NUMBER LESS THAN 32*/

		    Local_uint8LocalResult =  GET_BIT(NVIC_IABR0,Copy_uint8IntNumber);    /*FLAG VALUE = Local_uint8LocalResult*/

	}
	else if (Copy_uint8IntNumber <= MAX_POS_NUM){  /*POSITION NUMBER LESS THAN 59*/

	  	 Copy_uint8IntNumber = Copy_uint8IntNumber - MAX_REG_BITS ;   /*SUSTRACT 32 TO SET PROPER BIT IN SECOND REGISTER*/

		    Local_uint8LocalResult =   GET_BIT(NVIC_IABR1,Copy_uint8IntNumber);    /*FLAG VALUE = Local_uint8LocalResult*/
	}

	else{                     /*IF YOU ARE HERE THEN YOU CHOOSE A WRONG POSITION NUMBER*/

		NVIC_ERROR = WRONG_POS_GET_ACT ;       /* NVIC_ERROR VALUE INDICATE THE TYPE AND LOCATION OF ERROR */

	}
	return Local_uint8LocalResult;    /*GET ACTIVE FLAG VALUE*/

}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 
/***********************************************************************************************************************************************************************************************************************************************************/

void NVIC_voidSetPriority( uint8 Copy_uint8IntID ,             /*PERIPHERAL POSITION NUMBER TO SELECT ITS PERIORITY*/
                           uint8 Copy_uint8GroupPriority ,     /*VARIABLE TO CHOOSE WHICH GROUP PERIPHERAL IS IN */
                           uint8 Copy_uint8SubGroupPriority,   /*VARIABLE TO CHOOSE WHICH SUB GROUP PERIPHERAL IS IN */
                           uint32 Copy_uint32Group )           /*SCB_AIRCR REGISTER VALUE TO CHOSE PRIORITY DISTRIBUTION*/
{

	uint8 Local_uint8Priority =  ( Copy_uint8SubGroupPriority | Copy_uint8GroupPriority << (( Copy_uint32Group - 0X05FA0300) / 256 ));   /*THIS EQUATION TO GET FOUR BITS REPRESENT GROUP AND SUB GROUP PRIORITY*/


	if( Copy_uint8IntID <= MAX_POS_NUM ){ /*Number of Position should not above 59 */

		NVIC_IPR[Copy_uint8IntID]= (Local_uint8Priority << 4 );  /*SHIFT Local_uint8Priority by 4 TO acces high 4 bits,low 4 bit is reversed*/

	}
	else{                    
                                          		/*IF YOU ARE HERE THEN YOU CHOOSE A WRONG POSITION NUMBER*/

		NVIC_ERROR = WRONG_POS_SET_PR;       /* NVIC_ERROR VALUE INDICATE THE TYPE AND LOCATION OF ERROR */
	}

	SCB_AIRCR = Copy_uint32Group; /*SET THE REGISTER TO NEW VALUE*/

} 
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 
 uint8 NVIC_voidGetGroupPriority    (uint8 Copy_uint8IntID ){
 
	 
 
	  uint8 Local_uint8Group_Priority;               /*Local Var To get IPR[Copy_uint8IntID] Value*/
 
        Local_uint8Group_Priority = NVIC_IPR[Copy_uint8IntID]; /*Get 8 bits--> high 4 bits represent priority bits , low 4 bit is re*/
   
	      Local_uint8Group_Priority = (Local_uint8Group_Priority >>4 );  /*Shift high 4bits to rigth*/
	 
	      Local_uint8Group_Priority = (Local_uint8Group_Priority >> 2 ); /*Shift Second 2bits to rigth to Get Group priority*/
	 
	     //SUB_GROUP_PRIORITY = (Local_uint8Priority & 0X03); /*AND OPERATION TO GET FIRST TWO BITS TO GET SUB PRIORITY*/
	 
 return Local_uint8Group_Priority ;  /*Get 4Bits of Software Priority*/
 }      
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 
/***********************************************************************************************************************************************************************************************************************************************************/
uint8 NVIC_voidGetSubPriority    (uint8 Copy_uint8IntID ){
 
	 
 
	  uint8 Local_uint8Sub_Priority;               /*Local Var To get IPR[Copy_uint8IntID] Value*/
 
        Local_uint8Sub_Priority = NVIC_IPR[Copy_uint8IntID]; /*Get 8 bits--> high 4 bits represent priority bits , low 4 bit is re*/
   
	      Local_uint8Sub_Priority = (Local_uint8Sub_Priority >>4 );  /*Shift high 4bits to rigth*/
	 	 
	      Local_uint8Sub_Priority = (Local_uint8Sub_Priority & 0X03); /*AND OPERATION TO GET FIRST TWO BITS TO GET SUB PRIORITY*/
	 
 return Local_uint8Sub_Priority ;  /*Get 4Bits of Software Priority*/
 }      
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																 

/*void Soft_Reset_Req(void)
{

	SCB_AIRCR =0x05FA0004 ;



}*/



/***********************************************************************************************************************************************************************************************************************************************************/
