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
int target_angle = 0;
int superobj_x = 0;
int superobj_y = 0;
int box1_x = 240;
int box1_y = 245;
int box2_x = 150;
int box2_y = 130;
int box3_x = 310;
int box3_y = 60;
int target_x = 0;
int target_y = 0;
int Rosa = 0;
int Vermelho = 0;
int Ciano = 0;
int Preto = 0;
int BlackZone1_x = 0;
int BlackZone1_y = 0;
int BlackZone2_x = 0;
int BlackZone2_y = 0;
int CyanZone1_x = 0;
int CyanZone1_y = 0;
int CyanZone2_x = 0;
int CyanZone2_y = 0;
int RedZone1_x = 0;
int RedZone1_y = 0;
int RedZone2_x = 0;
int RedZone2_y = 0;
int trap1_x = 0;
int trap1_y = 0;
int trap2_x = 0;
int trap2_y = 0;
int dist_box1 = 999;
int dist_box2 = 999;
int dist_box3 = 999;
int EndTime = 0;
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
    sprintf(info, "Duration=%d;SuperDuration=%d;bGameEnd=%d;CurAction=%d;CurGame=%d;SuperObj_Num=%d;SuperObj_X=%d;SuperObj_Y=%d;Teleport=%d;LoadedObjects=%d;target_angle=%d;superobj_x=%d;superobj_y=%d;box1_x=%d;box1_y=%d;box2_x=%d;box2_y=%d;box3_x=%d;box3_y=%d;target_x=%d;target_y=%d;Rosa=%d;Vermelho=%d;Ciano=%d;Preto=%d;BlackZone1_x=%d;BlackZone1_y=%d;BlackZone2_x=%d;BlackZone2_y=%d;CyanZone1_x=%d;CyanZone1_y=%d;CyanZone2_x=%d;CyanZone2_y=%d;RedZone1_x=%d;RedZone1_y=%d;RedZone2_x=%d;RedZone2_y=%d;trap1_x=%d;trap1_y=%d;trap2_x=%d;trap2_y=%d;dist_box1=%d;dist_box2=%d;dist_box3=%d;EndTime=%d;US_Front=%d;US_Left=%d;US_Right=%d;CSLeft_R=%d;CSLeft_G=%d;CSLeft_B=%d;CSRight_R=%d;CSRight_G=%d;CSRight_B=%d;PositionX=%d;PositionY=%d;TM_State=%d;Compass=%d;Time=%d;WheelLeft=%d;WheelRight=%d;LED_1=%d;MyState=%d;",Duration,SuperDuration,bGameEnd,CurAction,CurGame,SuperObj_Num,SuperObj_X,SuperObj_Y,Teleport,LoadedObjects,target_angle,superobj_x,superobj_y,box1_x,box1_y,box2_x,box2_y,box3_x,box3_y,target_x,target_y,Rosa,Vermelho,Ciano,Preto,BlackZone1_x,BlackZone1_y,BlackZone2_x,BlackZone2_y,CyanZone1_x,CyanZone1_y,CyanZone2_x,CyanZone2_y,RedZone1_x,RedZone1_y,RedZone2_x,RedZone2_y,trap1_x,trap1_y,trap2_x,trap2_y,dist_box1,dist_box2,dist_box3,EndTime,US_Front,US_Left,US_Right,CSLeft_R,CSLeft_G,CSLeft_B,CSRight_R,CSRight_G,CSRight_B,PositionX,PositionY,TM_State,Compass,Time,WheelLeft,WheelRight,LED_1,MyState);
    return info;
}
 
