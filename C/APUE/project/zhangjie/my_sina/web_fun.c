#include"main.h"

int forward(int confd, sCts buf, pWeb pw)
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
	write(confd, &suc, sizeof(int));
	if(suc == 0)
	{
		p->publish_num++;
		pWeb pnew = NULL;
		init_web(&pnew);
		strcpy(pnew->content, pw->content);
		insert_web(p->web_list, pnew);
		write(confd, pw, sizeof(sWeb));
	}
	return suc;
}

int comment(int confd, sCts buf, pWeb pw)
{
	int suc = 0;
	pw->com_num++;
	strcpy(pw->com[pw->com_num-1].com_nam, buf.usr_nam);
	strcpy(pw->com[pw->com_num-1].com, buf.exe_fun.comment_content);
	write(confd, &suc, sizeof(int));
	write(confd, pw, sizeof(sWeb));
	return 0;
}

int delete_web(int confd, sCts buf, pWeb pw)
{
	pRed p = NULL;
	int num = 0;
	for(p = phead->next; p != phead; p = p->next)
	{
		if(strcmp(p->usr_msg.usr_nam, buf.exe_fun.search_usr_name) == 0)
		{
			num = p->publish_num;
			break;
		}
	}
	write(confd, &num, sizeof(int));
	printf("微博数%d\n", num);
	if(num >= 1)
	{
		p->publish_num--;
		pw->prev->next = pw->next;
		pw->next->prev = pw->prev;
		pw->prev = NULL;
		pw->next = NULL;
		i_free((void**)&pw);
	}
	return p->publish_num;
}

void i_free(void **p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
