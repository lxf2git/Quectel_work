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
#include<arpa/inet.h>
#include<sys/socket.h>


//命令枚举
enum CMD_VALUE{
	REGISTER,	//注册
	REG_ERR,	//注册失败
	LOGIN,		//登录
	LOG_ERR,	//登录失败
	QUE_TKT,	//查询票
	QUE_ERR,	//查询失败
	QUE_ORDER,	//查询订单
	QUE_OVER,	//查询信息发送结束
	ORD_TKT,	//订票
	ORD_ERR,	//订票失败
	CHA_TKT,	//改签
	CHA_ERR,	//改签失败
	BACK_TKT,       	//退票
	BACK_ERR
};
enum FLAG_VALUE{
	LOG_UNSUC,
	LOG_SUC,
};
#define REG 1
#define LOG 2
#define QUE 3
#define ORD 4
#define QUE_ORD 5
#define RET 6
#define CHANGE 7
#define QUIT 8
//用户信息
struct user_info{
	char username[30];
	char userpasswd[20];
};

//用户请求详细信息
union user_req{
	char que_buf[1024];
	char ord_num[1024];

};

//客户端发送的包
struct cli_ser_pakg{
	int cmd;				//命令
	int flag;				//标志（成功未成功）
	struct user_info user;	//用户信息
	union user_req req;		//用户请求（目的地,车次）
};

//服务器收到数据包后封装给线程
struct ser_deal_pakg{
	struct cli_ser_pakg recv_pakg;
	struct sockaddr_in cli_ip;
  int sockfd;
};

//发回给客户端的数据buf
union deal_ret{
	char reg_buf[1024];	//注册，登录buf
	char ord_buf[1024];	//订票buf
	char cha_buf[1024];	//改签buf
	char que_buf[1024];	//查询buf
	char back_buf[1024];//退票buf
};

//服务器发给客户端的包
struct ser_cli_pakg{
	int cmd;
	int flag;
	union deal_ret ret;  
};

static show_err(char *str)
{
	perror(str);
	exit(-1);
}

struct cli_pakg
{
  int fd;
  struct cli_ser_pakg cliTser;
  struct sockaddr_in seraddr;
};
typedef struct{
char end[10];
char blue[10];
char yell[10];
char violet[10];
char gren[10];
char white[10];
char red[10];
char shine[10];
}Scolo;
extern char tick[100];
extern Scolo colo;
void myexit(int fd);
int ord_tick(struct cli_pakg client,int say);
int change(char *add);
int que_all(struct cli_pakg client,int say);
int que_ord(struct cli_pakg client);
void reg_user(struct cli_pakg *client);
void user_login(struct cli_pakg *client);
int ret_tick(struct cli_pakg client,int say);
char * change_que(char *str,int flag);
#endif
