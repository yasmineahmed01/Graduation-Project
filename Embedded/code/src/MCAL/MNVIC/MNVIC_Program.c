/*
 * MNVIC_Program.c
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */







#include "MNVIC_Interface.h"
/*************************Global Variables*****************************/
u32 Global_u32Set_GroupPriority;


/**
 * return type : void
 * input Paramters:A_u8InterruptID
 * function: enable external interrupts
*/
void MNVIC_vInterruptSetEnable(u8 A_u8InterruptID){
        u8 Register = A_u8InterruptID/Register_NO; //Get Register Number
        u8 BIT_NO=A_u8InterruptID%Register_NO;  //Get Bit Number
        NVIC->ISER[Register] |= (1<<BIT_NO);
}
void MNVIC_vInterruptClearEnable(u8 A_u8InterruptID){
        u8 Register = A_u8InterruptID/Register_NO; //Get Register Number
        u8 BIT_NO=A_u8InterruptID%Register_NO;  //Get Bit Number
        NVIC->ICER[Register] |= (1<<BIT_NO);
}
/**
 * return type : void
 * input Paramters:Copy_GroupMode
 * function: Set group mode in SCB(AIRCR)
*/

void MNVIC_vSetGroupMode(Group_Mode Copy_GroupMode){
    Global_u32Set_GroupPriority= MNVIC_VECTKEY |(Copy_GroupMode<<8);
    AIRCR=Global_u32Set_GroupPriority;
}
/**
 * return type : void
 * input Paramters:Copy_u8InterruptId, Copy_GroupId, Copy_SubGroupId
 * function: Set group and Subgroup priority for interrupt
*/
void MNVIC_vSetInterruptPriority(u8 Copy_u8InterruptId,u8 Copy_GroupId,u8 Copy_SubGroupId){
    switch (Global_u32Set_GroupPriority)
    {
    case MNVIC_G16_SG0:NVIC->IPR[Copy_u8InterruptId]=(Copy_GroupId<<4);break;
    case MNVIC_G8_SG2:NVIC->IPR[Copy_u8InterruptId]=(Copy_GroupId<<5);
    NVIC->IPR[Copy_u8InterruptId]=(Copy_SubGroupId<<4);
    break;
    case MNVIC_G4_SG4:NVIC->IPR[Copy_u8InterruptId]=(Copy_GroupId<<6);
    NVIC->IPR[Copy_u8InterruptId]=(Copy_SubGroupId<<4);
    break;
    case MNVIC_G2_SG8:NVIC->IPR[Copy_u8InterruptId]=(Copy_GroupId<<7);
    NVIC->IPR[Copy_u8InterruptId]=(Copy_SubGroupId<<4);
    break;
    case MNVIC_G0_SG16: NVIC->IPR[Copy_u8InterruptId]=(Copy_SubGroupId<<4);
    break;
    default:
        break;
    }
}

