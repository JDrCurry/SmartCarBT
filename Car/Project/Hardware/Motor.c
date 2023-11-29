#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//ClockInit
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//push-pull output
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;	//初始化电机方向控制脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//Init speed
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	PWM_Init();
}



//这里的left&right是左侧马达/右

void Motor_SetSpeed_Right(int8_t Speed)		//P4、5 --> A1、2
{
	if(Speed > 0)//正转
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare3(Speed);
	}
	else if(Speed == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare3(0);
	}
	else
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		PWM_SetCompare3(-Speed);//SetC必须传入正数
	}
}

void Motor_SetSpeed_Left(int8_t Speed)		//P6、7 --> B1、2
{
	if(Speed > 0)//正转
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);
		PWM_SetCompare3(Speed);
	}
	else if(Speed == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
		PWM_SetCompare3(0);
	}
	else
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		PWM_SetCompare3(-Speed);//SetC必须传入正数
	}
}

