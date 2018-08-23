#ifndef _INIT_H_
#define _INIT_H_

#include "./apue.h"
#include "./microblog.h"
#define SUC 1
#define FAIL 0
#define SIZE 1024

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
int search(void **phead);//friend查询
int search_blog(PMicroblog *phead);
int search_comm(PComment *phead);
int search_use(PUser_info *phead);
//初始化链表init_chain.c
void create_memory(void **p,int size);
void free_memory(void **p);
void init_user_info(PUser_info *pnode_usrinfo);
void init_friend(PFriend *p_friend);
void init_user_basic_info(PUser_basic_info p_bsk_info);
void init_microblog(PMicroblog *p_blog);
void init_comment(PComment *p_comm);
//添加链表add_chain.c
void (*pnode)(void **p);
int (*add_chain_end)(void **phead,void **pnode);

int add(int arg,void **phead, void **pnode,int(*add_chain_end)(void **phead,void **pnode));
int add_back_info(PUser_info *phead,PUser_info *pnode);
int add_back_friend(PFriend *phead,PFriend *pnode);
int add_back_bsk_info(void **phead,void **pnode);
int add_back_blog(PMicroblog *phead,PMicroblog *pnode);
int add_back_comm(PComment *phead,PComment *pnode);

//删除链表del_chain.c
int del_back_comm(PComment *pnode);
int del_all_comm(PComment *phead);
int del_back_blog(PMicroblog *pnode);
int del_back_friend(PFriend *pnode);
int del_all_friend(PFriend *phead);
int del_back_info(PUser_info *pnode);

int change(PUser_info *puse);


#endif
