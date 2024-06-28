/*
 * HDCM_Private.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef HAL_HDCM_HDCM_PRIVATE_H_
#define HAL_HDCM_HDCM_PRIVATE_H_

#include "../../MCAL/MGPIO/MGPIO_Interface.h"


#define PWM_R GPIO_PIN2 //A2 channel 3 PWM
#define PWM_L GPIO_PIN3 //A3 channel 4 PWM

#define R_1 GPIO_PIN6	//RIGHT MOTOR
#define L_1 GPIO_PIN5	//LEFT MOTOR


#define DCmotor_EN  GPIO_PORTA
#define DCmotor_PINs GPIO_PORTA




#endif /* HAL_HDCM_HDCM_PRIVATE_H_ */
