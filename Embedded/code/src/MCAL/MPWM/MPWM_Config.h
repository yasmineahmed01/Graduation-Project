/*
 * MPWM_Config.h
 *
 *  Created on: Dec 21, 2023
 *      Author: yasmi
 */

#ifndef MCAL_MPWM_MPWM_CONFIG_H_
#define MCAL_MPWM_MPWM_CONFIG_H_



#define PWM_MODE1 0b110
#define PWM_MODE2 0b111
/* TIMx_CCMR1*/
/*Bit 15 OC2CE: Output compare 2 clear enable
 * 0: Clearing disabled  The Output Compare 2 signal is not forced to a specific state when the corresponding conditions are met.
 * 1: Clearing enabled.When certain conditions are met (determined by the configuration of the Output Compare mode and associated settings), the Output Compare 2 signal is forced to a specific state.
 * 0: OC1Ref is not affected by the ETRF input
1: OC1Ref is cleared as soon as a High level is detected on ETRF input*/
#define TIM2_CLEAR2_EN  0


/*  Bits 14:12 OC2M[2:0]
 *000: Frozen - The comparison between the output compare register TIMx_CCR2 and the
counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing
base).
001: Set channel 2to active level on match. OC1REF signal is forced high when the counter
TIMx_CNT matches the capture/compare register 1 (TIMx_CCR2).
010: Set channel 2 to inactive level on match. OC1REF signal is forced low when the
counter TIMx_CNT matches the capture/compare register 1 (TIMx_CCR2).
011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR2.
100: Force inactive level - OC1REF is forced low.
101: Force active level - OC1REF is forced high.
options
110: PWM_MODE1
111: PWM_MODE2 \ */
#define TIM2_OUTPUT2_MODE  PWM_MODE1


/*Bit 11 OC2PE: Output compare 2 preload enable
 * For PWM mode 1, the choice between enabling or disabling the preload register
 *  depends on your specific application requirements
 *  . If you want changes in the PWM duty cycle (controlled by TIMx_CCR1 in PWM mode) to take effect immediately upon writing a new value, you may set the bit to 0.
 *  If you want to synchronize the update of the PWM duty cycle with a specific event (like a timer update), you may set the bit to 1.
 *  If you set the bit to 1 (enabled): Preload register on TIMx_CCR1 is enabled. This means that when you write a new value to TIMx_CCR1, it will not take immediate effect. Instead, the new value is loaded into a preload register, and the actual update of TIMx_CCR1 occurs at a specific event, typically a timer update event.

If you set the bit to 0 (disabled): Preload register on TIMx_CCR1 is disabled. This means that when you write a new value to TIMx_CCR1, it takes immediate effect.*/
#define TIM2_PRELOAD2_EN   1



/*Bit 10 OC2FE:
 * 0: CC behaves normally depending on counter and CCR2 values even when the trigger is
ON. The minimum delay to activate CC2 output when an edge occurs on the trigger input is
5 clock cycles.
1: An active edge on the trigger input acts like a compare match on CC2 output. Then, OC
is set to the compare level independently from the result of the comparison. Delay to sample
the trigger input and to activate CC2 output is reduced to 3 clock cycles. OCFE acts only if
the channel is configured in PWM1 or PWM2 mode*/
#define TIM2_Fast2_EN  0



/*Bits 9:8 CC2S[1:0]
 * 00: CC2 channel is configured as output
01: CC2 channel is configured as input, IC2 is mapped on TI2
10: CC2 channel is configured as input, IC2 is mapped on TI1
11: CC2 channel is configured as input, IC2 is mapped on TRC*/
#define TIM2_selection2  0b00
/**********************************************/

