#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FPEC_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_Interface.h"
#include "UART_interface.h"
#include "BL_Interface.h"

void Parser_voidParseRecord(u8* Copy_u8BufData);

volatile u8  u8RecBuffer[100]   ;
volatile u8  u8RecCounter    = 0;
volatile u8  u8TimeOutFlag   = 0;
volatile u16 u16TimerCounter = 0;
volatile u8  u8BLWriteReq    = 1;

typedef void (*Function_TYPE)(void);

Function_TYPE addr_to_call = 0;

void func(void)
{

// Define SCB_VTOR to define stack pionter address	
#define SCB_VTOR   *((volatile u32*)0xE000ED08)
  // Init stack pionter
	SCB_VTOR = 0x08001000;

  // Jumo to start of entry piont
	addr_to_call = *(Function_TYPE*)(0x08001004);
 // jump to main function
	addr_to_call();

}

	int main (void){
		
		
		u8 Local_u8RecStatus;
	
		
	  MRCC_voidInitSysClock();
	
	  MRCC_voidEnableClock(RCC_APB2,RCC_IOPA_PERIPHERAL);

		MRCC_voidEnableClock(RCC_APB2,RCC_USART1_PERIPHERAL);
 
	 	MRCC_voidEnableClock(RCC_AHB,RCC_FLITF_PERIPHERAL);
		
    	
	  MUART_voidInit();
	
    MSTK_voidInit();

	  MSTK_voidSetIntervalSingle(15000000,func);		
		 

while(u8TimeOutFlag == 0)
	{

		Local_u8RecStatus = MUART_u8ReceiveSynch(&(u8RecBuffer[u8RecCounter]) );
		
		if (Local_u8RecStatus == 1)
		{
			MSTK_voidStopInterval();

			if(u8RecBuffer[u8RecCounter] == '\n')
			{
				if (u8BLWriteReq == 1)  //erase all app pages before flashing
				{
					MFPEC_voidEraseAppArea();
					
					u8BLWriteReq = 0;
				}
				
				/* Parse */
				
				Parser_voidParseRecord(u8RecBuffer); // flash buffer has received
				
				MUART_voidTransmitSynch("ok");  // send ok to transmitter to sent the next record
				
				u8RecCounter = 0;//Begin the buffer to base offset
			}

			else
			{
				u8RecCounter ++ ;
			}

	  MSTK_voidSetIntervalSingle(15000000,func);		
		}

		else
		{

		}
	}
}
