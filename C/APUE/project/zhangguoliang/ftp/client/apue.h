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

struct ftp_usr_info
{
	char ftp_usrname[30];
	char ftp_passwd[30];
};

enum cmd_type
{
	LOGIN,
	LS,
	PUT,
	GET,
	CD,
	PWD,
	MKDIR,
	QUIT
};

struct cli_to_ser
{
	int cmd;

	union
	{
		struct ftp_usr_info user_info;//LOGIN
		char ftp_get_file[100];//GET
		char ftp_put_file[100];//PUT
		char ftp_ls_path[100];//LS
		char ftp_cd_path[100];//CD
		char ftp_mkdir_path[100];//MKDIR
	};
}message;

typedef void (*sighandler_t)(int);
typedef  sighandler_t sig_t;

static show_err(char *str)
{
	perror(str);
	exit(-1);
}
#endif
