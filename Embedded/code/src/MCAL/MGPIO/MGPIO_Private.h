/*
 * MGPIO_Private.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MGPIO_MGPIO_PRIVATE_H_
#define MCAL_MGPIO_MGPIO_PRIVATE_H_


#include "../../LIB/STD_Types.h"

/* Base address of peripherals */
#define MGPIOA_BASE_ADDRESS    0x40010800
#define MGPIOB_BASE_ADDRESS    0x40010C00
#define MGPIOC_BASE_ADDRESS    0x40011000


typedef struct
{
  volatile u32 CRL;
  volatile u32 CRH;
  volatile u32 IDR;
  volatile u32 ODR;
  volatile u32 BSRR;
  volatile u32 BRR;
  volatile u32 LCKR;
}MGPIO_t;

/* 3mlt nos5a mn el reg. lkol port */
#define GPIOA   ((MGPIO_t*)MGPIOA_BASE_ADDRESS)
#define GPIOB   ((MGPIO_t*)MGPIOB_BASE_ADDRESS)
#define GPIOC   ((MGPIO_t*)MGPIOC_BASE_ADDRESS)






#endif /* MCAL_MGPIO_MGPIO_PRIVATE_H_ */
