/*
 * HDCM_Program.c
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmine & kareem & toka
 */

#include "HDCM_Interface.h"



void HDCM_Init(void)
{
	
	MGPIO_vSetPinMode(DCmotor_EN,PWM_L,GPIO_AF_OUTPUT_PP_50MHZ);
	MGPIO_vSetPinMode(DCmotor_EN,PWM_R,GPIO_AF_OUTPUT_PP_50MHZ);
	MGPIO_vSetPinMode(DCmotor_EN,R_1,GPIO_GP_OUTPUT_PP_2MHZ);

	MGPIO_vSetPinMode(DCmotor_EN,L_1,GPIO_GP_OUTPUT_PP_2MHZ);
	

	MPWM_vInit();
	MPWM_ChannelInit(CHANNEL3);
	MPWM_ChannelInit(CHANNEL4);
	MPWM_start();


}

void HDCM_Forward_M_Right(void)
{
	MGPIO_vSetPinValue(DCmotor_PINs,R_1,GPIO_LOW);

}
void HDCM_Backward_M_Right(void)
{
	MGPIO_vSetPinValue(DCmotor_PINs,R_1,GPIO_HIGH);
}
void HDCM_Forward_M_Left(void)
{
	MGPIO_vSetPinValue(DCmotor_PINs,L_1,GPIO_LOW);
}
void HDCM_Backward_M_Left(void)
{
	MGPIO_vSetPinValue(DCmotor_PINs,L_1,GPIO_HIGH);
}

void HDCM_Stop(void)
{
	MPWM_duty(0,CHANNEL3);
	MPWM_duty(0,CHANNEL4);
}
/**
 * Speed: from the adc(joystick) 
*/
void HDCM_Forward( u16 speed )
{

	MPWM_duty(speed,CHANNEL3);
	MPWM_duty(speed,CHANNEL4);
	HDCM_Forward_M_Left();
	HDCM_Forward_M_Right();
}

void HDCM_Back(u16 speed)
{
	MPWM_duty(speed,CHANNEL3);
	MPWM_duty(speed,CHANNEL4);
	HDCM_Backward_M_Left();
	HDCM_Backward_M_Right();
}


void HDCM_Right(u16 speed){
	HDCM_Forward_M_Right();
	HDCM_Backward_M_Left();
	MPWM_duty(speed,CHANNEL3);
	MPWM_duty(speed,CHANNEL4);

}
void HDCM_Left(u16 speed){
	HDCM_Backward_M_Right();
	HDCM_Forward_M_Left();
	MPWM_duty(speed,CHANNEL3);
	MPWM_duty(speed,CHANNEL4);

}


