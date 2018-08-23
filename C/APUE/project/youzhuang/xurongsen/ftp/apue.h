#ifndef APUE_H
#define APUE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <dirent.h>
#include <fcntl.h>
#include <grp.h>

#include <stdio.h>
#include <string.h>
#include <shadow.h>
#include <signal.h>
#include<setjmp.h>
#include<stdlib.h>

#include <unistd.h>
#include <pwd.h>
#include<time.h>


static show_err(char *str)
{
	perror(str);
	exit(-1);
}
#endif
