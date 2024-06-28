
#include"H_JoyStick_Interface.h"

void H_Joystick_init(void){
    /*
    gpio b0    b1
   CHANNEL_8,//PB0
   CHANNEL_9,//PB1
    */
   // input analog pin for the adc
    MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_INPUT_ANALOG);
    MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_INPUT_ANALOG);

    MADC_vSet_Channel_Seq(CHANNEL_4,1,ADC_1);
    MADC_vSet_Channel_Seq(CHANNEL_0,1,ADC_2);

    MADC_vInit(ADC_1,CHANNEL_4);
    MADC_vInit(ADC_2,CHANNEL_0);
}
// NEED ARRAY OF 2 VALUES 1-VRx 2- VRy
u16 H_Joystick_Read_x(void){
u16 X_Data = MADC_u16ReadData(ADC_1);
return X_Data;
}
u16 H_Joystick_Read_y(void){
u16 Y_Data = MADC_u16ReadData(ADC_2);
return Y_Data;
}
