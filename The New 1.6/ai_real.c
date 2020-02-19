////////////////////////////////////////
//
//	File : ai.c
//	CoSpace Robot
//	Version 1.0.0
//	Jan 1 2016
//	Copyright (C) 2016 CoSpace Robot. All Rights Reserved
//
//////////////////////////////////////
//
// ONLY C Code can be compiled.
//
/////////////////////////////////////

#define CsBot_AI_H//DO NOT delete this line
#ifndef CSBOT_REAL
#include <windows.h>
#include <stdio.h>
#include <math.h>
#define DLL_EXPORT extern __declspec(dllexport)
#define false 0
#define true 1
#endif//The robot ID : It must be two char, such as '00','kl' or 'Cr'.
char AI_MyID[2] = {'0','2'};

int Duration = 0;
int SuperDuration = 0;
int bGameEnd = false;
int CurAction = -1;
int CurGame = 0;
int SuperObj_Num = 0;
int SuperObj_X = 0;
int SuperObj_Y = 0;
int Teleport = 0;
int LoadedObjects = 0;
int dA = -100;
int Rosa = 0;
int Vermelho = 0;
int Preto = 0;
int Ciano = 0;
int dBx = 155;
int dBy = 140;
int box1_x = 240;
int box1_y = 245;
int target_x = 0;
int target_y = 0;
int target_angle = 0;
int box3_x = 0;
int box3_y = 0;
int dist_box1 = 1000;
int dist_box2 = 1000;
int dist_box3 = 1000;
int black_zone_x = 300;
int black_zone_y = 210;
int red_zone_y = 20;
int cyan1_zone_x = 130;
int cyan1_zone_y = 190;
int cyan2_zone_x = 115;
int cyan2_zone_y = 40;
int SOX1 = -1;
int SOY1 = -1;
int SOX2 = -1;
int SOY2 = -1;
int SOX3 = -1;
int SOY3 = -1;
int SOX4 = -1;
int SOY4 = -1;
int SOX5 = -1;
int SOY5 = -1;
int SOX6 = -1;
int SOY6 = -1;
int act = 0;
int box2_x = 0;
int box2_y = 0;
int distt1 = 1000;
int distt2 = 1000;
int distt3 = 1000;
int distt4 = 1000;
int distt5 = 1000;
int distt6 = 1000;
int red_zone_x = 225;
int US_Front = 0;
int US_Left = 0;
int US_Right = 0;
int CSLeft_R = 0;
int CSLeft_G = 0;
int CSLeft_B = 0;
int CSRight_R = 0;
int CSRight_G = 0;
int CSRight_B = 0;
int PositionX = 0;
int PositionY = 0;
int TM_State = 0;
int Compass = 0;
int Time = 0;
int WheelLeft = 0;
int WheelRight = 0;
int LED_1 = 0;
int MyState = 0;
int AI_SensorNum = 13;

#define CsBot_AI_C//DO NOT delete this line

DLL_EXPORT void SetGameID(int GameID)
{
    CurGame = GameID;
    bGameEnd = 0;
}

DLL_EXPORT int GetGameID()
{
    return CurGame;
}

//Only Used by CsBot Dance Platform
DLL_EXPORT int IsGameEnd()
{
    return bGameEnd;
}

#ifndef CSBOT_REAL

