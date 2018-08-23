//
//  main.c
//  222
//
//  Created by 朱晓珂 on 15/9/17.
//  Copyright (c) 2015年 朱晓珂. All rights reserved.
//

#include <stdio.h>
#define PID_NO_PROC 0xff
#define MODE_NO_CHG 0xff
#define TBL_END      0xff

#define KEY_STOP 0x12
#define KEY_PLAY 0x13
#define KEY_PAUSE 0x18

#define KEY_MAX 3

enum
{
    MODE_STOP,
    MODE_PLAY,
    MODE_PAUSE,
    MODE_MAX
};
enum
{
    PID_STP2PLY,
    PID_PLY2STP,
    PID_PLY2PUS,
    PID_PUS2STP,
    PID_PUS2PLY
};

///////////////////////////////////////////////////////////////
struct ModeMatrix {
    unsigned char	nucProcCode;
    unsigned char	nucNextMode;
};

///////////////////////////////////////////////////////////////
extern unsigned char	wucMakeSerialNumChar( const unsigned char *aucPointer , unsigned char aucChkData );
static void stop2play(void);
static void play2stop(void);
static void play2pause(void);
static void pause2stop(void);
static void pause2play (void);

///////////////////////////////////////////////////////////////
static const unsigned char nuiKeyTable[] =
{
    KEY_STOP,
    KEY_PLAY,
    KEY_PAUSE,
    TBL_END
};//按键的集合

static const struct ModeMatrix modematrix_tbl[][KEY_MAX] =
{
    {
        {PID_NO_PROC,MODE_NO_CHG},
        {PID_STP2PLY,MODE_PLAY},
        {PID_NO_PROC,MODE_NO_CHG}
    },
    {
        {PID_PLY2STP,MODE_STOP},
        {PID_NO_PROC,MODE_NO_CHG},
        {PID_PLY2PUS,MODE_PAUSE}
    },
    {
        {PID_PUS2STP,MODE_STOP},
        {PID_PUS2PLY,MODE_PLAY},
        {PID_NO_PROC,MODE_NO_CHG}
    }
};

static void ( * const nvdProcExecTable[] )( void ) =
{
    stop2play,
    play2stop,
    play2pause,
    pause2stop,
    pause2play
};

///////////////////////////////////////////////////////////////
static unsigned char nuccurmode;

///////////////////////////////////////////////////////////////
void driveengine(unsigned char key)//接收到的当前按下的按键key
{
    unsigned char auckeycode;//当前的按键
    const struct ModeMatrix *astEventChg;//当前模式
    
    auckeycode = wucMakeSerialNumChar(nuiKeyTable, key);
    
    if((TBL_END != auckeycode) && (nuccurmode < MODE_MAX))
    {
        astEventChg = &modematrix_tbl[nuccurmode][auckeycode];
    }//判断返回的按键是否有效
    else
    {
        return;
    }
    
    if(MODE_NO_CHG != astEventChg->nucNextMode)
    {
        nuccurmode = astEventChg->nucNextMode;
    }
    
    if(PID_NO_PROC != astEventChg->nucProcCode)
    {
        nvdProcExecTable[astEventChg->nucProcCode]();
    }
    
    return;
}

unsigned char wucMakeSerialNumChar( const unsigned char *aucPointer , unsigned char aucChkData )//判断按下的按键，返回按键编码
{
    unsigned char	aucCnt = 0;
    
    while( ( *aucPointer != aucChkData ) && ( *aucPointer != TBL_END ) ){
        aucPointer++;
        aucCnt++;
    }
    if( *aucPointer == TBL_END ){
        aucCnt = TBL_END;
    }
    return( aucCnt );
}
///////////////////////////////////////////////////////////////
static void stop2play(void)
{
    return ;
}
static void play2stop(void)
{
    return ;
}
static void play2pause(void)
{
    return ;
}
static void pause2stop(void)
{
    return ;
}
static void pause2play (void)
{
    return ;
}

