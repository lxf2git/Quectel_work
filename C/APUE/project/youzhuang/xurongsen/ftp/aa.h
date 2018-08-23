#ifndef AA_H
#define AA_H
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

int send_information( void *pdata,int sockfd);
int receive_information(void *pdata,int sockfd);
int getsocket(struct sockaddr_in selfaddr,int *sockfd);

//usr_msg.c  
int init_node(USR_MSG *pnode);
int change_op(USR_MSG *pusrhead,int op,USR_MSG *pusrnode);
void free_memory(void **p);
int del_usr(USR_MSG usrhead,USR_MSG *pusrnode);
int add_usr(USR_MSG *pusrhead,USR_MSG *pusrnode);
int find_usr(USR_MSG usrhead,USR_MSG *pusrnode);
void func(int sig);


#endif
