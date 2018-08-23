#include"main.h"

int pub_web(int confd, sCts buf)
{
	int suc = -1;
	pRed p = NULL;
	for(p = phead->next; p != phead; p = p->next)
	{
		if(strcmp(buf.usr_nam, p->usr_msg.usr_nam) == 0)
		{
			suc = 0;
			break;
		}
	}
	p->publish_num++;
	pWeb pnew = NULL;
	init_web(&pnew);
	strcpy(pnew->content, buf.exe_fun.web_content);
	insert_web(p->web_list, pnew);
	show(p->web_list);
	write(confd, &suc, sizeof(int));
	return 0;
}

int insert_web(pWeb phead, pWeb pnew)
{
	if(NULL == phead || NULL == pnew)
	{   
		return -1; 
	}
	pnew->next = phead->next;
	pnew->prev = phead;
	phead->next->prev = pnew;	
	phead->next = pnew;	
	return 0;
}

int concern(int confd, sCts buf)
{
	int suc = -1;
	pRed pf = NULL;//好友主页
	pRed ps = NULL;//自己主页
	pFri ptmp = NULL;//自己的朋友列表
	/*判断有没有这个人*/
	for(pf = phead->next; pf != phead; pf = pf->next)
	{
		if(strcmp(buf.exe_fun.concern_usr_name, pf->usr_msg.usr_nam) == 0)
		{
			suc = 0;
			break;
		}
	}
	if(suc == 0)
	{
		suc = -1;
		/*找到自己*/
		for(ps = phead->next; ps != phead; ps = ps->next)
		{
			if(strcmp(buf.usr_nam, ps->usr_msg.usr_nam) == 0)
			{
				suc = 0;
				break;
			}
		}
		if(suc == 0)
		{
			for(ptmp = ps->fri_list->next; ptmp != ps->fri_list; 
							ptmp = ptmp->next)
			{
				if(strcmp(ptmp->usr_nam, buf.exe_fun.concern_usr_name) == 0)
				{
					suc = -1;
					break;
				}
			}
			printf("%d\n", suc);
			if(suc == 0)
			{
				ps->friend_num++;
				pFri pnew2 = NULL;
				init_friend(&pnew2);
				strcpy(pnew2->usr_nam, buf.exe_fun.concern_usr_name);
				insert_friend(ps->fri_list, pnew2);
	
				pf->concern_num++;
				pFan pnew1 = NULL;
				init_fans(&pnew1);
				strcpy(pnew1->usr_nam, buf.usr_nam);
				insert_fans(pf->fans_list, pnew1);
			}
		}
	}
	write(confd, &suc, sizeof(int));
	return 0;
}

int insert_friend(pFri phead, pFri pnew)
{
	if(NULL == phead || NULL == pnew)
	{   
		return -1; 
	}   
	pnew->next = phead;
	pnew->prev = phead->prev;
	phead->prev->next = pnew;
	phead->prev = pnew;
	return 0;
}

int insert_fans(pFan phead, pFan pnew)
{
	if(NULL == phead || NULL == pnew)
	{   
		return -1; 
	}   
	pnew->next = phead;
	pnew->prev = phead->prev;
	phead->prev->next = pnew;
	phead->prev = pnew;
	return 0;
}

int unconcern(int confd, sCts buf)
{
	int suc = -1;
	pRed ps = NULL;
	//printf("%s\n", buf.usr_nam);
	for(ps = phead->next; ps != phead; ps = ps->next)//找到自己
	{
		if(strcmp(buf.usr_nam, ps->usr_msg.usr_nam) == 0)
		{
			break;
		}
	}
//	printf("%s\n", ps->usr_msg.usr_nam);
	pFri pf = NULL;
	for(pf = ps->fri_list->next; pf != ps->fri_list; pf = pf->next)//有没有这个好友
	{
		if(strcmp(pf->usr_nam, buf.exe_fun.not_concern_usr_name)==0)
		{
			suc = 0;
			break;
		}
	}
	if(suc == 0)
	{
	//	printf("取消成功\n");
		suc = -1;
		pRed pf_all = NULL;
		/*找到这个用户*/
		for(pf_all = phead->next; pf_all != phead; pf_all = pf_all->next)
		{
			if(strcmp(buf.exe_fun.not_concern_usr_name, 
					pf_all->usr_msg.usr_nam) == 0)
			{
				break;
			}
		}
		pFan pfan = NULL;
	//	printf("取消成功2\n");
		/*在这个用户粉丝列表中找到自己*/
		for(pfan = pf_all->fans_list->next; pfan != pf_all->fans_list; 
						pfan = pfan->next)
		{
			if(strcmp(buf.usr_nam, pfan->usr_nam) == 0)
			{
				suc = 0;
				break;
			}
		}
		if(suc == 0)
		{
			printf("取消成功3\n");
			ps->friend_num--;
			delete_friend(pf);//删除这个好友
			pf_all->concern_num--;
			delete_fans(pfan);//删除自己
		}
	}
	write(confd, &suc, sizeof(int));
}

void delete_friend(pFri pf)
{
	pf->prev->next = pf->next;
	pf->next->prev = pf->prev;
	pf->prev = NULL;
	pf->next = NULL;
	i_free((void **)&pf);
}

void delete_fans(pFan pf)
{
	pf->prev->next = pf->next;
	pf->next->prev = pf->prev;
	pf->prev = NULL;
	pf->next = NULL;
	i_free((void **)&pf);
}

int last(int confd, sCts buf)
{
	int suc = -1;
	pRed p = NULL;
	for(p = phead->next; p != phead; p = p->next)
	{
		if(strcmp(p->usr_msg.usr_nam, buf.usr_nam) == 0)
		{
			suc = 0;
			break;
		}
	}
	write(confd, &suc, sizeof(suc));
	if(suc == 0)
	{
		write(confd, p, sizeof(sRed));
	}
	return 0;
}

int quit(int confd, sCts buf)
{
	int suc = -1;
	pRed p = NULL;
	for(p = phead->next; p != phead; p = p->next)
	{
		if(strcmp(p->usr_msg.usr_nam, buf.usr_nam) == 0)
		{
			suc = 0;
			break;
		}
	}
	p->online = -1;
	write(confd, &suc, sizeof(suc));
	return suc;
}

void show(pWeb phead_web)
{
	pWeb p = NULL;
	for(p = phead_web->next; p != phead_web; p = p->next)
	{
		printf("%s %d %d\n", p->content, p->praise, p->com_num);
	}
}
