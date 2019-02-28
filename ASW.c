#include "ASW.h"

 T_F16 f16elapsedCMglobal;

void AWS_Start_Line_Follower()
{
		T_U8 u8_port = RTE_u8ReadPins();
		if((u8_port & 0x0C) == 0x0C)
		{
			RTE_vSetServoAngle(INAINTE);
		}
		else if ((u8_port & 0x30) == 0x30)
		{
			RTE_vSetServoAngle(STANGA);
		}
		else if ((u8_port & 0x03) == 0x03)
		{
			RTE_vSetServoAngle(DREAPTA);
		}
		/*else if (u8_port == 0x00)
		{
			RTE_vSetMotorSpeed(0);
		}*/
}

void AWS_Go_20_cm()
{
    T_F16 f16elapsed = RTE_f16getElapsed();
    if(f16elapsed <0)
    {
        f16elapsed = 0 - f16elapsed;
    }
    f16elapsedCMglobal += f16elapsed;
    RTE_vResetCount();
    if(f16elapsedCMglobal > 2000)
    {
        RTE_vSetMotorSpeed(0);
        f16elapsedCMglobal = 0;
    }
}
