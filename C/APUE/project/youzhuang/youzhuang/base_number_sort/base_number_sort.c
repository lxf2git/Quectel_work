#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct link
{
		int data;
		struct link *prev;
		struct link *next;
}sLink,*pLink;

typedef struct dis_chain
{
		pLink record;
		struct dis_chain *prev;
		struct dis_chain *next;
}sDis,*pDis;

void create_memory(void **p, int size);
void free_memory(void **p);
void add_node(pLink pHead,pLink pnew);
void print_link(pLink pHead);
void create_link(pLink pHead);
void create_dis(pDis pHead);
void create_link_node(pLink *p);
void create_dis_node(pDis *p);
void add_dis_node(pDis pHead,pDis pnew);
int judge_num(pLink pHead);
void del_node(pLink p);
void del_dis_node(pDis pdel);
void collected(pLink pHead,pDis pHead_dis);
void distribute(pLink pHead,pDis pHead_dis,int n);
int divi(int i);
void sort(pLink pHead,pDis pHead_dis);
void unload_link(pLink *pHead);
void unload_dis(pDis *pHead);

int main()
{
		pLink pHead=NULL;
		pDis pHead_dis=NULL;
		create_dis_node(&pHead_dis);
		create_link_node(&pHead);
		create_dis(pHead_dis);
		create_link(pHead);
		print_link(pHead);
		sort(pHead,pHead_dis);
		print_link(pHead);
		unload_link(&pHead);
		unload_dis(&pHead_dis);
		return 0;
}

void sort(pLink pHead,pDis pHead_dis)
{
		int num,i;
		num=judge_num(pHead);
		for(i=0;i<num;i++)
		{
				distribute(pHead,pHead_dis,divi(i));
				collected(pHead,pHead_dis);
		}
}

int divi(int i)
{
		int sum=1;
		if(i==0)
		{
				return sum;
		}
		else
		{
				sum=divi(--i)*10;
		}
		return sum;
}

void distribute(pLink pHead,pDis pHead_dis,int n)
{
		pLink p=pHead;
		pLink pnew=NULL;
		pDis pdis=pHead_dis->next;
		int i;
		while(p->prev!=pHead)
		{
				pdis=pHead_dis->next;
				for(i=0;i<10;i++)
				{
						if(p->prev->data/n%10==i)
						{
								create_link_node(&pnew);
								pnew->data=p->prev->data;
								add_node(pdis->record,pnew);
								del_node(p->prev);
								break;
						}
						pdis=pdis->next;
				}
		}
}

void collected(pLink pHead,pDis pHead_dis)
{
		pLink ptem=NULL,pnew=NULL;
		pLink p=pHead->next;
		pDis pdis=pHead_dis->next;
		while(pdis!=pHead_dis)
		{
				if(pdis->record!=NULL)
				{
						ptem=pdis->record;
						while(ptem->prev!=pdis->record)
						{
								create_link_node(&pnew);
								pnew->data=ptem->prev->data;
								add_node(pHead,pnew);
								del_node(ptem->prev);
						}
				}
				pdis=pdis->next;
		}
}

void unload_link(pLink *pHead)
{
		pLink p=(*pHead);
		while(p->next!=*pHead)
		{
				del_node(p->next);
		}
		free_memory((void **)pHead);
}

void unload_dis(pDis *pHead)
{
		pDis p=(*pHead);
		while(p->next!=*pHead)
		{
				del_dis_node(p->next);
		}
		free_memory((void **)pHead);
}

void del_dis_node(pDis pdel)
{
		pdel->next->prev=pdel->prev;
		pdel->prev->next=pdel->next;
		pdel->prev=NULL;
		pdel->next=NULL;
		free_memory((void **)&pdel);
}

void del_node(pLink pdel)
{
		pdel->next->prev=pdel->prev;
		pdel->prev->next=pdel->next;
		pdel->prev=NULL;
		pdel->next=NULL;
		free_memory((void **)&pdel);
}

int judge_num(pLink pHead)
{
		pLink p=pHead->next;
		int num=0,judge,i;
		while(p!=pHead)
		{
				i=0;
				judge=p->data;
				while(judge!=0)
				{
						i++;
						judge/=10;
						if(i>num)
						{
								num=i;
						}
				}
				p=p->next;
		}
		return num;
}

void print_link(pLink pHead)
{
		pLink p=pHead->next;
		while(p!=pHead)
		{
				printf("%d ",p->data);
				p=p->next;
		}
		printf("\n");
}

void create_link(pLink pHead)
{
		pLink pnew=NULL;
		int data,i;
		for(i=0;i<N;i++)
		{
				printf("请输入数字:\n");
				scanf("%d",&data);
				create_link_node(&pnew);
				pnew->data=data;
				add_node(pHead,pnew);
		}
}

void create_dis(pDis pHead)
{
		pDis pnew=NULL;
		pLink p;
		int i;
		for(i=0;i<10;i++)
		{
				create_link_node(&p);
				create_dis_node(&pnew);
				pnew->record=p;
				add_dis_node(pHead,pnew);
		}
}

void add_dis_node(pDis pHead,pDis pnew)
{
		pnew->next=pHead;
		pnew->prev=pHead->prev;
		pHead->prev->next=pnew;
		pHead->prev=pnew;
}

void add_node(pLink pHead,pLink pnew)
{
		pnew->next=pHead;
		pnew->prev=pHead->prev;
		pHead->prev->next=pnew;
		pHead->prev=pnew;
}

void create_dis_node(pDis *p)
{
		create_memory((void **)p, sizeof(sDis));
		(*p)->prev = (*p);
		(*p)->next = (*p);
}

void create_link_node(pLink *p)
{
		create_memory((void **)p, sizeof(sLink));
		(*p)->prev = (*p);
		(*p)->next = (*p);
}

void create_memory(void **p, int size)
{
		*p = malloc(size);
		if(*p == NULL)
		{
				printf("create memory error!\n");
				exit(-1);
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