/*Bit 7 OC1CE: Output compare 1 clear enable
 * 0: Clearing disabled  The Output Compare 1 signal is not forced to a specific state when the corresponding conditions are met.
 * 1: Clearing enabled.When certain conditions are met (determined by the configuration of the Output Compare mode and associated settings), the Output Compare 2 signal is forced to a specific state.
 * 0: OC1Ref is not affected by the ETRF input
1: OC1Ref is cleared as soon as a High level is detected on ETRF input*/
#define TIM2_CLEAR1_EN  0
/*  Bits 6:4 OC1M[2:0]
 *000: Frozen - The comparison between the output compare register TIMx_CCR1 and the
counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing
base).
001: Set channel 2to active level on match. OC1REF signal is forced high when the counter
TIMx_CNT matches the capture/compare register 1 (TIMx_CCR2).
010: Set channel 2 to inactive level on match. OC1REF signal is forced low when the
counter TIMx_CNT matches the capture/compare register 1 (TIMx_CCR2).
011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR2.
100: Force inactive level - OC1REF is forced low.
101: Force active level - OC1REF is forced high.
110: PWM_MODE1
111: PWM_MODE2\ */
#define TIM2_OUTPUT1_MODE PWM_MODE1
/*Bit 3 OC1PE: Output compare 1 preload enable
 * For PWM mode 1, the choice between enabling or disabling the preload register
 *  depends on your specific application requirements
 *  . If you want changes in the PWM duty cycle (controlled by TIMx_CCR1 in PWM mode) to take effect immediately upon writing a new value, you may set the bit to 0.
 *  If you want to synchronize the update of the PWM duty cycle with a specific event (like a timer update), you may set the bit to 1.
 *  If you set the bit to 1 (enabled): Preload register on TIMx_CCR1 is enabled. This means that when you write a new value to TIMx_CCR1, it will not take immediate effect. Instead, the new value is loaded into a preload register, and the actual update of TIMx_CCR1 occurs at a specific event, typically a timer update event.

If you set the bit to 0 (disabled): Preload register on TIMx_CCR1 is disabled. This means that when you write a new value to TIMx_CCR1, it takes immediate effect.*/
#define TIM2_PRELOAD1_EN   1
/*Bit 2 OC1FE:
 * 0: CC behaves normally depending on counter and CCR2 values even when the trigger is
ON. The minimum delay to activate CC2 output when an edge occurs on the trigger input is
5 clock cycles.
1: An active edge on the trigger input acts like a compare match on CC2 output. Then, OC
is set to the compare level independently from the result of the comparison. Delay to sample
the trigger input and to activate CC2 output is reduced to 3 clock cycles. OCFE acts only if
the channel is configured in PWM1 or PWM2 mode*/
#define TIM2_Fast1_EN  0
/*Bits 1:0 CC1S[1:0]
 * 00: CC1 channel is configured as output
01: CC1 channel is configured as input, IC1 is mapped on TI2
10: CC1 channel is configured as input, IC1 is mapped on TI1
11: CC1 channel is configured as input, IC1 is mapped on TRC*/
#define TIM2_selection1   0b00
/*********************TIMX_CCMR2**************************/

/* TIMx_CCMR1*/
/*Bit 15 OC4CE: Output compare 2 clear enable
*/
#define TIM2_CLEAR4_EN  0


/*  Bits 14:12 OC4M[2:0]
 *000: Frozen - The comparison between the output compare register TIMx_CCR2 and the
counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing
base).
001: Set channel 2to active level on match. OC1REF signal is forced high when the counter
TIMx_CNT matches the capture/compare register 1 (TIMx_CCR2).
010: Set channel 2 to inactive level on match. OC1REF signal is forced low when the
counter TIMx_CNT matches the capture/compare register 1 (TIMx_CCR2).
011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR2.
100: Force inactive level - OC1REF is forced low.
101: Force active level - OC1REF is forced high.
110: PWM_MODE1
111: PWM_MODE2\ */
#define TIM2_OUTPUT4_MODE PWM_MODE1