DLL_EXPORT char* GetTeamName()
{
     return "OpenSky GOD";
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
    else if(SuperObj_X!=0&&SuperObj_Y!=0&&superobj_x==0&&superobj_y==0)
    {
        SuperDuration = 0;
        Duration = 0;
        CurAction =1;
    }
    else if(Time>=0 && Time<=1)
    {
        SuperDuration = 0;
        Duration = 0;
        CurAction =2;
    }
    else if(Duration>0)
    {
        Duration--;
    }
    else if(CSLeft_R>=150 && CSLeft_R<=240 && CSLeft_G>=80 && CSLeft_G<=130 && CSLeft_B>=0 && CSLeft_B<=70 && CSRight_R>=150 && CSRight_R<=240 && CSRight_G>=80 && CSRight_G<=130 && CSRight_B>=0 && CSRight_B<=70&&((Vermelho>39&&Ciano>39&&Preto>39&&LoadedObjects>3)||
(Rosa>0&&Time>(EndTime*60-20))||(LoadedObjects>4&&Rosa==0)||LoadedObjects>5||Rosa>56
))
    {
        Duration = 33;
        CurAction =3;
    }
    else if(((CSLeft_R>=150&&CSLeft_R<=240&&CSLeft_G>=80&&CSLeft_G<=130&&CSLeft_B<=70)||(CSRight_R>=150&&CSRight_R<=240&&CSRight_G>=80&&CSRight_G<=130&&CSRight_B<=70))
&&
((Vermelho>39&&Ciano>39&&Preto>39&&LoadedObjects>3)||
(Rosa>0&&Time>(EndTime*60-20))||(LoadedObjects>4&&Rosa==0)||LoadedObjects>5||Rosa>56))
    {
        Duration = 0;
        CurAction =4;
    }
    else if(LoadedObjects<6&&((CSLeft_B>=250&&CSLeft_G<=50&&CSLeft_R>=230)||(CSRight_B>=250&&CSRight_G<=50&&CSRight_R>=230)))
    {
        Duration = 49;
        CurAction =5;
    }
    else if(LoadedObjects<6&&((CSLeft_B<=40&&CSLeft_G<=40&&CSLeft_R<=40)||(CSRight_B<=40&&CSRight_G<=40&&CSRight_R<=40))
&&Preto<79)
    {
        Duration = 39;
        CurAction =6;
    }
    else if(LoadedObjects<6&&((CSLeft_B>=240&&CSLeft_G>=240&&CSLeft_R<=50)||(CSRight_B>=240&&CSRight_G>=240&&CSRight_R<=50))
&&Ciano<79)
    {
        Duration = 39;
        CurAction =7;
    }
    else if(LoadedObjects<6&&((CSLeft_B<=40&&CSLeft_G<=40&&CSLeft_R>=230)||(CSRight_B<=40&&CSRight_G<=40&&CSRight_R>=230))
&&Vermelho<79)
    {
        Duration = 39;
        CurAction =8;
    }
    else if((sqrt(((trap1_x-PositionX)*(trap1_x-PositionX))+((trap1_y-PositionY)*(trap1_y-PositionY)))<60
&&
(PositionY-trap1_y>=-80&&PositionY-trap1_y<-50&&((Compass>=0&&Compass<50)||(Compass<=360&&Compass>310)))&&PositionX!=0&&PositionY!=0&&LoadedObjects>0)

||

(sqrt(((trap2_x-PositionX)*(trap2_x-PositionX))+((trap2_y-PositionY)*(trap2_y-PositionY)))<60
&&
(PositionY-trap2_y>=-60&&PositionY-trap2_y<-30&&((Compass>=0&&Compass<50)||(Compass<=360&&Compass>310)))&&PositionX!=0&&PositionY!=0&&LoadedObjects>0)
)
    {
        Duration = 0;
        CurAction =9;
    }
    else if((sqrt(((trap1_x-PositionX)*(trap1_x-PositionX))+((trap1_y-PositionY)*(trap1_y-PositionY)))<60
&&
PositionX-trap1_x<=60&&PositionX-trap1_x>10&&((Compass>=90&&Compass<140))&&PositionX!=0&&PositionY!=0&&LoadedObjects>0)

||

(sqrt(((trap2_x-PositionX)*(trap2_x-PositionX))+((trap2_y-PositionY)*(trap2_y-PositionY)))<60
&&
PositionX-trap2_x<=60&&PositionX-trap2_x>10&&((Compass>=90&&Compass<140))&&PositionX!=0&&PositionY!=0&&LoadedObjects>0))
    {
        Duration = 0;
        CurAction =10;
    }
    else if((sqrt(((trap1_x-PositionX)*(trap1_x-PositionX))+((trap1_y-PositionY)*(trap1_y-PositionY)))<60
&&
PositionX-trap1_x>=-70&&PositionX-trap1_x<-10&&((Compass>=270&&Compass<320))&&PositionX!=0&&PositionY!=0&&LoadedObjects>0)

||

(sqrt(((trap2_x-PositionX)*(trap2_x-PositionX))+((trap2_y-PositionY)*(trap2_y-PositionY)))<60
&&
PositionX-trap2_x>=-70&&PositionX-trap2_x<-10&&((Compass>=270&&Compass<320))&&PositionX!=0&&PositionY!=0&&LoadedObjects>0))
    {
        Duration = 0;
        CurAction =11;
    }
    else if((sqrt(((trap1_x-PositionX)*(trap1_x-PositionX))+((trap1_y-PositionY)*(trap1_y-PositionY)))<60
&&
PositionY-trap1_y<=60&&PositionY-trap1_y>15&&((Compass>=180&&Compass<230))&&PositionX!=0&&PositionY!=0&&LoadedObjects>0)

||

(sqrt(((trap2_x-PositionX)*(trap2_x-PositionX))+((trap2_y-PositionY)*(trap2_y-PositionY)))<60
&&
PositionY-trap2_y<=60&&PositionY-trap2_y>15&&((Compass>=180&&Compass<230))&&PositionX!=0&&PositionY!=0&&LoadedObjects>0))
    {
        Duration = 0;
        CurAction =12;
    }
    else if(CSLeft_R>=200 && CSLeft_R<=235 && CSLeft_G>=215 && CSLeft_G<=250 && CSLeft_B>=0 && CSLeft_B<=10&&(LoadedObjects>0))
    {
        Duration = 49;
        CurAction =13;
    }
    else if(CSRight_R>=200 && CSRight_R<=235 && CSRight_G>=215 && CSRight_G<=250 && CSRight_B>=0 && CSRight_B<=10&&(LoadedObjects>0))
    {
        Duration = 49;
        CurAction =14;
    }
    else if(0>1)
    {
        Duration = 0;
        CurAction =15;
    }
    else if((PositionY>=230&&((Compass>=0&&Compass<89)||(Compass<=360&&Compass>271))&&superobj_x==0&&superobj_y==0&&LoadedObjects<5)||(PositionY>=260&&((Compass>=0&&Compass<89)||(Compass<=360&&Compass>271)))&&PositionX!=0&&PositionY!=0&&PositionX>20&&PositionX<340)
    {
        Duration = 0;
        CurAction =16;
    }
    else if((PositionX<=40&&PositionX>0&&((Compass>=90&&Compass<179)||(Compass<=90&&Compass>1))&&superobj_x==0&&superobj_y==0&&LoadedObjects<5)||(PositionX<=10&&((Compass>=90&&Compass<179)||(Compass<=90&&Compass>1)))&&PositionX!=0&&PositionY!=0)
    {
        Duration = 0;
        CurAction =17;
    }
    else if((PositionY<=40&&PositionY>0&&((Compass>=180&&Compass<269)||(Compass<=180&&Compass>91))&&superobj_x==0&&superobj_y==0&&LoadedObjects<5)||(PositionY<=10&&((Compass>=180&&Compass<269)||(Compass<=180&&Compass>91)))&&PositionX!=0&&PositionY!=0&&PositionX>20&&PositionX<340)
    {
        Duration = 0;
        CurAction =18;
    }
    else if((PositionX>=310&&((Compass>=270&&Compass<359)||(Compass<=270&&Compass>181))&&superobj_x==0&&superobj_y==0&&LoadedObjects<5)||(PositionX>=340&&((Compass>=270&&Compass<359)||(Compass<=270&&Compass>181)))&&PositionY>10&&PositionX!=0&&PositionY!=0)
    {
        Duration = 0;
        CurAction =19;
    }
    else if(US_Front>=0 && US_Front<=10 && US_Left>=0 && US_Left<=10 && US_Right>=0 && US_Right<=10)
    {
        Duration = 33;
        CurAction =20;
    }
    else if(US_Front>=0 && US_Front<=40)
    {
        Duration = 0;
        CurAction =21;
    }
    else if(US_Left<=30||US_Right<=30)
    {
        Duration = 0;
        CurAction =22;
    }
    else if((Vermelho>39&&Ciano>39&&Preto>39&&LoadedObjects>3)||
(Rosa>0&&Time>(EndTime*60-20))||(LoadedObjects>4&&Rosa==0)||LoadedObjects>5||Rosa>56)
    {
        Duration = 0;
        CurAction =23;
    }
    else if(superobj_x!=0&&superobj_y!=0&&LoadedObjects<6)
    {
        Duration = 0;
        CurAction =24;
    }
    else if(Preto<1)
    {
        Duration = 0;
        CurAction =25;
    }
    else if(Ciano<1)
    {
        Duration = 0;
        CurAction =26;
    }
    else if(Vermelho<1)
    {
        Duration = 0;
        CurAction =27;
    }
    else if(Ciano<2)
    {
        Duration = 0;
        CurAction =28;
    }
    else if(Preto<2)
    {
        Duration = 0;
        CurAction =29;
    }
    else if(Ciano<3)
    {
        Duration = 0;
        CurAction =30;
    }
    else if(Vermelho<2)
    {
        Duration = 0;
        CurAction =31;
    }
    else if(Ciano<4)
    {
        Duration = 0;
        CurAction =32;
    }
    else if(Preto<3)
    {
        Duration = 0;
        CurAction =33;
    }
    else if(true)
    {
        Duration = 0;
        CurAction =34;
    }
    switch(CurAction)
    {
        case 1:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            superobj_x=SuperObj_X;
                    
superobj_y=SuperObj_Y;
                    
            break;
        case 2:
            WheelLeft=3;
            WheelRight=3;
            LED_1=0;
            MyState=0;
            EndTime=5;
                    
box1_x=240;
                    
box1_y=245;
                    
box2_x=0;
                    
box2_y=0;
                    
box3_x=0;
                    
box3_y=0;
                    
BlackZone1_x=300;
                    
BlackZone1_y=210;
                    
BlackZone2_x=0;
                    
BlackZone2_y=0;
                    
RedZone1_x=225;
                    
RedZone1_y=20;
                    
RedZone2_x=0;
                    
RedZone2_y=0;
                    
CyanZone1_x=130;
                    
CyanZone1_y=190;
                    
CyanZone2_x=115;
                    
CyanZone2_y= 40;
                    
trap1_x=55;
                    
trap1_y=135;
                    
trap2_x=9999;
                    
trap2_y=9999;
                    
            break;
        case 3:
            WheelLeft=0;
            WheelRight=0;
            LED_1=2;
            MyState=0;
            if((CSLeft_R < 150 || CSLeft_R > 240 || CSLeft_G < 80 || CSLeft_G > 130 || CSLeft_B > 70) && (CSRight_R < 150 || CSRight_R > 240 || CSRight_G < 80 || CSRight_G > 130 || CSRight_B > 70)){
LoadedObjects=6;
                    
}

Preto=0;
                    
Vermelho=0;
                    
Rosa=0;
                    
Ciano=0;
                    
            if(Duration == 1) {LoadedObjects = 0; } 
            break;
        case 4:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if(CSLeft_R >= 150 && CSLeft_R <= 240 && CSLeft_G >= 80 && CSLeft_G <= 130 && CSLeft_B <= 70){
WheelLeft=1;
                    
WheelRight=3;
                    
} else if(CSRight_R >= 150 && CSRight_R <= 240 && CSRight_G >= 80 && CSRight_G <= 130 && CSRight_B <= 70){
WheelLeft=3;
                    
WheelRight=1;
                    
}
            break;
        case 5:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            superobj_x=0;
                    
superobj_y=0;
                    
Rosa++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 6:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            Preto++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 7:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            Ciano++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 8:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            Vermelho++;
                    
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 9:
            WheelLeft=-5;
            WheelRight=-5;
            LED_1=0;
            MyState=0;
            if(Compass>=0 && Compass<89){
 WheelLeft=-2;
                    
 WheelRight=2;
                    
} else {
  WheelLeft=2;
                    
  WheelRight=-2;
                    
}
            break;
        case 10:
            WheelLeft=-5;
            WheelRight=-5;
            LED_1=0;
            MyState=0;
            if(Compass>=90 && Compass<179){
  WheelLeft=-2;
                    
  WheelRight=2;
                    
} else {
  WheelLeft=2;
                    
  WheelRight=-2;
                    
}
            break;
        case 11:
            WheelLeft=-5;
            WheelRight=-5;
            LED_1=0;
            MyState=0;
            if(Compass>=270 && Compass<359){
  WheelLeft=-2;
                    
  WheelRight=2;
                    
} else {
  WheelLeft=2;
                    
  WheelRight=-2;
                    
}

            break;
        case 12:
            WheelLeft=-5;
            WheelRight=-5;
            LED_1=0;
            MyState=0;
            if(Compass>=180 && Compass<269){
  WheelLeft=-2;
                    
  WheelRight=2;
                    
} else {
  WheelLeft=2;
                    
  WheelRight=-2;
                    
}
            break;
        case 13:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if(CSRight_R<200 || CSRight_R>235 || CSRight_G<215 || CSRight_G>250 || CSRight_B>10){
WheelLeft=4;
                    
WheelRight=2;
                    
} else {
WheelLeft=3;
                    
WheelRight=-2;
                    
}
if(CSLeft_R<200 || CSLeft_R>235 || CSLeft_G<215 || CSLeft_G>250 || CSLeft_B>10){
Duration=0;
                    
}
            break;
        case 14:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if(CSLeft_R<200 || CSLeft_R>235 || CSLeft_G<215 || CSLeft_G>250 || CSLeft_B>10){
WheelLeft=2;
                    
WheelRight=4;
                    
} else {
WheelLeft=-2;
                    
WheelRight=3;
                    
}
if(CSRight_R<200 || CSRight_R>235 || CSRight_G<215 || CSRight_G>250 || CSRight_B>10){
Duration=0;
                    
}
            break;
        case 15:
            WheelLeft=-5;
            WheelRight=-5;
            LED_1=0;
            MyState=0;
            break;
        case 16:
            WheelLeft=-5;
            WheelRight=-5;
            LED_1=0;
            MyState=0;
            if(Compass>=0 && Compass<89){
 if(PositionY>=260){
  WheelLeft=-2;
                    
  WheelRight=2;
                    
 } else {
  WheelLeft=2;
                    
  WheelRight=4;
                    
 }
} else {
  if(PositionY>=260){
  WheelLeft=2;
                    
  WheelRight=-2;
                    
 } else {
  WheelLeft=4;
                    
  WheelRight=2;
                    
 }
}
            break;
        case 17:
            WheelLeft=-5;
            WheelRight=-5;
            LED_1=0;
            MyState=0;
            if(Compass>=90 && Compass<179){
 if(PositionX<=10){
  WheelLeft=-2;
                    
  WheelRight=2;
                    
 } else {
  WheelLeft=2;
                    
  WheelRight=4;
                    
 }
} else {
  if(PositionX<=10){
  WheelLeft=2;
                    
  WheelRight=-2;
                    
 } else {
  WheelLeft=4;
                    
  WheelRight=2;
                    
 }
}
            break;
        case 18:
            WheelLeft=-5;
            WheelRight=-5;
            LED_1=0;
            MyState=0;
            if(Compass>=180 && Compass<269){
 if(PositionY<=10){
  WheelLeft=-2;
                    
  WheelRight=2;
                    
 } else {
  WheelLeft=2;
                    
  WheelRight=4;
                    
 }
} else {
  if(PositionY<=10){
  WheelLeft=2;
                    
  WheelRight=-2;
                    
 } else {
  WheelLeft=4;
                    
  WheelRight=2;
                    
 }
}
            break;
        case 19:
            WheelLeft=-5;
            WheelRight=-5;
            LED_1=0;
            MyState=0;
            if(Compass>=270 && Compass<359){
 if(PositionX>=340){
  WheelLeft=-2;
                    
  WheelRight=2;
                    
 } else {
  WheelLeft=2;
                    
  WheelRight=4;
                    
 }
} else {
  if(PositionX>=340){
  WheelLeft=2;
                    
  WheelRight=-2;
                    
 } else {
  WheelLeft=4;
                    
  WheelRight=2;
                    
 }
}

            break;
        case 20:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if(US_Right>=US_Left){
WheelLeft=3;
                    
WheelRight=-3;
                    
} else {
WheelLeft=-3;
                    
WheelRight=3;
                    
}
            break;
        case 21:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if(US_Front<=10){
 if(US_Left>=US_Right){
   WheelLeft=-3;
                    
   WheelRight=3;
                    
 } else {
   WheelLeft=3;
                    
   WheelRight=-3;
                    
 }
} else if(US_Front<=20){
 if(US_Left>=US_Right){
   WheelLeft=-2;
                    
   WheelRight=4;
                    
 } else {
   WheelLeft=4;
                    
   WheelRight=-2;
                    
 }
} else if(US_Front<=30){
 if(US_Left>=US_Right){
   WheelLeft=2;
                    
   WheelRight=4;
                    
 } else {
   WheelLeft=4;
                    
   WheelRight=2;
                    
 }
} else {
 if(US_Left>=US_Right){
   WheelLeft=3;
                    
   WheelRight=4;
                    
 } else {
   WheelLeft=4;
                    
   WheelRight=3;
                    
 }
}
            break;
        case 22:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if(US_Left>=US_Right){
WheelLeft=3;
                    
WheelRight=4;
                    
} else {
WheelLeft=4;
                    
WheelRight=3;
                    
}
            break;
        case 23:
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
        case 24:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            if(PositionX != 0 || PositionY != 0){
target_angle = atan2((superobj_y - PositionY), (superobj_x - PositionX)) * 57.2957795131 - 90;
                    

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
if(sqrt(((superobj_x - PositionX)*(superobj_x - PositionX)) + ((superobj_y - PositionY)*(superobj_y - PositionY))) <= 80 && sqrt(((superobj_x - PositionX)*(superobj_x - PositionX)) + ((superobj_y - PositionY)*(superobj_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}
            break;
        case 25:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= BlackZone1_x;
                    
target_y= BlackZone1_y;
                    
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
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80 && sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}


if (PositionX> target_x-3 && PositionX < target_x+3 && PositionY> target_y-3 && PositionY < target_y+3){
Preto++;
                     
}





            break;
        case 26:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= CyanZone2_x;
                    
target_y= CyanZone2_y;
                    
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
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80 && sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}
if (PositionX> target_x-3 && PositionX < target_x+3 && PositionY> target_y-3 && PositionY < target_y+3){
Ciano++;
                     
}

            break;
        case 27:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x = RedZone1_x;
                    
target_y = RedZone1_y;
                    
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
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80 && sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}
if (PositionX> target_x-3 && PositionX < target_x+3 && PositionY> target_y-3 && PositionY < target_y+3){
Vermelho++;
                     
}

            break;
        case 28:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= CyanZone1_x;
                    
target_y= CyanZone1_y;
                    
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
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80 && sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}
if (PositionX> target_x-3 && PositionX < target_x+3 && PositionY> target_y-3 && PositionY < target_y+3){
Ciano++;
                     
}
            break;
        case 29:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= BlackZone1_x;
                    
target_y= BlackZone1_y;
                    
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
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80 && sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}


if (PositionX> target_x-3 && PositionX < target_x+3 && PositionY> target_y-3 && PositionY < target_y+3){
Preto++;
                     
}


            break;
        case 30:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= CyanZone2_x;
                    
target_y= CyanZone2_y;
                    
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
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80 && sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}
if (PositionX> target_x-3 && PositionX < target_x+3 && PositionY> target_y-3 && PositionY < target_y+3){
Ciano++;
                     
}

            break;
        case 31:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x = RedZone1_x;
                    
