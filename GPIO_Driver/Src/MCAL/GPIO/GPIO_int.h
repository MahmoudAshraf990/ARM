/*
 * GPIO_int.h
 *
 *  Created on: Oct 16, 2022
 *      Author: mahmo
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_


#define GPIO_PORTA      0
#define GPIO_PORTB      1
#define GPIO_PORTC      2

//#define GPIO_INPUT_MODE          0
//#define GPIO_OUTPUT_MODE         1
//#define GPIO_ALTERNATE_FUNC      2
//#define GPIO_ANALOG_MODE         3


/*INPUT OPTIONS*/
#define GPIO_INPUT_PULL_UP          				0
#define GPIO_INPUT_PULL_DOWEN          				1

#define GPIO_OUTPUT_PUSHPULL_LOWSPEED    			2
#define GPIO_OUTPUT_PUSHPULL_MEDSPEED    			3
#define GPIO_OUTPUT_PUSHPULL_HIGHSPEED    			4
#define GPIO_OUTPUT_PUSHPULL_VHIGHSPEED    			5

#define GPIO_OUTPUT_OPENDRAIN_LOWSPEED    			6
#define GPIO_OUTPUT_OPENDRAIN_MEDSPEED    			7
#define GPIO_OUTPUT_OPENDRAIN_HIGHSPEED    			8
#define GPIO_OUTPUT_OPENDRAIN_VHIGHSPEED    		9





typedef struct {
	u8 PortId;
	u8 PinId;
	u8 PinMode;
}GPIO_PINCONFIG_T;


#define GPIO_HIGH       1
#define GPIO_LOW        0

enum {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15

};


///*GPIO port output type register options*/
//#define GPIO_OUTPUT_PUSH_PULL   0
//#define GPIO_OUTPUT_OPEN_DRAIN  1
//
//
///*GPIO port output speed register options*/
//#define GPIO_OUTPUT_LOW_SPEED           0
//#define GPIO_OUTPUT_MEDIUM_SPEED        1
//#define GPIO_OUTPUT_HIGH_SPEED          2
//#define GPIO_OUTPUT_VERY_HIGH_SPEED     3
//
///*GPIO port pull-up/pull-down register*/
//#define GPIO_NO_PULL_UP_DOWN   0
//#define GPIO_PULL_UP           1
//#define GPIO_PULL_DOWN   	   2


u8 MGPIO_u8PinInit(const GPIO_PINCONFIG_T *cpy_PstrPinConfig);
u8 MGPIO_u8SetPinValue(const GPIO_PINCONFIG_T *cpy_PstrPinConfig, u8 cpy_u8PinValue);
u8 MGPIO_u8GetPinValue(const GPIO_PINCONFIG_T* cpy_PstrPinConfig, u8 *cpy_u8ReturnedValue);
u8 MGPIO_u8TogPinValue(const GPIO_PINCONFIG_T *cpy_PstrPinConfig);


u8 MGPIO_voidSetPinValueATOMIC(const GPIO_PINCONFIG_T *cpyPstrPinConfig, u8 cpy_u8PinValue);


#endif /* MCAL_GPIO_GPIO_INT_H_ */
