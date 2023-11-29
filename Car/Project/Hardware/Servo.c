#include "stm32f10x.h"                  // Device header
#include "PWM_Servo.h"

void Servo_Init(void)
{
	PWM_Servo_Init();
}

/*
	PWM_SetCompare2(500);			//0
	PWM_SetCompare2(1500);			//90
	PWM_SetCompare2(2500);			//180

	0	~	180		angle
	500	~	2500	ccr
	liner function f(x) = k*x + b
	k = (2500-500)/180
	b = 500
*/


void Servo_SetAngle(float Angle)
{
	PWM_Servo_SetCompare3(Angle / 180 * 2000 + 500);
}
	