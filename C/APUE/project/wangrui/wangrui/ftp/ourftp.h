#ifndef OURFTP_H
#define OURFTP_H
#define _XOPEN_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <dirent.h>
#include <shadow.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <setjmp.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#include "struct.h"
#include "input.h"
#include "fun.h"

typedef void (*sighandler_t)(int);
typedef  sighandler_t sig_t;

static show_err(char *str)
{
	perror(str);
	exit(-1);
}

#endif
