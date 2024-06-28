/*
 * MNVIC_Interface.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MNVIC_MNVIC_INTERFACE_H_
#define MCAL_MNVIC_MNVIC_INTERFACE_H_


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "MNVIC_Config.h"
#include "MNVIC_Private.h"


typedef enum{
    MNVIC_G16_SG0=3
    ,MNVIC_G8_SG2
    ,MNVIC_G4_SG4
    ,MNVIC_G2_SG8
    ,MNVIC_G0_SG16
}Group_Mode;

void MNVIC_vInterruptSetEnable(u8 A_u8InterruptID);
void MNVIC_vInterruptClearEnable(u8 A_u8InterruptID);
void MNVIC_vSetGroupMode(Group_Mode Copy_GroupMode);
void MNVIC_vSetInterruptPriority(u8 Copy_u8InterruptId,u8 Copy_GroupId,u8 Copy_SubGroupId);





#endif /* MCAL_MNVIC_MNVIC_INTERFACE_H_ */
