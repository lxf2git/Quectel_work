#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}sNode,*pNode;

void create_memory(pNode *p)
{
	*p=(pNode)malloc(sizeof(sNode));
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_node(pNode *p)
{
	create_memory(p);
	(*p)->prev=(*p);
	(*p)->next=(*p);
}
		
void insert(pNode pHead,int n)
{
	pNode pnew=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		init_node(&pnew);
		scanf("%d",&pnew->data);
		pHead->next->prev=pnew;
		pnew->prev=pHead;
		pnew->next=pHead->next;
		pHead->next=pnew;
	}
}

void destory(pNode *pHead)
{
	pNode pdel;
	while((*pHead)->next!=*pHead)
	{
		pdel=(*pHead)->next;
		pdel->next->prev=pdel->prev;
		pdel->prev->next=pdel->next;
		pdel->next=pdel;	
		pdel->prev=pdel;
		if(pdel!=NULL)
		{
			free(pdel);
			pdel=NULL;
		}
	}
	if(*pHead!=NULL)
	{
		free(*pHead);
		*pHead=NULL;
	}
}

void free_node(pNode *p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void delete(pNode pHead,pNode pdel)
{
	pNode ptmp=pHead->next;
	pNode pfree=NULL;
	while(ptmp!=pHead)
	{
		if(ptmp->data==pdel->data)
		{
			
			pfree=ptmp;
			ptmp->next->prev=ptmp->prev;
			ptmp->prev->next=ptmp->next;
		//	ptmp->next->next->prev=ptmp;
		//	ptmp->next=ptmp->next->next;
			free_node(&pfree);
			ptmp=ptmp->prev;
	/*		if(pfree!=NULL)
			{
				free(pfree);
				pfree=NULL;
			}
	*/	}
		ptmp=ptmp->next;
	}
}

void compare(pNode pHeadA,pNode pHeadB)
{
	pNode ptmpa=pHeadA->next;
	while(ptmpa!=pHeadA)
	{
		pNode ptmpb=pHeadB->next;
		while(ptmpb!=pHeadB)
		{
			if(ptmpb->data == ptmpa->data)
			{
				delete(pHeadA,ptmpa);
				delete(pHeadB,ptmpb);
				ptmpa=pHeadA;
			}
			ptmpb=ptmpb->next;
		}
		ptmpa=ptmpa->next;
	}
}

void show_chain(pNode pHead)
{
	pNode ptmp=pHead;
	while(ptmp->next != pHead)
	{
		printf("%d ",ptmp->next->data);
		ptmp=ptmp->next;
	}
	printf("\n");
}

int main()
{
	pNode pHeadA=NULL;
	init_node(&pHeadA);
	pNode pHeadB=NULL;
	init_node(&pHeadB);
	printf("输入多少数字:\n");
	int n;
	scanf("%d",&n);
	printf("input A:\n");
	insert(pHeadA,n);
	printf("input B:\n");
	insert(pHeadB,n);
	compare(pHeadA,pHeadB);
	printf("output A:\n");
	show_chain(pHeadA);
	printf("output B:\n");
	show_chain(pHeadB);
	destory(&pHeadA);
	destory(&pHeadB);
}
