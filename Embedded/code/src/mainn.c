u16 now_x;
u16 now_y;
s32 previous_x=4;
u16 previous_y;
u16 analog_rx;
u16 analog_ry;
s32 current_speed = 0;
s32 target_speed = 0;
bool is_stopping = false;


/*
void gradual_stop() {
     (is_stopping == true ) {
        
			previous_x -= SPEED_DECREMENT;
			if (previous_x < MIN_SPEED) {
            previous_x = MIN_SPEED;
        }
			HDCM_Stop(previous_x);
      // Add a small delay to simulate gradual stopping
      for (volatile int i = 0; i < 10000; i++);  // Simple delay loo
			if (previous_x == MIN_SPEED) {
        is_stopping = false;
		    HDCM_Stop(0);
			}
			
			}
}*/

void control_motor() {
		
    analog_rx = H_Joystick_Read_x();
    analog_ry = H_Joystick_Read_y();
    while ((analog_rx > 1700) && (analog_ry > 1400) && (analog_ry < 1700)) {
        // Forward
			analog_rx = H_Joystick_Read_x();
    analog_ry = H_Joystick_Read_y();
        current_speed = analog_rx ;
        HDCM_Forward(current_speed-1700);
				previous_x = current_speed;
        is_stopping = false;
    } while ((analog_rx > 1400) && (analog_rx < 1700) && (analog_ry > 1400) && (analog_ry < 1700)) {
        // STOP gradually
			analog_rx = H_Joystick_Read_x();
			analog_ry = H_Joystick_Read_y();
        is_stopping = true;
			HDCM_Stop(0);
			
				
			// gradual_stop();
    }  while ((analog_rx < 1400) && (analog_ry > 1400) && (analog_ry < 1700)) {
			analog_rx = H_Joystick_Read_x();
    analog_ry = H_Joystick_Read_y();
        // Backward
        current_speed =  analog_rx;
				previous_x = current_speed;
        HDCM_Back(2000-current_speed);
        is_stopping = false;
    } while ((analog_ry > 1700) && (analog_rx > 1400) && (analog_rx < 1700)) {
			analog_rx = H_Joystick_Read_x();
      analog_ry = H_Joystick_Read_y();
        // Right
        current_speed = analog_ry ;
        HDCM_Left(current_speed-1700);
			previous_x = current_speed;
        is_stopping = false;
    } while ((analog_ry < 1400) && (analog_rx > 1400) && (analog_rx < 1700)) {
			analog_rx = H_Joystick_Read_x();
    analog_ry = H_Joystick_Read_y();
        // Left
        current_speed =  analog_ry;
        HDCM_Right(1800-current_speed);
				previous_x = current_speed;
        is_stopping = false;
    }
		

		

}



void Delays(int time);
u16 analog_rx = 0;
u16 analog_ry = 0;
volatile s32 Data =0;
volatile s32 Data_R =0; 
volatile s32 Data_L =0;
volatile s32 motor_1 = 0;
volatile s32 motor_2 =0;


int main(void)
	{

	//MRCC_vInit();
	MRCC_vEnableClock(RCC_APB2,GPIOPA);
	MRCC_vEnableClock(RCC_APB2,GIOPB);
  MRCC_vEnableClock( RCC_APB1,TIM2);
	MRCC_vEnableClock(RCC_APB2,SPI1);
	MRCC_vEnableClock(RCC_APB2,AFIO);
	MRCC_vEnableClock( RCC_APB2  , ADC1);
	MRCC_vEnableClock( RCC_APB2  , ADC2);
  HDCM_Init();
	H_Joystick_init();
	MCAL_SPI_GPIO_SET_PINS(0);
	MCAL_SPI_Init(0);
	u8 limit_R = 'R';
	s8 limit_L = 'L';
	u8 Data_1 = 0;
	// Choose the mode
	while( !((Data_1=='A') || (Data_1=='B'))){
	Data_1=MCAL_SPI_ReceiveData(SPI_1);
	} 
		while(1)
		{
		//Autonomous Mode
		while(Data_1 == 'A'){
		Data =MCAL_SPI_ReceiveData(SPI_1); 
			if (Data % 2 == 0 ){
				motor_1=Data;
			}
		  if(Data % 2 != 0){
				motor_2=Data;
			}	

	HDCM_Motors_Auto_Forward(motor_2,motor_1);		
			//Switch to Automatic
			if(Data == 'Y'){
		  Data_1 = 'B';
			}
	}
	Automatic Mode
	while(Data_1 == 'B'){
			control_motor();
 		}
	}

}