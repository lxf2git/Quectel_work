#include<stdio.h>
#include<stdlib.h>

#define M 8
#define N 5
#define FULL -1
#define SUC   0

typedef struct data
{
	int data;
	struct data *prev;
	struct data *next;
}sData,*pData;

typedef struct and
{
	struct data *and[M];
}sAnd,*pAnd;

typedef struct mod
{
	struct and *mod[N];
}sMod,*pMod;

void init_data(pData *p,int size);
void creat_memory(void **p, int size);
void creat_chain(pData phead);
void hash(pMod mod,pData phead);
void show(sMod smod);

int main()
{
	int i,j;
	pData phead=NULL;
	init_data(&phead,sizeof(sData));
	creat_chain(phead);
	sMod smod;
	for(i=0;i<N;i++)
	{
		creat_memory((void **)&smod.mod[i],sizeof(sAnd));
		for(j=0;j<M;j++)
		{		
			init_data(&(smod.mod[i]->and[j]),sizeof(sData));
		}
	}
	hash(&smod,phead);
	show(smod);
	return SUC;
}

void init_data(pData *p,int size)
{
	creat_memory((void **)p,size);
	(*p)->prev=*p;
	(*p)->next=*p;
}

void creat_memory(void **p, int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void creat_chain(pData phead)
{
	printf("please input a lenge\n");
	int n,i;
	scanf("%d",&n);
	pData pnew=NULL;
	for(i=0;i<n;i++)
	{
		init_data(&pnew,sizeof(sData));
		scanf("%d",&pnew->data);
		insert_(phead,pnew);
	}
}

int insert_(pData p1,pData p2)
{
	if(p1==NULL||p2==NULL)
	{
		printf("insert data error\n");
		return FULL;
	}
	p2->next=p1;
	p2->prev=p1->prev;
	p1->prev->next=p2;
	p1->prev=p2;
	return SUC;
}

void hash(pMod pmod,pData phead)
{
	int i,j;
	pData p=NULL;
	for(p=phead->next;p!=phead;p=p->next)
	{
		pData pnew=NULL;
		init_data(&pnew,sizeof(sData));
		pnew->data=p->data;
		insert_(pmod->mod[p->data%5]->and[p->data>>3&7],pnew);
	}
}

void show(sMod smod)
{
	printf("please input a number\n");
	int num,n,m,i=0;
	scanf("%d",&num);
	n=num%N;
	m=num>>3&(M-1);
	pData p=NULL;
	for(p=smod.mod[n]->and[m]->next;p!=smod.mod[n]->and[m];p=p->next)
	{
		if(p->data==num)
		{
			i++;
			printf("it is have %d\n",i);
		}
	}
	if(i==0)
	{
		printf("not found\n");
	}
}
