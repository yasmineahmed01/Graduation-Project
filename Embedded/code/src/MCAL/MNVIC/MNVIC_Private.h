/*
 * MNVIC_Private.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MNVIC_MNVIC_PRIVATE_H_
#define MCAL_MNVIC_MNVIC_PRIVATE_H_



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"


typedef struct  //modified
{
    u32 ISER[3];
    u32 Reserved1[29];
    u32 ICER[3];
    u32 Reserved2[29];
    u32 ISPR[3];
    u32 Reserved3[29];
    u32 ICPR[3];
    u32 Reserved4[29];
    u32 IABR[3];
    u32 Reserved5[61];
    u8  IPR[84];
    u32 Reserved6[695];
    u32 STIR;

}MNVIC_T;

#define MNVIC_BASE_ADD 0xE000E100 //Modified
#define NVIC ((volatile MNVIC_T* )MNVIC_BASE_ADD)
#define AIRCR (*(volatile u32*)0xE000ED0C)
#define Register_NO 32
#define MNVIC_VECTKEY 0x05FA0000




#endif /* MCAL_MNVIC_MNVIC_PRIVATE_H_ */
