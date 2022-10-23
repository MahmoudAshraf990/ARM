/*
 * GPIO_prog.c
 *
 *  Created on: Oct 16, 2022
 *      Author: mahmo
 */

#include "../../LIB/STD_TYPES.h"

#include"../../LIB/BIT_MATH.h"


#include "GPIO_int.h"
#include "GPIO_prv.h"
#include "GPIO_cfg.h"



static GPIO_Memm_t *GPIO_Astr[3] = {GPIOA, GPIOB, GPIOC};



u8 MGPIO_u8PinInit(const GPIO_PINCONFIG_T *cpy_PstrPinConfig){
	u8 Local_u8ErrorState = STD_NOTOK;
	/*Check if the pointer is wild pointer or not */
	if(cpy_PstrPinConfig != NULL){
		if(cpy_PstrPinConfig->PortId <= GPIO_PORTC && cpy_PstrPinConfig->PinId <= PIN15 && cpy_PstrPinConfig->PinMode <= GPIO_OUTPUT_OPENDRAIN_VHIGHSPEED){

			switch(cpy_PstrPinConfig->PinMode){
				case GPIO_INPUT_PULL_UP:
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->PUPDR, cpy_PstrPinConfig->PinId*2);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->PUPDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;
				case GPIO_INPUT_PULL_DOWEN:
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->PUPDR, cpy_PstrPinConfig->PinId*2);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->PUPDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;
				case GPIO_OUTPUT_PUSHPULL_LOWSPEED:
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OTYPER, cpy_PstrPinConfig->PinId);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, cpy_PstrPinConfig->PinId*2);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;
				case GPIO_OUTPUT_PUSHPULL_MEDSPEED:
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OTYPER, cpy_PstrPinConfig->PinId);
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, cpy_PstrPinConfig->PinId*2);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;

				case GPIO_OUTPUT_PUSHPULL_HIGHSPEED:
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OTYPER, cpy_PstrPinConfig->PinId);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, cpy_PstrPinConfig->PinId*2);
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;
				case GPIO_OUTPUT_PUSHPULL_VHIGHSPEED:
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OTYPER, cpy_PstrPinConfig->PinId);
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, cpy_PstrPinConfig->PinId*2);
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;
				case GPIO_OUTPUT_OPENDRAIN_LOWSPEED:
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OTYPER, cpy_PstrPinConfig->PinId);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, cpy_PstrPinConfig->PinId*2);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;
				case GPIO_OUTPUT_OPENDRAIN_MEDSPEED:
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OTYPER, cpy_PstrPinConfig->PinId);
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, cpy_PstrPinConfig->PinId*2);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;
				case GPIO_OUTPUT_OPENDRAIN_HIGHSPEED:
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OTYPER, cpy_PstrPinConfig->PinId);
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, cpy_PstrPinConfig->PinId*2);
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;
				case GPIO_OUTPUT_OPENDRAIN_VHIGHSPEED:
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, (cpy_PstrPinConfig->PinId*2));
					CLR_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->MODER, ((cpy_PstrPinConfig->PinId*2)+1));
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OTYPER, cpy_PstrPinConfig->PinId);
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, cpy_PstrPinConfig->PinId*2);
					SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->OSPEEDR, ((cpy_PstrPinConfig->PinId*2)+1));
					Local_u8ErrorState = STD_OK;
				break;

				default: return Local_u8ErrorState;
			}
		}
	}

	return Local_u8ErrorState;
}

u8 MGPIO_u8SetPinValue(const GPIO_PINCONFIG_T *cpy_PstrPinConfig, u8 cpy_u8PinValue){
	u8 Local_u8ErrorState  = STD_NOTOK;
	if(cpy_PstrPinConfig != NULL && cpy_u8PinValue <= GPIO_HIGH){
		if(cpy_PstrPinConfig->PortId <= GPIO_PORTC && cpy_PstrPinConfig->PinId <= PIN15){
			switch(cpy_u8PinValue){
					case GPIO_HIGH:
						SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->ODR, cpy_PstrPinConfig->PinId);
						Local_u8ErrorState = STD_OK;
					break;
					case GPIO_LOW:
						SET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->ODR, cpy_PstrPinConfig->PinId);
						Local_u8ErrorState = STD_OK;
					break;
			}
		}

	}
	return Local_u8ErrorState;

}

u8 MGPIO_u8GetPinValue(const GPIO_PINCONFIG_T* cpy_PstrPinConfig, u8 *cpy_u8ReturnedValue){

	u8 Local_u8ErrorState  = STD_NOTOK;
	if(cpy_PstrPinConfig != NULL && (cpy_u8ReturnedValue != NULL)){
		if(cpy_PstrPinConfig->PortId <= GPIO_PORTC && cpy_PstrPinConfig->PinId <= PIN15){
			*(cpy_u8ReturnedValue) = GET_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->IDR, cpy_PstrPinConfig->PinId);
			Local_u8ErrorState = STD_OK;
		}
	}
	return Local_u8ErrorState;
}

u8 MGPIO_u8TogPinValue(const GPIO_PINCONFIG_T *cpy_PstrPinConfig){
	u8 Local_u8ErrorState  = STD_NOTOK;
	if(cpy_PstrPinConfig != NULL){
		if(cpy_PstrPinConfig->PortId <= GPIO_PORTC && cpy_PstrPinConfig->PinId <= PIN15){
			TOGGLE_BIT(GPIO_Astr[cpy_PstrPinConfig->PortId]->ODR, cpy_PstrPinConfig->PinId);
			Local_u8ErrorState = STD_OK;
		}
	}
	return Local_u8ErrorState;
}

u8 MGPIO_voidSetPinValueATOMIC(const GPIO_PINCONFIG_T *cpyPstrPinConfig, u8 cpy_u8PinValue){
	u8 Local_u8ErrorState  = STD_NOTOK;
	if(cpyPstrPinConfig != NULL){
		if(cpyPstrPinConfig->PortId <= GPIO_PORTC && cpyPstrPinConfig->PinId <= PIN15){
			switch(cpy_u8PinValue){
					case GPIO_HIGH:
						GPIO_Astr[cpyPstrPinConfig->PortId]->BSRR = (1<<(cpyPstrPinConfig->PinId));
						Local_u8ErrorState = STD_OK;
					break;
					case GPIO_LOW:
						GPIO_Astr[cpyPstrPinConfig->PortId]->BSRR = (1<<(cpyPstrPinConfig->PinId + 16));
						Local_u8ErrorState = STD_OK;
					break;
			}
		}

	}
	return Local_u8ErrorState;

}


