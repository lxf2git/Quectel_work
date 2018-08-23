#ifndef APUE_H
#define APUE_H



#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <shadow.h>
#include <pwd.h>
#include<time.h>
#include<setjmp.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/msg.h>
#include <sys/sem.h>

#include<arpa/inet.h>
#include<sys/socket.h>
 #define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>
#include <pthread.h>
static show_err(char *str)
{
	perror(str);
	exit(-1);
}
#endif
