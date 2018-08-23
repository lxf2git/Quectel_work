#include "../include/apue.h"

void destroy_node(pchain p)
{
		if(p->data!=NULL)
		{
				free(p->data);
				p->data=NULL;
		}
		if(p!=NULL)
		{
				free(p);
				p = NULL;
				printf("结点删除成功!\n");
		}
}
void create_memory(pchain *pnew)
{
	*pnew=(pchain)malloc(sizeof(chain));
	if(NULL==*pnew)
	{
			printf("malloc error!\n");
			exit(-1);
	}
}
void init_chain(pchain *p)
{
	create_memory(p);
	(*p)->next = *p;
	(*p)->conaddr.sin_family = AF_INET;
	(*p)->conaddr.sin_addr.s_addr=0;
	(*p)->conaddr.sin_port=htons(PORT);
	(*p)->data=NULL;
	(*p)->if_log='0';
}
void Destory_list(pchain pHead)
{
		pchain pdel=NULL;
		while(pHead->next!=NULL)
		{
				pdel=pHead->next;
				pHead->next=pdel->next;
				pdel->next=NULL;
				destroy_node(pdel);
		}
}
void add_to_chain(pchain p)
{
		p->next = phead->next;
		phead->next = p;

}
void remove_node(pchain p)
{
	pchain ptmp = phead;
	pchain pdel = NULL;
	while(ptmp->next!=phead)
	{
		if(ptmp->next==p)
		{
				pdel = ptmp->next;
				ptmp->next = ptmp->next->next;
				destroy_node(pdel);
				break;
		}
		ptmp = ptmp->next;
	}
}
void show_chain()
{
	pchain ptmp = NULL;
	for(ptmp=phead->next;ptmp!=phead;ptmp=ptmp->next)
	{
			printf("ip:%s已连接\n",inet_ntoa(ptmp->conaddr.sin_addr));
			if(ptmp->if_log=='0')
			{
				printf(" 未登录任何qq\n");
			}
			else
			{
				printf(" 已登录qq:%d 昵称:%s\n",ptmp->data->id,ptmp->data->virtual_name);
			}
	}
	if(phead->next==phead)
			printf("没有人在线\n");
}
