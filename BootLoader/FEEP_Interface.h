/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:15/12/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef FEEP_INTERFACE_H
#define FEEP_INTERFACE_H


void Flags_Init  (void) ;  //Set Init values of Flags
void BL_MODE     (void) ;   // Activate BL mode before soft reset in app
void APP_MODE    (void) ;   // Activate app mode before soft reset in BL
void Change_CRC1 (u32 Copy_u32Newcrc1);   // Update CRC1 of new app1
void Change_CRC2 (u32 Copy_u32Newcrc2);   // Update CRC2 of new app2
u32 Read_Mode(void); //return current mode
u32 Read_Crc1(void); //return crc1 value
u32 Read_Crc2(void); //return crc2 value




#endif
