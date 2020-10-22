/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:22/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "EXTI_Interface.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"



static void (*EXTI_CallBack[3])(void); 


                           /*iNITIONALIZATION THE CHOSEN lINE AND MODE*/

void EXTI_voidInit(void){


#if     EXTI_LINE   ==  LINE0
	      SET_BIT(EXTI->IMR,LINE0);
#elif   EXTI_LINE   ==  LINE1
	      SET_BIT(EXTI->IMR,LINE1);
#elif   EXTI_LINE   ==  LINE2
		    SET_BIT(EXTI->IMR,LINE2);
#elif   EXTI_LINE   ==  LINE3
		      SET_BIT(EXTI->IMR,LINE3);
#elif   EXTI_LINE   ==  LINE4
	      SET_BIT(EXTI->IMR,LINE4);
#elif   EXTI_LINE   ==  LINE5
	      SET_BIT(EXTI->IMR,LINE5);
#elif   EXTI_LINE   ==  LINE6
	      SET_BIT(EXTI->IMR,LINE6);
#elif   EXTI_LINE   ==  LINE7
	      SET_BIT(EXTI->IMR,LINE7);
#elif   EXTI_LINE   ==  LINE8
	      SET_BIT(EXTI->IMR,LINE8);
#elif   EXTI_LINE   ==  LINE9
	      SET_BIT(EXTI->IMR,LINE9);
#elif   EXTI_LINE   ==  LINE10
	      SET_BIT(EXTI->IMR,LINE10);
#elif   EXTI_LINE   ==  LINE11
	      SET_BIT(EXTI->IMR,LINE11);
#elif   EXTI_LINE   ==  LINE12
	      SET_BIT(EXTI->IMR,LINE12);
#elif   EXTI_LINE   ==  LINE13
	      SET_BIT(EXTI->IMR,LINE13);
#elif   EXTI_LINE   ==  LINE14
	      SET_BIT(EXTI->IMR,LINE14);
#elif   EXTI_LINE   ==  LINE15
	      SET_BIT(EXTI->IMR,LINE15);
	
#else  #error  "Wrong Mode and Line Choice"	
#endif
	    
#if     EXTI_MODE   ==  RISING
	SET_BIT( EXTI->RTSR , EXTI_LINE);
	
#elif   EXTI_MODE   ==  FALING
	SET_BIT( EXTI->FTSR , EXTI_LINE);
	
#elif   EXTI_MODE   ==  ON_CHANGE
	SET_BIT( EXTI->RTSR , EXTI_LINE);
	SET_BIT( EXTI->FTSR , EXTI_LINE);
	
#else  #error  "Wrong Mode and Line Choice"	
#endif	

}


                             /* Enable The Chosen InterruptLine*/

 void EXTI_voidEnableEXTI(uint8 Copy_uint8Line){
 
 
	 SET_BIT( EXTI->IMR,Copy_uint8Line);

 
 }
 
                             /* DISable The Chosen InterruptLine*/
 
 void EXTI_voidDisableEXTI(uint8 Copy_uint8Line){
 
	 CLEAR_BIT(EXTI->IMR,Copy_uint8Line);
 
 
 }
 

 
 void EXTI_voidSwTrigger(uint8 Copy_uint8Line){
 
 
 	 SET_BIT( EXTI->SWIER,Copy_uint8Line);

 
 }
 
                       /* Trigger The mode During THe RunTime*/

 
void EXTI_voidSignalLatch( uint8 Copy_uint8Line , uint8 Copy_uint8Mode){

	switch(Copy_uint8Mode)

	          {
							
		           case RISING       :  	SET_BIT( EXTI->RTSR , Copy_uint8Line);   break;
		           case FALING       :  	SET_BIT( EXTI->FTSR , Copy_uint8Line);   break;
		           case ON_CHANGE    :  	SET_BIT( EXTI->RTSR , Copy_uint8Line);
	                                    SET_BIT( EXTI->FTSR , Copy_uint8Line);   break;                       							

						}
						
						
		    SET_BIT(EXTI->IMR,Copy_uint8Line);
}


void EXTI0_voidSetCallBack(void (*ptr)(void)){


EXTI_CallBack[0] = ptr;   /*ptr piont to the function1 to be excuted*/

}

void EXTI1_voidSetCallBack(void (*ptr)(void)){        /*EXTI1 CALL BACK FUNCTION*/

EXTI_CallBack[1] = ptr;


}  
 void EXTI2_voidSetCallBack(void (*ptr)(void)){  /*EXTI2 CALL BACK FUNCTION*/
	 
EXTI_CallBack[2] = ptr;
	 
 }
 
                                                    /*ISR OF EXTERNAL INTERRUPTS*/
void  EXTI0_IRQHandler(void){

	 EXTI_CallBack[0]();
	
	SET_BIT(EXTI->PR,LINE0); /* Clear Pending Bit*/
	

}

void  EXTI1_IRQHandler(void){

	 EXTI_CallBack[1]();
	
	SET_BIT(EXTI->PR,LINE1); /* Clear Pending Bit*/
	
}

void  EXTI2_IRQHandler(void){

	 EXTI_CallBack[2]();
	
	SET_BIT(EXTI->PR,LINE2); /* Clear Pending Bit*/
	

}
