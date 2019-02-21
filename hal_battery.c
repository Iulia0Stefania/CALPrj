#include "hal_baterry.h"
#include "general.h"
T_F16 HAL_f16GetBaterryPercentage()
{
    T_U16 adcVoltage = ADC_u16Read(0);
    T_F16 batVoltage = (float)adcVoltage*VREF/MAXDIGVAL;
    batVoltage = batVoltage * 4;
    T_F16 chargePercentage;
    T_F16 deltaVoltage = 8.4 - batVoltage;
    if(batVoltage <=PERCENTAGE100 && batVoltage >=PERCENTAGE20)
    { 
        chargePercentage = 100-(deltaVoltage*FIRSTREZ);        
    }
    else if(batVoltage <=PERCENTAGE20 && batVoltage >=PERCENTAGE10)
    {
        chargePercentage = 100-(deltaVoltage*SECONDREZ);
    }
    else if(batVoltage <=PERCENTAGE10 && batVoltage >=PERCENTAGE0)
    {
        chargePercentage = 100-(deltaVoltage*THIRDREZ);
    }
    if(chargePercentage <= 60)
    {
        GPIO_u8WritePortPin(PORT_A,10,HIGH);
        //_RA10 = ~_RA10;
    }
    
    return chargePercentage;
}
