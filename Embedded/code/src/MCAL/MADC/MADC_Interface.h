/*
 * MADC_Interface.h
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MADC_MADC_INTERFACE_H_
#define MCAL_MADC_MADC_INTERFACE_H_



#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

/*choose independent mode*/
#define Single_Mode                 0
#define Cont_Mode                   1
#define Single_Mode_And_Scan_Mode   2
#define Cont_Mode_And_Scan_Mode     3

/*choose Data Align*/
#define Right_Align 0
#define Left_Align  1

/*choose encable or disable EOC interrupt*/
#define Disable_EOC 0
#define Enable_EOC  1

/*choose sample time*/
#define _1_5_cycles    0
#define _7_5_cycles    1
#define _13_5_cycles   2
#define _28_5_cycles   3
#define _41_5_cycles   4
#define _55_5_cycles   5
#define _71_5_cycles   6
#define _239_5_cycles  7

/*choose channel*/
typedef enum
{
   CHANNEL_0=0, //PA0
   CHANNEL_1,//PA1
   CHANNEL_2,//PA2
   CHANNEL_3,//PA3
   CHANNEL_4,//PA4
   CHANNEL_5,//PA5
   CHANNEL_6,//PA5
   CHANNEL_7,//PA7
   CHANNEL_8,//PB0
   CHANNEL_9,//PB1
   CHANNEL_10,//PC0
   CHANNEL_11,//PC1
   CHANNEL_12,//PC2
   CHANNEL_13,//PC3
   CHANNEL_14,//PC4
   CHANNEL_15,//PC5
   CHANNEL_16,//internal
   CHANNEL_17//internal
}Enu_ADC_Channels;


/*
PA0 -> ADC12_IN0
PA1 -> ADC12_IN1
PA2 -> ADC12_IN2
PA3 -> ADC12_IN3
PA4 -> ADC12_IN4
PA5 -> ADC12_IN5
PA6 -> ADC12_IN6
PA7 -> ADC12_IN7
PB0 -> ADC12_IN8
PB1 -> ADC12_IN9

PC0 -> ADC12_IN10
PC1 -> ADC12_IN11
PC2 -> ADC12_IN12
PC3 -> ADC12_IN13
PC4 -> ADC12_IN14
PC5 -> ADC12_IN15

ADC12_IN16 input channel which is used to convert the sensor output voltage into a digital value.


*/
/*Regular channel sequence length */
typedef enum
{
   _1_CONV=1,
   _2_CONV,
   _3_CONV,
   _4_CONV,
   _5_CONV,
   _6_CONV,
   _7_CONV,
   _8_CONV,
   _9_CONV,
   _10_CONV,
   _11_CONV,
   _12_CONV,
   _13_CONV,
   _14_CONV,
   _15_CONV,
   _16_CONV
}ADC_Channels_seq_Length;


/*ADC_NUM*/
typedef enum
{
   ADC_1=0,
   ADC_2
}ADC_Num;


void MADC_vInit(ADC_Num Copy_ADC_NUM , Enu_ADC_Channels Channel_num);
void MADC_vSet_Channel_Seq(Enu_ADC_Channels Channel_num,u32 Copy_u32Seq ,ADC_Num Copy_ADC_NUM);
void MADC_SetNumberOfChannels(ADC_Num Copy_ADC_NUM, ADC_Channels_seq_Length Copy_u8Channels);
void MADC_vDisable(ADC_Num Copy_ADC_NUM);
int adc_rx(ADC_Num Copy_ADC_NUM);
char adc_check(ADC_Num Copy_ADC_NUM );
void MADC_vSet_Sample_Time(Enu_ADC_Channels Channel_num,u32 Copy_Sample_Time ,ADC_Num Copy_ADC_NUM);
u16 MADC_u16ReadData(ADC_Num Copy_ADC_NUM);

#endif /* MCAL_MADC_MADC_INTERFACE_H_ */
