/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:15/12/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FEEP_Interface.h"
#include "FEEP_Private.h"
#include "FEEP_Config.h"
#include "FPEC_Interface.h"
                                     /*Definition of Init values*/
u16 BL        = SAVED_BL    ;
u16 APP       = SAVED_APP   ;
u16 APP1_CRC  = SAVED_CRC1 ;
u16 APP2_CRC  = SAVED_CRC2 ;
void Flags_Init(void)         //Set Init values of Flags
{

//first we erase last page 1K
FPEC_voidFlashPageErase(LAST_PAGE);
//write Init values that locate in config file
FPEC_voidFlashWrite( CRC1_ADD ,  & APP1_CRC ,LENGTH );
FPEC_voidFlashWrite( CRC2_ADD ,  & APP2_CRC ,LENGTH) ;
FPEC_voidFlashWrite( MODE_ADD ,  & BL       ,LENGTH) ; // make BL as Init mode

}
void BL_MODE (void)    // Activate BL mode before soft reset in app
{
	
// Local Var to store old valu es
u32 OLD_CRC1,OLD_CRC2 ;
OLD_CRC1 = CRC1 ;
OLD_CRC2 = CRC2 ;
// earse all 1k 
FPEC_voidFlashPageErase(LAST_PAGE);
//write old values	
FPEC_voidFlashWrite(CRC1_ADD ,&OLD_CRC1,LENGTH);
FPEC_voidFlashWrite(CRC2_ADD ,&OLD_CRC2,LENGTH);
//write new value	
FPEC_voidFlashWrite(MODE_ADD ,&BL      ,LENGTH);
	
}   
void APP_MODE(void)    // Activate app mode before soft reset in BL
{
	
// Local Var to store old values	
u32 OLD_CRC1,OLD_CRC2 ;
OLD_CRC1 = CRC1 ;
OLD_CRC2 = CRC2 ;
// earse all 1k 
FPEC_voidFlashPageErase(LAST_PAGE);
//write old values	
FPEC_voidFlashWrite(CRC1_ADD,&OLD_CRC1,LENGTH);
FPEC_voidFlashWrite(CRC2_ADD,&OLD_CRC2,LENGTH);
//write new value	
FPEC_voidFlashWrite(MODE_ADD,&APP     ,LENGTH);

}
void Change_CRC1(u32 Copy_u32Newcrc1)   // Update CRC1 of new app
{
// Local Var to store old values
u32 curent_mode,OLD_CRC2 ;
OLD_CRC2 = CRC2 ;
curent_mode = MODE ;
// erase all 1k
FPEC_voidFlashPageErase(LAST_PAGE);
//write old values
FPEC_voidFlashWrite(MODE_ADD,&curent_mode,LENGTH);
FPEC_voidFlashWrite(CRC2_ADD,&OLD_CRC2,LENGTH);
//write new value
FPEC_voidFlashWrite(CRC1_ADD,&Copy_u32Newcrc1,LENGTH);

}

void Change_CRC2(u32 Copy_u32Newcrc2)   // Update CRC2 of new app
{
// Local Var to store old values
u32 curent_mode,OLD_CRC1 ;
OLD_CRC1 = CRC1 ;
curent_mode = MODE ;
// erase all 1k
FPEC_voidFlashPageErase(LAST_PAGE);
//write old values
FPEC_voidFlashWrite(MODE_ADD,&curent_mode,LENGTH);
FPEC_voidFlashWrite(CRC1_ADD,&OLD_CRC1   ,LENGTH);
//write new value
FPEC_voidFlashWrite(CRC2_ADD,&Copy_u32Newcrc2,LENGTH);

}

u32 Read_Mode(void)
{
	return MODE ;
}
u32 Read_Crc1(void)
{
	return CRC1 ;

}
u32 Read_Crc2(void)
{
	return CRC2 ;

}
