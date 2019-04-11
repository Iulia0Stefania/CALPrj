/* 
 * File:   asw_com.c
 * Author: Cristian T. A.
 *
 * Created on August 28, 2018, 9:37 AM
 */

#include "general.h"
#include "rte.h"
#include "asw_com.h"


/* nRF variables */
extern T_U8 au8RxBuff[];
extern T_U8 u8RxBuff_Index;
extern BOOL u8NewRX;
extern carInfo car;
BOOL bIsConflict = FALSE;

/***********************************************************************************************************************
*  Function name    : COM_vCheckIRQ
*
*  Description      : Checks if there is a new received message OR if the transmission is complete.
*                            
*  List of arguments: -
*
*  Return value     : -
*
***********************************************************************************************************************/
void COM_vCheckIRQ()
{
    RTE_RF_vCheckIRQ();
}

/***********************************************************************************************************************
*  Function name    : COM_vSendMessage
*
*  Description      : Puts the RF module in the Transmit State, to transmit the message.
*                            
*  List of arguments: T_U8 u8Message - the message to be transmitted.
*
*  Return value     : -
*
***********************************************************************************************************************/
void COM_vSendMessage(T_U8 u8Message)
{
    RTE_RF_vBeginTransmit(u8Message);
}

/***********************************************************************************************************************
*  Function name    : COM_vStartListening
*
*  Description      : Puts the RF module in the Receive State.
*                            
*  List of arguments: -
*
*  Return value     : -
*
***********************************************************************************************************************/
void COM_vStartListening()
{
    RTE_RF_vBeginReceive();
}

/****************************************/
/* Message decoding ********************/
/**************************************/

/***********************************************************************************************************************
*  Function name    : COM_vProcessMessage
*
*  Description      : Takes action depending on the message type and the current state 
*          of the Application's Finite State Machine (APP_FSM).
*                            
*  List of arguments: -
*
*  Return value     : -
*
***********************************************************************************************************************/
void COM_vProcessMessage(T_U8 u8Message)
{
    carInfo otherCar;
    otherCar.u8RoadNum = u8Message & 0x03;
    otherCar.s16Direction = u8Message & 0x0C;
    switch(otherCar.u8RoadNum)
    {
        case 0: 
            switch(otherCar.s16Direction)
            {
                case 0: 
                if(car.u8RoadNum == 1 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }  
                else if(car.u8RoadNum == 1 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                } 
                else if(car.u8RoadNum == 2 && car.s16Direction == 2)
                {
                  bIsConflict = TRUE;  
                }
                else
                {
                    bIsConflict = FALSE;
                }
                break;
                case 1:
                    if(car.u8RoadNum == 1 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                }   
                else if(car.u8RoadNum == 2 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }
                else
                {
                    bIsConflict = FALSE;
                }
                break;
                case 2:
                    if(car.u8RoadNum == 1 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }  
                    if(car.u8RoadNum == 1 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                }   
                else
                {
                    bIsConflict = FALSE;
                }
                break;
                    
            }
            break; 
        case 1:
            switch(otherCar.s16Direction)
            {
                case 0: 
                if(car.u8RoadNum == 3 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }  
                else if(car.u8RoadNum == 2 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                } 
                else if(car.u8RoadNum == 2 && car.s16Direction == 2)
                {
                  bIsConflict = TRUE;  
                }
                else
                {
                    bIsConflict = FALSE;
                }
                break;
                case 1:
                    if(car.u8RoadNum == 2 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                }   
                else if(car.u8RoadNum == 3 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }
                else
                {
                    bIsConflict = FALSE;
                }
                break;
                case 2:
                    if(car.u8RoadNum == 3 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                }  
                    if(car.u8RoadNum == 3 && car.s16Direction == 1)
                {
                    bIsConflict = TRUE;
                }  
                    if(car.u8RoadNum == 2 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                }   
                    if(car.u8RoadNum == 2 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }   
                else
                {
                    bIsConflict = FALSE;
                }
                break;                
            }
            break; 
        case 2:
            switch(otherCar.s16Direction)
            {
                case 0: 
                if(car.u8RoadNum == 0 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }  
                else if(car.u8RoadNum == 3 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                } 
                else if(car.u8RoadNum == 3 && car.s16Direction == 2)
                {
                  bIsConflict = TRUE;  
                }
                else
                {
                    bIsConflict = FALSE;
                }
                break;
                case 1:
                    if(car.u8RoadNum == 0 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }   
                else if(car.u8RoadNum == 3 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                }
                else
                {
                    bIsConflict = FALSE;
                }
                break;
                case 2:
                    if(car.u8RoadNum == 3 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                }  
                    if(car.u8RoadNum == 3 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }  
                else
                {
                    bIsConflict = FALSE;
                }
                break;         
            }
            break;
        case 3:
            switch(otherCar.s16Direction)
            {
                case 0: 
                if(car.u8RoadNum == 1 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }  
                else if(car.u8RoadNum == 0 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                } 
                else if(car.u8RoadNum == 0 && car.s16Direction == 2)
                {
                  bIsConflict = TRUE;  
                }
                else
                {
                    bIsConflict = FALSE;
                }
                break;
                case 1:
                    if(car.u8RoadNum == 1 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }   
                else if(car.u8RoadNum == 0 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                }
                else
                {
                    bIsConflict = FALSE;
                }
                break;
                case 2:
                    if(car.u8RoadNum == 0 && car.s16Direction == 0)
                {
                    bIsConflict = TRUE;
                }  
                    if(car.u8RoadNum == 0 && car.s16Direction == 2)
                {
                    bIsConflict = TRUE;
                }  
                else
                {
                    bIsConflict = FALSE;
                }
                break;         
            }
            break;    
    }
}

/***********************************************************************************************************************
*  Function name    : COM_vProcessFIFO
*
*  Description      : Processes every message in the message queue, if there is any available.
*                            
*  List of arguments: -
*
*  Return value     : -
*
***********************************************************************************************************************/
void COM_vProcessFIFO()
{
    if(TRUE == u8NewRX)
    {
        u8NewRX = FALSE;
        
        T_U8 i;
        for(i = 0; i < u8RxBuff_Index; ++i)
        {
            COM_vProcessMessage(au8RxBuff[i]);
        } 
        u8RxBuff_Index = 0;
    }
    else
    {
        bIsConflict = FALSE;
    }
}

