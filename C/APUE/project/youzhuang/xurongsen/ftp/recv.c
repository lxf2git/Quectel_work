
//#include"../apue.h"
#include "rev_snd.h"
void test(USR_MSG head);
int main()
{
	struct sockaddr_in selfaddr,conaddr;
	char buf[30],send_buf[30];
	int n;
	int ret;
	bzero(buf,sizeof(buf));	
	bzero(send_buf,sizeof(send_buf));	
	socklen_t len = sizeof(struct sockaddr_in);
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);	
	if(sockfd<0)
	{
		show_err("socket");
	}

	bzero(&selfaddr,sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_port = htons(5678);
	selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	ret = bind(sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
	if(ret<0)
	{
		close(sockfd);
		show_err("bind");
	}
	

	USR_MSG usrhead;
	char rcv_ip[20];
	init_head(&usrhead);
	while(1)
	{
			n = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&conaddr,&len);
			sprintf(rcv_ip,"%s",inet_ntoa(conaddr.sin_addr));
			oper_use(&usrhead,rcv_ip,buf);
			memset(rcv_ip,0,sizeof(rcv_ip));
			if(strcmp(buf,"#") == 0)
			{
				break;
			}
			if(0 != n)
			{
					printf("ip:%s connet! data:%s \n",inet_ntoa(conaddr.sin_addr),buf);
					bzero(send_buf,sizeof(send_buf));
					printf("回复：");
					scanf("%s",send_buf);
					n = sendto(sockfd,send_buf,sizeof(send_buf),0,
									(struct sockaddr*)&conaddr,len);
					if(n<0)
					{
							show_err("sendto");
					}
					if(strcmp(send_buf,"#") == 0)
					{
						break;
					}
					bzero(send_buf,sizeof(send_buf));
			}
			memset(buf,0,sizeof(buf));
	}
	return 0;

}

void oper_use(USR_MSG *phead,char rcv_ip[20],char buf[20])
{
	//处理接受到的信息进行处理

	
	//printf("ip:%s\n",rcv_ip);
	//查找
	USR_MSG *puse_node;
	int ret=-2,n;
	ret = find_usr(phead,rcv_ip);
	printf("ret:%d\n",ret);
	if(ret == FAILED )
	{
		create_memory((void **)&puse_node,sizeof(USR_MSG));
		init_node(puse_node);
		strcpy(puse_node->clientip,rcv_ip);
	//	printf("cpy:ip%s\n",puse_node->clientip);
		ret = add_usr(phead,puse_node);
		if(ret<0)
		{
			printf("添加失败！\n");
		}
//	ret = find_usr(phead,rcv_ip);//查询测试，检验是否插入成功
	}
	else
	{
		printf("该用户已存在！\n");
	}
	//	test( *phead);
#if 1
	n = strlen(buf);
	if((*buf == '#') && n==1)
	{
		ret = del_usr(*phead, rcv_ip);
		if(ret == FAILED)
		{
			printf("删除失败！\n");
		}
	}
#endif
}
//头节点初始化
void init_head(USR_MSG *phead)
{
	//初始化头节点
//	USR_MSG usrhead;
	phead->head = 1;
	bzero(phead->usrname,sizeof(phead->usrname));
	bzero(phead->usrpwd,sizeof(phead->usrpwd));
	bzero(phead->clientip,sizeof(phead->clientip));
	phead->next = phead;
	phead->prev = phead;
}
//函数查找，调用添加,删除
int init_node(USR_MSG *pnode)
{
	pnode->head = 0;
//	printf("请输入用户名：");
//	scanf("%s",pnode->usrname);
//	printf("请输入用户密码：");
//	scanf("%s",pnode->usrpwd);
//	printf("请输入用户ip：");
//	scanf("%s",pnode->clientip);

	bzero(pnode->usrname,sizeof(pnode->usrname));
	bzero(pnode->usrpwd,sizeof(pnode->usrpwd));
	bzero(pnode->clientip,sizeof(pnode->clientip));
	pnode->next = pnode;
	pnode->prev = pnode;
	return SUC;
}


int add_usr(USR_MSG *pusrhead, USR_MSG *pusrnode)
{
	//采用尾插的方法插入链表中
	pusrnode->prev = pusrhead->prev;
	pusrnode->next = pusrhead;
	pusrhead->prev->next = pusrnode;
	pusrhead->prev = pusrnode;
//	printf("prev->ip:%s\n",pusrhead->prev->clientip);
//	printf("name:%s\n",pusrhead->prev->usrname);
	printf("添加成功!\n");
	return SUC;
}
#if 0
void test(USR_MSG head)
{
	USR_MSG *p;
	p = head.next;
	int i=1;
	while(p->head != 1)
	{
		printf("i:%d  ip:%s  addr:%p\n",i,p->clientip,p->clientip);
		p = p->next;
		i++;
	}
}
#endif

int find_usr(USR_MSG *pusrhead,char p_ip[20])
{
	USR_MSG *p;
	int ret=-2;
	p= pusrhead->next;
	printf("find-->aa!%s cli:%d\n",p_ip,p->clientip);
	while((p->head) == 0)
	{
		printf("clientip:%s\n",p->clientip);
		ret =strcmp((p->clientip) ,(p_ip));
		printf("ret:%d\n",ret);
		if(ret == 0)
		{
				printf("find_usr-->查询成功!\n");
				printf("该用户已经存在！\n");
			//	printf("usrname:%s\n",p->usrname);
			//	printf("usrpwd:%s\n",p->usrpwd);
			//	printf("clientip:%s\n",p->clientip);
				printf("suc!\n");
				return SUC;
		}
		p = p->next;
	}
	printf("find-->dd!\n");
	return FAILED;
}


int del_usr(USR_MSG usrhead, char *p_ip)
{
	USR_MSG *p,*pre,*pnext,*pfind;
	p = usrhead.next;
	int ret=0;//判断是否找到，1是找到
	while(p->head != 1)
	{
		if(*(p->clientip) == *p_ip)
		{
			ret = 1;
			pfind = p;
			pre = p->prev;
			pnext = p->next;
			break;
		}
		p = p->next;
	}
	if(ret == 1)
	{
		pre->next = pnext;
		pnext->prev = pre;
//		printf("namen:%s\n",p->prev->next->usrname);
//		printf("namer:%s\n",p->next->prev->usrname);
		p->prev = p;
		p->next = p;
		free_memory((void **)&pfind);
		printf("删除成功!\n");
		return SUC;
	}
	return FAILED;
}


void free_memory(void **p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p == NULL)
	{
		perror("malloc");
	}
}
