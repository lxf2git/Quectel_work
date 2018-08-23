#include "init.h"

//采用尾插的方法进行插入
int add(int arg,void **phead,void **pnode,
			   	int (*add_chain_end)(void **phead,void **pnode))
{
	int ret;
	if(USER_INFO == arg)
	{
	PUser_info phead_info = (PUser_info)(*phead);
		add_chain_end = add_back_info;
		(*add_chain_end)(phead,pnode);
		phead_info->friend_num = 22;
		return SUC;
	}
	if(FRIEND == arg)
	{
		add_chain_end = add_back_friend;
		(*add_chain_end)(phead,pnode);	
	}
	if(FRI_FANS == arg)
	{
		add_chain_end = add_back_friend;
		(*add_chain_end)(phead,pnode);	
	}
	if(BLOG == arg)
	{
		add_chain_end = add_back_blog;
		ret = (*add_chain_end)(phead,pnode);
		if(ret == FAILED)
		{
			printf("add_back_blog 添加失败\n");
		}	
	//	printf("add-->out blog\n");
	}
	if(COMM == arg)
	{
		printf("add-->inter COMM\n");
		add_chain_end = add_back_comm;
		ret = (*add_chain_end)(phead,pnode);
		if(ret == FAILED)
		{
			printf("add_back_comm 添加失败\n");
		}	
		printf("comm out!\n");
	}
}

//使用尾插user_info
int add_back_info(void **phead,void **pnode)
{
	PUser_info phead_info = (PUser_info)(*phead);
	PUser_info pnode_info = (PUser_info)(*pnode);
	(pnode_info)->next = (phead_info);
	(pnode_info)->prev = (phead_info)->prev;
	(phead_info)->prev->next = (pnode_info);
	(phead_info)->prev = (pnode_info);
}
//使用尾插friend
int add_back_friend(void **phead,void **pnode)
{
	PFriend phead_fri = (PFriend)(*phead);
	PFriend pnode_fri = (PFriend)(*pnode);
	(pnode_fri)->next = (phead_fri);
	(pnode_fri)->prev = (phead_fri)->prev;
	(phead_fri)->prev->next = (pnode_fri);
	(phead_fri)->prev = (pnode_fri);
	printf("out add_back_friend!\n");
}


//使用尾插microblog
int add_back_blog(void **phead,void **pnode)
{
	PMicroblog phead_info = (PMicroblog)(*phead);
	PMicroblog pnode_info = (PMicroblog)(*pnode);
	(pnode_info)->next = (phead_info);
	(pnode_info)->prev = (phead_info)->prev;
	(phead_info)->prev->next = (pnode_info);
	(phead_info)->prev = (pnode_info);
	printf("add_back_blog-->%d\n",phead_info->next->s_praise);
	return SUC;
}
//使用尾插comment
int add_back_comm(void **phead,void **pnode)
{
	PComment phead_info = (PComment)(*phead);
	PComment pnode_info = (PComment)(*pnode);
	printf("com--->%s\n",pnode_info->s_user_name);
	(pnode_info)->next = (phead_info);
	(pnode_info)->prev = (phead_info)->prev;
	(phead_info)->prev->next = (pnode_info);
	(phead_info)->prev = (pnode_info);
	return SUC;
}
