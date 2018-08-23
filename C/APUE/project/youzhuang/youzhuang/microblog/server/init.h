#ifndef _INIT_H_
#define _INIT_H_

#include "../apue.h"
#include "../microblog.h"
#define SIZE 512

enum Add_Chain
{
	USER_INFO=5,
	FRIEND,
	FRI_FANS,
	USER_BSK_INFO,
	BLOG,
	COMM
};

PUser_info phead_use_info;
//test
int search(void **phead);

void create_memory(void **p,int size);
void free_memory(void **p);
void init_user_info(PUser_info *pnode_usrinfo);
void init_friend(PFriend *p_friend);
void init_user_basic_info(PUser_basic_info *p_bsk_info);
void init_microblog(PMicroblog *p_blog);
void init_comment(PComment *p_comm);

int add_back_info(PUser_info phead, PUser_info pnode);
int add_back_friend(PFriend phead,PFriend pnode);
int add_back_blog(PMicroblog phead,PMicroblog pnode);
int add_back_comm(PComment phead,PComment pnode);

int del_friend_node(PFriend *p);

#endif
