#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_Interface.h"

int main (void){

		     RCC_voidInitSysClock(); //Enable External Clock

			 RCC_voidEnableClock(RCC_APB2,2); //Enable APB2 bus Clock to PORTB
			 MGPIO_voidSetPinMode(PORTA,PIN3,GPIO_OUTPUT_2MHZ_PP); // Config A3 as output


		while(1){
			
		       MGPIO_voidSetPinValue(PORTA,PIN3,GPIO_LOW); // Set high to A3			
			   STK_voidSetBusyWait(1000000);
			 
		       MGPIO_voidSetPinValue(PORTA,PIN3,GPIO_HIGH); // Set high to A3
		       STK_voidSetBusyWait(1000000);

		}

}




