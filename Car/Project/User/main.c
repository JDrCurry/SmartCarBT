#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"
#include "Car_Direction.h"
#include "Serial.h"
#include "Servo.h"

//本工程为

uint8_t KeyNum;
int8_t Speed;

int main(void)
{
	OLED_Init();
	Key_Init();

	Motor_Init();
	Serial_Init();
	

	OLED_ShowString(1,1,"Power:");
	
	while(1)
	{
		
	}
	
}

/*	//OLED模板
	OLED_ShowChar(1,1,'A');
	OLED_ShowString(1,1,"Count:");
	OLED_ShowNum(2,1,12345,5);
	OLED_ShowSignedNum(2,7, -56,2);
	OLED_ShowHexNum(3,1,0xAA55,4);
	OLED_ShowBinNum(4,1,0xAA55,16);
	OLED_Clear();					//有清屏*/