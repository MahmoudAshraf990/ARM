
#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"





int main(void)
{
    MRCC_voidInitSysClk();
    MRCC_u8EnablePeripheralClock(RCC_AHB1_BUS, GPIOAEN);

    GPIO_PINCONFIG_T LED1 = {
    	GPIO_PORTA,
		PIN1,
		GPIO_OUTPUT_PUSHPULL_LOWSPEED
    };

	MGPIO_u8PinInit(&LED1);
	MGPIO_u8SetPinValue(&LED1, GPIO_HIGH);


	for(;;);
}
