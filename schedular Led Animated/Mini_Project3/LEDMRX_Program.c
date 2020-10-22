/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:1/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "GPIO_interface.h"
#include "SYSTIMER_Interface.h"
#include "LEDMRX_Private.h"
#include "LEDMRX_Config.h"
#include "LEDMRX_Interface.h"

void LEDMRX_VoidInit(void){
	 
	for(uint8 L0 = 0 ; L0 <8 ;L0++){
	
	GPIO_VoidSetPinDirection(LEDMRX_ROW[L0],LEDMRX_COL_PIN[L0],OUTPUT_2MHZ_PP);
	}
	
	
	for(uint8 L0 = 0 ; L0 <8 ;L0++){
	
	
	GPIO_VoidSetPinDirection(LEDMRX_COL[L0],LEDMRX_COL_PIN[L0],OUTPUT_2MHZ_PP);
	}
	
}


void LEDMRX_VoidDisplay (uint8 *Copy_uint8Data){

		                    /*Disable All coloums*/		                      /*Enable Coloum 0*/
                          /*Enable Coloum 0*/

    for(uint8 L0 = 0 ; L0 <35 ;L0++){


							for(uint8 L1 = 0 ; L1 <8 ;L1++){
	
              DisableAllColoums();	 
	            SetRowValues(Copy_uint8Data[L1 + L0 ]);                                  /* Set Row Value one by one*/
	            GPIO_VoidSetPinValue(LEDMRX_COL[L1],LEDMRX_COL_PIN[L1],GPIO_LOW);
	            STK_voidSetBusyWait(3000);                                              /* Delay the Led*/
		
        		                               	}               
  	           DisableAllColoums();	
		 					STK_voidSetBusyWait(27500);                                              /* Delay the Led*/
							
					    }
	
	      }

	
 void DisableAllColoums(void){
	
	
	                /*Disable All coloums*/
		
		for(uint8 L0 = 0 ; L0 <8 ;L0++){
		
	GPIO_VoidSetPinValue(LEDMRX_COL[L0],LEDMRX_COL_PIN[L0],GPIO_HIGH);
		}	
	}



 void SetRowValues(uint8 Copy_uint8Value){

		uint8  Local_uint8GetBit;

								for(uint8 L2 = 0 ; L2 <8 ;L2++){

	
    Local_uint8GetBit = (GET_BIT(Copy_uint8Value,L2));
	  GPIO_VoidSetPinValue(LEDMRX_ROW[L2],LEDMRX_COL_PIN[L2],Local_uint8GetBit);
									
									


}

}








