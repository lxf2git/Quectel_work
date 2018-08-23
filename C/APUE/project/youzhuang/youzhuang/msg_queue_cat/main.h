#ifndef _MAIN_H_
#define _MAIN_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/msg.h>
typedef struct msg
{
		long type;
		char msg[1024];
}Msg;
#endif
