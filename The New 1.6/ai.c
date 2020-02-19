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
void Game1()
{

    if(SuperDuration>0)
    {
        SuperDuration--;
    }
    else if(Duration>0)
    {
        Duration--;
    }
    else if(act==3)
    {
        Duration = 49;
        CurAction =1;
    }
    else if(PositionX>=350 && PositionX<=1000 && PositionY>=1 && PositionY<=1000)
    {
        Duration = 2;
        CurAction =2;
    }
    else if(PositionX>=1 && PositionX<=1000 && PositionY>=260 && PositionY<=1000)
    {
        Duration = 2;
        CurAction =3;
    }
    else if(PositionX>=1 && PositionX<=15 && PositionY>=1 && PositionY<=1000)
    {
        Duration = 2;
        CurAction =4;
    }
    else if(PositionX>=1 && PositionX<=1000 && PositionY>=1 && PositionY<=15)
    {
        Duration = 0;
        CurAction =5;
    }
    else if(CSLeft_R>=180 && CSLeft_R<=220 && CSLeft_G>=100 && CSLeft_G<=125 && CSLeft_B>=50 && CSLeft_B<=70 && CSRight_R>=180 && CSRight_R<=220 && CSRight_G>=100 && CSRight_G<=125 && CSRight_B>=50 && CSRight_B<=70&&(Preto>49&&Ciano>49&&Vermelho>49))
    {
        Duration = 59;
        CurAction =6;
    }
    else if(CSRight_R>=180 && CSRight_R<=220 && CSRight_G>=100 && CSRight_G<=125 && CSRight_B>=50 && CSRight_B<=70&&(Preto>49&&Ciano>49&&Vermelho>49))
    {
        Duration = 0;
        CurAction =7;
    }
    else if(CSLeft_R>=180 && CSLeft_R<=220 && CSLeft_G>=100 && CSLeft_G<=125 && CSLeft_B>=50 && CSLeft_B<=70&&(Preto>49&&Ciano>49&&Vermelho>49))
    {
        Duration = 0;
        CurAction =8;
    }
    else if(CSLeft_R>=180 && CSLeft_R<=220 && CSLeft_G>=100 && CSLeft_G<=125 && CSLeft_B>=50 && CSLeft_B<=70 && CSRight_R>=180 && CSRight_R<=220 && CSRight_G>=100 && CSRight_G<=125 && CSRight_B>=50 && CSRight_B<=70&&(Rosa>0))
    {
        Duration = 59;
        CurAction =9;
    }
    else if(CSRight_R>=180 && CSRight_R<=220 && CSRight_G>=100 && CSRight_G<=125 && CSRight_B>=50 && CSRight_B<=70&&(Rosa>0))
    {
        Duration = 0;
        CurAction =10;
    }
    else if(CSLeft_R>=180 && CSLeft_R<=220 && CSLeft_G>=100 && CSLeft_G<=125 && CSLeft_B>=50 && CSLeft_B<=70&&(Rosa>0))
    {
        Duration = 0;
        CurAction =11;
    }
    else if(SuperObj_X>0&&SuperObj_Y>0)
    {
        Duration = 0;
        CurAction =12;
    }
    else if(CSLeft_R>=20 && CSLeft_R<=50 && CSLeft_G>=20 && CSLeft_G<=50 && CSLeft_B>=20 && CSLeft_B<=50 && PositionX>=1 && PositionX<=1000 && PositionY>=1 && PositionY<=1000&&(LoadedObjects<6&&Preto<99))
    {
        Duration = 49;
        CurAction =13;
    }
    else if(CSRight_R>=20 && CSRight_R<=50 && CSRight_G>=20 && CSRight_G<=50 && CSRight_B>=20 && CSRight_B<=50&&(LoadedObjects<6&&Preto<99))
    {
        Duration = 49;
        CurAction =14;
    }
    else if(CSLeft_R>=210 && CSLeft_R<=255 && CSLeft_G>=15 && CSLeft_G<=70 && CSLeft_B>=15 && CSLeft_B<=70&&(LoadedObjects<6&&Vermelho<99))
    {
        Duration = 49;
        CurAction =15;
    }
    else if(CSRight_R>=210 && CSRight_R<=255 && CSRight_G>=15 && CSRight_G<=70 && CSRight_B>=15 && CSRight_B<=70&&(LoadedObjects<6&&Vermelho<99))
    {
        Duration = 49;
        CurAction =16;
    }
    else if(CSLeft_R>=15 && CSLeft_R<=70 && CSLeft_G>=230 && CSLeft_G<=255 && CSLeft_B>=230 && CSLeft_B<=255&&(LoadedObjects<6&&Ciano<99))
    {
        Duration = 49;
        CurAction =17;
    }
    else if(CSRight_R>=14 && CSRight_R<=70 && CSRight_G>=230 && CSRight_G<=255 && CSRight_B>=230 && CSRight_B<=255&&(LoadedObjects<6&&Ciano<99))
    {
        Duration = 49;
        CurAction =18;
    }
    else if(US_Left>=0 && US_Left<=15 && US_Right>=0 && US_Right<=15)
    {
        Duration = 4;
        CurAction =19;
    }
    else if(US_Right>=0 && US_Right<=13)
    {
        Duration = 1;
        CurAction =20;
    }
    else if(US_Left>=0 && US_Left<=11)
    {
        Duration = 0;
        CurAction =21;
    }
    else if(US_Front>=0 && US_Front<=15)
    {
        Duration = 1;
        CurAction =22;
    }
    else if(US_Front>=0 && US_Front<=20)
    {
        Duration = 0;
        CurAction =23;
    }
    else if(PositionX>=1 && PositionX<=111 && PositionY>=65 && PositionY<=185 && Time>=10 && Time<=1000)
    {
        Duration = 1;
        CurAction =24;
    }
    else if(act==1&&LoadedObjects<6)
    {
        Duration = 0;
        CurAction =25;
    }
    else if(Preto<1)
    {
        Duration = 0;
        CurAction =26;
    }
    else if(Ciano<1)
    {
        Duration = 0;
        CurAction =27;
    }
    else if(Vermelho<1)
    {
        Duration = 0;
        CurAction =28;
    }
    else if(Ciano<2)
    {
        Duration = 0;
        CurAction =29;
    }
    else if(Preto<3)
    {
        Duration = 0;
        CurAction =30;
    }
    else if(Vermelho>49&&Ciano>49&&Preto>49&&LoadedObjects>3)
    {
        Duration = 0;
        CurAction =31;
    }
    else if(PositionX>=0 && PositionX<=0 && PositionY>=0 && PositionY<=0)
    {
        Duration = 0;
        CurAction =32;
    }
    else if(true)
    {
        Duration = 0;
        CurAction =33;
    }
    switch(CurAction)
    {
        case 1:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            if (target_x == SOX1){
 SOX1=-1;
                    
 distt1=1000;
                    
}
if (target_x == SOX2){
 SOX2=-1;
                    
 distt2=1000;
                    
}
if (target_x == SOX3){
 SOX3=-1;
                    
 distt3=1000;
                    
}
if (target_x == SOX4){
 SOX4=-1;
                    
 distt4=1000;
                    
}
if (target_x == SOX5){
 SOX5=-1;
                    
 distt5=1000;
                    
}
if (target_x == SOX6){
 SOX6=-6;
                    
 distt6=1000;
                    
}
act = 1;
                    
Rosa++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 2:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if (Compass > 270 && Compass < 361) {
 WheelRight = -1;
                    
 WheelLeft=-3;
                    
 }
if (Compass < 271 && Compass > 179) {
 WheelRight = -3;
                    
 WheelLeft=-1;
                    
 }
if (Compass > -1 && Compass <180 ) {
 WheelRight = 2;
                    
 WheelRight = 2;
                    
 }

            break;
        case 3:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if (Compass > -1 && Compass < 91) {
 WheelLeft = -3;
                    
 WheelRight=-1;
                     
 }
if (Compass > 269 && Compass < 361) {
 WheelRight = -3;
                    
 WheelLeft=-1;
                    
 }
if (Compass > 90 && Compass < 270) {
 WheelRight = 2;
                    
 WheelRight = 2;
                    
 }

            break;
        case 4:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if (Compass > 90 && Compass < 180) {
 WheelLeft = -3;
                    
 }
if (Compass > -1 && Compass < 91) {
 WheelRight = -3;
                    
 }
if (Compass> 180 && Compass < 360) {
 WheelLeft = 5;
                    
 WheelRight = 5;
                    
}

            break;
        case 5:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if (Compass > 179 && Compass < 270) {
 WheelRight = 1;
                    
 WheelLeft=-3;
                    
 }
if (Compass > 90 && Compass < 180) {
 WheelRight = -3;
                    
 WheelLeft=1;
                    
 }

if (Compass> 269 && Compass < 360) {
 WheelLeft = 5;
                    
 WheelRight = 5;
                    
}
if (Compass> 0 && Compass < 91) {
 WheelLeft = 5;
                    
 WheelRight = 5;
                    
}

            break;
        case 6:
            WheelLeft=0;
            WheelRight=0;
            LED_1=2;
            MyState=0;
            Ciano = 0;
                    
Preto =0;
                    
Vermelho=0;
                    
Rosa=0;
                    
if (Time> 210){
act = 1;
                    
}
            if(Duration == 1) {LoadedObjects = 0; } 
            break;
        case 7:
            WheelLeft=2;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            break;
        case 8:
            WheelLeft=0;
            WheelRight=2;
            LED_1=0;
            MyState=0;
            break;
        case 9:
            WheelLeft=0;
            WheelRight=0;
            LED_1=2;
            MyState=0;
            Ciano = 0;
                    
Preto =0;
                    
Vermelho=0;
                    
Rosa=0;
                    

            if(Duration == 1) {LoadedObjects = 0; } 
            break;
        case 10:
            WheelLeft=2;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            break;
        case 11:
            WheelLeft=0;
            WheelRight=2;
            LED_1=0;
            MyState=0;
            break;
        case 12:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            if (SOX1<0){
 SOX1= SuperObj_X;
                    
 SOY1= SuperObj_Y;
                    
}
else {
 if (SOX2<0 && SuperObj_X != SOX1){
  SOX2 = SuperObj_X;
                    
  SOY2 = SuperObj_Y;
                    
 }
 else {
  if (SOX3<0 && SuperObj_X != SOX2 && SuperObj_X != SOX1){
   SOX3 = SuperObj_X;
                    
   SOY3 = SuperObj_Y;
                    
  }
  else {
   if (SOX4<0 && SuperObj_X != SOX3 && SuperObj_X != SOX2 && SuperObj_X != SOX1){
    SOX4 = SuperObj_X;
                    
    SOY4 = SuperObj_Y;
                    
   }
   else {
    if (SOX5<0 && SuperObj_X != SOX4 && SuperObj_X != SOX3 && SuperObj_X != SOX2 && SuperObj_X != SOX1){
     SOX5 = SuperObj_X;
                    
     SOY5 = SuperObj_Y;
                    
    }
    else {
     if (SOX6<0 && SuperObj_X != SOX5 && SuperObj_X != SOX4 && SuperObj_X != SOX3 && SuperObj_X != SOX2 && SuperObj_X != SOX1){
      SOX6 = SuperObj_X;
                    
      SOY6 = SuperObj_Y;
                    
act = 2;
                    
     }
     else {
     }
    }
   }
  }
 }
}

            break;
        case 13:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            Preto ++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 14:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            Preto ++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 15:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            Vermelho ++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 16:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            Vermelho ++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 17:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            Ciano ++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 18:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            Ciano ++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 19:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if (US_Front < 25){
 WheelLeft = -3;
                    
 WheelRight= -5;
                    
}
if (US_Front > 24){
 WheelLeft = 5;
                    
 WheelRight= 5;
                    
}

            break;
        case 20:
            WheelLeft=-1;
            WheelRight=2;
            LED_1=0;
            MyState=0;
            break;
        case 21:
            WheelLeft=2;
            WheelRight=-1;
            LED_1=0;
            MyState=0;
            break;
        case 22:
            WheelLeft=2;
            WheelRight=-1;
            LED_1=0;
            MyState=0;
            break;
        case 23:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if (US_Left >= US_Right) {
 WheelLeft=2;
                    
 WheelRight=3;
                    
}
if (US_Left < US_Right) {
 WheelLeft=3;
                    
 WheelRight=2;
                    
}
            break;
        case 24:
            WheelLeft=2;
            WheelRight=2;
            LED_1=0;
            MyState=0;
            if (Compass>89 && Compass< 181 && PositionX> 91){
 //lateral da armadilha
 WheelLeft = -4;
                    
 WheelRight=-1;
                    
}
if (Compass>-1 && Compass< 90 && PositionX> 91){
 //lateral da armadilha
 WheelLeft = -1;
                    
 WheelRight=-4;
                    
}
if (Compass>89 && Compass< 181 && PositionY>155){
 //cima da armadilha
 WheelRight=-4;
                    
 WheelLeft=-1;
                    
}
if (Compass>180 && Compass< 271 && PositionY<158){
 //cima da armadilha
 WheelRight=-2;
                    
 WheelLeft=-5;
                    
}
if (Compass>0 && Compass< 91 && PositionY< 85){
 //baixo da armadilha
 WheelRight=-1;
                    
 WheelLeft=-4;
                    
}
if (Compass>269 && Compass< 361 && PositionY< 85){
 //baixo da armadilha
 WheelRight=-4;
                    
 WheelLeft=-1;
                    
}
if (Compass>-1 && Compass< 1 && PositionY< 85){
 //baixo da armadilha
 WheelRight=-4;
                    
 WheelLeft=-1;
                    
}
            break;
        case 25:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if(SOX1 >0){
distt1 = sqrt(((SOX1- PositionX)*(SOX1 - PositionX)) + ((SOY1 - PositionY)*(SOY1 - PositionY)));
                    
}
if(SOX2 >0){
distt2 = sqrt(((SOX2- PositionX)*(SOX2 - PositionX)) + ((SOY2 - PositionY)*(SOY2 - PositionY)));
                    
}
if(SOX3 >0){
distt3 = sqrt(((SOX3- PositionX)*(SOX3 - PositionX)) + ((SOY3 - PositionY)*(SOY3 - PositionY)));
                    
}
if(SOX4 >0){
distt4 = sqrt(((SOX4- PositionX)*(SOX4 - PositionX)) + ((SOY4 - PositionY)*(SOY4 - PositionY)));
                    
}
if(SOX5 >0){
distt5 = sqrt(((SOX5- PositionX)*(SOX5 - PositionX)) + ((SOY5 - PositionY)*(SOY5 - PositionY)));
                    
}
if(SOX6 >0){
distt6 = sqrt(((SOX6- PositionX)*(SOX6 - PositionX)) + ((SOY6 - PositionY)*(SOY6 - PositionY)));
                    
}

if(distt1 < distt2 && distt1 < distt3 && distt1 < distt4 & distt1< distt5 && distt1< distt6){
target_x = SOX1;
                    

target_y = SOY1;
                    
}

if(distt2 < distt1 && distt2 < distt3 && distt2 < distt4 & distt2< distt5 && distt2< distt6){
target_x = SOX2;
                    

target_y = SOY2;
                    
}

if(distt3 < distt2 && distt3 < distt1 && distt3 < distt4 & distt3< distt5 && distt3< distt6){
target_x = SOX3;
                    

target_y = SOY3;
                    
}

if(distt4 < distt2 && distt4 < distt3 && distt4 < distt1 & distt4< distt5 && distt4< distt6){
target_x = SOX4;
                    

target_y = SOY4;
                    
}

if(distt5 < distt2 && distt5 < distt3 && distt5 < distt4 & distt5< distt1 && distt5< distt6){
target_x = SOX5;
                    

target_y = SOY5;
                    
}

if(distt6 < distt2 && distt6 < distt3 && distt6 < distt4 & distt6< distt5 && distt6< distt1){
target_x = SOX6;
                    

target_y = SOY6;
                    
}

if(PositionX != 0 || PositionY != 0){
target_angle = atan2((target_y - PositionY), (target_x - PositionX)) * 57.2957795131 - 90;
                    

}
if(target_angle < 0){
target_angle = 360 + target_angle;
                    

}


if(Compass < target_angle && abs(Compass + 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass - 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(Compass < target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80){


if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -2;
                    
WheelRight = 2;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 2;
                    
WheelRight = -2;
                    
}

}
if(distt1>999 && distt2>999 && distt3 > 999 && distt4 > 999 && distt5 > 999 && distt6 > 999){
 act = 0;
                    
}
if(PositionX>target_x-5  && PositionX < target_x+5 && PositionY> target_y-5 && PositionY< target_y+5){
 act=3;
                    
}

            break;
        case 26:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x = black_zone_x;
                    
target_y = black_zone_y;
                    
if(PositionX != 0 || PositionY != 0){
target_angle = atan2((target_y - PositionY), (target_x - PositionX)) * 57.2957795131 - 90;
                    

}
if(target_angle < 0){
target_angle = 360 + target_angle;
                    

}


if(Compass < target_angle && abs(Compass + 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass - 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(Compass < target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80){


if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -2;
                    
WheelRight = 2;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 2;
                    
WheelRight = -2;
                    
}

}
if (PositionX> black_zone_x-3 && PositionX < black_zone_x+3 && PositionY> black_zone_y-3 && PositionY < black_zone_y+3){
Preto++;
                     
}

            break;
        case 27:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= cyan2_zone_x;
                    
target_y=cyan2_zone_y;
                    
if(PositionX != 0 || PositionY != 0){
target_angle = atan2((target_y - PositionY), (target_x - PositionX)) * 57.2957795131 - 90;
                    

}
if(target_angle < 0){
target_angle = 360 + target_angle;
                    

}


if(Compass < target_angle && abs(Compass + 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass - 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(Compass < target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80){


if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -2;
                    
WheelRight = 2;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 2;
                    
WheelRight = -2;
                    
}

}
if (PositionX== black_zone_x && PositionY== black_zone_y){
Ciano++;
                    
}
if (PositionX> cyan2_zone_x-3 && PositionX < cyan2_zone_x+3 && PositionY> cyan2_zone_y-3 && PositionY < cyan2_zone_y+3){
Ciano++;
                     
}

            break;
        case 28:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= red_zone_x;
                    
target_y= red_zone_y;
                    
if(PositionX != 0 || PositionY != 0){
target_angle = atan2((target_y - PositionY), (target_x - PositionX)) * 57.2957795131 - 90;
                    

}
if(target_angle < 0){
target_angle = 360 + target_angle;
                    

}


if(Compass < target_angle && abs(Compass + 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass - 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(Compass < target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80){


if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -2;
                    
WheelRight = 2;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 2;
                    
WheelRight = -2;
                    
}

}
if (PositionX> red_zone_x-5 && PositionX < red_zone_x+5 && PositionY> red_zone_y-5 && PositionY < red_zone_y+5){
Vermelho++;
                     
}
            break;
        case 29:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= cyan1_zone_x;
                    
target_y=cyan1_zone_y;
                    
if(PositionX != 0 || PositionY != 0){
target_angle = atan2((target_y - PositionY), (target_x - PositionX)) * 57.2957795131 - 90;
                    

}
if(target_angle < 0){
target_angle = 360 + target_angle;
                    

}


if(Compass < target_angle && abs(Compass + 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass - 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(Compass < target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80){


if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -2;
                    
WheelRight = 2;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 2;
                    
WheelRight = -2;
                    
}

}
if (PositionX> cyan1_zone_x-3 && PositionX < cyan1_zone_x+3 && PositionY> cyan1_zone_y-3 && PositionY < cyan1_zone_y+3){
Ciano++;
                     
}
            break;
        case 30:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x = black_zone_x;
                    
target_y = black_zone_y;
                    
if(PositionX != 0 || PositionY != 0){
target_angle = atan2((target_y - PositionY), (target_x - PositionX)) * 57.2957795131 - 90;
                    

}
if(target_angle < 0){
target_angle = 360 + target_angle;
                    

}


if(Compass < target_angle && abs(Compass + 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass - 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(Compass < target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80){


if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -2;
                    
WheelRight = 2;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 2;
                    
WheelRight = -2;
                    
}

}
if (PositionX> black_zone_x-3 && PositionX < black_zone_x+3 && PositionY> black_zone_y-3 && PositionY < black_zone_y+3){
Preto++;
                     
}

            break;
        case 31:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            if(box1_x != 0 || box1_y != 0){
dist_box1 = sqrt(((box1_x - PositionX)*(box1_x - PositionX)) + ((box1_y - PositionY)*(box1_y - PositionY)));
                    

}
if(box2_x != 0 || box2_y != 0){
dist_box2 = sqrt(((box2_x - PositionX)*(box2_x - PositionX)) + ((box2_y - PositionY)*(box2_y - PositionY)));
                    

}
if(box3_x != 0 || box3_y != 0){
dist_box3 = sqrt(((box3_x - PositionX)*(box3_x - PositionX)) + ((box3_y - PositionY)*(box3_y - PositionY)));
                    

}


if(dist_box1 < dist_box2 && dist_box1 < dist_box3){
target_x = box1_x;
                    

target_y = box1_y;
                    

}
if(dist_box2 < dist_box1 && dist_box2 < dist_box3){
target_x = box2_x;
                    

target_y = box2_y;
                    

}
if(dist_box3 < dist_box1 && dist_box3 < dist_box2){
target_x = box3_x;
                    

target_y = box3_y;
                    

}


if(PositionX != 0 || PositionY != 0){
target_angle = atan2((target_y - PositionY), (target_x - PositionX)) * 57.2957795131 - 90;
                    

}
if(target_angle < 0){
target_angle = 360 + target_angle;
                    

}


if(Compass < target_angle && abs(Compass + 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 5;
                    

WheelRight = 3;
                    

}
if(Compass > target_angle && abs(Compass - 360 - target_angle) <= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(Compass < target_angle && abs(Compass + 360 - target_angle) >= abs(Compass - target_angle)){
WheelLeft = 3;
                    

WheelRight = 5;
                    

}
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80){


if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -2;
                    
WheelRight = 2;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 2;
                    
WheelRight = -2;
                    
}

}
            break;
        case 32:
            WheelLeft=2;
            WheelRight=2;
            LED_1=0;
            MyState=0;
            break;
        case 33:
            WheelLeft=5;
            WheelRight=5;
            LED_1=0;
            MyState=0;
            if(Time> 240 && LoadedObjects<1 && act == 0){
 act = 1;
                    
}
            break;
        default:
            break;
    }

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
        case 1:
            Game1();
            break;
        default:
            break;
    }
}

