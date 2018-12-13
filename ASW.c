#include "ASW.h"

void AWS_Start_Line_Follower(T_U16 u16Speed)
{
		T_U8 u8_port = RTE_u8ReadPins();
		RTE_vSetMotorSpeed(u16Speed);
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
		else if (u8_port == 0x00)
		{
			RTE_vSetMotorSpeed(0);
		}
}
