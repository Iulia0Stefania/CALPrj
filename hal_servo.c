#include "hal_servo.h"
#include "mcal_pwm.h"
#include "general.h"

#define minAngle 10
#define maxAngle 170
#define minDuty 4
#define maxDuty 11
#define Rezolution 0.04375
#define maxCarAngle 120
#define minCarAngle 60


void HAL_vInitServo()
{
	PWM1_vInit();
}

void HAL_vSetServoAngle(T_U16 u16Angle)
{
	if(u16Angle < minCarAngle)	
	{
		u16Angle = minCarAngle;
	}
	else if(u16Angle >maxCarAngle)
	{
		u16Angle = maxCarAngle;
	}
	T_F16 f16Duty = (float)(u16Angle - minAngle)*Rezolution + minDuty;
	PWM1_vSetDuty(f16Duty,1);

}
