/*******************************************************************************/
/*******************************************************************************/
/***********************   MAHMOUD ASHRAF  ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):RCC 			 ***********************/
/***********************   DATA : 12-10-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_






/*Macros for Buses * */

#define RCC_AHB1_BUS       1
#define RCC_AHB2_BUS       2
#define RCC_APB1_BUS       3
#define RCC_APB2_BUS       4



/* AHB1 Peripherals */
#define   GPIOAEN     0
#define   GPIOBEN     1
#define   GPIOCEN     2
#define   GPIODEN     3
#define   GPIOEEN     4
#define   GPIOHEN     7
#define   DMA1EN      21
#define   DMA2EN      22

/* AHB2 Peripherals */
#define OTGFSEN    7

/* APB1 Peripherals */
#define PWREN      28
#define I2C3EN     23
#define I2C2EN     22
#define I2C1EN     21
#define USART2EN   17
#define SPI3EN     15
#define SPI2EN     14
#define WWDGEN     11
#define TIM5EN     3
#define TIM4EN     2
#define TIM3EN     1
#define TIM2EN     0

/* APB2 Peripherals */
#define   TIM11EN    18
#define   TIM10EN    17
#define   TIM9EN     16
#define   SYSCFGEN   14
#define   SPI4EN     13
#define   SPI1EN     12
#define   SDIOEN     11
#define   ADC1EN     8
#define   USART6EN   5
#define   USART1EN   4
#define   TIM1EN     0


void MRCC_voidInitSysClk(void);

u8 MRCC_u8EnablePeripheralClock(u8 A_u8BusId, u8 A_u8PeripheralId);

u8 MRCC_u8DisablePeripheralClock(u8 A_u8BusId, u8 A_u8PeripheralId);



#endif /* MCAL_RCC_RCC_INT_H_ */
