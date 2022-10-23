/*******************************************************************************/
/*******************************************************************************/
/***********************   MAHMOUD ASHRAF  ***********************/
/***********************   Layer :MCAL                   ***********************/
/***********************   SWC (DRIVER):RCC 			 ***********************/
/***********************   DATA : 12-10-2022 			 ***********************/
/*******************************************************************************/
/*******************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_int.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"




void MRCC_voidInitSysClk(void){

#if (CLOCK_SOURCE == HSI)
	/*
	 * 1- Turn on HSI Clock
	 * 2- Check HSI is Ready
	 * 3- Switch to HSI
	 * 4- Turn off PLL
	 * 5- Turn off HSE
	 */
	SET_BIT(RCC->CR, HSION);
	while(GET_BIT(RCC->CR, HSIRDY)==0);
	CLR_BIT(RCC->CFGR, SW0);
	CLR_BIT(RCC->CFGR, SW1);
	CLR_BIT(RCC->CR, HSEON);
	CLR_BIT(RCC->CR, PLLON);

#elif CLOCK_SOURCE == HSE
	/*
	 * 1- Turn on HSE Clock
	 * 2- Check HSe is Ready
	 * 3- Switch to HSE
	 * 4- Turn off PLL
	 * 5- Turn off HSI
	 * 6- Turn On CSS
	 */
	SET_BIT(RCC->CR, HSEON);
	while(GET_BIT(RCC->CR, HSERDY) == 0);
	SET_BIT(RCC->CFGR, SW0);
	CLR_BIT(RCC->CFGR, SW1);
	CLR_BIT(RCC->CR, PLLON);
	CLR_BIT(RCC->CR, HSION);
	SET_BIT(RCC->CR, CSSON);
#elif CLOCK_SOURCE == PLL

#else
#error "Wrong Choice"

#endif

}
u8 MRCC_u8EnablePeripheralClock(u8 A_u8BusId, u8 A_u8PeripheralId){

	u8 Local_u8ErrorState = STD_OK;
	if(A_u8PeripheralId < 32){

		switch(A_u8BusId){
			case RCC_AHB1_BUS:SET_BIT(RCC->AHB1ENR, A_u8PeripheralId);break;
			case RCC_AHB2_BUS: SET_BIT(RCC->AHB2ENR, A_u8PeripheralId);break;
			case RCC_APB1_BUS:SET_BIT(RCC->APB1ENR, A_u8PeripheralId);break;
			case RCC_APB2_BUS: SET_BIT(RCC->APB2ENR, A_u8PeripheralId);break;
			default: Local_u8ErrorState = STD_NOTOK;
		}


	}
	else{
		Local_u8ErrorState = STD_NOTOK;
	}

	return Local_u8ErrorState;


}

u8 MRCC_u8DisablePeripheralClock(u8 A_u8BusId, u8 A_u8PeripheralId){
	u8 Local_u8ErrorState = STD_OK;
	if(A_u8PeripheralId < 32){

		switch(A_u8BusId){
			case RCC_AHB1_BUS:CLR_BIT(RCC->AHB1ENR, A_u8PeripheralId);break;
			case RCC_AHB2_BUS: CLR_BIT(RCC->AHB2ENR, A_u8PeripheralId);break;
			case RCC_APB1_BUS:CLR_BIT(RCC->APB1ENR, A_u8PeripheralId);break;
			case RCC_APB2_BUS: CLR_BIT(RCC->APB2ENR, A_u8PeripheralId);break;
			default: Local_u8ErrorState = STD_NOTOK;
		}
	}
	else{
		Local_u8ErrorState = STD_NOTOK;
	}

	return Local_u8ErrorState;
}









