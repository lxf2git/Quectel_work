#ifndef APUE_H_
#define APUE_H_
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<shadow.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<signal.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<arpa/inet.h>
#include<sys/socket.h>



static show_err(char *str)
{
	perror(str);
	exit(-1);
}

typedef struct get_or_put
{
		char  file_name[30];
		char  file_buf[1024];
}sG_p,*pG_p;

typedef struct ftp_usr_info
{
		char ftp_usrname[30];
		char ftp_passwd[30];
		struct ftp_usr_info *prev;
		struct ftp_usr_info *next;
}sF,*pF;
typedef struct msg
{
	long type;
	char name[20];
	char data[1024];
}Msg,*Psg;

void init_node(pF *pnode);
int login_infor(pF pHead,char *name,char *passwd);
void delete(pF pHead,char *name);
int login_user_psw(char *name,char *passwd);
int  choose_command(char *buf,char *buffile,int confd);
#endif

