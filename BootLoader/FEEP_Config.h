/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:15/12/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef FEEP_Config_H
#define FEEP_Config_H
/*
Description  :  this Driver is supported for only three addresses in last 1k in ROM
                the variable and its addresses are :
				 0x0800fc00                MODE
                 0x0800fc04                CRC1
                 0x0800fc08                CRC2


*/

                                            /* Init Variable  values to store */
#define   SAVED_BL             0x01
#define   SAVED_APP            0x02
#define   SAVED_CRC1           0x03
#define   SAVED_CRC2           0x04





#endif
