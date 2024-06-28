/*
 * MPWM_Interface.h
 *
 *  Created on: Dec 21, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MPWM_MPWM_INTERFACE_H_
#define MCAL_MPWM_MPWM_INTERFACE_H_


//#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "MPWM_Config.h"
#include "MPWM_Private.h"


enum CCER{
	 CC1E ,
	 CC1P ,
	 CC2E=4 ,
	 CC2P ,
	 CC3E=8 ,
	 CC3P ,
	 CC4E=12 ,
	 CC4P


} ;
/*active high or active low*/
//#define CHANNEL_POLARITY  or active low




#define TIM2_CEN   0
#define Update_Generation 0


#define TIM2_REMAP_bit_1     8
#define TIM2_REMAP_bit_2     9

#define CHANNEL1    1
#define CHANNEL2    2
#define CHANNEL3    3
#define CHANNEL4    4


void MPWM_ChannelInit( u8 copy_u8chanel);
void MPWM_vInit(void);
void MPWM_start(void);
void MPWM_channeldisable(u8 copy_u8chanel);
void MPWM_VPWMEND(void);
void MPWM_duty(u16 copy_u8dutycycle ,u8 copy_u8chanel);




#endif /* MCAL_MPWM_MPWM_INTERFACE_H_ */
