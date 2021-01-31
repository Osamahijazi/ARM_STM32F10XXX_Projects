#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface2.h"
#include "FPEC_interface.h"
#include "BL_Interface.h"
#include "FEE2_Interface.h"
#include "STK_interface.h"
#include "Branch_Interface.h"
u32 osama ;
int main(void)
{	
	
BR_VoidIinit(); //Init branch 
	
//FEEP_voidUpdateFlag(SYS_MODE_ADD , 0X01); // bl mode to resent the image
	
osama = BR_CheckAPPCrc();
	
osama =	BR_CheckBackupCrc();
	
	
	
if( CURRENT_MODE == BL_MODE  ) 
{
	                                                   //Flag is BL MODE
BR_VoidJumpToBL();
	
}

else      // APP flag is set	
{
	
//	FEEP_voidUpdateFlag(SYS_MODE_ADD , 0X00); // bl mode to resent the image

			
 BR_VoidJumpToApp(); //check app
					
}
			
while(1)
{
	
	
  /*No thing to do*/

}
}

