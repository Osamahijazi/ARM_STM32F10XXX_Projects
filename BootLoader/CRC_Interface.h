/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:18/11/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef CRC_Interface_H
#define CRC_Interface_H
/***********************************************************************************/
                      /***FUNCTIONS PROTOTYPES***/
/***********************************************************************************/						
/************************************************************************************

*Name       :   CRC_VoidInit

*Description: * Function to set CRC peripheral 
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : void

*Output     : void

*Return     : void

****************************************************************************************/
void CRC_VoidInit(void);
/************************************************************************************

*Name       :   CRC_CalculateCRC_HW

*Description: * Function to get crc of input Data                
							
*Pre-Cond   :	crc is set				
							
*pos-Cond   : None

*Input      : input array and size

*Output     : CRC of that Data

*Return     : CRC of that Data
****************************************************************************************/
u32 CRC_CalculateCRC_HW   (const u32 * wordArray , const u8 arraySize); 
/************************************************************************************

*Name       :   CRC_CalculateCRC32_LKT

*Description: * Function to get crc of input Data using LKT table                
							
*Pre-Cond   :	crc is set				
							
*pos-Cond   : None

*Input      : input array and size

*Output     : CRC of that Data

*Return     : CRC of that Data
****************************************************************************************/
u32 CRC_CalculateCRC32_LKT(const u8 * byteArray  , const u8 arraySize); 
/************************************************************************************

*Name       :   CRC_CalculateCRC_HW_Rom

*Description: * Function to get crc of input Data using crc peripheral  of specific region in Rom               
							
*Pre-Cond   :	crc is set				
							
*pos-Cond   : None

*Input      :base adddress and numbers of words of the code

*Output     : CRC of that region in Rom

*Return     : CRC of that region in Rom
****************************************************************************************/
u32 CRC_CalculateCRC_HW_Rom (u32 Copy_u32BaseAddress, u32 Copy_u32WordNumber);   


#endif
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/
