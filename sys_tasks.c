/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"

#include "ASW.h"
#include "RTE.h"
#include "mcal_encoder.h"

#include "mcal_init.h"

T_U16 u16SpeedGL;
T_F16 batteryPercentage = 0;

void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL, OUTPUT);
	RTE_vMotorInit();
	RTE_vSetMotorDir(FATA);	
	RTE_vSetServoAngle(INAINTE);
    u16SpeedGL = 30;
    RTE_vSetMotorSpeed(u16SpeedGL);
    QEI_vInit();
}

void TASK_1ms()
{
	
    
}

void TASK_5ms()
{
    
}

void TASK_10ms()
{   
   //AWS_Go_20_cm();
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