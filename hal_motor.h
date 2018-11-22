#ifndef HAL_MOTOR_H
#define HAL_MOTOR_H

#include "general_types.h"

#define INAINTE 0
#define INAPOI 1

void vMotorInit();
void vSetMotorDir(BOOL bDir);
void vSetMotorSpeed(T_U16 u16Speed);

#endif