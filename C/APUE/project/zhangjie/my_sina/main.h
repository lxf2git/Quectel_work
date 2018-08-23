#ifndef _MAIN_H_
#define _MIAN_H_

#include"apue.h"

#define SUCCESS 0
#define FAILURE -1
#define EXIST 2
#define SU_QUIT -2
#define COM_NUM 10
#define LINE_NUM 10

enum fun_self //用户功能选择操作
{
	REGISTER,//注册
	LOGIN,//登录
	SEARCH,//搜查
	CONCERN,//关注
	NOT_CONCERN,//取消关注
	PUBLISH,//发表
	VIEW_BLOG,//查看微波
	VIEW_FRI,//查看朋友
	VIEW_FAN,//查看粉丝
	FORWARDING,//转发（微博界面）
	COMMENT,//评论（微博界面）
	PRAISE,//加赞（微博界面）
	DELETE,//删除（微博界面）
	PAGEUP,//上一页（微博界面）
	PAGEDOWN,//下一页（微博界面）
	QUIT_V,//返回上一级
	QUIT_S//退出微博
};


typedef struct worker
{
	void *(*usrFun)(void * confd);	
	void *confd;
	struct worker *next;
}Thread_worker;

typedef struct 
{
	pthread_mutex_t queue_lock;
	pthread_cond_t queue_ready;
	
	Thread_worker *queue_head;
	int shutdown;
	pthread_t *threadid;
	int max_thread_num;
	int cur_queue_size;
}Thread_pool;

typedef struct usr_inf//用户id、密码、名字
{
	char usr_id[30];
	char usr_passwd[30];
	char usr_nam[30];
}sUsr, *pUsr;

typedef struct cli_to_ser//客户端-》服务器（用户命令）
{
	enum fun_self type;
	char usr_nam[30];
	union 
	{
		sUsr usr_self_info;
		char search_usr_name[30];
		char concern_usr_name[30];
		char not_concern_usr_name[30]; 
		char view_usr_name[30];
		char comment_content[50];
		char web_content[200];
	}exe_fun;
}sCts, *pCts;

typedef struct fans//粉丝列表
{
	char usr_nam[30];
	struct fans *next;
	struct fans *prev;
}sFan, *pFan;

typedef struct friend_s//关注好友列表
{
	char usr_nam[30];
	struct friend_s *next;
	struct friend_s *prev;
}sFri, *pFri;

typedef struct content//个人微博评论
{
	char com_nam[30];//该评论的写的人
	char com[50];
}sCom, *pCom;

typedef struct web//个人微博动态列表
{
	char content[200];//内容
	int praise;
	int com_num;
	sCom com[COM_NUM];//评论
	struct web *prev;
	struct web *next;
}sWeb, *pWeb;

typedef struct usr_record//个人界面
{
	sUsr usr_msg;//用户信息
	int online;//是否在线
	int concern_num;//粉丝人数
	pFan fans_list;	//粉丝列表
	int friend_num;//好友
	pFri fri_list;//好友列表
	int publish_num;//个人微博数量
	pWeb web_list;//微博列表
	struct usr_record *prev;
	struct usr_record *next;
}sRed, *pRed;

Thread_pool *pool;
pRed phead;

int socket_fun();
void creat_memory(void **p, int size);
void pool_init(int max_line);
void *thread_routine(void *arg);
void *myprocess(void *confd);
int pool_add_task(void *(*process)(void *), void *confd);
int pool_destroy();
int func(int confd, sCts buf, int line);
void init_red(pRed *p);
void init_fans(pFan *p);
void init_friend(pFri *p);
void init_web(pWeb *p);
int reg_fun(int confd, sCts buf);
int insert_red(pRed phead, pRed pnew);
int log_fun(int confd, sCts buf);
int search(int confd, sCts buf);
int view_friend(int confd, sCts buf);
int view_fans(int confd, sCts buf);
int forward(int confd, sCts buf, pWeb pw);
int comment(int confd, sCts buf, pWeb pw);
int delete_web(int confd, sCts buf, pWeb pw);
void i_free(void **p);
int pub_web(int confd, sCts buf);
int insert_web(pWeb phead, pWeb pnew);
int concern(int confd, sCts buf);
int insert_friend(pFri phead, pFri pnew);
int insert_fans(pFan phead, pFan pnew);
int unconcern(int confd, sCts buf);
void delete_friend(pFri pf);
void delete_fans(pFan pf);
void service(int sig);
void ser_fun(pRed p);
int start_sina();
int start_fun(pRed pnew);
void show(pWeb phead_web);

#endif