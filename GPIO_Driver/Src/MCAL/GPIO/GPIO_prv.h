/*
 * GPIO_prv.h
 *
 *  Created on: Oct 16, 2022
 *      Author: mahmo
 */

#ifndef MCAL_GPIO_GPIO_PRV_H_
#define MCAL_GPIO_GPIO_PRV_H_

#define GPIOA_BASE_ADDR    0x40020000
#define GPIOB_BASE_ADDR    0x40020400
#define GPIOC_BASE_ADDR    0x40020800






typedef struct{

	volatile u32  MODER;
	volatile u32  OTYPER;
	volatile u32  OSPEEDR;
	volatile u32  PUPDR;
	volatile u32  IDR;
	volatile u32  ODR;
	volatile u32  BSRR;
	volatile u32  LCKR;
	volatile u32  AFRL;
	volatile u32  AFRH;

}GPIO_Memm_t;


#define GPIOA          ((volatile GPIO_Memm_t *)(GPIOA_BASE_ADDR))
#define GPIOB		   ((volatile GPIO_Memm_t *)(GPIOB_BASE_ADDR))
#define GPIOC		   ((volatile GPIO_Memm_t *)(GPIOC_BASE_ADDR))

#endif /* MCAL_GPIO_GPIO_PRV_H_ */
