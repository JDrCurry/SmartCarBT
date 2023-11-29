#include "stm32f10x.h"                  // Device header


void PWM_Init (void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//外部定时器使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//LED灯所在的GPIOA使能
	
	
	
	//初始化GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		//Multiplexed push-pull output复用推挽输出(控制权交给外设（定时器）)
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;			//Pin2是给TB6612中的PWMA传输（并联试一下、太窄并不了）
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	
	//选择时基单元的时钟
	TIM_InternalClockConfig(TIM2);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; 	
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
	
	
	
/*
	PWM频率：Freq=CK_PSC/(PSC+1)/(ARR+1)							1khz
	PWM占空比：Duty=CCR/(ARR+1)										50%
	PWM分辨率：Reso=1/(ARR+1)										1%
*/
	
	
	//配置时基单元关键寄存器（ARR、PSC）
	TIM_TimeBaseInitStructure.TIM_Period = 100-1;					//ARR	自动重装器的值
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720-1;				//PSC	预分频器的值
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;			
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	
	
	//配置输出比较单元（CCR）
	TIM_OCInitTypeDef TIM_OCInitStructure;
			TIM_OCStructInit(&TIM_OCInitStructure);//此处将只赋值部分结构体成员，为防止错误，应先给所有成员统一赋初值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;								//CCR	的值(arr设置100，所以ccr的值就是占空比例),初始化为0
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	
	
	
	//手动清除更新中断的标志位，避免列初始化完就进中断
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	
	//运行控制
	TIM_Cmd(TIM2, ENABLE);
}



//CCR控制函数，(arr设置100，所以ccr的值就是占空比例)
void PWM_SetCompare3 (uint16_t Compare)
{
	TIM_SetCompare3(TIM2, Compare);
}
