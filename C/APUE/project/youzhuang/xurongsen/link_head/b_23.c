
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct St
{
	int id;
	char name[20];
	struct St *prev;
	struct St *next;
}sStu,*pStu;

void init_node(pStu *ppnode);
void create_memory(void **pp,int size);
void create_head_chain(pStu phead,int num);
void show_chain(pStu phead);
void init_node(pStu *ppnode)
{
	int len=sizeof(sStu);
	create_memory((void **)ppnode,len);
	(*ppnode)->next = *ppnode;
	(*ppnode)->prev = *ppnode;
}

void create_memory(void **pp,int size)
{
	*pp = malloc(size);
	if(NULL == *pp)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}

void input_node(pStu phead,pStu *pnew)
{
	pStu p;
	printf("please input message(id,name):");
	scanf("%d%s",&((*pnew)->id),(*pnew)->name);
	for(p=phead->next;p != phead;p=p->next)
	{
		if(p->id == (*pnew)->id)
		{
			printf("输入的id有重复，请重输：");
			input_node(phead,pnew);
			break;
		}
	}
}

pStu find_max(pStu phead, pStu pnew, int num)
{
	pStu p=phead->next;
	int i=0;
	for(;i<num;i++)
	{
		if(p->id >= pnew->id)
		{
			return p->prev;
		}
		p=p->next;
		if(p == phead)
		{
			return phead->prev;
		}
	}
//	return p;
}

void insert_back(pStu pos,pStu pnew)
{
	pos->next->prev = pnew;
	pnew->prev = pos;
	pnew->next = pos->next;
	pos->next = pnew;
}

void create_head_chain(pStu phead,int num)
{
	int i;
	pStu pnew=NULL,pmax=NULL;
	
	for(i=0;i<num;i++)
	{
		init_node(&pnew);
		input_node(phead,&pnew);
		pmax=find_max(phead,pnew,num);
		printf("pmax:id:%d  name:%s\n",pmax->id,pmax->name);
		insert_back(pmax,pnew);
/*
	//尾插
		pnew->prev = phead->prev;
		phead->prev->next = pnew;
		pnew->next = phead;
		phead->prev = pnew;
*/

//头插
/*
		pnew->next=phead->next;
		pnew->prev = phead;
		phead->next->prev = pnew;
		phead->next = pnew;
*/
	}
//	phead = pnew;
//	show_chain(phead);
}

void show_chain(pStu phead)
{
	pStu ptmp;
	for(ptmp=phead->next;ptmp != phead;ptmp=ptmp->next)
	{
		printf("data:%d  %s\n ",ptmp->id,ptmp->name);
	}
	printf("\n");
}
int main()
{
	pStu phead;
	init_node(&phead);
	phead->id = 0;
	int num;
	printf("please input nember of student:");
	scanf("%d",&num);
	create_head_chain(phead,num);
	show_chain(phead);
	return 0;
}
