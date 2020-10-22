/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "LED_DISPLAY.h"
#include "SYSTIMER_Interface.h"


 static uint8 COUNTER1   ;
 static uint8 COUNTER2   ; 
 
 
 
 
 
void DISPLAY_AllShiftLeft(void){

	
		          GPIOA_ODR = ((GPIOA_ODR & 0X11111100)|(1 << COUNTER1));
	
			      	COUNTER1 = COUNTER1 + 1 ;
	
           if( COUNTER1 == 8){
				
				      COUNTER1 = 1 ;
					
			  	}
}


 void DISPLAY_AllShiftRight (void){
 				 
				        GPIOA_ODR =((GPIOA_ODR & 0X11111100)|( 0X00000040 >> COUNTER2));
	 
					 	    COUNTER2 = COUNTER2 + 1 ;	
	 
	            if( COUNTER2 == 7){
				
				COUNTER2 = 0;
					
				}
 }

 
  void DISPLAY_HalfShiftRight(void){
 		GPIOA_ODR = ((GPIOA_ODR & 0X11111100)|0X00000000);
		STK_voidSetBusyWait(STK_DEALY_VALUE);
		
			for(uint8 L2 =0 ; L2 < 4; L2++){

    GPIOA_ODR =((GPIOA_ODR & 0X11111100)|(0X00000018));
		STK_voidSetBusyWait(STK_DEALY_VALUE);
    GPIOA_ODR =((GPIOA_ODR & 0X11111100)|(0X00000024));
	  STK_voidSetBusyWait(STK_DEALY_VALUE);
    GPIOA_ODR =((GPIOA_ODR & 0X11111100)|(0X00000042));
		STK_voidSetBusyWait(STK_DEALY_VALUE);
    GPIOA_ODR =((GPIOA_ODR & 0X11111100)|(0X00000081));
		STK_voidSetBusyWait(STK_DEALY_VALUE);
		GPIOA_ODR =((GPIOA_ODR & 0X11111100)|(0X00000042));
		STK_voidSetBusyWait(STK_DEALY_VALUE);
		GPIOA_ODR =((GPIOA_ODR & 0X11111100)|(0X00000024));
	  STK_voidSetBusyWait(STK_DEALY_VALUE);
			}
			
		GPIOA_ODR =((GPIOA_ODR & 0X11111100)|(0X00000018));
		STK_voidSetBusyWait(STK_DEALY_VALUE);

 }

 
  void DISPLAY_AllLedON(void){
		GPIOA_ODR = ((GPIOA_ODR & 0X11111100)|0X00000000);
	  STK_voidSetBusyWait(STK_DEALY_VALUE);	
		
	    for(uint8 L3 =0 ; L3 < 4; L3++){

		GPIOA_ODR = ((GPIOA_ODR & 0X11111100)|0X000000FF);
	  STK_voidSetBusyWait(STK_DEALY_VALUE);	
		GPIOA_ODR = ((GPIOA_ODR & 0X11111100)|0X00000000);
	  STK_voidSetBusyWait(STK_DEALY_VALUE);	
		
	           }
	}

 
 
 
 
 
 
 
 
 

