#ifndef APUE_H_
#define APUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<shadow.h>
#include<time.h>
#include<grp.h>
#include<setjmp.h>
#include<unistd.h>
#include<pwd.h>
#include<signal.h>
#include<sys/time.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define CREAT_NEW_SON 1
#define INTO_SON 0
#define OUT_SON -1
#define MAX_USR 10
void show_err(char *);
void set_err(int,char *);
in_addr_t now_login[10];
/*void show_err(char *str)//显示错误，并退出
{
		perror(str);
		exit(-1);
}
void set_err(int a,char b[50])
{
		if(a==-1)
		show_err(b);
}*/


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

	union //ftp_arg
	{
		struct ftp_usr_info user_info;//LOGIN
		char ftp_get_file[100];//GET
		char ftp_put_file[100];//PUT
		char ftp_cd_path[100];//CD
		char ftp_mkdir_path[100];//MKDIR
		char ftp_ls_path[100];//LS
	};
};

struct recv_to_deal
{
	struct cli_to_ser to_ser;
	struct sockaddr_in conaddr;
};


typedef void (*sighandler_t)(int);
typedef sighandler_t sig_t;
void recv_process(struct recv_to_deal*);
#endif

