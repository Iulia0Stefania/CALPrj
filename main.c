#include "general.h"

int main()
{
	vInitServo();
	T_U16 i;
	for(i=60; i<=120;i+=10)
	{
		__delay_ms(100);
		vSetServoAngle(i);
	}	
    
    while(1)
    {
        
    }
    return 0;
}