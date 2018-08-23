#include<stdio.h>
#include"Joseph.h"

void show_chain(pNode phead);
int main()
{
	pNode phead = NULL;
	init_node(&phead);
	create_node_ring(phead);
//	show_chain(phead);
	kill_and_free(&phead);
//	free_node(&phead);
	return 0;
}
void show_chain(pNode phead)
{
		int i=0;
	printf("show\n");
	pNode ptmp = phead;
		for(ptmp=phead->next;i<10;ptmp = ptmp->next,i++)
		{
			printf("%d ",ptmp->data);
		}
		printf("\n");
}

void kill_and_free(pNode *phead)
{
		int i=0;
		int k = 0;
	pNode ptmp = *phead;
	pNode pdel = NULL;
	while(1)
	{
		ptmp = ptmp->next;	
		ptmp = ptmp->next;
		pdel = ptmp->next;
		ptmp->next = pdel->next;
		pdel->next = NULL;
		free_node(&pdel);
		if(ptmp->next == ptmp)
		{
			break;
		}
	}
	
	
	printf("%d\n",ptmp->data);
	free_node(&ptmp);
}
void free_node(pNode *p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
void create_node_ring(pNode phead)
{
	int n;
	int i;
	phead->data = 1;
	printf("How many people:\n");
	scanf("%d",&n);
	insert_back(phead,n-1);
}

void insert_back(pNode phead , int n)
{
	int i;
	pNode ptail = phead;
	pNode pnew = NULL;
	for(i=0;i<n;i++)
	{
		init_node(&pnew);
		pnew->data = i+1;
		ptail->next = pnew;
		ptail = pnew;
		pnew->next = phead;
	}
}

void init_node(pNode *p)
{
	creat_memory(p,sizeof(sNode));
	(*p)->next = *p;
}
void creat_memory(pNode *p,int size)
{
	*p = (pNode)malloc(size);
	bzero(*p,size);
	if(*p == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

