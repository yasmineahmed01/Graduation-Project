/*
 * MRCC_Private.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_

#include "../../LIB/STD_Types.h"

#define RCC_Base_Address 0x4002 1000
#define FLASH_ACR  *((volatile u32*)0x40022000+0)



typedef struct {
	u32 CR;
	u32 CFGR ;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;



}RCC_t;

#define RCC    ((volatile RCC_t*) 0x40021000)




#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
