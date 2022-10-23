/*******************************************************************************/
/*******************************************************************************/
/***********************   MAHMOUD ASHRAF  ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):RCC 			 ***********************/
/***********************   DATA : 12-10-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef MCAL_RCC_RCC_PRV_H_
#define MCAL_RCC_RCC_PRV_H_


#define RCC_BASE_ADDR  		0x40023800

typedef struct{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 Reserved1;
	volatile u32 Reserved2;
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 Reserved3;
	volatile u32 Reserved4;
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 Reserved5;
	volatile u32 Reserved6;
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 Reserved7;
	volatile u32 Reserved8;
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 Reserved9;
	volatile u32 Reserved10;
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 Reserved11;
	volatile u32 Reserved12;
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 Reserved13;
	volatile u32 DCKCFGR;

}RCC_MemMap_t;


#define RCC    ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))


#define HSI  		1
#define HSE  		2
#define PLL  		3


/*RCC clock control register (RCC_CR) BITS * */
#define PLLI2SRDY     27
#define PLLI2SON      26
#define PLLRDY     	  25
#define PLLON         24
#define CSSON         19
#define HSEBYP        18
#define HSERDY     	  17
#define HSEON         16
#define HSICAL
#define HSITRIM
#define HSIRDY        1
#define HSION    	  0

/*RCC PLL configuration register (RCC_PLLCFGR) * */


/*RCC_CFGR*/

#define SW0     0
#define SW1     1
#define SWS0    2
#define SWS1    3





#endif /* MCAL_RCC_RCC_PRV_H_ */
