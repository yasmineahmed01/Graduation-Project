#include "LIB/STD_Types.h"
#include "MCAL/MGPIO/MGPIO_Interface.h"
#include "MCAL/MRCC/MRCC_Interface.h"
#include "MCAL/MPWM/MPWM_Interface.h"
#include "MCAL/MPWM/MPWM_Private.h"
#include "MCAL/MADC/MADC_Interface.h"
#include "HAL/HDCM/HDCM_Interface.h"
#include "HAL/H_JoyStick/H_JoyStick_Interface.h"

void Delays(int time);
u16 analog_rx = 0;
u16 analog_ry = 0;
int main(void)
{


	MRCC_vEnableClock(RCC_APB2,GPIOPA);
	MRCC_vEnableClock(RCC_APB2,GIOPB);

	MRCC_vEnableClock( RCC_APB1,TIM2);
	MRCC_vEnableClock( RCC_APB2  , AFIO);
	MRCC_vEnableClock( RCC_APB2  , ADC1);
	MRCC_vEnableClock( RCC_APB2  , ADC2);
	




	//Configure PA1 as Output Alternate Push/Pull

	//MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_AF_OUTPUT_PP_50MHZ);

	//MGPIO_vSetPinMode(GPIO_PORTA, GPIO_PIN0 ,GPIO_INPUT_ANALOG); //channel_0 ADC
	//MADC_vSet_Channel_Seq(CHANNEL_0,0 ,ADC_1); //sa7

	//MADC_vInit(ADC_1 , CHANNEL_0 );
	 //MPWM_vInit();
	 HDCM_Init();
	 H_Joystick_init();

		while(1)
		{



			analog_rx = H_Joystick_Read_x();
	        analog_ry = H_Joystick_Read_y();

	        //Forward
	        if((analog_rx>1700)&&(analog_ry>1400)&&(analog_ry<1700)){
	        	HDCM_Forward(analog_rx-1500);
	        }
	        //STOP
	        if((analog_rx>1400)&&(analog_rx<1700)&&(analog_ry>1400)&&(analog_ry<1700)){
	        	HDCM_Stop();
	        }
	        //backward
	        if((analog_rx<1400)&&(analog_ry>1400)&&(analog_ry<1700)){
	        	HDCM_Back(1800-analog_rx);
	        }
	        //Right
	        if((analog_ry>1700)&&(analog_rx>1400)&&(analog_rx<1700)){
	        	HDCM_Left(analog_ry-1500);
	        }
	        //Left
	        if((analog_ry<1400)&&(analog_rx>1400)&&(analog_rx<1700)){
	        	HDCM_Right(1800-analog_ry);
	        }

	/*if(analog_rx<1500){
		HDCM_Forward_M_Right();
		u16 Map_Speed =3300-analog_rx ;

		//u16 speed=3300;
		MPWM_duty(Map_Speed,CHANNEL3);
	/*	for(speed=0;speed<3300;speed+=10){

		MPWM_duty(speed,CHANNEL3);
		Delays(10);
		}

	}else if(analog_rx>1800){HDCM_Backward_M_Right();
		u16 speedB;
		u16 Map_SpeedB = analog_rx;
		MPWM_duty(Map_SpeedB,CHANNEL3);
			/*for(speedB=1700;speedB<3200;speedB++){
			MPWM_duty(speedB,CHANNEL3);
			}
	}else if((analog_rx<1800)&&(analog_rx>1500)){HDCM_Backward_M_Right();


			MPWM_duty(0,CHANNEL3);

	}


}*/
		}

}


void Delays(int time) /// Random delay function
{
	int t;
	for(;time>0;time--)
	{
	 for(t=0;t<100000;t++)
		{}
	}
}
