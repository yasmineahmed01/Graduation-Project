/*
 * MRCC_Program.c
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */




#include "MRCC_Interface.h"
#include "MRCC_Config.h"
#include "MRCC_Private.h"
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"


void MRCC_vInit(void){

#if RCC_SYSCLK_SRC == RCC_HSI
	/*RCC_CR*/
	RCC->CR=0;
	RCC->CR|=(RCC_CSS_ON<<19);
   if ( (RCC_HSITRIM<=32) &&( RCC_HSITRIM>=0)){
	RCC->CR|=(RCC_HSITRIM<<3);}
    RCC->CR|=(RCC_HSI_ON<<0);
	while (!((RCC->CR >> 1)&1));
	/*RCC_CFGR*/
	RCC->CFGR=0;
	RCC->CFGR|=(RCC_MCO<<24);
    RCC->CFGR|=(RCC_ADC_PRESCALER<<14);
	RCC->CFGR|=(RCC_APB2_PRESCALER<<11);
	RCC->CFGR|=(RCC_APB1_PRESCALER<<8);
	RCC->CFGR|=(RCC_AHB_PRESCALER<<4);

	RCC->CFGR|=(RCC_SYSCLK_SRC<<0);

#elif RCC_SYSCLK_SRC == RCC_HSE
	/*RCC_CR*/
		RCC->CR=0;
		RCC->CR|=(RCC_CSS_ON<<19);
		RCC->CR|=(RCC_HSE_BYP<<18);
		RCC->CR|=(RCC_HSE_ON<<16);
		while (!((RCC->CR >> 17)&1));
		/*RCC_CFGR*/
		RCC->CFGR=0;
		RCC->CFGR|=(RCC_MCO<<24);
		RCC->CFGR|=(RCC_ADC_PRESCALER<<14);
		RCC->CFGR|=(RCC_APB2_PRESCALER<<11);
		RCC->CFGR|=(RCC_APB1_PRESCALER<<8);
		RCC->CFGR|=(RCC_AHB_PRESCALER<<4);

		RCC->CFGR|=(RCC_SYSCLK_SRC<<0);


#elif RCC_SYSCLK_SRC == RCC_PLL
		//HCLK to 72MHZ
		//SYSCLK TO 72MHZ
		//AHBCLK TO 72MHZ
		//APB1CLK TO 36MHZ
		//APB2CLK TO 72MHZ
		/* SETTING 2 wait states using 72 mhz*/
		FLASH_ACR &=~(0b111<<0); //clear first3 bits
		FLASH_ACR|=(RCC_FLASH_LATENCY<<0);


		/*RCC_CFGR*/
		RCC->CFGR=0;
		/*RCC_CFGR*/
		RCC->CFGR=0;


		/* Buses prescaler*/
		RCC->CFGR|=(RCC_ADC_PRESCALER<<14);
		RCC->CFGR|=(RCC_APB2_PRESCALER<<11);
		RCC->CFGR|=(RCC_APB1_PRESCALER<<8); //max 36MHZ
		RCC->CFGR|=(RCC_AHB_PRESCALER<<4);
		/*HSE not div*/
		RCC->CFGR|=(RCC_PLL_HSE<<17);
		/*enable HSE*/
		RCC->CR|=(RCC_HSE_ON<<16);
		while (!((RCC->CR >> 17)&1));
		/*HSE IS PLL SOURCE*/
		RCC->CFGR|=(RCC_PLL_SRC<<16);
		/*pllmul=9*/
		RCC->CFGR|=(RCC_PLLMUL<<18);
		/* enable pll*/
		RCC->CR|=(RCC_PLL_ON<<24);
		while (!((RCC->CR >> 25 )&1));
		/* set pll as a source to system clk*/
		RCC->CFGR|=(RCC_SYSCLK_SRC<<0);
		while ((GET_BIT(RCC->CFGR,3)!=1)&&(GET_BIT(RCC->CFGR,2)!=0));


#endif









}
void MRCC_vEnableClock(u8 Copy_u8BusName , Peripherals_t Copy_u8PeripheralName){
	switch (Copy_u8BusName){
	case RCC_AHB:
	SET_BIT(RCC->AHBENR,Copy_u8PeripheralName);
	break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,Copy_u8PeripheralName);
		break;

	case RCC_APB2:
		SET_BIT(RCC->APB2ENR,Copy_u8PeripheralName);
		break;
default: /*return error msg*/
	break;


	}
}

void MRCC_vDisableClock(u8 Copy_u8BusName , Peripherals_t Copy_u8PeripheralName){
	switch (Copy_u8BusName){
	case RCC_AHB:
		CLR_BIT(RCC->AHBENR,Copy_u8PeripheralName);
	break;
	case RCC_APB1:
		CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralName);
		break;

	case RCC_APB2:
		CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralName);
		break;
default: /*return error msg*/
	break;

	}
}



