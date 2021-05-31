#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface2.h"
#include "STK_Interface.h"
#include "NVIC_Interface.h"
#include "USART_Interface.h"
#include "CAN.h"
		
	
 int main (void)
 {

/*FOR BIT RATE 500KHZ , PRESCALE = 1, SJW = 0 ,SEG1 = 11 , SEG2 = 4 , SAMPLE PIONT AT 87.5 , BTR=  0x00140001 */	 
CAN_InitTypeDef        CAN_InitStruct         =	{ 1 , CAN_Mode_Normal   , 0 , 11 , 4, DISABLE , DISABLE , DISABLE , DISABLE , DISABLE , DISABLE } ;

CAN_FilterInitTypeDef  CAN_FilterInitStruct_1 = { 0x00600000 , 0x00600000 , CAN_FilterMode_IdMask ,  1  , CAN_FilterScale_32bit , CAN_Filter_FIFO0 , ENABLE}; // ID = 0X03 
CAN_FilterInitTypeDef  CAN_FilterInitStruct_2 = { 0x00400000 , 0x00400000 , CAN_FilterMode_IdList ,  2  , CAN_FilterScale_32bit , CAN_Filter_FIFO0 , ENABLE}; // ID = 0X02 
  
CanRxMsg   RxxMessage ;


		   RCC_InitysClock(); //Enable External Clock
			 RCC_VoidEnableClock(RCC_APB2_EN,2); //Enable APB2 bus Clock to PORTA

			 RCC_VoidEnableClock(RCC_APB2_EN,0); /* AFIO ENABLE */
			 RCC_VoidEnableClock(RCC_APB1_EN,25); /* CAN1 ENALE */

  //     NVIC_voidEnableInterrupt (CAN1_RX0);  // Enable interrupt for Reception 

	         GPIO_VoidSetPinDirection(GPIOA,PIN11 , INPUT_FLOATING);   
		       GPIO_VoidSetPinDirection(GPIOA,PIN12 , OUTPUT_2MHZ_AFPP); 


			 GPIO_VoidSetPinDirection(GPIOA,8,OUTPUT_2MHZ_PP); // config A8 as output
	 		 GPIO_VoidSetPinDirection(GPIOA,2,OUTPUT_2MHZ_PP); // config A8 as output
	
   CAN_VoidInit(  CAN1 , &CAN_InitStruct ) ; //Init can
	 
// CAN_VoidInterruptSet(CAN1, CAN_FMPIE0 , ENABLE) ; /*message pending interrupt*/
	
	  
	 CAN_VoidFilterSet( & CAN_FilterInitStruct_1 ); 
   CAN_VoidFilterSet( & CAN_FilterInitStruct_2 );
	
	
	
while(1)
{

 CAN_VoidReceive ( CAN1 , CAN_FIFO0 , &RxxMessage );	// check if there is a received message 

	
	

}
}
