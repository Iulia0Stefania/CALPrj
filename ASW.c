#include "ASW.h"
#include "sys_tasks.h"
#include "asw_com.h"

 T_F16 f16elapsedCMglobal;
 T_U16 u16AngleGL = 90;
 BOOL bTXflag = FALSE;
 
 BOOL RoadNumflag = FALSE;
 extern carInfo car;
 

void AWS_Start_Line_Follower() //de testat
{
		T_U8 u8_port = RTE_u8ReadPins();
		if(car.bintersection && (u8_port  == 0x3F))  //DACA E INTERSECTIE se uita la directie
		{
            switch(car.s16Direction)
            {
                case 0:
                    RTE_vSetServoAngle(u16AngleGL);
                    u16AngleGL = 90;
                    break;
                case 1:
                    u16AngleGL+=2;
                    RTE_vSetServoAngle(u16AngleGL);
                    break;
                case 2:
                     u16AngleGL-=2;
                    RTE_vSetServoAngle(u16AngleGL);
                    break;           
            }	
		}
        else //DACA E UN SINGUR DRUM se uita la line follower
        {
            if((u8_port & 0x0C) == 0x0C)  //INAINTE
            {
                RTE_vSetServoAngle(u16AngleGL);
                u16AngleGL = 90;
            }
            else if ((u8_port & 0x30) == 0x30) //STANGA
            {
                u16AngleGL-=2;
                RTE_vSetServoAngle(u16AngleGL);
            }
            else if ((u8_port & 0x03) == 0x03) //DREAPTA
            {
                u16AngleGL+=2
                        ;
                RTE_vSetServoAngle(u16AngleGL);
            }
            
        }
        if(u16AngleGL < 60)
        {
            u16AngleGL = 60;
        }else if(u16AngleGL >120)
        {
           u16AngleGL = 120; 
        }
}

void AWS_Go_20_cm()
{
    T_F16 f16elapsed = RTE_f16getElapsed();
    if(f16elapsed <0)
    {
        f16elapsed = 0 - f16elapsed;
    }
    f16elapsedCMglobal += f16elapsed;
    RTE_vResetCount();
    if(f16elapsedCMglobal > 2000)
    {
        RTE_vSetMotorSpeed(0);
        f16elapsedCMglobal = 0;
    }
}


T_U8 u8RoadNumber()
{
    static T_U8 u8previous = 0;
    static T_U8 u8gaps;
    static T_U8 u8current = 0;
    u8previous = u8current;
    u8current = RTE_u8ReadPins();
    if((u8previous != 0x00) && ((u8current<<3) == 0x00))
    {
        ++u8gaps;
    }
    if(u8current == 0x3F) //prima bara
    {
		RoadNumflag = TRUE;
        return u8gaps;
    }
    else
    {
        return 8;
    }
}

BOOL bReachIntersection()
{
    static T_U8 u8previous = 0;
    static T_U8 u8current = 0;
    u8previous = u8current;
    u8current = RTE_u8ReadPins();
     if((u8current == 0x3F) && ((u8previous != 0x3F) && (u8previous != 0x00))) //daca intalneste linie orizontala
     {
         return TRUE;
     }
     else
     {
         return FALSE;
     }
}

T_U8 u8WriteMessage()
{
   T_U8 u8Message = 0x00;
   switch(car.u8RoadNum)
   {
       case 0:
           u8Message &=0xFC; //b1=0 si b0 = 0 - drumul 0 
           break;
       case 1:
           u8Message |= 0x01; // b1=0 si b0=1 - drumul 1
           break;
       case 2:
           u8Message |= 0x02; // b1=1 si b0=0 - drumul 2
           break;
       case 3:
           u8Message |= 0x03; //b1=1 si b0=0 - drumul 3
           break;
   }
   switch(car.s16Direction)
   {
       case 0:
           u8Message &=0xF3; // b3=0 si b2=0 - inainte
           break;
       case 1:
           u8Message |=0x04; //b3=0 si b2=1 - dreapta
           break;
       case 2:
           u8Message |=0x08; //b3=1 si b2=0 -stanga
           break;         
   }
   if(car.bintersection)
   {
       u8Message |=0x10;
   }
   else
   {
       u8Message &=0xEF;
   }
   return u8Message;
}

void vStateMachine()
{
    static T_U8 u8currentState = 0;
    T_U8 u8nextState = 8;
    switch(u8currentState)
    {
        case 0: 
            if(car.bintersection == TRUE) //se duce starea 1
            {
                bTXflag = TRUE;
                T_U8 u8Message = u8WriteMessage();
                if(bTXflag)
                {
                    COM_vSendMessage(u8Message);
                }
               
                u8nextState = 1;
            }
            else //ramane starea 0
            {
                u8nextState = 0;
               
                if(!RoadNumflag)
                {
					car.u8RoadNum = u8RoadNumber();
                }
				else
				{
					car.bintersection = bReachIntersection();
				}
                            
            }
            break;
        case 1:
            
            break;
    }
}

/*void AWS_Start_Line_Follower()
{
		T_U8 u8_port = RTE_u8ReadPins();
		if((u8_port & 0x0C) == 0x0C)
		{
			RTE_vSetServoAngle(INAINTE);
		}
		else if ((u8_port & 0x30) == 0x30)
		{
			RTE_vSetServoAngle(STANGA);
		}
		else if ((u8_port & 0x03) == 0x03)
		{
			RTE_vSetServoAngle(DREAPTA);
		}
		//else if (u8_port == 0x00)
		//{
		//	RTE_vSetMotorSpeed(0);
		//}
}*/


 /*void AWS_Start_Line_Follower()
{
		T_U8 u8_port = RTE_u8ReadPins();
		if((u8_port & 0x0C) == 0x0C)  //INAINTE
		{
			RTE_vSetServoAngle(u16AngleGL);
            u16AngleGL = 90;
		}
		else if ((u8_port & 0x30) == 0x30) //STANGA
		{
            u16AngleGL-=2;
			RTE_vSetServoAngle(u16AngleGL);
		}
		else if ((u8_port & 0x03) == 0x03) //DREAPTA
		{
            u16AngleGL+=2;
			RTE_vSetServoAngle(u16AngleGL);
		}
        if(u16AngleGL < 60)
        {
            u16AngleGL = 60;
        }else if(u16AngleGL >120)
        {
           u16AngleGL = 120; 
        }
}*/

  