/*Bit 11 OC4PE: Output compare 2 preload enable
 * For PWM mode 1, the choice between enabling or disabling the preload register
 *  depends on your specific application requirements
 *  . If you want changes in the PWM duty cycle (controlled by TIMx_CCR1 in PWM mode) to take effect immediately upon writing a new value, you may set the bit to 0.
 *  If you want to synchronize the update of the PWM duty cycle with a specific event (like a timer update), you may set the bit to 1.
 *  If you set the bit to 1 (enabled): Preload register on TIMx_CCR1 is enabled. This means that when you write a new value to TIMx_CCR1, it will not take immediate effect. Instead, the new value is loaded into a preload register, and the actual update of TIMx_CCR1 occurs at a specific event, typically a timer update event.

If you set the bit to 0 (disabled): Preload register on TIMx_CCR1 is disabled. This means that when you write a new value to TIMx_CCR1, it takes immediate effect.*/
#define TIM2_PRELOAD4_EN   1



/*Bit 10 OC4FE:
 * 0: CC behaves normally depending on counter and CCR2 values even when the trigger is
ON. The minimum delay to activate CC2 output when an edge occurs on the trigger input is
5 clock cycles.
1: An active edge on the trigger input acts like a compare match on CC2 output. Then, OC
is set to the compare level independently from the result of the comparison. Delay to sample
the trigger input and to activate CC2 output is reduced to 3 clock cycles. OCFE acts only if
the channel is configured in PWM1 or PWM2 mode*/
#define TIM2_Fast4_EN  0



/*Bits 9:8 CC4S[1:0]
 * 00: CC4 channel is configured as output
01: CC4 channel is configured as input, IC4 is mapped on TI2
10: CC4 channel is configured as input, IC4 is mapped on TI1
11: CC4 channel is configured as input, IC4 is mapped on TRC*/
#define TIM2_selection4  0b00
/**********************************************/

/*Bit 7 OC3CE: Output compare 1 clear enable
 * 0: Clearing disabled  The Output Compare 1 signal is not forced to a specific state when the corresponding conditions are met.
 * 1: Clearing enabled.When certain conditions are met (determined by the configuration of the Output Compare mode and associated settings), the Output Compare 2 signal is forced to a specific state.
 * 0: OC1Ref is not affected by the ETRF input
1: OC1Ref is cleared as soon as a High level is detected on ETRF input*/
#define TIM2_CLEAR3_EN  0
/*  Bits 6:4 OC3M[2:0]
 *000: Frozen - The comparison between the output compare register TIMx_CCR1 and the
counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing
base).
001: Set channel 2to active level on match. OC1REF signal is forced high when the counter
TIMx_CNT matches the capture/compare register 1 (TIMx_CCR2).
010: Set channel 2 to inactive level on match. OC1REF signal is forced low when the
counter TIMx_CNT matches the capture/compare register 1 (TIMx_CCR2).
011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR2.
100: Force inactive level - OC1REF is forced low.
101: Force active level - OC1REF is forced high.
110: PWM_MODE1
111: PWM_MODE2\ */
#define TIM2_OUTPUT3_MODE PWM_MODE1
/*Bit 3 OC3PE: Output compare 1 preload enable
 * For PWM mode 1, the choice between enabling or disabling the preload register
 *  depends on your specific application requirements
 *  . If you want changes in the PWM duty cycle (controlled by TIMx_CCR1 in PWM mode) to take effect immediately upon writing a new value, you may set the bit to 0.
 *  If you want to synchronize the update of the PWM duty cycle with a specific event (like a timer update), you may set the bit to 1.
 *  If you set the bit to 1 (enabled): Preload register on TIMx_CCR1 is enabled. This means that when you write a new value to TIMx_CCR1, it will not take immediate effect. Instead, the new value is loaded into a preload register, and the actual update of TIMx_CCR1 occurs at a specific event, typically a timer update event.

If you set the bit to 0 (disabled): Preload register on TIMx_CCR1 is disabled. This means that when you write a new value to TIMx_CCR1, it takes immediate effect.*/
#define TIM2_PRELOAD3_EN   1
/*Bit 2 OC3FE:
 * 0: CC behaves normally depending on counter and CCR2 values even when the trigger is
ON. The minimum delay to activate CC2 output when an edge occurs on the trigger input is
5 clock cycles.
1: An active edge on the trigger input acts like a compare match on CC2 output. Then, OC
is set to the compare level independently from the result of the comparison. Delay to sample
the trigger input and to activate CC2 output is reduced to 3 clock cycles. OCFE acts only if
the channel is configured in PWM1 or PWM2 mode*/
#define TIM2_Fast3_EN  0
/*Bits 1:0 CC3S[1:0]
 * 00: CC3 channel is configured as output
01: CC3 channel is configured as input, IC3 is mapped on TI2
10: CC3 channel is configured as input, IC3 is mapped on TI1
11: CC3 channel is configured as input, IC3 is mapped on TRC*/
#define TIM2_selection3  0b00
/**********************************************************************/
/******************(TIMx_CR1)********************/
/*Bits 9:8 CKD: Clock division
This bit-field indicates the division ratio between the timer clock (CK_INT) frequency and
sampling clock used by the digital filters (ETR, TIx),
00: tDTS = tCK_INT
01: tDTS = 2 � tCK_INT
10: tDTS = 4 � tCK_INT
11: Reserved*/
#define TIM2_Clock_Division 0b11

