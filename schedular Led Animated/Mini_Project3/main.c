#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTIMER_Interface.h"
#include "OS_Interface.h"
#include "LEDMRX_Interface.h"


		void Toggle_Led1  (void);
		void Toggle_Led2  (void);
		void Toggle_Led3  (void);

                                                                  /*Data to be Animated*/


	 int main (void){
		 
	RCC_InitysClock();
	
	/*ENABLE RCC FOR GPIOA*/
	RCC_VoidEnableClock(RCC_APB2,2);
	
	 /*ENABLE RCC FOR GPIOB*/
	RCC_VoidEnableClock(RCC_APB2,3);
	
	/*ENABLE RCC FOR GPIOC*/
	RCC_VoidEnableClock(RCC_APB2,4);
		                               /*PINS INIT*/
	GPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_2MHZ_PP);
		 
   OS_voidCreateTask (PRIORITY_ZERO,Periodicity_TASK_ZERO,Toggle_Led1,DELAY_ZERO);
   OS_voidCreateTask (PRIORITY_ONE ,Periodicity_TASK_ONE ,Toggle_Led2,DELAY_ONE );
   OS_voidCreateTask (PRIORITY_TWO ,Periodicity_TASK_TWO ,Toggle_Led3,DELAY_TWO );
		 
	// OS_voidKillTask(PRIORITY_ZERO);
	 //OS_voidKillTask(PRIORITY_ONE);
		 	
   OS_voidStart();  /*Begin The Scheduler*/


		while(1){
			

	
		}
	}
		void Toggle_Led1 (void){
		
			static uint8 Local_uint8Pin0 ;
	  	TOGGLE_BIT(Local_uint8Pin0,0);
		 GPIO_VoidSetPinValue(0,0,Local_uint8Pin0);	
			
		}
		
		void Toggle_Led2 (void){
		
			static uint8 Local_uint8Pin1 ;
	  	TOGGLE_BIT(Local_uint8Pin1,0);
		 GPIO_VoidSetPinValue(0,1,Local_uint8Pin1);	
			
		}
		
		void Toggle_Led3 (void){
		
			static uint8 Local_uint8Pin2 ;
	  	TOGGLE_BIT(Local_uint8Pin2,0);
		 GPIO_VoidSetPinValue(0,2,Local_uint8Pin2);	
			
		}
		
		





	