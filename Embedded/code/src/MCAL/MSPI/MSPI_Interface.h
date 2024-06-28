#ifndef MCAL_MSPI_INTERFACE_H_
#define MCAL_MSPI_INTERFACE_H_
#include"../../LIB/BIT_Math.h"
#include"../../LIB/STD_Types.h"
#include"../MGPIO/MGPIO_Interface.h"
#include"MSPI_Private.h"


 typedef struct  {
    u8 Device_Mode;
    u8 Communication_mode;
    u8 Frame_Format;
    u8 Data_Size;
    u8 CLKPolarity;
    u8 CLKPhase;
    u8 NSS;
    u8 SPI_CLK_Freq;
}SPI_Config;



/**
 * Select Master or Slave
 * 0: Slave
 * 1: Master
*/

#define SPI_Master_Mode (u32)(1<<SPI_CR1_MSTR)
#define SPI_Slave_Mode  (u32)(0<<SPI_CR1_MSTR)

/**
 * 
*/

#define SPI_DIRECTION_2LINES				(u16)(0)
#define SPI_DIRECTION_2LINES_RXONLY			(u16)(1<<SPI_CR1_RXONLY) //CR1 RXONLY:1 receive only
#define SPI_DIRECTION_1LINE_RECEIVE_ONLY	(u16)(1<<SPI_CR1_BIDIMODE) //CR1 BIDIMODE:1 bidirectional data mode enable
#define SPI_DIRECTION_1LINE_TRANSMIT_ONLY	(u16)((1<<SPI_CR1_BIDIOE) | (1<<SPI_CR1_BIDIMODE))//CR1 bit 15 is bidimode: 1 line Bidirectional data mode enable & bit 14 BIDIOE: Output enable (Transmit only)

/**
 * Data Frame Format
 *  0: 8-bit data frame format is selected for transmission/reception
 *  1:16-bit data frame format is selected for transmission/reception
*/
#define SPI_8_DataSize     (u32)(0<<SPI_CR1_DFF)
#define SPI_16_DataSize     (u32)(1<<SPI_CR1_DFF)

/**
 * Select most or least signficant bit
 *  0: MSB transmitted first
 *  1: LSB transmitted first
*/
#define SPI_MSB     (u32)(0<<SPI_CR1_LSBFIRST)
#define SPI_LSB     (u32)(1<<SPI_CR1_LSBFIRST)

/**
 * Clock Polarity
 *  0: CK to 0 when idle
 *  1: CK to 1 when idle
*/
#define SPI_CLK_Low     (u32)(0<<SPI_CR1_CPOL) 
#define SPI_CLK_High    (u32)(1<<SPI_CR1_CPOL)

/**
 * Clock phase
 *  0: The first clock transition is the first data capture edge
 * 1: The second clock transition is the first data capture edge
*/
#define SPI_FirstClk (u32)(0<<SPI_CR1_CPHA)
#define SPI_SecondClk (u32)(1<<SPI_CR1_CPHA)

/**
 *  0: Software slave management disabled
 *  1: Software slave management enabled
*/
#define SPI_Software_ON  (u32)(1<<SPI_CR1_SSM) | (1<<SPI_CR1_SSI)
#define SPI_Software_OFF (u32)(0<<SPI_CR1_SSM)

//@ref SPI_BAUDRATEPRESCALER
#define SPI_BAUDRATEPRESCALER_2         (0<<SPI_CR1_BR0)
#define SPI_BAUDRATEPRESCALER_4         (0b001 << SPI_CR1_BR0)
#define SPI_BAUDRATEPRESCALER_8         (0b010 << SPI_CR1_BR0)
#define SPI_BAUDRATEPRESCALER_16        (0b011 << SPI_CR1_BR0)
#define SPI_BAUDRATEPRESCALER_32        (0b100 << SPI_CR1_BR0)
#define SPI_BAUDRATEPRESCALER_64        (0b101 << SPI_CR1_BR0)
#define SPI_BAUDRATEPRESCALER_128       (0b110 << SPI_CR1_BR0)
#define SPI_BAUDRATEPRESCALER_256       (0b111 << SPI_CR1_BR0)

typedef enum
{
   SPI_1=0,
   SPI_2,
}SPI_Num;


void MCAL_SPI_Init(SPI_Num SPI_Number);
void MCAL_SPI_GPIO_SET_PINS(SPI_Num SPIx);
u16 MCAL_SPI_ReceiveData(SPI_Num SPI_Number);
void MCAL_SPI_SendData(u16 Data ,SPI_Num SPI_Number);
#endif