/*	Bit 7 ARPE:Auto-reload preload enable
 *	0: TIMx_ARR register is not buffered
	1: TIMx_ARR register is buffered  // ARPE.  Operations on ARR are taken into account at next update event */
#define TIM2_Auto_preload_enable  1

/*Bits 6:5 CMS: Center-aligned mode selection
00: Edge-aligned mode. The counter counts up or down depending on the direction bit
(DIR).
01: Center-aligned mode 1. The counter counts up and down alternatively. Output compare
interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
only when the counter is counting down.
10: Center-aligned mode 2. The counter counts up and down alternatively. Output compare
interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
only when the counter is counting up.
11: Center-aligned mode 3. The counter counts up and down alternatively. Output compare
interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
both when the counter is counting up or down.*/
#define TIM2_Center_aligned_mode  0b00

/*Bit 4 DIR: Direction
0: Counter used as upcounter
1: Counter used as downcounter
Note: This bit is read only when the timer is configured in Center-aligned mode or Encoder
mode.*/
#define TIM2_DIR  0

/*
 * 	Bit 3 OPM: One-pulse mode
	0: Counter is not stopped at update event
	1: Counter stops counting at the next update event (clearing the bit CEN)
 *
 */

#define TIM2_One_Pulse_Mode 0


/*
 * 	Bit 2 URS: Update request source
	This bit is set and cleared by software to select the UEV event sources.
	0: Any of the following events generate an update interrupt or DMA request if enabled.
	These events can be:
	� Counter overflow/underflow
	� Setting the UG bit
	� Update generation through the slave mode controller
	1: Only counter overflow/underflow generates an update interrupt or DMA request if
	enabled.
 *
 */

#define TIM2_URS 0

/*Bit 1 UDIS: Update disable
This bit is set and cleared by software to enable/disable UEV event generation.
0: UEV enabled. The Update (UEV) event is generated by one of the following events:
� Counter overflow/underflow
� Setting the UG bit
� Update generation through the slave mode controller
Buffered registers are then loaded with their preload values.
1: UEV disabled. The Update event is not generated, shadow registers keep their value
(ARR, PSC, CCRx). However the counter and the prescaler are reinitialized if the UG bit is
set or if a hardware reset is received from the slave mode controller*/

#define TIM2_UDIS 0

//ARR
#define ARR_Period 3300
/*prescaler
 * PSC[15:0]: Prescaler value
The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
PSC contains the value to be loaded in the active prescaler register at each update event
(including when the counter is cleared through UG bit of TIMx_EGR register or through
trigger controller when configured in �reset mode�).*/
#define PRESCALER     0
/**********************/
/*put interuot regs and enable and status*/












#endif /* MCAL_MPWM_MPWM_CONFIG_H_ */
