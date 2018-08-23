#include"init.h"


int del_back_comm(PComment *p)
{
		(*p)->next->prev = (*p)->prev;
		(*p)->prev->next = (*p)->next;
		(*p)->next = NULL;
		(*p)->prev = NULL;
		free_memory((void**)p);
		return SUC;
}


#if 1
//删除以phead为头节点的链表里的所有节点
int del_all_comm(PComment phead)
{
	PComment pdel;
	pdel = phead;
	while(pdel->next != phead)
	{
		del_back_comm(&pdel->next);
	}
	del_back_comm(&phead);
	return SUC;
}
#endif


# if 1
int del_back_blog(PMicroblog *p)
{
		if((*p)->s_comment->next != (*p)->s_comment)
		{
				del_all_comm((*p)->s_comment);
		}
		(*p)->next->prev = (*p)->prev;
		(*p)->prev->next = (*p)->next;
		(*p)->next = NULL;
		(*p)->prev = NULL;
		free_memory((void**)p);
		return SUC;
}
#endif

#if 1
//删除以phead为头节点的链表里的所有节点
int del_all_blog(PMicroblog phead)
{
	PMicroblog pdel;
	pdel = phead;
	while(pdel->next != phead)
	{
		del_back_blog(&pdel->next);
	}
	del_back_blog(&phead);
	return SUC;
}
#endif


int del_back_friend(PFriend *p)
{
		(*p)->next->prev = (*p)->prev;
		(*p)->prev->next = (*p)->next;
		(*p)->next = NULL;
		(*p)->prev = NULL;
		free_memory((void**)p);
		return SUC;
}

int del_all_friend(PFriend phead)
{
	PFriend pdel;
	pdel = phead;
	while(pdel->next != phead)
	{
		del_back_friend(&pdel->next);
	}
	del_back_friend(&phead);
	return SUC;
}

int del_back_info(PUser_info *p)
{
		printf("0.0\n");
		if((*p)->s_friend->next != (*p)->s_friend)
		{
				del_all_friend((*p)->s_friend);
		}
		printf("0.0\n");
		if((*p)->s_fanc->next != (*p)->s_fanc)
		{
				del_all_friend((*p)->s_fanc);
		}
		printf("0.0\n");
		if((*p)->s_microblog->next != (*p)->s_microblog)
		{
				del_all_blog((*p)->s_microblog);
		}
		printf("0.0\n");
		(*p)->next->prev = (*p)->prev;
		(*p)->prev->next = (*p)->next;
		(*p)->next = NULL;
		(*p)->prev = NULL;
		free_memory((void**)p);
		return SUC;
}

int del_all_info(PUser_info phead)
{
		printf("del\n");
	PUser_info pdel;
	pdel = phead;
	while(pdel->next != phead)
	{
		del_back_info(&pdel->next);
	}
	printf("poiu\n");
	del_back_info(&phead);
	return SUC;
}
