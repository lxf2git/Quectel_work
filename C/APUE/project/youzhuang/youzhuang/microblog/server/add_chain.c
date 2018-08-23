#include "init.h"

//采用尾插的方法进行插入
// user_info 5 friend 6 fac 7 basic 8 blog 9 comm 10
//使用尾插user_info
int add_back_info(PUser_info phead,PUser_info pnode)
{
		printf("add_back_info\n");
	pnode->prev = phead->prev;
	pnode->next = phead;
	phead->prev->next = pnode;
	phead->prev = pnode;
	return SUC;
}
//使用尾插friend
int add_back_friend(PFriend phead,PFriend pnode)
{
		printf("add_back_friend\n");
	pnode->prev = phead->prev;
	pnode->next = phead;
	phead->prev->next = pnode;
	phead->prev = pnode;
	return SUC;
}


//使用尾插microblog
int add_back_blog(PMicroblog phead,PMicroblog pnode)
{
		printf("add_back_blog\n");
	pnode->prev = phead->prev;
	pnode->next = phead;
	phead->prev->next = pnode;
	phead->prev = pnode;
	return SUC;
}
//使用尾插comment
int add_back_comm(PComment phead,PComment pnode)
{
		printf("add_back_comm\n");
	pnode->prev = phead->prev;
	pnode->next = phead;
	phead->prev->next = pnode;
	phead->prev = pnode;
	return SUC;
}
