#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_Init(void)
{
	
	PWM_init1();
}

void Servo_SetAngle(float Angle)
{
	PWM_SetCompare1(Angle / 180 * 2000 + 500);
}
