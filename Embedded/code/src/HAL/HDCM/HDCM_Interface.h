/*
 * HDCM_Interface.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef HAL_HDCM_HDCM_INTERFACE_H_
#define HAL_HDCM_HDCM_INTERFACE_H_



#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "../../MCAL/MGPIO/MGPIO_Interface.h"
#include "../../MCAL/MRCC/MRCC_Interface.h"
#include"../../MCAL/MPWM/MPWM_Interface.h"
#include "HDCM_Private.h"


void HDCM_Init(void);
void HDCM_Forward_M_Left(void);
void HDCM_Backward_M_Left(void);
void HDCM_Forward_M_Right(void);
void HDCM_Backward_M_Right(void);


void HDCM_Stop(void);
void HDCM_Forward(u16 speed);
void HDCM_Back(u16 speed);
void HDCM_Right(u16 speed);
void HDCM_Left(u16 speed);



#endif /* HAL_HDCM_HDCM_INTERFACE_H_ */
