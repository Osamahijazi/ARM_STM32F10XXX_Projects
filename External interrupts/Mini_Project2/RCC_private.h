#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H




#define RCC_CR         *((uint32*)0x40021000)
#define RCC_CFGR       *((uint32*)0x40021004)
#define RCC_CIR        *((uint32*)0x40021008)
#define RCC_APB2RSTR   *((uint32*)0x4002100C)
#define RCC_APB1RSTR   *((uint32*)0x40021010)
#define RCC_AHBENR     *((uint32*)0x40021014)
#define RCC_APB2ENR    *((uint32*)0x40021018)
#define RCC_APB1ENR    *((uint32*)0x4002101C)
#define RCC_BDCR       *((uint32*)0x40021020)
#define RCC_CSR        *((uint32*)0x40021024)


   


                /*CLOCK TYPES*/
								
     #define  RCC_HSE_CRYSTAL         0
     #define  RCC_HSE_RC              1
		 #define  RCC_HSI                 2
		 #define  RCC_PLL                 3
		 
		             /*PLL_TYPES*/
								 
		 #define RCC_PLL_IN_HSI_DIV_2     0
     #define RCC_PLL_IN_HSE_DIV_2     1 
     #define RCC_PLL_IN_HSE           2
		 
                /*PLL MAX INPUT OPTONS */
								
		#define  PLL input clock x2       0000
		#define  PLL input clock x3       0001
		#define  PLL input clock x4       0010 
		#define  PLL input clock x5       0011
		#define  PLL input clock x6       0100
		#define  PLL input clock x7       0101 
		#define  PLL input clock x8       0110 
		#define  PLL input clock x9       0111
		#define  PLL input clock x10      1000
		#define  PLL input clock x11      1001
		#define  PLL input clock x12      1010
		#define  PLL input clock x13      1011
		#define  PLL input clock x14      1100
		#define  PLL input clock x15      1101
		#define  PLL input clock x16      1110
		#define  PLL input clock x17      1111
		

								
								
								
								
								
								
								

#endif
