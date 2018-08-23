#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct human
{
	int num;
	struct human *next;
}sHum,*pHum;

void create_memory(pHum *p,int size)
{
	*p=(pHum)malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit (-1);
	}
}

void init_hum(pHum *p,int size)
{
	create_memory(p,size);
	(*p)->next=(*p);
}

void create_circle_chain(pHum pHead)
{
	pHum ptail=pHead;
	pHum pnew=NULL;
	int i;
	for(i=1;i<N;i++)
	{
		init_hum(&pnew,sizeof(sHum));
		(pnew->num)=(i+1);
		ptail->next = pnew;
		ptail = pnew;
		ptail->next=pHead;
	}
	pHead->num=1;
}

void Destory(pHum *pdel)
{
	if(*pdel!=NULL)
	{
		free(*pdel);
		*pdel=NULL;
	}
}

void kill_human(pHum pHead)
{
	pHum pTrav=pHead;
	pHum pdel=NULL;
	int i=0;
	while(pTrav->next!=pTrav)
	{
		i++;
		if(i==2)
		{
			pdel=pTrav->next;
			pTrav->next=pTrav->next->next;		
			i=0;
		}
		Destory(&pdel);
		pTrav=pTrav->next;
	}
	printf("alive:%d\n",pTrav->num);
	pdel=pTrav;
	Destory(&pdel);
}

int main()
{
	pHum pHead = NULL;
	init_hum(&pHead,sizeof(sHum));
	create_circle_chain(pHead);
	kill_human(pHead);
	return 0;
}
