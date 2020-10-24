/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:16/10/2020***********************************/
/***********version:1***************************************/
/*********Description:FLASH DRIVER***********************/
/***********************************************************/


#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

#include "STD_TYPES.h"

/*
Description: WRITE 16 BITS AT A TIME
Input: ADDRESS AND DATA TO BE WRITTEN                
output: ERROR CHECK TO DATA FLASHED BY READING ITS ADDRESS
*/
uint8 FPEC_u8WriteHalfWord( uint32 Copy_uint32Address,
                            uint16 Copy_uint16Data    );
/* 
 Description: ERASE PAGE
Input: Number of THE PAGE                
output: CHECK ERROR
*/
void FPEC_voidErasePage( uint8 Copy_uint8PageNumber );
/* 
Description: ERASE ALL PAGES
Input: VOID              
output:void
*/
void FPEC_voidMassErase(void);
/* 
Description: ERASE FIXED NUMBER PAGES
Input: FIRST OAGE AND LAST PAGE              
output:void
*/
void FPEC_voidErasPages(uint8 Copy_uint8FirstPage,
                        uint8 Copy_uint8LastPage    );
/* 
Description: Write 2 byte data at once
Input: address ,data and length of data              
output:void
*/
void FPEC_voidFlashWrite(uint32  Copy_u32Address, 
                         uint16* Copy_u16Data  , 
                         uint8   Copy_u8Length     );

void FPEC_voidEraseAppArea(void); 





#endif
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/
