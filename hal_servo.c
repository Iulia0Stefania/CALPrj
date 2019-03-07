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

#define OFFSET 4
#define REZ 0.04375
#define MIN_ANGLE 10


void HAL_vInitServo()
{
	PWM1_vInit();
}

void HAL_vSetServoAngle(T_U16 u16Angle)
{
    T_F16 f16Duty=90;
	
	if(u16Angle<=60)
	{
		u16Angle=60;
	}
	else if(u16Angle>=120)
	{
		u16Angle=120;
	}
	f16Duty=OFFSET+REZ*(u16Angle-MIN_ANGLE);
	PWM1_vSetDuty(f16Duty,1);
}

