/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
 
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "SYSTIMER_Interface.h"
#include "SYSTIMER_Config.h"
#include "SYSTIMER_Private.h"

/* Define Callback Global Variable */
static void(*STK_CallBack)(void);

/* Define Variable for interval mode */
static uint8 STK_uint8_Interval_Mode;




                                           /*Choosing the Clock*/

void STK_voidInit(void) {
	
 #if   STK_CLOCK_SOURCE == STK_AHB
	 
	           SET_BIT(STK->CTRL,STK_CLOCK); 
	 
#elif  STK_CLOCK_SOURCE == STK_AHB_DIV_8
	 
	           CLEAR_BIT(STK->CTRL,STK_CLOCK); 
 #endif        
					}
	

					                               /* Delay for aspecific Time */
					
void STK_voidSetBusyWait(uint32 copy_DelayValue){
	                           
	 	              STK->LOAD = copy_DelayValue; /*LOAD THE COUNTER VALUE*/
			            SET_BIT( STK->CTRL,STK_ENABLE); /*ENABLE STK*/
	                while(GET_BIT(STK->CTRL ,OVER_FLOW_FLAG) == 0){}
			            CLEAR_BIT( STK->CTRL,STK_ENABLE); /*DISABLE STK*/
									STK->LOAD  = 0; 
								  STK->Value = 0;
 }

 
 void STK_voidSetIntervalSingle  ( uint32 copy_DelayValue, void (*Copy_ptr)(void) ) /*Take Delay value and Function to be excuted name*/
{
	/* Load ticks to load register */
	STK -> LOAD = copy_DelayValue;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, STK_ENABLE);
	
	/* Save CallBack */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	STK_uint8_Interval_Mode = STK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, STK_INTERRUPT_ENABLE);
}
 
 
 void STK_voidSetIntervalPeriodic( uint32 copy_DelayValue, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	STK -> LOAD = copy_DelayValue;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, STK_ENABLE);
	
	/* Save CallBack */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	STK_uint8_Interval_Mode = STK_PERIOD_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, STK_INTERRUPT_ENABLE);
}


void STK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLEAR_BIT(STK->CTRL, STK_INTERRUPT_ENABLE);
	
	/* Disable Timer */
	CLEAR_BIT(STK->CTRL, STK_ENABLE);
	STK -> LOAD   = 0;
	STK -> Value  = 0;
}

uint32  STK_uint32GetElapsedTime(void)
{
	uint32 Local_uint32ElapsedTime;
	
	Local_uint32ElapsedTime = (STK -> LOAD) - (STK -> Value) ;
	
	return Local_uint32ElapsedTime;
}

uint32  STK_uint32GetRemainingTime(void)
{
	uint32 Local_uint32RemainTime;
	
	Local_uint32RemainTime = STK -> Value ;
	
	return Local_uint32RemainTime;
}
 
void SysTick_Handler(void)
{
	uint8 Local_uint8Temporary;
	
	if (STK_uint8_Interval_Mode == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLEAR_BIT(STK->CTRL,STK_INTERRUPT_ENABLE);
	
		/* Stop Timer */
		SET_BIT(STK->CTRL, 0);
		STK -> LOAD   = 0;
		STK -> Value  = 0;
	}
	
	/* Callback notification */
	STK_CallBack();
	
	/* Clear interrupt flag */
	Local_uint8Temporary = GET_BIT(STK->CTRL,OVER_FLOW_FLAG);
	
}
 
 
 
 
 
 