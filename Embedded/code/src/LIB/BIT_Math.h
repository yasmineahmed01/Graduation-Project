/*
 * BIT_Math.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef LIB__BIT_MATH_H_
#define LIB__BIT_MATH_H_


#define SET_BIT(REG,BIT_NUM) (REG|=1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM) REG&= ~(1<<BIT_NUM)
#define TOGGLE_BIT(REG,BIT_NUM) REG^=(1<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM) (1&(REG>>BIT_NUM))


#endif /* LIB__BIT_MATH_H_ */
