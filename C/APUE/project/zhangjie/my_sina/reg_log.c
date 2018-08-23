#include"main.h"

int reg_fun(int confd, sCts buf)
{
	int suc = 0;
	pRed p = NULL;
	for(p = phead->next; p != phead; p = p->next)//判断重复注册
	{
		if((strcmp(p->usr_msg.usr_id, 
			buf.exe_fun.usr_self_info.usr_id) == 0) || 
			(strcmp(p->usr_msg.usr_nam, 
			buf.exe_fun.usr_self_info.usr_nam) == 0))
		{
			suc = -1;
			break;
		}
	}
	if(suc == 0)
	{
		pRed pnew = NULL;
		init_red(&pnew);
		pnew->usr_msg = buf.exe_fun.usr_self_info;
		suc = insert_red(phead, pnew);//判断是否插入成功
	}
	write(confd, &suc, sizeof(int));
	return suc;
}

int insert_red(pRed phead, pRed pnew)
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

int log_fun(int confd, sCts buf)
{
	pRed p = NULL;
	int suc = -1;
	for(p = phead->next; p != phead; p = p->next)
	{
		if(strcmp(p->usr_msg.usr_id, 
			buf.exe_fun.usr_self_info.usr_id)==0)
		{
			printf("帐号判定\n");
			if(strcmp(p->usr_msg.usr_passwd, 
			buf.exe_fun.usr_self_info.usr_passwd)==0)
			{
				printf("密码判定\n");
				if(p->online == -1)//判断重复登录
				{
					puts("登录成功");
					p->online = 0;
					suc = 0;
				}
			}
			break;
		}
	}
	printf("%d\n", suc);
	write(confd, &suc, sizeof(int));
	if(suc == 0)
	{
		write(confd, p, sizeof(sRed));
	}
	return suc;
}
