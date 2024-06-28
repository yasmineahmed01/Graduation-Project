/*
 * MPWM_Program.c
 *
 *  Created on: Dec 21, 2023
 *      Author: yasmi
 */




//#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MPWM_Interface.h"

void MPWM_ChannelInit( u8 copy_u8chanel){

	/*Configure PA0,PA1,PA2,P43as Output Alternate Push/Pull */


	 //put polarity for channels active high or active low*/
	switch (copy_u8chanel) {
	case CHANNEL1:

		CLR_BIT(TIM2_P->TIMx_CCER,CC1P);

		break;
	case CHANNEL2:
		CLR_BIT(TIM2_P->TIMx_CCER,CC2P);
		break;
	case CHANNEL3:
		CLR_BIT(TIM2_P->TIMx_CCER,CC3P);
		break;
	case CHANNEL4:
		CLR_BIT(TIM2_P->TIMx_CCER,CC4P);
		break;
	}




    /* set pwm_mode and make chanel output in ccmr1
	 OC2PE. Write operations on CCR are taken into account at next update event*/
	switch (copy_u8chanel) {
	case CHANNEL1:
		 TIM2_P->TIMx_CCMR1 &=0xFFFFFF00;


		 TIM2_P->TIMx_CCMR1|=(TIM2_CLEAR2_EN <<7);
		 TIM2_P->TIMx_CCMR1 |=(TIM2_OUTPUT1_MODE <<4);
		 TIM2_P->TIMx_CCMR1 |=(TIM2_PRELOAD1_EN <<3);
		 TIM2_P->TIMx_CCMR1 |=(TIM2_Fast1_EN <<2);
		 TIM2_P->TIMx_CCMR1 |=(TIM2_selection1 <<0);


		break;

	case CHANNEL2:
		TIM2_P->TIMx_CCMR1 &=0xFFFF00FF;
		TIM2_P->TIMx_CCMR1 |=(TIM2_CLEAR2_EN <<15);
		TIM2_P->TIMx_CCMR1 |=(TIM2_OUTPUT2_MODE <<12);
		TIM2_P->TIMx_CCMR1 |=(TIM2_PRELOAD2_EN <<11);
		TIM2_P->TIMx_CCMR1 |=(TIM2_Fast2_EN <<10);
		TIM2_P->TIMx_CCMR1 |=(TIM2_selection2 <<8);
		break;
	case CHANNEL3:
		TIM2_P->TIMx_CCMR2 &=0xFFFFFF00;
		TIM2_P->TIMx_CCMR2 |=(TIM2_CLEAR3_EN  <<7);
		TIM2_P->TIMx_CCMR2 |=(TIM2_OUTPUT3_MODE <<4);
		 TIM2_P->TIMx_CCMR2 |=(TIM2_PRELOAD3_EN <<3);
		TIM2_P->TIMx_CCMR2 |=(TIM2_Fast3_EN <<2);
		TIM2_P->TIMx_CCMR2 |=(TIM2_selection3 <<0);
		break;
	case CHANNEL4:
		TIM2_P->TIMx_CCMR2 &=0xFFFF00FF;
		TIM2_P->TIMx_CCMR2 |=(TIM2_CLEAR4_EN <<15);
		TIM2_P->TIMx_CCMR2 |=(TIM2_OUTPUT4_MODE <<12);
		TIM2_P->TIMx_CCMR2 |=(TIM2_PRELOAD4_EN <<11);
		TIM2_P->TIMx_CCMR2 |=(TIM2_Fast4_EN <<10);
		TIM2_P->TIMx_CCMR2 |=(TIM2_selection4 <<8);
		break;

	}

	// CCxE.  Enable Channelx to be seen in output pin
				switch (copy_u8chanel) {
					case CHANNEL1:

						SET_BIT(TIM2_P->TIMx_CCER,CC1E);

						break;
					case CHANNEL2:
						SET_BIT(TIM2_P->TIMx_CCER,CC2E);
						break;
					case CHANNEL3:
						SET_BIT(TIM2_P->TIMx_CCER,CC3E);
						break;
					case CHANNEL4:
						SET_BIT(TIM2_P->TIMx_CCER,CC4E);
						break;
					}



}
void MPWM_vInit(void){
	// Enable GPIOA Clock
	 /*Enable TIM2 Clock*/
	// UG.  Update generation to restart CNT and load new ARR and CCR2 values
	SET_BIT(TIM2_P->TIMx_EGR,Update_Generation);
	TIM2_P->TIMx_PSC =PRESCALER;
    TIM2_P->TIMx_ARR =ARR_Period;



	TIM2_P->TIMx_CR1 &=0xFFFFFF0D;
	TIM2_P->TIMx_CR1|=(TIM2_Auto_preload_enable<<7);// ARPE.  Operations on ARR are taken into account at next update event
	TIM2_P->TIMx_CR1|=(TIM2_Center_aligned_mode <<5);
	TIM2_P->TIMx_CR1|=(TIM2_DIR<<4);// DIR.	  Counter in upcounting mode  choose counter dir in general

	TIM2_P->TIMx_CR1|=(TIM2_UDIS<<1);  // UDIS.  Update Event enabled at counter overflow or UG bit





	}

void MPWM_start(void){



		// CEN. Enable Timer2 PWM
		SET_BIT( TIM2_P->TIMx_CR1 , TIM2_CEN);

}
void MPWM_channeldisable(u8 copy_u8chanel){
	// CC2E. Disable Channel 2 to be seen in output pin
	switch (copy_u8chanel) {
			case CHANNEL1:

				CLR_BIT(TIM2_P->TIMx_CCER , CC1E);

				break;
			case CHANNEL2:
				CLR_BIT(TIM2_P->TIMx_CCER,CC2E);
				break;
			case CHANNEL3:
				CLR_BIT(TIM2_P->TIMx_CCER,CC3E);
				break;
			case CHANNEL4:
				CLR_BIT(TIM2_P->TIMx_CCER,CC4E);
				break;
			}

}


void MPWM_VPWMEND(void){
	// CEN. Disable Timer2
		CLR_BIT( TIM2_P->TIMx_CR1 , TIM2_CEN);
}


void MPWM_duty(u16 copy_u8dutycycle ,u8 copy_u8chanel){
switch (copy_u8chanel) {
case CHANNEL1:

    TIM2_P->TIMx_CCR1=copy_u8dutycycle;
	break;
case CHANNEL2:
	TIM2_P->TIMx_CCR2=copy_u8dutycycle;
	break;
case CHANNEL3:
	TIM2_P->TIMx_CCR3=copy_u8dutycycle;
	break;
case CHANNEL4:
	TIM2_P->TIMx_CCR4=copy_u8dutycycle;
	break;
}
}

