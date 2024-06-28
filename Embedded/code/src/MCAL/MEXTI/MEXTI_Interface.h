/*
 * MEXTI_Interface.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_


typedef enum
{
	EXTI_LINE0 = 0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15


}EXTI_LINE_t;

typedef enum
{
	EXTI_RISING,
	EXTI_FALLING,
	EXTI_ANY_CHANGE
}EXTI_TRIGGER_t;

typedef enum
{
	PORTA = 0,
	PORTB,
	PORTC
}EXTI_PORT_t;

#define EXTI_CFG_MUSK0 0xFFFFFFF0
#define EXTI_CFG_MUSK1 0xFFFFFF0F
#define EXTI_CFG_MUSK2 0xFFFFF0FF
#define EXTI_CFG_MUSK3 0xFFFF0FFF

/*#####################################################################################################*/
/*                                      Function Prototypes                                            */
/*#####################################################################################################*/

void MEXTI_vInterruptEnable(EXTI_LINE_t Copy_u8Line);
void MEXTI_vInterruptDisable(EXTI_LINE_t Copy_u8Line);
void MEXTI_vInterruptTrigger(EXTI_LINE_t Copy_u8Line , EXTI_TRIGGER_t Copy_u8Trigger);
void MEXTI_vSoftwareInterrupt(EXTI_LINE_t Copy_u8Line);
void MEXTI_vSetInterruptConfig(EXTI_LINE_t Copy_u8Line , EXTI_PORT_t Copy_u8Port);
void MEXTI0_vCallBackFunc(void (*ptr)(void));







#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
