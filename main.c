#include "general.h"
#include "hal_servo.h"
#include "hal_motor.h"
#include "hal_line_follower.h"
#include "general_types.h"

#pragma config ICS = PGD2               // Comm Channel Select (Communicate on PGC2/EMUC2 and PGD2/EMUD2)
#pragma config JTAGEN = ON  

int main()
{
	/*vInitServo();
	T_U16 i;
	for(i=60; i<=120;i+=10)
	{
		__delay_ms(100);
		vSetServoAngle(i);
	}	*/
	TASK_Inits();
	OSC_vInit();
	TASK_vSchedule();


	/*while(1)
	{
		u8_port = LF_u8ReadPins();
		if((u8_port & 0x0C) == 0x0C)
		{
			vSetServoAngle(80);
		}
		else
		{
			vSetServoAngle(120);
		}
	}*/
 

    return 0;
}