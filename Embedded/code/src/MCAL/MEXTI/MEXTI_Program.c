/*
 * MEXTI_Program.c
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */



#include "MEXTI_Interface.h"
#include "MEXTI_Config.h"
#include "MEXTI_Private.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"



static void (*Global_EXTI_ptr[16])(void)= {NULL};

void MEXTI_vInterruptEnable(EXTI_LINE_t Copy_u8Line)
{
	SET_BIT(EXTI -> IMR , Copy_u8Line);
}


void MEXTI_vInterruptDisable(EXTI_LINE_t Copy_u8Line)
{
	CLR_BIT(EXTI -> IMR , Copy_u8Line);
}


void MEXTI_vInterruptTrigger(EXTI_LINE_t Copy_u8Line , EXTI_TRIGGER_t Copy_u8Trigger)
{
	switch (Copy_u8Trigger)
	{
	case EXTI_RISING:     SET_BIT(EXTI -> RTSR , Copy_u8Line); break;

	case EXTI_FALLING:    SET_BIT(EXTI -> FTSR , Copy_u8Line); break;

	case EXTI_ANY_CHANGE: SET_BIT(EXTI -> RTSR , Copy_u8Line);
						  SET_BIT(EXTI -> FTSR , Copy_u8Line); break;
	default:break;
	}

}

void MEXTI_vSoftwareInterrupt(EXTI_LINE_t Copy_u8Line)
{
	SET_BIT(EXTI -> SWIER , Copy_u8Line);
}


void MEXTI_vSetInterruptConfig(EXTI_LINE_t Copy_u8Line , EXTI_PORT_t Copy_u8Port)
{


	switch (Copy_u8Line)
	{

	case EXTI_LINE0: AFIO -> EXTICR[0] &= EXTI_CFG_MUSK0;
			         AFIO -> EXTICR[0] |= Copy_u8Port;        break;

	case EXTI_LINE1: AFIO -> EXTICR[0] &= EXTI_CFG_MUSK1;
	                 AFIO -> EXTICR[0] |= Copy_u8Port <<  4;  break;

	case EXTI_LINE2: AFIO -> EXTICR[0] &= EXTI_CFG_MUSK2;
	                 AFIO -> EXTICR[0] |= Copy_u8Port <<  8;  break;

	case EXTI_LINE3: AFIO -> EXTICR[0] &= EXTI_CFG_MUSK3;
					 AFIO -> EXTICR[0] |= Copy_u8Port << 12;  break;

	case EXTI_LINE4: AFIO -> EXTICR[1] &= EXTI_CFG_MUSK0;
					 AFIO -> EXTICR[1] |= Copy_u8Port;        break;

	case EXTI_LINE5: AFIO -> EXTICR[1] &= EXTI_CFG_MUSK1;
					 AFIO -> EXTICR[1] |= Copy_u8Port <<  4;  break;

	case EXTI_LINE6: AFIO -> EXTICR[1] &= EXTI_CFG_MUSK2;
					 AFIO -> EXTICR[1] |= Copy_u8Port <<  8;  break;

	case EXTI_LINE7: AFIO -> EXTICR[1] &= EXTI_CFG_MUSK3;
					 AFIO -> EXTICR[1] |= Copy_u8Port << 12;  break;
	default:  break;

	}

}



void MEXTI0_vCallBackFunc(void (*ptr)(void))
{
	Global_EXTI_ptr[0]= ptr;
}

void EXTI0_IRQHandler(void)
{
	Global_EXTI_ptr[0]();
	SET_BIT(EXTI -> PR , 0);
}

void MEXTI1_vCallBackFunc(void (*ptr)(void))
{
	Global_EXTI_ptr[1]= ptr;
}

void EXTI1_IRQHandler(void)
{
	Global_EXTI_ptr[1]();
	SET_BIT(EXTI -> PR , 1);
}

void MEXTI2_vCallBackFunc(void (*ptr)(void))
{
	Global_EXTI_ptr[2]= ptr;
}

void EXTI2_IRQHandler(void)
{
	Global_EXTI_ptr[2]();
	SET_BIT(EXTI -> PR , 2);
}

void MEXTI3_vCallBackFunc(void (*ptr)(void))
{
	Global_EXTI_ptr[3]= ptr;
}

void EXTI3_IRQHandler(void)
{
	Global_EXTI_ptr[3]();
	SET_BIT(EXTI -> PR , 3);
}

void MEXTI4_vCallBackFunc(void (*ptr)(void))
{
	Global_EXTI_ptr[4]= ptr;
}

void EXTI4_IRQHandler(void)
{
	Global_EXTI_ptr[4]();
	SET_BIT(EXTI -> PR , 4);
}

void MEXTI5_vCallBackFunc(void (*ptr)(void))
{
	Global_EXTI_ptr[5]= ptr;
}

void EXTI5_IRQHandler(void)
{
	Global_EXTI_ptr[5]();
	SET_BIT(EXTI -> PR , 5);
}

void MEXTI6_vCallBackFunc(void (*ptr)(void))
{
	Global_EXTI_ptr[6]= ptr;
}

void EXTI6_IRQHandler(void)
{
	Global_EXTI_ptr[6]();
	SET_BIT(EXTI -> PR , 6);
}

void MEXTI7_vCallBackFunc(void (*ptr)(void))
{
	Global_EXTI_ptr[7]= ptr;
}

void EXTI7_IRQHandler(void)
{
	Global_EXTI_ptr[7]();
	SET_BIT(EXTI -> PR , 7);
}


