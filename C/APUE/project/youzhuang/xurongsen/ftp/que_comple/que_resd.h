
#ifndef QUE_RESD_H
#define QUE_RESD_H
#include"apue.h"
#define SUC 0
#define FAILED -1
//存储登录信息的结构体
typedef struct usr_message
{
	int head;//确定是否是头节点 1是  0不是 
	char usrname[50];
	int usrpwd[20];
	char clientip[20];
	struct usr_message *next;
	struct usr_message *prev;
}USR_MSG;

//消息队列用于存储命令
typedef struct txt
{
	long type;
	char text[50];
}Txt;


//recv.c
void init_head(USR_MSG *phead);
int init_node(USR_MSG *pnode);
void free_memory(void **p);
void create_memory(void **p,int size);
int del_usr(USR_MSG usrhead,char *p_ip);
int add_usr(USR_MSG *pusrhead,USR_MSG *pusrnode);
int find_usr(USR_MSG *pusrhead,char *p_ip);

void oper_use(USR_MSG *phead,char rcv_ip[20],char buf[20]);

//send.c
int send_information( void *pdata,int sockfd);
int receive_information(void *pdata,int sockfd);

#endif
