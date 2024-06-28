/*
 * MPWM_Private.h
 *
 *  Created on: Dec 21, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MPWM_MPWM_PRIVATE_H_
#define MCAL_MPWM_MPWM_PRIVATE_H_


#include "../../LIB/STD_Types.h"

#define TIM2_Base_Address   0x4000 0000
#define  AFIO_MAPR       *((volatile u32*)0x40010000+ 0x04)

typedef struct {
	u32 TIMx_CR1;
	u32 TIMx_CR2;
	u32 TIMx_SMCR;
    u32 TIMx_DIER;
    u32 TIMx_SR;
	u32 TIMx_EGR;
	u32 TIMx_CCMR1;
	u32 TIMx_CCMR2;
	u32 TIMx_CCER;
	u32 TIMx_CNT;
	u32 TIMx_PSC;
	u32 TIMx_ARR;
	u32 RESERVED;
	u32 TIMx_CCR1;
	u32 TIMx_CCR2;
	u32 TIMx_CCR3;
	u32 TIMx_CCR4;
	u32 RESERVED2;
	u32 TIMx_DCR;
	u32 TIMx_DMAR;





}TIM2_t;

#define TIM2_P ((volatile TIM2_t*)0x40000000)



#endif /* MCAL_MPWM_MPWM_PRIVATE_H_ */
