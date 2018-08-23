#include"main.h"

int search(int confd, sCts buf)
{
	int suc = -1;
	pRed p = NULL;
	printf("search\n");
	for(p = phead->next; p != phead; p = p->next)
	{
		if(strcmp(buf.exe_fun.search_usr_name, p->usr_msg.usr_nam) == 0)
		{
			printf("搜索成功\n");
			suc = 0;
			write(confd, &suc, sizeof(int));
			write(confd, p, sizeof(sRed));
			return 0;
		}
	}
	suc = -1;
	write(confd, &suc, sizeof(int));
	return -1;
}

int view_friend(int confd, sCts buf)
{
	int suc = -1;
	pRed p = NULL;
	for(p = phead->next; p != phead; p = p->next)
	{
		if(strcmp(buf.exe_fun.search_usr_name, p->usr_msg.usr_nam) == 0)
		{
			suc = p->friend_num;
			break;
		}
	}
	write(confd, &suc, sizeof(int));
	if(suc == -1)
	{
		return suc;
	}
	pFri pf = NULL;
	for(pf = p->fri_list->next; pf != p->fri_list; pf = pf->next)
	{
		write(confd, pf, sizeof(sFri));
	}
	return suc;
}

int view_fans(int confd, sCts buf)
{
	int suc = -1;
	pRed p = NULL;
	for(p = phead->next; p != phead; p = p->next)
	{
		if(strcmp(buf.exe_fun.search_usr_name, p->usr_msg.usr_nam) == 0)
		{
			suc = p->concern_num;
			break;
		}
	}
	write(confd, &suc, sizeof(int));
	if(suc == -1)
	{
		return suc;
	}
	pFan pf = NULL;
	for(pf = p->fans_list->next; pf != p->fans_list; pf = pf->next)
	{
		write(confd, pf, sizeof(sFan));
	}
	return suc;
}

int view_web(int confd, sCts buf)
{
	int suc = -1;
	pRed p = NULL;
	for(p = phead->next; p != phead; p = p->next)
	{
		if(strcmp(buf.exe_fun.search_usr_name, p->usr_msg.usr_nam) == 0)
		{
			suc = 0;
			break;
		}
	}
	write(confd, &suc, sizeof(int));
	if(-1 == suc)
	{
		return suc;
	}
	int self;
	if(strcmp(buf.usr_nam, buf.exe_fun.search_usr_name) == 0)
	{
		self = 0;
	}
	pWeb pw = NULL;
	pw = p->web_list->next;
	printf("%s:%s\n获得%d个赞\n", buf.usr_nam, pw->content, pw->praise);
	int i;
	for(i = 0; i < pw->com_num; i++)
	{   
		printf("%s:%s\n", pw->com[i].com_nam, pw->com[i].com);
	}   

	write(confd, pw, sizeof(sWeb));
	sCts buf_web;
	int err;
	while(1)
	{
		bzero(&buf_web, sizeof(buf_web));
		read(confd, &buf_web, sizeof(buf_web));
		printf("%d\n", buf_web.type);
		switch(buf_web.type)
		{
			case PAGEDOWN:
				if(pw ->prev != p->web_list)
				{
					suc = 0;
					write(confd, &suc, sizeof(int));
					pw = pw->prev;
					write(confd, pw, sizeof(sWeb));
				}
				else
				{
					suc = -1;
					write(confd, &suc, sizeof(int));
				}
				break;
			case PAGEUP:
				if(pw ->next != p->web_list)
				{
					suc = 0;
					write(confd, &suc, sizeof(int));
					pw = pw->next;
					write(confd, pw, sizeof(sWeb));
				}
				else
				{
					suc = -1;
					write(confd, &suc, sizeof(int));
				}
				break;
			case PRAISE:
				if(self != 0)
				{
					pw->praise++;
					write(confd, pw, sizeof(sWeb));
				}
				break;
			case FORWARDING:
				if(self != 0)
				{
					forward(confd, buf_web, pw);
				}
				break;
			case COMMENT:
				if(self != 0)
				{
					comment(confd, buf_web, pw);
				}
				break;
			case DELETE:
				if(self == 0)
				{
					err = delete_web(confd, buf_web, pw);
					if(err >= 1)
					{
						pw = p->web_list->next;
						write(confd, pw, sizeof(sWeb));
						printf("%s:%s\n获得%d个赞\n", 
						buf.usr_nam, pw->content, pw->praise);
					}
				}
				break;
			case QUIT_V:
			//	search(confd, buf);
				printf("返回成功\n");
				return 0;
			default:
				err = 10;
				write(confd, &err, sizeof(int));
				break;
		}
	}
}
