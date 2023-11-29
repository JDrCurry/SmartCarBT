#include "stm32f10x.h"
#include "Motor.h"   

void Car_Ahead(void/*waiting for speed control system*/)
{
    Motor_SetSpeed_Left(-70);
    Motor_SetSpeed_Right(-70);
}

void Car_Back(void/*waiting for speed control system*/)
{
    Motor_SetSpeed_Left(70);
    Motor_SetSpeed_Right(70);
}

void Car_Left(void/*waiting for speed control system*/)
{
    Motor_SetSpeed_Left(0);
    Motor_SetSpeed_Right(-70);
}

void Car_Right(void/*waiting for speed control system*/)
{
   
    Motor_SetSpeed_Right(0);                            //赋值0必须放在前面，否则会出现左右轮同时0的情况
    Motor_SetSpeed_Left(-70);
}

void Car_Stop(void/*waiting for speed control system*/)
{
    Motor_SetSpeed_Left(0);
    Motor_SetSpeed_Right(0);
}

void Car_Spin_Left(void/*waiting for speed control system*/)
{
    Motor_SetSpeed_Left(-70);
    Motor_SetSpeed_Right(70);
}

void Car_Spin_Right(void/*waiting for speed control system*/)
{
    Motor_SetSpeed_Left(70);
    Motor_SetSpeed_Right(-70);
}