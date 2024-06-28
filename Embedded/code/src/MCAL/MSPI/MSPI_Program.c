
#include"MSPI_Interface.h"
#include"MSPI_Config.h"



void MCAL_SPI_Init(SPI_Num SPI_Number){
// Enable SPI pheripheral
 SET_BIT(arrSPI[SPI_Number]->SPI_CR1,SPI_CR1_SPE);
// Choose Master or Slave
 arrSPI[SPI_Number]->SPI_CR1 |= SPI_Configurations.Device_Mode;
//Choose Communications mode
 arrSPI[SPI_Number]->SPI_CR1 |= SPI_Configurations.Communication_mode;
//Choose Frame Format
arrSPI[SPI_Number]->SPI_CR1 |= SPI_Configurations.Frame_Format;
//Choose Clock Phase
arrSPI[SPI_Number]->SPI_CR1 |= SPI_Configurations.CLKPhase;
// Choose Clock Polarity
arrSPI[SPI_Number]->SPI_CR1 |= SPI_Configurations.CLKPolarity;
// Choose Data size
arrSPI[SPI_Number]->SPI_CR1 |= SPI_Configurations.Data_Size;
// Choose NSS
arrSPI[SPI_Number]->SPI_CR1 |= SPI_Configurations.NSS;
// Choose BaudRate
arrSPI[SPI_Number]->SPI_CR1 |= SPI_Configurations.SPI_CLK_Freq;
}
void MCAL_SPI_GPIO_SET_PINS(SPI_Num SPIx){
    if(SPIx==SPI_1){
        if(SPI_Configurations.Device_Mode == SPI_Master_Mode ) 
        //Sclock pin selection
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_AF_OUTPUT_PP_10MHZ);
        //MISO pin Selection 
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN4,GPIO_INPUT_FLOATING);
        //MOSI
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN5,GPIO_AF_OUTPUT_PP_10MHZ);
    }else if(SPI_Configurations.Device_Mode == SPI_Slave_Mode){
        //Sclock pin selection
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_INPUT_FLOATING);
        //MISO pin Selection 
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN4,GPIO_AF_OUTPUT_PP_10MHZ);
        //MOSI
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN5,GPIO_INPUT_FLOATING);
    }
    else if( SPIx == SPI_2){
        if(SPI_Configurations.Device_Mode == SPI_Master_Mode ) 
        //Sclock pin selection
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN13,GPIO_AF_OUTPUT_PP_10MHZ);
        //MISO pin Selection 
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN14,GPIO_INPUT_FLOATING);
        //MOSI
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN15,GPIO_AF_OUTPUT_PP_10MHZ);
    }else if(SPI_Configurations.Device_Mode == SPI_Slave_Mode){
        //Sclock pin selection
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN13,GPIO_INPUT_FLOATING);
        //MISO pin Selection 
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN14,GPIO_AF_OUTPUT_PP_10MHZ);
        //MOSI
        MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN15,GPIO_INPUT_FLOATING);
    }
    }

void MCAL_SPI_SendData(u16 Data ,SPI_Num SPI_Number)
{
    /*wait until Flag is high*/
   while (GET_BIT(arrSPI[SPI_Number]->SPI_SR,SPI_SR_TXE)  == 0);
   Data=arrSPI[SPI_Number]->SPI_DR;

}
u16 MCAL_SPI_ReceiveData(SPI_Num SPI_Number)
{
   u16 RetuernedValue;
    /*wait until Flag is high*/
   while (GET_BIT(arrSPI[SPI_Number]->SPI_SR,SPI_SR_RXNE)  == 0);

   RetuernedValue=arrSPI[SPI_Number]->SPI_DR;

   return RetuernedValue;
}