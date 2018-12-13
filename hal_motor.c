#include "hal_motor.h"
#include "mcal_pwm.h"
#include "mcal_gpio.h"
#include "general.h"

#define MAXSPEED 100
#define MINSPEED 0

void HAL_vMotorInit()
{
	GPIO_u8SetPortPin(PORT_A,9,DIGITAL, OUTPUT);
	PWM1_vInit();
}

void HAL_vSetMotorDir(BOOL bDir)
{
	GPIO_u8WritePortPin(PORT_A,9,bDir);
}

void HAL_vSetMotorSpeed(T_U16 u16Speed)
{
	if(u16Speed >MAXSPEED)
	{
		PWM1_vSetDuty(MAXSPEED, 2);
	}
	else if(u16Speed <MINSPEED)
	{
		PWM1_vSetDuty(MINSPEED, 2);
	}
	else 
	{
		PWM1_vSetDuty(u16Speed, 2);
	}
}