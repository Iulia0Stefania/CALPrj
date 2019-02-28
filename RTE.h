#ifndef RTE_H
#define RTE_H

#include "hal_motor.h"
#include "hal_servo.h"
#include "hal_line_follower.h"
#include "general_types.h"
#include "hal_baterry.h"

#define INAINTE 90
#define STANGA 60
#define DREAPTA 120
#define FATA 0
#define SPATE 1

#define RTE_vMotorInit() HAL_vMotorInit()
#define RTE_vSetMotorDir(bDir) HAL_vSetMotorDir(bDir)
#define RTE_vSetMotorSpeed(u16Speed) HAL_vSetMotorSpeed(u16Speed)
#define RTE_vInitServo() HAL_vInitServo()
#define RTE_vSetServoAngle(u16Angle) HAL_vSetServoAngle(u16Angle)
#define RTE_vSetPinDir(bDir) LF_vSetPinsDir(bDir)
#define RTE_vWritePins() LF_vWritePins()
#define RTE_u8ReadPins() LF_u8ReadPins() 
#define RTE_f16GetBaterryPercentage() HAL_f16GetBaterryPercentage()
#define RTE_f16getElapsed() QEI_f16getElapsed()
#define RTE_vResetCount() QEI_vResetCount()
 
#endif