#include "hal_motor.h"
#include "mcal_pwm.h"
#include "mcal_gpio.h"
#include "general.h"

void vMotorInit()
{
	GPIO_u8SetPortPin(PORT_A,9,DIGITAL, OUTPUT);
	PWM1_vInit();
}

void vSetMotorDir(BOOL bDir)
{
	GPIO_u8WritePortPin(PORT_A,9,bDir);
}

void vSetMotorSpeed(T_U16 u16Speed)
{
	if(u16Speed >100)
	{
		PWM1_vSetDuty(100, 2);
	}
	else if(u16Speed <0)
	{
		PWM1_vSetDuty(0, 2);
	}
	else 
	{
		PWM1_vSetDuty(u16Speed, 2);
	}
}