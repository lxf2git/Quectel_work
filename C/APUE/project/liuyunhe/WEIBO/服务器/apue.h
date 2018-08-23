#ifndef APUE_H
#define APUE_H

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
#include<pthread.h>
#include<assert.h>

static show_err(char *str)
{
		perror(str);
		exit(-1);
}
struct message					/*传的函数*/
{ 
		int sockfd;/*套接字*/
		char userid[30];/*用户id*/
		char destid[30];/*目的id*/
};

typedef struct fans				/*粉丝*/
{
		char fans_id[30];			/*粉丝id*/
		char fans_name[30];		/*粉丝名称*/
		struct fans *next;
		struct fans *prev;
}sFans,*pFans;

typedef struct attenrion				/*关注*/
{
		char attenrion_id[30];				/*关注的人id*/
		char attenrion_name[30];		/*关注人的名字*/
		struct attenrion *next;			
		struct attenrion *prev;
}sAttenrion,*pAttenrion;
typedef struct comment					/*评论*/
{
		char comment_content[1024];		/*评论内容*/
		char content_id[30];					/*评论人的id*/
		char content_name[30];			/*评论人名字*/
		struct comment *next;
		struct comment *prev;	
}sComment,*pComment;

typedef struct publish					/*发博信息*/
{
		int number;						/*围博编号*/
		char content[1024];				/*围博内容*/
		int praise;						/*点赞个数*/
		pComment comment_Head;		/*评论内容*/
		struct publish *next;
		struct publish *prev;
}sPublish,*pPublish;

typedef struct user					/*用户信息*/
{
		char id[30];						/*用户id*/	
		char password[30];			/*用户密码*/
		char name[30];				/*用户名字*/
		pFans fans_Head;			/*粉丝头*/
		pAttenrion attenrion_Head;	/*关注头*/
		pPublish publish_Head;		/*围博头*/
		struct user *next;
		struct user *prev;
}sUser,*pUser;
// pUser pHead=NULL;
#endif
