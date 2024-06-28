#ifndef MCAL_MSPI_PRIVATE_H_
#define MCAL_MSPI_PRIVATE_H_


#include "../../LIB/STD_Types.h"
#define NUM_OF_SPI 3

typedef struct SPI_R
{
    u32 SPI_CR1    ;
    u32 SPI_CR2    ;
    u32 SPI_SR     ;
    u32 SPI_DR     ;
    u32 SPI_CRCPR  ;
    u32 SPI_RXCRCR ;
    u32 SPI_TXCRCR ;
    u32 SPI_I2SCFGR;
    u32 SPI_I2SPR  ;
}SPI_R;


volatile SPI_R* arrSPI[NUM_OF_SPI] =
{
    ((volatile SPI_R *)0x40013000), //SPI1
    ((volatile SPI_R *)0x40003800), //SPI2
    ((volatile SPI_R *)0x40003C00), //SPI3
};



/* SPI_CR1 Register */
#define SPI_CR1_BIDIMODE         15
#define SPI_CR1_BIDIOE           14
#define SPI_CR1_CRCEN            13
#define SPI_CR1_CRCNEXT          12
#define SPI_CR1_DFF              11
#define SPI_CR1_RXONLY           10
#define SPI_CR1_SSM               9
#define SPI_CR1_SSI               8
#define SPI_CR1_LSBFIRST          7
#define SPI_CR1_SPE               6
#define SPI_CR1_BR2              5
#define SPI_CR1_BR1              4
#define SPI_CR1_BR0              3
#define SPI_CR1_MSTR              2
#define SPI_CR1_CPOL              1
#define SPI_CR1_CPHA              0

/* SPI_CR2 Register */
#define SPI_CR2_TXEIE            7
#define SPI_CR2_RXNEIE           6
#define SPI_CR2_ERRIE            5
#define SPI_CR2_SSOE             2
#define SPI_CR2_TXDMAEN          1
#define SPI_CR2_RXDMAEN          0

/* SPI_SR Register */
#define SPI_SR_TXE               1
#define SPI_SR_RXNE              0
#define SPI_SR_BSY               7
#define SPI_SR_OVR               6
#define SPI_SR_MODF              5
#define SPI_SR_CRCERR            4
#define SPI_SR_UDR               3

/* SPI_DR Register */
#define SPI_DR_DATA              15

/* SPI_CRCPR Register */
#define SPI_CRCPR_CRCPOLY        15

/* SPI_RXCRCR Register */
#define SPI_RXCRCR_RXCRC         15

/* SPI_TXCRCR Register */
#define SPI_TXCRCR_TXCRC         15

/* SPI_I2SCFGR Register */
#define SPI_I2SCFGR_I2SMOD       11
#define SPI_I2SCFGR_I2SE         10
#define SPI_I2SCFGR_I2SCFG1      9
#define SPI_I2SCFGR_I2SCFG0      8
#define SPI_I2SCFGR_PCMSYNC       7
#define SPI_I2SCFGR_I2SSTD1      5
#define SPI_I2SCFGR_I2SSTD0      4
#define SPI_I2SCFGR_CKPOL        3
#define SPI_I2SCFGR_DATLEN1      2
#define SPI_I2SCFGR_DATLEN0      1
#define SPI_I2SCFGR_CHLEN         0

/* SPI_I2SPR Register */
#define SPI_I2SPR_MCKOE           9
#define SPI_I2SPR_ODD             8
#define SPI_I2SPR_I2SDIV7        7
#define SPI_I2SPR_I2SDIV6        6
#define SPI_I2SPR_I2SDIV5        5
#define SPI_I2SPR_I2SDIV4        4
#define SPI_I2SPR_I2SDIV3        3
#define SPI_I2SPR_I2SDIV2        2
#define SPI_I2SPR_I2SDIV1        1
#define SPI_I2SPR_I2SDIV0        0




#endif /* MCAL_MADC_MADC_PRIVATE_H_ */
