#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface2.h"
#include "FPEC_interface.h"
#include "BL_Interface.h"
#include "FEE2_Interface.h"
#include "STK_interface.h"
#include "Branch_Interface.h"

int main(void)
{
	
BR_VoidIinit(); //Init branch 

if( MODE == BL_MODE  ) 
{
	                                                   //Flag is BL MODE
BL_VoidInit(); //Init BL
	
BL_VoidACK(); //BL Talk to Node

BL_Erase_Inactive_APP(); // BL specify the Image to erase	
	
BL_VoidRec();		//BL Receive new Image		
							
}

else      // APP flag is set	
{

BR_CheckCorruptFlags();	// check if any file is currupted	
	
BR_DefResetVect(); // Define reset vector of each app 
	
BR_Check_App_Exist  (); //check app
	
BR_Check_Backup_Exist(); // check backup
	
					
}
			
while(1)
{
	
  /*No thing to do*/

}
}

