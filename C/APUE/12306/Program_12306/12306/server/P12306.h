#ifndef P12306_H
#define  P12306_H

#include<stdio.h> 
#include<stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h> 
#include<strings.h> 
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include<time.h> 
#include <signal.h>
#include<sys/time.h>
#include <shadow.h>
#include <setjmp.h>
#include <assert.h> 
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>

#define  FALSE   (-1)
#define  TRUE     (0)

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
	BACK_TKT,     //退票
	BACK_ERR
};

//flag标志
enum FLAG_VALUE{
	LOG_UNSUC,
	LOG_SUC,
};

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

struct db_user{
	char name[30];
	char passwd[20];
	unsigned long index;
};

struct db_user_info{
	char train[100];
};

struct db_train{
	char train[10];
	char place[20];
	unsigned int num;
};

typedef struct db_fd{
	int db_train_fd;
	int db_index_fd;
	int db_data_fd;
	pthread_rwlock_t rwlock;
}DB;


void my_register(void *arg);
void my_login(void *arg);
void my_que_tkt(void *arg);
void my_ord_tkt(void *arg);
void my_que_order(void *arg);
void my_back_tkt(void *arg);
extern DB db_12306;

//打开一个数据库
int db_open();

//获取用户密码 成功返回0 未找到返回-1
int db_user_passwd(char username[30], char *passwd);

//获取车次 结尾返回0 没有返回-1
int db_train_info(char place[50], char *);

//添加用户信息 成功返回0 已存在返回-1
int db_add_user(char username[30], char passwd[20]);

//获取此用户的订单信息 成功返回1 结束返回0  没有信息返回-1
int db_user_info(chae[30], char train[10]);

//删除用户的订单信息 未找到返回-1
int db_del_ticket(char username[30], char train[10]);

//修改余票信息
int db_change_train(char train[10], char flag);

//获取此车次剩余车票
int db_ticket_num(char train[10]);

//获取此车次的目的地
int db_ticket_place(char train[10], char *data);

//关闭一个数据库
int db_close();

//获取此车次的目的地
int db_ticket_place(char train[10], char *data);

//添加车次
void db_add_train();

#endif 
