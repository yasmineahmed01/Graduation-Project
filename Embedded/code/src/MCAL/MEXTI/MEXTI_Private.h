/*
 * MEXTI_Private.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_


#include "../../LIB/STD_Types.h"

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}MEXTI_t;

typedef struct
{
	u32 EXTICR[4];
}MAFIO_t;

#define MEXTI_BASE_ADDRESS     0x40010400
#define MAFIO_BASE_ADDRESS     0x40010008

#define EXTI   ((volatile MEXTI_t*) MEXTI_BASE_ADDRESS)
#define AFIO   ((volatile MAFIO_t*) MAFIO_BASE_ADDRESS)

#define Musk 15
#define Div_Fac 4







#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
