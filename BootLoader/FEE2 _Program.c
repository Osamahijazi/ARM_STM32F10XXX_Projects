/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:15/12/2020**********************************/
/***********version:1***************************************/
/***********Name:Flash Emulator EPROM***********************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FEE2_Interface.h"
#include "FEE2_Private.h"
#include "FEE2_Config.h"
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
// u16 WORD_NUMBERS = (u16)(((u32)(Last_Address-First_Address)) / 4) ; //number of words in determined region

void FEEP_voidAddFlag(u32 Copy_u32Address, u32 Copy_u32Data) // to save a new flag 
{

	FPEC_voidFlashWrite( Copy_u32Address ,  & Copy_u32Data ,LENGTH ); // flash input Data in input address

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void FEEP_voidUpdateFlag(u32 Copy_u32Address, u32 Copy_u32NewData) // change the value of a current flag
{

	u32 ADD[25]; // store current addresses before erase
	u32 VAL[25]; // store current values    before erase
	u16  StoreCounter = 0 ;
	u16  resaveCounter = 0;
	u32 AddressCounter  ;

	for ( AddressCounter = First_Address ; AddressCounter <= Last_Address ;)
	{

		if( (AddressCounter != Copy_u32Address) & ( *((u32*)(AddressCounter))  != ERASED_WORD ) )	//check to save current flags
		{
			ADD[StoreCounter] = AddressCounter ; // save addresses
			VAL[StoreCounter] = *((u32*)(AddressCounter)); //save values
			StoreCounter ++ ;
		}
		AddressCounter = AddressCounter + WORD ; // incerement address
	}

	FPEC_voidFlashPageErase(LAST_PAGE); // erase after save

	for (resaveCounter=0 ; resaveCounter < StoreCounter ;resaveCounter++ ) //restore flags
	{
		FPEC_voidFlashWrite( ADD[resaveCounter] ,  &VAL[resaveCounter] ,LENGTH );
	}

	FPEC_voidFlashWrite( Copy_u32Address ,  & Copy_u32NewData ,LENGTH ); //save new input Data

}									 
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																	
void FEEP_voidFreeFlag(u32 Copy_u32Address) // free a flag 
{
	u32 ADD[25];
	u32 VAL[25];
	u8  StoreCounter = 0 ;
	u8  resaveCounter = 0;
	u32 AddressCounter  ;

	for ( AddressCounter = First_Address ; AddressCounter <= Last_Address ;)
	{

		if( (AddressCounter != Copy_u32Address) & ( *((u32*)(AddressCounter))  != ERASED_WORD ) )	// save current flags
		{
			ADD[StoreCounter] = AddressCounter ; // save addresses
			VAL[StoreCounter] = *((u32*)(AddressCounter)); //save values
			StoreCounter ++ ;
		}
		AddressCounter = AddressCounter + WORD ; // incerement address
	}

	FPEC_voidFlashPageErase(LAST_PAGE);

	for (resaveCounter=0 ; resaveCounter < StoreCounter ;resaveCounter++ )
	{
		FPEC_voidFlashWrite( ADD[resaveCounter] ,  &VAL[resaveCounter] ,LENGTH );
	}

}	
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 				