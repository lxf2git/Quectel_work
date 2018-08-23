#ifndef _MAIN_H_
#define _MAIN_H_

#include"apue.h"
#define FAILURE -1
#define SUCCESS 0
#define EXE_SUC 2

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

typedef struct ftp_usr_info
{
	char ftp_usrname[50];
	char ftp_passwd[50];
}sFui, *pFui;

typedef struct cli_to_ser
{
	enum cmd_type type;
	union ftp_arg
	{
		sFui ftp_cli_login;
		char ftp_get_file[100];
		char ftp_put_file[100];
		char ftp_cd_path[100];
		char ftp_mkdir_path[100];
	}uFg;
}sCts, *pCts;

typedef struct recv_to_deal
{
	sCts usr_order_msg;
	int confd;
	struct sockaddr_in usr_log_msg;
}sRtd, *pRtd;

typedef struct deal_to_pros
{
	struct sockaddr_in usr_log_msg;
	pid_t pid_fun;//执行命令pid;
	struct deal_to_pros *prev;
	struct deal_to_pros *next;
}sDtp, *pDtp;

typedef struct Msg
{
	long type;
	sRtd msgbuf;
}sMsg, *pMsg;

typedef struct Msg_file
{
	long type;
	char msgbuf[1024];
}sMfile, *pMfile;

int  recive(int sockfd, int *pfd);
int  sock_fun();
void creat_memory(void **p, int size);
void zomb_fun(int sig);
void init_node(pDtp *p);
int  recive_msg(int sockfd, int confd, struct sockaddr_in conaddr, int *pfd
				);
int  creat_msg_que();
int deal(int *pfd, int fd, pDtp phead, int msgid, sMsg msgbuf);
int insert_(pDtp phead, pDtp pnew);
int judge_pid(pDtp phead, pRtd data);
void record(int fd, int msgid);

#endif
