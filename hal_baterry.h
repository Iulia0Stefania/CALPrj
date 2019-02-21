/* 
 * File:   hal_baterry.h
 * Author: student
 *
 * Created on February 21, 2019, 6:33 PM
 */

#ifndef HAL_BATERRY_H
#define	HAL_BATERRY_H

#include "general_types.h"
#include "mcal_adc.h"

#define VREF 3.07
#define MAXDIGVAL 4095
#define FIRSTREZ 57.14
#define SECONDREZ 6.666
#define THIRDREZ 20
#define PERCENTAGE100 8.4
#define PERCENTAGE20 7
#define PERCENTAGE10 6.5
#define PERCENTAGE0 6

T_F16 HAL_f16GetBaterryPercentage();

#endif	/* HAL_BATERRY_H */

