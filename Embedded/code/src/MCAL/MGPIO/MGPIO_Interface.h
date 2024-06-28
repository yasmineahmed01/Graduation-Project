/*
 * MGPIO_Interface.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MGPIO_MGPIO_INTERFACE_H_
#define MCAL_MGPIO_MGPIO_INTERFACE_H_


#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

/* Ports Definitions */
#define GPIO_PORTA  0
#define GPIO_PORTB  1
#define GPIO_PORTC  2




/* Pins Definitions */
#define GPIO_PIN0   0
#define GPIO_PIN1   1
#define GPIO_PIN2   2
#define GPIO_PIN3   3
#define GPIO_PIN4   4
#define GPIO_PIN5   5
#define GPIO_PIN6   6
#define GPIO_PIN7   7
#define GPIO_PIN8   8
#define GPIO_PIN9   9
#define GPIO_PIN10  10
#define GPIO_PIN11  11
#define GPIO_PIN12  12
#define GPIO_PIN13  13
#define GPIO_PIN14  14
#define GPIO_PIN15  15


/* Modes Definitions */

// 2 config General Purpose x 3 modes OUTPUT = 6
#define GPIO_GP_OUTPUT_PP_10MHZ   0b0001
#define GPIO_GP_OUTPUT_PP_2MHZ    0b0010
#define GPIO_GP_OUTPUT_PP_50MHZ   0b0011

#define GPIO_GP_OUTPUT_OD_10MHZ   0b0101
#define GPIO_GP_OUTPUT_OD_2MHZ    0b0110
#define GPIO_GP_OUTPUT_OD_50MHZ   0b0111

// 2 config Alternative Func. x 3 modes OUTPUT = 6
#define GPIO_AF_OUTPUT_PP_10MHZ   0b1001
#define GPIO_AF_OUTPUT_PP_2MHZ    0b1010
#define GPIO_AF_OUTPUT_PP_50MHZ   0b1011

#define GPIO_AF_OUTPUT_OD_10MHZ   0b1101
#define GPIO_AF_OUTPUT_OD_2MHZ    0b1110
#define GPIO_AF_OUTPUT_OD_50MHZ   0b1111

// 3 config  x 1 mode INPUT = 3
#define GPIO_INPUT_ANALOG         0b0000
#define GPIO_INPUT_FLOATING       0b0100
#define GPIO_INPUT_PU_PD          0b1000


/* Values Definitions */
#define GPIO_LOW    0
#define GPIO_HIGH   1



/*prototypes of functions */
void MGPIO_vSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Mode) ;
void MGPIO_vSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value) ;
// talma ha5od value yb2a msh void
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin) ;






#endif /* MCAL_MGPIO_MGPIO_INTERFACE_H_ */