target_y = RedZone1_y;
                    
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
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80 && sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}
if (PositionX> target_x-3 && PositionX < target_x+3 && PositionY> target_y-3 && PositionY < target_y+3){
Vermelho++;
                     
}

            break;
        case 32:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= CyanZone1_x;
                    
target_y= CyanZone1_y;
                    
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
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80 && sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}
if (PositionX> target_x-3 && PositionX < target_x+3 && PositionY> target_y-3 && PositionY < target_y+3){
Ciano++;
                     
}
            break;
        case 33:
            WheelLeft=1;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            target_x= BlackZone1_x;
                    
target_y= BlackZone1_y;
                    
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
if(sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) <= 80 && sqrt(((target_x - PositionX)*(target_x - PositionX)) + ((target_y - PositionY)*(target_y - PositionY))) >= 10){

if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass <= 180) || (target_angle <= Compass && target_angle-Compass >= 180))){
WheelLeft = -3;
                    
WheelRight = 3;
                    
} else if(abs(target_angle-Compass)>=50 && ((target_angle >= Compass && target_angle-Compass >= 180) || (target_angle <= Compass && target_angle-Compass <= 180))){
WheelLeft = 3;
                    
WheelRight = -3;
                    
}

}


if (PositionX> target_x-3 && PositionX < target_x+3 && PositionY> target_y-3 && PositionY < target_y+3){
Preto++;
                     
}




            break;
        case 34:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            if(PositionX==0 && PositionY==0){
WheelLeft=3;
                    
WheelRight=3;
                    
}

else {
WheelLeft=5;
                    
WheelRight=5;
                    
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

