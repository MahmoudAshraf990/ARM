/*******************************************************************************/
/*******************************************************************************/
/***********************   MAHMOUD ASHRAF  ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):RCC 			 ***********************/
/***********************   DATE : 12-10-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/
#include "stdio.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_int.h"



int main(void)
{
	MRCC_voidInitSysClk();
	u8 LocalErr = 2;

	LocalErr = MRCC_u8EnablePeripheralClock(RCC_AHB1_BUS, GPIOAEN);
	printf("ERROR = %d", LocalErr);
    /* Loop forever */
	for(;;);
}
