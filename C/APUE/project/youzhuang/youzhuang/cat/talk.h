#ifndef _TALK_H_
#define _TALK_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<sys/stat.h>
#include<fcntl.h>
void fun(int sig);
void func(int sig, siginfo_t *info, void *p);
#endif
