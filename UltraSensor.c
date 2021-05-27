/*******************************************************************************
**  FILENAME     : UltraSensor.c                         			                **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2021-05-24                                                 **
**                                                                            **
**  AUTHOR       : osamahijazi	                                              **
**                                                                            **
*******************************************************************************/
/*****************************************************************************************/
/*                                   Include Headers                                     */
/*****************************************************************************************/
#include "BIT_MATH.h"
#include "Std_Types.h"
/*****************************************************************************************/
/*                                Include modules Headers                                */
/*****************************************************************************************/
#include "UltraSensor_Interface.h"
#include "UltraSensor_Private.h"
#include "UltraSensor_Cfg.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
/*****************************************************************************************/
/*                                Local Data Types                                       */                              
/*****************************************************************************************/                         

/*****************************************************************************************/
/*                              Local Varaible Definition                                */
/*****************************************************************************************/
 volatile uint8   Global_uint8TimerFlag = 0 ;
/*****************************************************************************************/
/*                               Function Definition                                     */
/*****************************************************************************************/
void HCSR04_VoidInit(void)
{
	             /********** Enable UltraSensor PINS***********/
    GPIO_VoidSetPinDirection(TRIGGER_PORT,TRIGGER_PIN , OUTPUT_MODE); 
    GPIO_VoidSetPinDirection(ECHO_PORT,ECHO_PIN , INPUT_MODE); 
    GPIO_VoidSetPinValue(ECHO_PORT , ECHO_PIN , ECHO_PULLDOWN); 
  
}
/***********************END OF FUNCTION************************/																                                  																 																
uint8 HCSR04_uint8ReadDistance(void)
{
	/*
	  Step 1 :*Send Trigger Pulse 
    */
     /*Local variables to get Duration of echo pulse & measured Distance*/
    static uint32  Local_uint32Duration = 0 ; 
    static uint8   Local_uint8Distance  = 0 ;
               /*Reset Trigger Pin before send pulse*/
    GPIO_VoidSetPinValue(TRIGGER_PORT , TRIGGER_PIN , LOW );
    STK_voidSetBusyWait( 2 , TIME_US );	
                     /*Send Trigger pulse*/
    GPIO_VoidSetPinValue(TRIGGER_PORT , TRIGGER_PIN , HIGH );
    STK_voidSetBusyWait( 15 , TIME_US );	
    GPIO_VoidSetPinValue(TRIGGER_PORT , TRIGGER_PIN , LOW  );
    /*
	  Step 2 :*wait until high echo pulse .
              *wait until low  echo pulse .
              *calculate the time interval .
              *dont wait more than configrable time interval.			  
    */
                       	/*Set time interval and start timer */ 
    STK_voidSetIntervalSingle( TIMEOUT_INTERVAL , TIME_US , HCSR04_VoidCallBack) ; 
                 /*wait echo pin to be High with limited time out*/
	while( GPIO_VoidGetPinValue(GPIOA,PIN9) == 0 )
	{			  /* incase of interrupt happened*/
	    if(Global_uint8TimerFlag == 1) 
        {	       /*return Distance = zero indicate that signal was not returned*/
		    Local_uint8Distance = OUT_OF_RANGE ;
            return Local_uint8Distance ; 	
        }			
   }
                       	/*Set time interval again and start timer */ 
    STK_voidSetIntervalSingle( TIMEOUT_INTERVAL , TIME_US , HCSR04_VoidCallBack) ; 
                    /*wait echo pin to be Low with limited time out*/
	while( GPIO_VoidGetPinValue(GPIOA,PIN9) == 1 )
	{			          /* incase of interrupt happened*/
	    if(Global_uint8TimerFlag == 1) 
		{	   /*return Distance = zero indicate that signal was not returned*/
	       Local_uint8Distance = OUT_OF_RANGE ;
           return Local_uint8Distance ; 	
        }			
    }
	                      /*Get time between two pulses in micro*/
    Local_uint32Duration = STK_uint32GetElapsedTime(TIME_US ) ; 	
	STK_voidStop();
	               /*Calculate the distance by devide pulse duration by 58*/
	Local_uint8Distance = (uint8)(Local_uint32Duration / 58 ) ;
	                    /*Return measured Distance by the Sensor*/
	return Local_uint8Distance ;
	                   
}
/***********************END OF FUNCTION************************/																                                  																 																
void HCSR04_VoidCallBack(void)
{
          /*Indicate that time is out and no echo signal has returned*/
    Global_uint8TimerFlag = 1 ; 

}
/***********************END OF FUNCTION************************/																                                  																 																