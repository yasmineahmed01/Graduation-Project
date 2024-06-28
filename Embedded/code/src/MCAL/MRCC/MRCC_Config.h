/*
 * MRCC_Config.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MRCC_MRCC_CONFIG_H_
#define MCAL_MRCC_MRCC_CONFIG_H_


#define RCC_HSI    0b00
#define RCC_HSE    0b01
#define RCC_PLL    0b10

/*Clock control register (RCC_CR)*/
/*options for PLLON starts from bit 24
 * 0: PLL OFF
1: PLL ON
 * */
#define RCC_PLL_ON   1

/*
 * options for CSSON  starts from bit 19
 * 0: Clock detector OFF
1: Clock detector ON (Clock detector ON if the HSE oscillator is ready , OFF if not)
 * */
#define RCC_CSS_ON  0
/* options for  HSEBYP  starts from bit 18
0: external 4-16 MHz oscillator not bypassed working clk crystal
1: external 4-16 MHz oscillator bypassed with external clock working with clk rc
*/
#define RCC_HSE_BYP 0

/* options for HSEON  starts from bit 16
 * 0: HSE oscillator OFF
   1: HSE oscillator ON*/
#define RCC_HSE_ON  1
/*
 * options for HSITRIM [4 :0]  starts from bit 3:7
 * should  be from 0 to 31  be used if there is an error in HSI CLK defaukt value is 16
 *
 *  */
#define RCC_HSITRIM   16

/*options for HSION  starts from bit 0
 *
 * 0: internal 8 MHz RC oscillator OFF
   1: internal 8 MHz RC oscillator ON
 *
 * */
#define RCC_HSI_ON  1
/*...................*/
/*Clock configuration register (RCC_CFGR) */
/*options for MCO  starts from bit 24:26
 *0xx: No clock
100: System clock (SYSCLK) selected
101: HSI clock selected
110: HSE clock selected
111: PLL clock divided by 2 selected */
#define RCC_MCO  0
/* Options for PLLMUL  starts from bit 18:21
 * 0000: PLL input clock x 2
0001: PLL input clock x 3
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8
0111: PLL input clock x 9
1000: PLL input clock x 10
1001: PLL input clock x 11
1010: PLL input clock x 12
1011: PLL input clock x 13
1100: PLL input clock x 14
1101: PLL input clock x 15
1110: PLL input clock x 16
1111: PLL input clock x 16
 * */
#define RCC_PLLMUL    0b0111
/* options for 7 PLLXTPRE  starts from bit 17
 *  HSE divider for PLL entry
 * 0: HSE clock not divided
1: HSE clock divided by 2
 * */
#define RCC_PLL_HSE   0
/*options for PLLSRC  starts from bit 16
 * 0: HSI oscillator clock / 2 selected as PLL input clock
1: HSE oscillator clock selected as PLL input clock
 * */
#define RCC_PLL_SRC   1
/*options for ADC prescaler  starts from bit 14:15
 * 00: PCLK2 divided by 2
01: PCLK2 divided by 4
10: PCLK2 divided by 6
11: PCLK2 divided by 8
 * */
#define RCC_ADC_PRESCALER  0b00
/*options for  PPRE2 APB high-speed prescaler (APB2)  starts from bit 11:13
 *  0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
 *  */
#define RCC_APB2_PRESCALER  0b000
/*options for PPRE1: APB low-speed prescaler (APB1)  starts from bit 10:8
 *0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16 */
#define RCC_APB1_PRESCALER  0b100
/* options for  AHB prescaler  starts from bit 4:7
 *
 *0xxx: SYSCLK not divided
1000: SYSCLK divided by 2
1001: SYSCLK divided by 4
1010: SYSCLK divided by 8
1011: SYSCLK divided by 16
1100: SYSCLK divided by 64
1101: SYSCLK divided by 128
1110: SYSCLK divided by 256
1111: SYSCLK divided by 512  */
#define RCC_AHB_PRESCALER  0b0000
/* System clock switch status  starts from bit 0:1
Set and cleared by hardware to indicate which clock source is used as system clock.
00: HSI oscillator used as system clock
01: HSE oscillator used as system clock
10: PLL used as system clock
11: not applicable
options :
RCC_HSI
RCC_HSE
RCC_PLL


*/
#define RCC_SYSCLK_SRC RCC_PLL


/*
 * Bits 2:0 LATENCY: Latency
These bits represent the ratio of the SYSCLK (system clock) period to the Flash access
time.
000 Zero wait state, if 0 < SYSCLK 24 MHz
001 One wait state, if 24 MHz < SYSCLK  48 MHz
010 Two wait states, if 48 MHz < SYSCLK  72 MHz*/
#define RCC_FLASH_LATENCY   0b010





#endif /* MCAL_MRCC_MRCC_CONFIG_H_ */
