#ifndef APUE_H
#define APUE_H

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
#include <sys/ipc.h> 
#include<sys/msg.h>
#include<stdlib.h>
#include <sys/shm.h>
#include<signal.h>
#include<sys/time.h>
#include<sys/sem.h>
#include<sys/mman.h>
#define FAIL -1
typedef void (*sighandler_t)(int);
typedef  sighandler_t sig_t;

static show_err(char *str)
{
	perror(str);
	exit(-1);
}


#endif
