

#include "MADC_Interface.h"
#include "MADC_Config.h"
#include "MADC_Private.h"
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"



void MADC_vSet_Channel_Seq(Enu_ADC_Channels Channel_num,u32 Copy_u32Seq ,ADC_Num Copy_ADC_NUM)
{    arrADC[Copy_ADC_NUM]->ADC_CR2=0; // clear cr2
   /*this function is used to do sequence of channels (which one to be converted first)*/
   if(Copy_u32Seq<7)
   {
      arrADC[Copy_ADC_NUM]->ADC_SQR3 &= ~((0x1F)<<(5*(Copy_u32Seq-1)));
      arrADC[Copy_ADC_NUM]->ADC_SQR3 |= (((u32)Channel_num)<<(5*(Copy_u32Seq-1)));
   }
    else if (Copy_u32Seq < 13)
    {
        arrADC[Copy_ADC_NUM]->ADC_SQR2 &= ~((0x1F)<<(5*(Copy_u32Seq-7)));
        arrADC[Copy_ADC_NUM]->ADC_SQR2 |= (((u32)Channel_num)<<(5*(Copy_u32Seq-7)));
    }
    /* from 13 to 16 */
    else
    {
        arrADC[Copy_ADC_NUM]->ADC_SQR1 &= ~((0x1F)<<(5*(Copy_u32Seq-13)));
        arrADC[Copy_ADC_NUM]->ADC_SQR1 |= (((u32)Channel_num)<<(5*(Copy_u32Seq-13)));
    }

}


void MADC_vInit(ADC_Num Copy_ADC_NUM , Enu_ADC_Channels Channel_num)
{

	   /*Enable ADC*/
	  SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2,ADC_CR2_ADON);



	int time =100;
	int t;
	for(;time>0;time--)
	{
	 for(t=0;t<100000;t++)
		{}}
 SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2,ADC_CR2_ADON);




    /*CHOOSE MODE*/
   #if ADC_Mode==Single_Mode
       CLR_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2,ADC_CR2_CONT);
    #elif ADC_Mode==Cont_Mode
       SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2,ADC_CR2_CONT);
    #elif ADC_Mode==Cont_Mode_And_Scan_Mode
       SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR1,ADC_CR1_SCAN);
       SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2,ADC_CR2_CONT);
    #elif ADC_Mode==Single_Mode_And_Scan_Mode
       SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR1,ADC_CR1_SCAN);
       CLR_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2,ADC_CR2_CONT);
   #endif


    /*CHOOSE ALIGN*/
   #if ADC_ALIG_STATE==Right_Align
	  CLR_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2 , ADC_CR2_ALIGN);

	 #elif ADC_ALIG_STATE==Left_Align
	  SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2 , ADC_CR2_ALIGN);

   #endif

	  SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR1 , ADC_CR2_EXTTRIG);

	  SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR1 , 17);
	  SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR1 , 18);
	  SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR1 , 19);


}

char adc_check(ADC_Num Copy_ADC_NUM )
{
	char check = 0;


			if(arrADC[Copy_ADC_NUM]->ADC_SR & 2)
			{
				check  = 1;
			}


	return check;
}


int adc_rx(ADC_Num Copy_ADC_NUM)
{
	int result = 0;


	result = arrADC[Copy_ADC_NUM]->ADC_DR ;

	result = (result*1000)/0xfff;
	result=(result*330)/100;


	return result;
}


void MADC_SetNumberOfChannels(ADC_Num Copy_ADC_NUM, ADC_Channels_seq_Length Copy_u8Channels)
{
    /* Assign the number of channels in sequence register */
    arrADC[Copy_ADC_NUM]->ADC_SQR1 |= ((Copy_u8Channels - (u8) 1) << 20);
}

void MADC_vDisable(ADC_Num Copy_ADC_NUM)
{
    /* Disable ADC */
    CLR_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2,ADC_CR2_ADON);

}


void MADC_vSet_Sample_Time(Enu_ADC_Channels Channel_num,u32 Copy_Sample_Time ,ADC_Num Copy_ADC_NUM)
{
   /*this function is used to set sample time of each channel */
   if(Channel_num>9)
   {
      arrADC[Copy_ADC_NUM]->ADC_SMPR1 &= ~((0x7)<<(3*(Channel_num-10)));
      arrADC[Copy_ADC_NUM]->ADC_SMPR1 |= (((u32)Copy_Sample_Time)<<(3*(Channel_num-10)));
   }
    else if (Channel_num < 10)
    {
       arrADC[Copy_ADC_NUM]->ADC_SMPR2 &= ~((0x7)<<(3*(Channel_num)));
       arrADC[Copy_ADC_NUM]->ADC_SMPR2 |= (((u32)Copy_Sample_Time)<<(3*(Channel_num)));
    }


}
u16 MADC_u16ReadData(ADC_Num Copy_ADC_NUM)
{
   u16 RetuernedValue;
  /* Enable interrupt for regular channels  */
	//SET_BIT(ADC[Copy_ADC_NUM]->ADC_CR1 , ADC_CR1_EOCIE);

    /* Start conversion of regular channels */
	SET_BIT(arrADC[Copy_ADC_NUM]->ADC_CR2 ,ADC_CR2_SWSTART);

    /*wait until conversion is ended*/
   while (GET_BIT(arrADC[Copy_ADC_NUM]->ADC_SR, ADC_SR_EOC)  == 0);

   RetuernedValue=arrADC[Copy_ADC_NUM]->ADC_DR;

   /*clear EOC FLAG AND STRT FLAG*/
   CLR_BIT(arrADC[Copy_ADC_NUM]->ADC_SR, ADC_SR_EOC);
	CLR_BIT(arrADC[Copy_ADC_NUM]->ADC_SR, ADC_SR_STRT);

	RetuernedValue = (RetuernedValue*1000)/0xfff;
	RetuernedValue=(RetuernedValue*330)/100;

   return RetuernedValue;

}
