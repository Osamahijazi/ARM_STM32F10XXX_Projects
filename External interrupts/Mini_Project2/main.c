#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTIMER_Interface.h"
#include "EXTI_Interface.h"
#include "AFIO_Interface.h"
#include "NVIC_Interface.h"
# include "LED_DISPLAY.h"



void LED_void_ANIMATION1(void){
	
	
 for( uint8 K = 0 ; K < 8 ; K++){
		       DISPLAY_AllShiftLeft();
					STK_voidSetBusyWait(STK_DEALY_VALUE);
		}
 for(uint8 L = 0 ; L < 7 ; L++){
		       DISPLAY_AllShiftRight();
					STK_voidSetBusyWait(STK_DEALY_VALUE);
		}
	for(uint8 L1 = 0 ; L1 < 3 ; L1++){
	for(uint8 L2 = 0 ; L2 < 7 ; L2++){
		        DISPLAY_AllShiftLeft();
				  	STK_voidSetBusyWait(STK_DEALY_VALUE);
		}
	for(uint8 L3 = 0 ; L3 < 7 ; L3++){
		        DISPLAY_AllShiftRight();
					  STK_voidSetBusyWait(STK_DEALY_VALUE);

		}
		}


}

void LED_void_ANIMATION2(void){
	
			DISPLAY_HalfShiftRight();
}

void LED_void_ANIMATION3(void){
	
			DISPLAY_AllLedON();

}

                                                              
	int main (void){
	RCC_InitysClock();
	  
	/*ENABLE RCC FOR GPIOA */
	RCC_VoidEnableClock(RCC_APB2,RCC_GPIOA);
	/*ENABLE RCC FOR AFIO*/
	RCC_VoidEnableClock(RCC_APB2,RCC_AFIO);
	 /*ENABLE RCC FOR GPIOB*/
	RCC_VoidEnableClock(RCC_APB2,RCC_GPIOB);
	/*ENABLE RCC FOR GPIOC*/
	RCC_VoidEnableClock(RCC_APB2,RCC_GPIOC);
	
	 STK_voidInit(); /*Enable systick Timer*/
		
	 GPIO_VoidSetPinDirection(GPIOB,PIN0,INPUT_FLOATING);
	 GPIO_VoidSetPinDirection(GPIOB,PIN1,INPUT_FLOATING);
	 GPIO_VoidSetPinDirection(GPIOB,PIN2,INPUT_FLOATING);
	
	 NVIC_voidEnableInterrupt(EXTI0);
	 NVIC_voidEnableInterrupt(EXTI1);
	 NVIC_voidEnableInterrupt(EXTI2);

   EXTI_voidSignalLatch(LINE0,RISING);
   EXTI_voidSignalLatch(LINE1,RISING);
   EXTI_voidSignalLatch(LINE2,RISING);

   AFIO_VoidSetEXTIConfig( LINE0 , LINE_PINB );
	 AFIO_VoidSetEXTIConfig( LINE1 , LINE_PINB );
	 AFIO_VoidSetEXTIConfig( LINE2 , LINE_PINB );
				
		
	 EXTI0_voidSetCallBack(LED_void_ANIMATION1);
	 EXTI1_voidSetCallBack(LED_void_ANIMATION2);
	 EXTI2_voidSetCallBack(LED_void_ANIMATION3);
	 
	 
	 
		                     /*LEDS Init*/
	GPIO_VoidSetPinDirection(GPIOA,PIN0, OUTPUT_2MHZ_PP ); 
	GPIO_VoidSetPinDirection(GPIOA,PIN1, OUTPUT_2MHZ_PP );
	GPIO_VoidSetPinDirection(GPIOA,PIN2, OUTPUT_2MHZ_PP );
	GPIO_VoidSetPinDirection(GPIOA,PIN3, OUTPUT_2MHZ_PP );
	GPIO_VoidSetPinDirection(GPIOA,PIN4, OUTPUT_2MHZ_PP );
	GPIO_VoidSetPinDirection(GPIOA,PIN5, OUTPUT_2MHZ_PP );
	GPIO_VoidSetPinDirection(GPIOA,PIN6, OUTPUT_2MHZ_PP );
	GPIO_VoidSetPinDirection(GPIOA,PIN7, OUTPUT_2MHZ_PP );
	
	
				


	while(1){
		
		
		
		
		for( uint8 K = 0 ; K < 8 ; K++){
		
		       DISPLAY_AllShiftLeft();
					STK_voidSetBusyWait(STK_DEALY_VALUE);

		}
				

		for(uint8 L = 0 ; L < 7 ; L++){
		
			
		       DISPLAY_AllShiftRight();
					STK_voidSetBusyWait(STK_DEALY_VALUE);

		}
		
		
		for(uint8 L1 = 0 ; L1 < 3 ; L1++){
			
		
		
		for(uint8 L2 = 0 ; L2 < 7 ; L2++){
		
			
		        DISPLAY_AllShiftLeft();
				  	STK_voidSetBusyWait(STK_DEALY_VALUE);

		}
		
		
		for(uint8 L3 = 0 ; L3 < 7 ; L3++){
		
			
		        DISPLAY_AllShiftRight();
					  STK_voidSetBusyWait(STK_DEALY_VALUE);

		}
		
		
			
		
		}
		
		
		
		
		
		DISPLAY_HalfShiftRight();
		
		DISPLAY_AllLedON();
		
	  STK_voidSetBusyWait(STK_DEALY_VALUE * 10);

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	 

	 }
	 
	 }