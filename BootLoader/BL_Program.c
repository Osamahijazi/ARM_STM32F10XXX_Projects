//***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:18/10/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "BL_Interface.h"
#include "BL_Config.h"
#include "BL_Private.h"
/* Data Array to store record one by one*/
u16 Data[100] = {0};
/*veritfy Base Array of flash*/
u32 Address= 0x08000000;

u8 AsciToHex(u8 Copy_u8Asci)
{
	// local var to return result of format
	u8 Result;
	// convert ascii format to hexa format to flash it 
	if ( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		/*0 TO 9*/
		Result = Copy_u8Asci - 48;
	}

	else
	{
		/*A TO F*/
		Result = Copy_u8Asci - 55;
	}

	return Result;
}


void ParseData(u8* Copy_u8BufData)
{
	//
	u8 DigitLow,DigitHigh,CC,i;
	
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	
	u8 DataCounter = 0;

	/* Get Character Count */
	DigitHigh = AsciToHex (Copy_u8BufData[1]);
	DigitLow  = AsciToHex (Copy_u8BufData[2]);
	CC        = (DigitHigh<<4) | DigitLow ;

	/* Get Address */
	DataDigit0 = AsciToHex (Copy_u8BufData[3]);
	DataDigit1 = AsciToHex (Copy_u8BufData[4]);
	DataDigit2 = AsciToHex (Copy_u8BufData[5]);
	DataDigit3 = AsciToHex (Copy_u8BufData[6]);

	/* Clear Low Part of Address */
	Address = Address & 0xFFFF0000;
	Address = Address | (DataDigit3) | (DataDigit2 << 4) | (DataDigit1 << 8) | (DataDigit0<<12);

/*store received Data in data Array*/
	for (i=0;i<CC/2; i++)
	{
		DataDigit0 = AsciToHex (Copy_u8BufData[4*i+9 ]);
		DataDigit1 = AsciToHex (Copy_u8BufData[4*i+10]);
		DataDigit2 = AsciToHex (Copy_u8BufData[4*i+11]);
		DataDigit3 = AsciToHex (Copy_u8BufData[4*i+12]);
    /*alignment Data in Array elements */
		Data[DataCounter] = (DataDigit3 << 8) | (DataDigit2 << 12) | (DataDigit1) | (DataDigit0<<4);
		DataCounter++;
	}
  /*flash the Data element by element*/
	MFPEC_u8ProgramFlash(Address,Data,CC/2);
}

/* if you configure base address use this function*/
void ParseUpperAddress(u8* Copy_u8BufData)
{

//	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
//
//	/* Get Address */
//	DataDigit0 = AsciToHex (Copy_u8BufData[3]);
//	DataDigit1 = AsciToHex (Copy_u8BufData[4]);
//	DataDigit2 = AsciToHex (Copy_u8BufData[5]);
//	DataDigit3 = AsciToHex (Copy_u8BufData[6]);
//
//	/* Clear Low Part of Address */
//	Address = Address & (u32)0x0000FFFF;
//	Address = Address | (u32)((u32)(DataDigit3 << 28) | (u32)(DataDigit2 << 24) | (u32)(DataDigit1 << 20) | (u32)(DataDigit0 << 16));

}

void Parser_voidParseRecord(u8* Copy_u8BufData)
{
	switch (Copy_u8BufData[8])
	{
	case '0': ParseData(Copy_u8BufData); break;
	case '4': ParseUpperAddress(Copy_u8BufData); break;
	}
}
