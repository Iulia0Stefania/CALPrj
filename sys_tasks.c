/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"
#include "asw_com.h"
#include "ASW.h"
#include "RTE.h"
#include "mcal_encoder.h"

#include "mcal_init.h"


T_U16 u16SpeedGL;
T_F16 batteryPercentage = 0;
extern BOOL bTXflag;
carInfo car;

void TASK_Inits()
{
    car.breachInt = FALSE;
    car.u8RoadNum = 8;
    car.breachInt = FALSE;
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL, OUTPUT);
	RTE_vMotorInit();
	RTE_vSetMotorDir(FATA);	
	RTE_vSetServoAngle(INAINTE);
    T_U16 rand = ADC_u16Read(0);
    //u16SpeedGL = 15 + rand%21; //generate speed at start
    u16SpeedGL = 17;
    RTE_vSetMotorSpeed(u16SpeedGL);
    QEI_vInit();
    car.s16Direction = rand%3; //generate road at start
}

void TASK_1ms()
{
	if(!bTXflag)
    {
        COM_vStartListening();
    }
  
}

void TASK_5ms()
{
    
}

void TASK_10ms()
{   
   //AWS_Go_20_cm();
  
   vStateMachine(); 
}

void TASK_100ms()
{ 
     AWS_Start_Line_Follower();
}

void TASK_500ms()
{ 

}

void TASK_1000ms()
{
   batteryPercentage = RTE_f16GetBaterryPercentage();
}