#include<stdio.h>
#include<stdlib.h>

typedef struct Data
{
	int data;
	struct Data *prev;
	struct Data *next;
}sDa,*pDa;

void init_node(pDa *p,int size);
void creat_memory(void **p,int size);
void creat_chain(pDa phead,int x);
int insert_(pDa p1,pDa p2);
void change(pDa pheadA,pDa pheadB);
void show(pDa phead);
void delete_(pDa phead,int x);
void destory(pDa *phead);
void del(pDa p);

int main()
{
	pDa pHeadA=NULL;
	pDa pHeadB=NULL;
	int x,y;
	init_node(&pHeadA,sizeof(pHeadA));
	init_node(&pHeadB,sizeof(sDa));
	printf("please input A and B' lenge\n");
	scanf("%d%d",&x,&y);
	creat_chain(pHeadA,x);
	creat_chain(pHeadB,y);
	change(pHeadA,pHeadB);
	show(pHeadA);
	show(pHeadB);
	destory(&pHeadA);
	destory(&pHeadB);
	return 0;
}

void init_node(pDa *p,int size)
{
	creat_memory((void **)p,size);
	(*p)->prev=*p;
	(*p)->next=*p;
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void creat_chain(pDa phead,int x)
{
	int i;
	pDa pnew=NULL;
	printf("please input %d data\n",x);
	for(i=0;i<x;i++)
	{
		init_node(&pnew,sizeof(sDa));
		scanf("%d",&pnew->data);
		insert_(phead,pnew);
	}
}

int insert_(pDa p1,pDa p2)
{
	if(p1==NULL||p2==NULL)
	{
		return -1;
	}
	p2->next=p1->next;
	p2->prev=p1;
	p1->next=p2;
	p2->next->prev=p2;
	return 0;
}

void change(pDa pheadA,pDa pheadB)
{
	pDa p1=NULL,p2=NULL;
	int t;
	for(p1=pheadA->next;p1!=pheadA;p1=p1->next)
	{
		for(p2=pheadB->next;p2!=pheadB;p2=p2->next)
		{
			if(p1->data==p2->data)
			{
				t=p1->data;
				delete_(pheadA,t);
				delete_(pheadB,t);
				p1=pheadA->next;
				break;
			}
		}
	}
}

void delete_(pDa phead,int x)
{
	pDa p=phead;
	for(p=phead->next;p!=phead;p=p->next)
	{
		if(p->data==x)
		{
			p=p->prev;
			del(p);
		}
	}
}

void show(pDa phead)
{
	pDa p=NULL;
	for(p=phead->next;p!=phead;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}
i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void destory(pDa *phead)
{
	while((*phead)->next!=*phead)
	{
		del(*phead);
	}
	i_free((void **)phead);
}

void del(pDa p)
{
	pDa ptmp=NULL;
	ptmp=p->next;
	p->next=ptmp->next;
	ptmp->next->prev=p;
	ptmp->next=ptmp;
	ptmp->prev=ptmp;
	i_free((void **)&ptmp);
}
