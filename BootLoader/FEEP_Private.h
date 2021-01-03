/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:15/12/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef FEEP_Private_H
#define FEEP_Private_H

#define   LAST_PAGE             63
#define   LENGTH                1

                                           /*Variables addresses and  Definitions*/
#define  MODE_ADD     0x0800FC00  // address of mode flag
#define  CRC1_ADD     0x0800FC04  // address of crc of first  app
#define  CRC2_ADD     0x0800FC08  // address of crc of second app

#define  MODE       *(( u32*)(MODE_ADD))  // variable to indicate the current mode (BL OR APP)
#define  CRC1       *(( u32*)(CRC1_ADD))  // variable to store crc of first  app
#define  CRC2       *(( u32*)(CRC2_ADD))  // variable to store crc of second app







#endif
