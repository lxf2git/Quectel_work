#ifndef _APUE_H_
#define _APUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>


/***微博成员结构体信息***/
typedef struct fans 		/*粉丝*/
{
	int fans_id;
	char fans_name[30];
	struct fans *next;
	struct fans *prev;
}sFans,*pFans;

typedef struct attenrion
{
	int attenrion_id;
	char sttenrion_name[30];
	struct attenrion *next;
	struct attenrion *prev;
}sAttenrion,*pAttenrion;

typedef struct comment
{
	char comment_content[1024];
	int content_id;
	int content_name[30];
	struct comment *next;
	struct commment *prev;
}sComment,*pComment;

typedef struct publish
{
	int number;
	char content[1024];
	int praise;
	pComment comment_Head;
	struct publish *next;
	struct publish *prev;
}sPublish,*pPublish;

typedef struct user
{
	int id;
	char password[30];
	char name[30];
	pFans fans_Head;
	pAttenrion attenrion_Head;
	pPublish publish_Head;
	struct user *next;
	struct user *prev;
}sUser,*pUser;


void show_err(char *str)
{
	perror(str);
	exit(-1);
}


#endif

