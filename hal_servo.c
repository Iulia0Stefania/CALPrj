#include "hal_servo.h"
#include "mcal_pwm.h"
#include "general.h"

#define minAngle 10
#define maxAngle 170
#define minDuty 4
#define maxDuty 11
#define Rezolution 0.04375

void vInitServo()
{
	PWM1_vInit();
}

void vSetServoAngle(T_U16 u16Angle)
{
	if(u16Angle <60)	
	{
		u16Angle = 60;
	}
	else if(u16Angle >120)
	{
		u16Angle = 120;
	}
	T_F16 f16Duty = (float)(u16Angle - minAngle)*Rezolution + minDuty;
	PWM1_vSetDuty(f16Duty,1);

}
