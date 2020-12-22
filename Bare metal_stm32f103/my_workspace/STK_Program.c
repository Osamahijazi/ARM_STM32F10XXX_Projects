/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_Interface.h"
#include "STK_Config.h"
#include "STK_Private.h"
/***********************************************************************************************************************************************************************************************************************************************************/
static void(*STK_CallBack)(void);  
static uint8 STK_Interval_Mode; /*VARIABLE TO CHECK INTERVAL MODE*/
/***********************************************************************************************************************************************************************************************************************************************************/
void STK_voidInit(void) {                 /*ADJUST STK CLOCK CONFIGURATIONS*/
	
 #if   STK_CLOCK_SOURCE == STK_AHB               /*STK INPUT CLOCK CHIOCES */	 
	           SET_BIT(STK->CTRL,STK_CLK);   /*STK CLOCK EQUAL TO AHB BUS CLOCK*/ 
	
#elif  STK_CLOCK_SOURCE == STK_AHB_DIV_BY_8	 
	           CLEAR_BIT(STK->CTRL,STK_CLK); /*STK CLOCK EQUAL TO AHB BUS CLOCKDEVIDED BY 2*/
	
 #endif        
					}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/										                              				
void STK_voidSetBusyWait(uint32 copy_DelayValue){      /*DELAY FUNCTION USING STK*/
	                           
	     STK->LOAD = copy_DelayValue; /*LOAD THE COUNTER VALUE BY US */
	
	    SET_BIT( STK->CTRL,STK_EN); /*ENABLE STK*/
	
	     while(WAIT_COUNT_FINISH){} /*WAIT TILL STK CURRENT VALUE COUNTER REACH TO ZERO*/
										
			  CLEAR_BIT( STK->CTRL,STK_EN); /*DISABLE STK*/
										
				                       /*WE PUT ZERO IN RELOAD AND CURRENT REGISTER TO BE READUY FOR NEXT DELAY */
			STK->LOAD  = 0;    
			STK->Value = 0;   
				 
 }
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/										                              				 
 void STK_voidSetIntervalSingle  ( uint32  copy_DelayValue,  /*AYNCHRONOUS FUNCTION THAT EXCUTE A CERTAIN FUNCTION AFTER A CERTAIN TIME USING ONE SHOT INTERRUPT*/
                                	 void  (*Copy_ptr)(void) ){ 
																		 
	STK -> LOAD = copy_DelayValue;           /*LOAD CURRENT COUNTER BY INPUT VALUE */
																			 
	SET_BIT(STK->CTRL, STK_EN);          /*SET ENABLE BIT TO BEGIN COUNTING*/
	
	STK_CallBack = Copy_ptr;                 /*LOAD INPUT FUNCTION ADDRESS TO GLOBAL PIONTER TO EXCUTE IN ISR*/
	
	STK_Interval_Mode = STK_SINGLE_INTERVAL;       /*SET MODE TO SINGLE */
	
	SET_BIT(STK->CTRL, STK_INT_EN);          /*ENBLE INTERRUPT BIT*/
}
/******************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/										                              				 
 void STK_voidSetIntervalPeriodic( uint32  copy_DelayValue,
                                	 void  (*Copy_ptr)(void)  ){
																		 
	STK -> LOAD = copy_DelayValue;             /*LOAD CURRENT COUNTER BY INPUT VALUE */
	                                         
	SET_BIT(STK->CTRL, STK_EN);            /*SET ENABLE BIT TO BEGIN COUNTING*/
	                                         
	STK_CallBack = Copy_ptr;                   /*LOAD INPUT FUNCTION ADDRESS TO GLOBAL PIONTER TO EXCUTE IN ISR*/
	
	STK_Interval_Mode = STK_PERIOD_INTERVAL;   /*SET MODE TO PERIODIC */
	
	SET_BIT(STK->CTRL, STK_INT_EN);      /*ENBLE INTERRUPT BIT*/
}
/******************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/										                              				 
void STK_voidStopInterval(void)          /*STOP PERIODIC INTERRUPT*/
{
	
	CLEAR_BIT(STK->CTRL, STK_INT_EN);      /*CLEAR ENABLE INTERRUPT BIT TO STOP*/
	
	CLEAR_BIT(STK->CTRL, STK_EN);                 /*CLEAR ENABLE TIMER BIT TO STOP*/
	
	STK -> LOAD   = 0;
	STK -> Value  = 0;
}
/******************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/										                              				 
uint32  STK_uint32GetElapsedTime(void){    /*GET ELAPSED TIME FROM THE BEGINING OF COUNTING*/
	
	uint32 Local_uint32ElapsedTime;       /*VARIABLR TO SAVE ELAPSED TIME*/
	
	Local_uint32ElapsedTime = (STK -> LOAD) - (STK -> Value) ;  /*TIME OUT = FULLTIME  - REMAINING TIME*/
	
	return Local_uint32ElapsedTime;   
}
/******************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/										                              				 
uint32  STK_uint32GetRemainingTime(void){
	
	uint32 Local_uint32RemainTime;       /*VARIABLR TO SAVE REMAINIG TIME*/
	
	Local_uint32RemainTime = STK -> Value ;  /*REMANING TIME EQUAL TO CURRENT REGISTER VALUE*/
	
	return Local_uint32RemainTime;
}
/******************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/										                              				  
void SysTick_Handler(void)                               /*STK HANDLER*/
{
	
	if (STK_Interval_Mode == STK_SINGLE_INTERVAL)             
		                              /*IF YOU ARE HERE THEN IT SINGLE SHOT INTERRUPY*/
	 {
		CLEAR_BIT(STK->CTRL,STK_INT_EN);  /*CLEAR ENABLE INTERRUPT BIT TO STOP*/
	
		SET_BIT(STK->CTRL,STK_EN);        /*CLEAR ENABLE TIMER BIT TO STOP*/
			                       
		STK -> LOAD   = 0;
		STK -> Value  = 0;
		
	}
		STK_CallBack();             /* CALL BACK TO THE FUNCTION SAVED IN STK PIONTER*/
	
	
	
}
/******************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/										                              				  