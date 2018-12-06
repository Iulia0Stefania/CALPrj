#ifndef HAL_LINE_FOLLOWER_H
#define HAL_LINE_FOLLOWER_H

#include "general.h"

void LF_vSetPinsDir (BOOL bDir); 
void LF_vWritePins(void);
T_U8 LF_u8ReadPins(void);


#endif