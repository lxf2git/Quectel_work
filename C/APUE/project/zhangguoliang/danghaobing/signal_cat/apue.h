#ifndef _APUE_H_
#define _APUE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <shadow.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <strings.h>
#include <setjmp.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/mman.h>

typedef void (*sighandler_t)(int);
typedef sighandler_t sig_t;
static show_err(char *str)
{
	perror(str);
	exit(-1);
}

static fork_err(pid_t p)
{
		if(p<0)
		{
				show_err("fork");
		}
}

void set_err(int a,char b[50])
{
    if(a<0)
            show_err(b);
}
#endif
