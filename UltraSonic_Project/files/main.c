#include "BIT_MATH.h"
#include "Std_Types.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_Interface.h"
#include "Rte_DistanceSensor.h"
#include "Rte_Buzzer.h"

 volatile uint8   Global_Distance  = 0 ;
 uint8 status = 0 ;
 int main (void)
 { 
	 
 /*******************  RCC SOURCE CLOCK  **********/
  RCC_VoidInitSysClock(); 
 /*******************  PORTA ENABLE CLOCK  ********/
  RCC_VoidEnableClock(RCC_APB2_EN,RCC_GPIOA); 
 /********************** STK init *****************/
  STK_voidInit(); 
 /*******************  UltraSensor Init  **********/
	HCSR04_VoidInit();
 /*******************  Buzzer Init  *******************/
	ALarm_VoidInit();
	 
  while(1)
  { 
		
		DistanceSensor_MainFunction();
		Buzzer_MainFunction();
		
		/*
		
		status = Rte_Read_Buzzer_DistanceData(&Global_Distance);
		
		if( Global_Distance <= 20 )
	   { 
		     status =  Alarm_uint8SetPulse() ;
	   }
		/*
     status = HCSR04_uint8ReadDistance(&Global_Distance);
	  if( Global_Distance <= 20  && Global_Distance != 0 )
	   { 
		     status =  Alarm_uint8SetPulse() ;
	   }
		*/
   }  
}
