/*
 * MRCC_Interface.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MRCC_MRCC_INTERFACE_H_
#define MCAL_MRCC_MRCC_INTERFACE_H_




#include "MRCC_Config.h"
#include "MRCC_Private.h"

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2


typedef enum {
	DMA1,
	DMA2,
	SRAM,
	FLITF=4,
	CRC=6,
	FSMC=8,
	SDIO=10,
	AFIO =0,
	GPIOPA=2,
	GIOPB,
	GIOPC,
	GIOPD,
	GIOPE,
	GIOPF,
	GIOPG,
	ADC1,
	ADC2,
	TIM1,
	SPI1,
	TIM8,
	USART,
	ADC3,
	TIM9=19,
	TIM10,
	TIM11,
	TIM2=0,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWD=11,
	SPI2=14,
	SPI3,
	USART2=17,
	USART3,
	USART4,
	USART5,
	I2C1,
	I2C2,
	USB=23,
	CAN=25,
	BKP=27,
	PWR,
	DAC,

	} Peripherals_t;
/*prototypes of functions*/
void MRCC_vInit(void);

void MRCC_vEnableClock(u8 Copy_u8BusName , Peripherals_t Copy_u8PeripheralName);

void MRCC_vDisableClock(u8 Copy_u8BusName , Peripherals_t Copy_u8PeripheralName);




#endif /* MCAL_MRCC_MRCC_INTERFACE_H_ */
