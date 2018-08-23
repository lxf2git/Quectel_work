#include"aa.h"

#if 1
int main()
{
	USR_MSG usrhead,usrnode;
	usrhead.head = 1;
	bzero(usrhead.usrname,sizeof(usrhead.usrname));
	bzero(usrhead.usrpwd,sizeof(usrhead.usrpwd));
	bzero(usrhead.clientip,sizeof(usrhead.clientip));
	usrhead.next = &usrhead;
	usrhead.prev = &usrhead;

//	daemon(0,0);
	init_node(&usrnode);

	int op = 0;

	int ret = change_op(&usrhead,op,&usrnode);
	if(ret<0)
	{
		printf("操作失败！\n");
	}
}

int init_node(USR_MSG *pnode)
{
	pnode->head = 0;
	printf("请输入用户名：");
	scanf("%s",pnode->usrname);
	printf("请输入用户密码：");
	scanf("%s",pnode->usrpwd);
	printf("请输入用户ip：");
	scanf("%s",pnode->clientip);
	pnode->next = pnode;
	pnode->prev = pnode;
	return SUC;
}
#endif
///上面是测试的程序
///--------------------------------------------------------
int change_op(USR_MSG *pusrhead,int op,USR_MSG *pusrnode)
{
	int ret;
	int login_suc = 0;//标记是否成功登录过一次

	daemon(0,0);
	while(1)
	{
			switch(op)
			{
					case 0:
							if(0 == op)
							{
									printf("请输入操作类型：1,查询 2,添加 3,删除:");
									scanf("%d",&op);
							}
							break;
					case 1:
							ret = find_usr(*pusrhead,pusrnode);
							if(ret == FAILED)
							{
									printf("查找失败！链表中不存在该成员\n");
									op = 2;
								//	login_suc = 1;
							}
							else
							{
								printf("该用户已经登录...\n");
								login_suc = 1;
							}
							break;
					case 2:
							ret = add_usr(pusrhead,pusrnode);
							if(ret == FAILED)
							{
									printf("添加失败！\n");
									return FAILED;
							}
							//op = 0;//添加后可以继续查询
							login_suc = 1;
							break;
					case 3:
							signal(SIGCHLD,func);
							ret = del_usr(*pusrhead,pusrnode);
							if(ret == FAILED)
							{
									printf("删除失败!\n");
									return FAILED;
							}
						//	op = 0;
							login_suc = 1;
							break;
					default:
							printf("操作失误！\n");
							op = 0;
							break;
			}
			if(1 == login_suc)
			{
				break;
			}
	}
	return SUC;
}

void func(int sig)
{
	sleep(1);
	switch(sig)
	{
		case SIGCHLD:
				printf("收尸\n");
				waitpid(0,NULL,WNOHANG);
				break;
	}
}

void free_memory(void **p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

int del_usr(USR_MSG usrhead, USR_MSG *pusrnode)
{
	USR_MSG *p,*pre,*pnext;
	int ret = find_usr(usrhead,pusrnode);
	if(ret == SUC)
	{
		p = pusrnode;
		pre = p->prev;
		pnext = p->next;
		pre->next = pnext;
		pnext->prev = pre;
//		printf("namen:%s\n",p->prev->next->usrname);
//		printf("namer:%s\n",p->next->prev->usrname);
		p->prev = p;
		p->next = p;
		free_memory((void **)pusrnode);
		printf("删除成功!\n");
		return SUC;
	}
	return FAILED;
}

int add_usr(USR_MSG *pusrhead, USR_MSG *pusrnode)
{
	//采用尾插的方法插入链表中
	pusrnode->prev = pusrhead->prev;
	pusrnode->next = pusrhead;
	pusrhead->prev->next = pusrnode;
	pusrhead->prev = pusrnode;
//	printf("name:%s\n",pusrhead->next->usrname);
//	printf("name:%s\n",pusrhead->prev->usrname);
	printf("添加成功!\n");
	return SUC;
}

int find_usr(USR_MSG usrhead,USR_MSG *pusrnode)
{
	USR_MSG *p;
	p= usrhead.next;
	while((p) != &usrhead)
	{
		if((*p).clientip == (*pusrnode).clientip)
			if((*p).usrname == (*pusrnode).usrname)
				if((*p).usrpwd == (*pusrnode).usrpwd)
				{
					pusrnode = p;
					printf("find_usr-->查询成功!\n");
					printf("usrname:%s\n",p->usrname);
					printf("usrpwd:%s\n",p->usrpwd);
					printf("clientip:%s\n",p->clientip);
					return SUC;
				}
		p++;
	}
	return FAILED;
}
