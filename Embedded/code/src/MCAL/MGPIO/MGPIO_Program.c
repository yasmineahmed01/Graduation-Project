/*
 * MGPIO_Program.c
 *
 *  Created on: Dec 20, 2023
 *      Author: yasmi
 */




#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_Types.h"
#include"MGPIO_Config.h"
#include"MGPIO_Interface.h"
#include"MGPIO_Private.h"



void MGPIO_vSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Mode){
switch (Copy_u8Port)
{
case GPIO_PORTA :
    // 3mlt if 3lashan a3rf rkm el pin w 3la asasoh a7otoh fe anhi reg
    if(Copy_u8Pin < 8){
    // hms7 mkan el mode ely mwgood
         GPIOA -> CRL &= ~ ((0b1111) << (Copy_u8Pin *4)) ;
  // 3mlt shift 3lashan a7ot el mode ll pin bta3ti
         GPIOA -> CRL |= ((Copy_u8Mode) << (Copy_u8Pin *4));

        }
    else if (Copy_u8Pin < 16)
        { // h3ml -8 3lashan arg3 lbit 0 a a7ot el modes sa7
           GPIOA -> CRH &= ~ ((0b1111) << ((Copy_u8Pin - 8)*4)) ;
           GPIOA -> CRH |= (Copy_u8Mode << ((Copy_u8Pin-8) *4));
        }
    break;

case GPIO_PORTB :

    if(Copy_u8Pin < 8)
        { // h3ml nfs el klam lkol port
        GPIOB -> CRL &= ~ (0b1111 << (Copy_u8Pin *4)) ;
        GPIOB -> CRL |= (Copy_u8Mode << (Copy_u8Pin *4));
        }
    else if (Copy_u8Pin < 16)
        {
          GPIOB -> CRH &= ~ (0b1111 << ((Copy_u8Pin - 8)*4)) ;
        GPIOB -> CRH |= (Copy_u8Mode << ((Copy_u8Pin-8) *4));
        }
    break;

case GPIO_PORTC :
    if(Copy_u8Pin < 8){
         GPIOA -> CRL &= ~ (0b1111 << (Copy_u8Pin *4)) ;

         GPIOA -> CRL |= (Copy_u8Mode << (Copy_u8Pin *4));
        }
    else if (Copy_u8Pin < 16)
        {
           GPIOA -> CRH &= ~ (0b1111 << ((Copy_u8Pin - 8)*4)) ;
           GPIOA -> CRH |= (Copy_u8Mode << ((Copy_u8Pin-8) *4));
        }
    break;
        }
            }


void MGPIO_vSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value){
switch (Copy_u8Port)
{
case GPIO_PORTA:
   if(Copy_u8Value == GPIO_HIGH)
   {
        GPIOA -> BSRR = (1 << Copy_u8Pin);
   }
   else if (Copy_u8Value == GPIO_LOW)
   {
        GPIOA -> BRR = (1 << Copy_u8Pin);
   }
    break;

case GPIO_PORTB:
   if(Copy_u8Value == GPIO_HIGH)
   {
        GPIOB -> BSRR = (1 << Copy_u8Pin);
   }
   else if (Copy_u8Value == GPIO_LOW)
   {
        GPIOB -> BRR = (1 << Copy_u8Pin);
   }
   break;

case GPIO_PORTC:
     if(Copy_u8Value == GPIO_HIGH)
   {
        GPIOC -> BSRR = (1 << Copy_u8Pin);
   }
    else if (Copy_u8Value == GPIO_LOW)
   {
        GPIOC -> BRR = (1 << Copy_u8Pin);
   }
    break;
}
}


u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin){
// h3ml local variable tygi 3lih el data bta3ti
u8 Local_u8ReturnValue =0;
switch (Copy_u8Port)
{
case GPIO_PORTA:
    Local_u8ReturnValue= GET_BIT(GPIOA -> IDR ,Copy_u8Pin );
    break;


case GPIO_PORTB:
    Local_u8ReturnValue= GET_BIT(GPIOB -> IDR ,Copy_u8Pin );
    break;

case GPIO_PORTC :
    Local_u8ReturnValue= GET_BIT(GPIOC -> IDR ,Copy_u8Pin );
    break;
}
return Local_u8ReturnValue;
}


