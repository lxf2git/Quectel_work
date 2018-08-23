#include"init.h"

//删除评论链表里的以phead为头节点，删除pnode节点
#if 0
int del_back_comm(PComment *phead,PComment *pnode)
{
	PComment p,pdel;
	p = (*phead)->next;
	while((p) != (*phead))
	{
		if(((p)->s_user_name==(*pnode)->s_user_name)
						&&(p->s_text==(*pnode)->s_text))
		{
			pdel = p;
			break;
		}
		p = (p)->next;
	}	

	if((pdel)->s_text != NULL)
	{
		(pdel)->prev->next = (pdel)->next;
		(pdel)->next->prev = (pdel)->prev;
		(pdel)->next = (pdel);
		(pdel)->prev = (pdel);
		printf("del-----com\n");
		free_memory((void **)&pdel);
	}
	printf("free=====\n");
	return SUC;
}
#endif
//删除微博里的一个节点
#if 0
int del_back_blog(PMicroblog *phead,PMicroblog *pnode)
{
	PMicroblog p;
	p = (*phead)->next;
	while((p->s_text != NULL)&&(p->s_praise != 0))
	{
		if((p->s_text==(*pnode)->s_text)
						&&(p->s_comment==(*pnode)->s_comment))
		{
			break;
		}
		p = p->next;
	}	

	p->prev->next = p->next;
	p->next->prev = p->prev;
	p->next = p;
	p->prev = p;
	
	printf("del one comm\n");

	//删除评论链表
	del_all_comm(&(p->s_comment));
	free_memory((void **)&p);
	return SUC;
}
#endif
#if 0
int del_back_friend(PFriend *phead,PFriend *pnode)
{
	PFriend p;
	p = (*phead)->next;
	while(p->s_id != 0)
	{
		if(p->s_id==(*pnode)->s_id)
		{
			break;
		}
		p = p->next;
	}	

	p->prev->next = p->next;
	p->next->prev = p->prev;
	p->next = p;
	p->prev = p;
	free_memory((void **)&p);
	return SUC;
}
#endif
int del_back_comm(PComment *pnode)
{
	PComment pdel = (*pnode);
	printf("del_com-->aaa\n");
	printf("p:%p\n",(*pnode));
	(*pnode)->prev->next = (*pnode)->next;
	(*pnode)->next->prev = (*pnode)->prev;
	(*pnode)->prev = (*pnode);
	(*pnode)->next = (*pnode);
	free_memory((void **)&((*pnode)->s_text));
	printf("p:%p\n",(*pnode));
	free_memory((void **)&pdel);
	return SUC;
}


#if 1
//删除以phead为头节点的链表里的所有节点
int del_all_comm(PComment *phead)
{
	PComment p,pdel;
	p = (*phead)->next;
	while(p != (*phead))
	{
		pdel = p;
		p = p->next;
		del_back_comm(&pdel);
	}
	printf("com   删除完成！\n");
	return SUC;
}
#endif


# if 1
int del_back_blog(PMicroblog *pnode)
{
	PMicroblog pdel;
	pdel = (*pnode);
	printf("del_blog--->\n");
	printf("p:%p\n",(*pnode));	
	(*pnode)->prev->next = (*pnode)->next;
	(*pnode)->next->prev = (*pnode)->prev;
	(*pnode) = (*pnode)->next;
	pdel->prev = NULL;
	pdel->next = NULL;
	del_all_comm(&(pdel->s_comment));
	printf("p:%p\n",(*pnode));
	free_memory((void **)&pdel);
	return SUC;
}
#endif

#if 1
//删除以phead为头节点的链表里的所有节点
int del_all_blog(PMicroblog *phead)
{
	PMicroblog p,pdel;
	p = (*phead)->next;
	while(p != (*phead))
	{
		pdel = p;
		p = p->next;
		del_back_blog(&pdel);
	}
	return SUC;
}
#endif


int del_back_friend(PFriend *pnode)
{
	PFriend pdel;
	pdel = (*pnode);
	(*pnode) = (*pnode)->next;	
	pdel->prev->next = pdel->next;
	pdel->next->prev = pdel->prev;
	
	
	(pdel)->prev = NULL;
	(pdel)->next = NULL;
/*
	printf("pnode3:%d\n",(*pnode)->next->s_id);
	printf("p:%d\n",(pnode));

	printf("del_fri-->pfans,%d\n",(*pnode)->prev->s_id);
//intf("del_fri-->pfans,%d\n",(*pnode)->next->s_id);
*/
	free_memory((void **)&pdel);
	return SUC;
}

int del_all_friend(PFriend *phead)
{
	PFriend pn1,pn2;
	pn1 = (*phead)->next;
	while(pn1->s_id != 0)
	{
		pn2 = pn1;
		pn1 = pn1->next;
		del_back_friend(&pn2);
		//free_memory((void**)&pn2);
	}
	free_memory((void **)&pn1);
	return SUC;
}

int del_back_info(PUser_info *pnode)
{
	PUser_info p;
	p = (phead_use_info)->next;
	while(p->s_user_basic_info.s_id != 0)
	{
		if((p->s_user_basic_info.s_id)==(*pnode)->s_user_basic_info.s_id)
		{
			break;
		}
		p = p->next;
	}	

	p->prev->next = p->next;
	p->next->prev = p->prev;
	p->next = p;
	p->prev = p;
	//删除微博链表
	PMicroblog p_blog,pb_del;
	p_blog = p->s_microblog->next;
	while((p_blog->s_text != NULL)&&(p_blog->s_comment!=NULL))
	{
		p_blog = pb_del;
		p_blog = p_blog->next;
		del_back_blog(&pb_del);
	}
	free_memory((void **)&p_blog);

	//删除好友链表
	PFriend pf,pf_del;
	pf = p->s_friend->next;
	while(pf->s_id != 0)
	{
		pf_del = pf;
		pf = pf->next;
   	    del_back_friend(&pf_del);
	}
	free_memory((void **)&pf);
	//删除粉丝链表
	PFriend pf_fans,pfans_del;
	pf_fans = p->s_fanc->next;
	while(pf_fans->s_id != 0)
	{
		pfans_del = pf_fans;
		pf_fans = pf_fans->next;
        del_back_friend(&pfans_del);
	}
	free_memory((void **)&pf_fans);

	free_memory((void **)&p);
	return SUC;
}
