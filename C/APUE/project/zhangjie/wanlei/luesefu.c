#include<stdio.h>
#include<stdlib.h>

#define N 41

typedef struct people
{
	int id;
	struct people *next;
}sPeo;

void fun();
void init_peo(sPeo **p,int size,int id);
void change(sPeo **p);
void i_free(void **p);
void creat_memory(void **p,int size);
void kill_peo(sPeo **p,sPeo *p1);
void show(sPeo *p);

int main()
{
	fun();
	return 0;
}

void fun()
{
	int i;
	sPeo *p=NULL;
	init_peo(&p,sizeof(sPeo),1);
	sPeo *phead=p;
	sPeo *ptail=phead;
	for(i=1;i<N;i++)
	{	
		init_peo(&p,sizeof(sPeo),i+1);
		ptail->next=p;
		ptail=p;
		ptail->next=phead;
	}
	//show(phead);
	change(&phead);
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_peo(sPeo **p,int size,int id)
{
	creat_memory((void **)p,size);
	(*p)->next=(*p);
	(*p)->id=id;
}

void change(sPeo **p)
{
	int i=1;
	sPeo *p1=NULL;
	while((*p)->next!=*p)
	{
		p1=*p;
		(*p)=(*p)->next;
		i++;
		if(i%3==0)
		{
			printf("kill:%d ",(*p)->id);
			kill_peo(p,p1);
		}
	}
	printf("\n活着的人：%d\n",(*p)->id);
	i_free((void **)p);
}

void kill_peo(sPeo **p,sPeo *p1)
{
	p1->next=(*p)->next;
	(*p)->next=NULL;
	i_free((void **)p);
	(*p)=p1;
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void show(sPeo *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%d ",p->id);
		p=p->next;
	}
}
