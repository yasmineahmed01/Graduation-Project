
#ifndef HAL_JoyStick_INTEFACE_H_
#define HAL_JoyStick_INTERFACE_H_

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.H"
#include "../../MCAL/MGPIO/MGPIO_Interface.h"
#include"../../MCAL/MADC/MADC_Interface.h"
#include "H_Joystick_Private.h"

// we need 2 ADC pins for VRx , VRy 

void H_Joystick_init(void);
u16 H_Joystick_Read_x(void);
u16 H_Joystick_Read_y(void);


#endif