DLL_EXPORT char* GetDebugInfo()
{
    char info[1024];
    sprintf(info, "Duration=%d;SuperDuration=%d;bGameEnd=%d;CurAction=%d;CurGame=%d;SuperObj_Num=%d;SuperObj_X=%d;SuperObj_Y=%d;Teleport=%d;LoadedObjects=%d;dA=%d;Rosa=%d;Vermelho=%d;Preto=%d;Ciano=%d;dBx=%d;dBy=%d;box1_x=%d;box1_y=%d;target_x=%d;target_y=%d;target_angle=%d;box3_x=%d;box3_y=%d;dist_box1=%d;dist_box2=%d;dist_box3=%d;black_zone_x=%d;black_zone_y=%d;red_zone_y=%d;cyan1_zone_x=%d;cyan1_zone_y=%d;cyan2_zone_x=%d;cyan2_zone_y=%d;SOX1=%d;SOY1=%d;SOX2=%d;SOY2=%d;SOX3=%d;SOY3=%d;SOX4=%d;SOY4=%d;SOX5=%d;SOY5=%d;SOX6=%d;SOY6=%d;act=%d;box2_x=%d;box2_y=%d;distt1=%d;distt2=%d;distt3=%d;distt4=%d;distt5=%d;distt6=%d;red_zone_x=%d;US_Front=%d;US_Left=%d;US_Right=%d;CSLeft_R=%d;CSLeft_G=%d;CSLeft_B=%d;CSRight_R=%d;CSRight_G=%d;CSRight_B=%d;PositionX=%d;PositionY=%d;TM_State=%d;Compass=%d;Time=%d;WheelLeft=%d;WheelRight=%d;LED_1=%d;MyState=%d;",Duration,SuperDuration,bGameEnd,CurAction,CurGame,SuperObj_Num,SuperObj_X,SuperObj_Y,Teleport,LoadedObjects,dA,Rosa,Vermelho,Preto,Ciano,dBx,dBy,box1_x,box1_y,target_x,target_y,target_angle,box3_x,box3_y,dist_box1,dist_box2,dist_box3,black_zone_x,black_zone_y,red_zone_y,cyan1_zone_x,cyan1_zone_y,cyan2_zone_x,cyan2_zone_y,SOX1,SOY1,SOX2,SOY2,SOX3,SOY3,SOX4,SOY4,SOX5,SOY5,SOX6,SOY6,act,box2_x,box2_y,distt1,distt2,distt3,distt4,distt5,distt6,red_zone_x,US_Front,US_Left,US_Right,CSLeft_R,CSLeft_G,CSLeft_B,CSRight_R,CSRight_G,CSRight_B,PositionX,PositionY,TM_State,Compass,Time,WheelLeft,WheelRight,LED_1,MyState);
    return info;
}
 
DLL_EXPORT char* GetTeamName()
{
     return "";
}

DLL_EXPORT int GetCurAction()
{
    return CurAction;
}

//Only Used by CsBot Rescue Platform
DLL_EXPORT int GetTeleport()
{
    return Teleport;
}

//Only Used by CsBot Rescue Platform
DLL_EXPORT void SetSuperObj(int X, int Y, int num)
{
    SuperObj_X = X;
    SuperObj_Y = Y;
    SuperObj_Num = num;
}
//Only Used by CsBot Rescue Platform
DLL_EXPORT void GetSuperObj(int *X, int *Y, int *num)
{
    *X = SuperObj_X;
    *Y = SuperObj_Y;
    *num = SuperObj_Num;
}

#endif ////CSBOT_REAL

DLL_EXPORT void SetDataAI(volatile int* packet, volatile int *AI_IN)
{

    int sum = 0;

    US_Front = AI_IN[0]; packet[0] = US_Front; sum += US_Front;
    US_Left = AI_IN[1]; packet[1] = US_Left; sum += US_Left;
    US_Right = AI_IN[2]; packet[2] = US_Right; sum += US_Right;
    CSLeft_R = AI_IN[3]; packet[3] = CSLeft_R; sum += CSLeft_R;
    CSLeft_G = AI_IN[4]; packet[4] = CSLeft_G; sum += CSLeft_G;
    CSLeft_B = AI_IN[5]; packet[5] = CSLeft_B; sum += CSLeft_B;
    CSRight_R = AI_IN[6]; packet[6] = CSRight_R; sum += CSRight_R;
    CSRight_G = AI_IN[7]; packet[7] = CSRight_G; sum += CSRight_G;
    CSRight_B = AI_IN[8]; packet[8] = CSRight_B; sum += CSRight_B;
    PositionX = AI_IN[9]; packet[9] = PositionX; sum += PositionX;
    PositionY = AI_IN[10]; packet[10] = PositionY; sum += PositionY;
    TM_State = AI_IN[11]; packet[11] = TM_State; sum += TM_State;
    Compass = AI_IN[12]; packet[12] = Compass; sum += Compass;
    Time = AI_IN[13]; packet[13] = Time; sum += Time;
    packet[14] = sum;

}
DLL_EXPORT void GetCommand(int *AI_OUT)
{
    AI_OUT[0] = WheelLeft;
    AI_OUT[1] = WheelRight;
    AI_OUT[2] = LED_1;
    AI_OUT[3] = MyState;
}

DLL_EXPORT void OnTimer()
{
    switch (CurGame)
    {
        case 9:
            break;
        case 10:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            break;
        default:
            break;
    }
}

