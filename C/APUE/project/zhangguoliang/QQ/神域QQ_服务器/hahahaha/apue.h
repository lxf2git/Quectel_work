#ifndef _APUE_H
#define _APUE_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <shadow.h>
#include <unistd.h>
#include <pwd.h>
#include<time.h>
#include<setjmp.h>
#include <semaphore.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<pthread.h>
#include<arpa/inet.h>
#include<sys/socket.h>
typedef void (*sighandler_t)(int);
typedef  sighandler_t sig_t;

static show_err(char *str)
{
	perror(str);
	exit(-1);
}
enum {APPLY=1,LOGIN,CHQQ,FDPWD,CHINFO,SHOWF,ADDFD,DELFD,FTALK};
enum {Q_TALK,NEWF,S_TALK,SENDF,N_TALK,M_TALK,AEXIT,OKFD,KOFD,NKOFD};

static int semid;
static struct sembuf sem;

#endif
