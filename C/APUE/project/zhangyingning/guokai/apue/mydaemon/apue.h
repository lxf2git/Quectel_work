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
#include<stdlib.h>

int  mydaemon(int pid_chdir,int pid_close);
static show_err(char *str)
{
	perror(str);
	exit(-1);
}
#endif
