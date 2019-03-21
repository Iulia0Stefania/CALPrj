#ifndef AWS_H
#define AWS_H

#include "RTE.h"
#include "general_types.h"

#include "mcal_encoder.h"

void AWS_Start_Line_Follower();
void AWS_Go_20_cm();
T_U8 u8RoadNumber();
BOOL bReachIntersection();
void  vStateMachine();

#endif