#ifndef HAL_MOTOR_H
#define HAL_MOTOR_H

#include "general_types.h"

void HAL_vMotorInit();
void HAL_vSetMotorDir(BOOL bDir);
void HAL_vSetMotorSpeed(T_U16 u16Speed);

#endif