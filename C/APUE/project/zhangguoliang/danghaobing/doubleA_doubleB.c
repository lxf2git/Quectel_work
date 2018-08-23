#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
		int data;
		struct node *next;
		struct node *prev;
}sNode,*pNode;

void create_memory(pNode *p)
{
		*p = (pNode)malloc(sizeof(sNode));
		if(*p==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}

void init_Node(pNode *p)
{
		create_memory(p);
		(*p)->next=(*p);
		(*p)->prev=(*p);
}

void creat_chain(pNode pHead)
{
		pNode pnew = NULL;
		int x,i;
		printf("please input how many node you'll save\n");
		scanf("%d",&x);
		for(i=0;i<x;i++)
		{
				init_Node(&pnew);
				printf("please input data\n");
				scanf("%d",&pnew->data);
				pHead->prev->next = pnew;
				pnew->next = pHead;
				pnew->prev = pHead->prev;
				pHead->prev = pnew;
		}

}

void show_chain(pNode pHead)
{
		pNode pTrav=pHead->next;
		while(pTrav!=pHead)
		{
				printf("%d ",pTrav->data);
				pTrav = pTrav->next;
		}
		printf("\n");
}

void free_Node(pNode *pfree)
{
		(*pfree)->next=NULL;
		(*pfree)->next=NULL;
		if(*pfree!=NULL)
		{
			free(*pfree);
			*pfree=NULL;
		}
}

void delete_same(pNode pHead,int data)
{
		pNode ptmp = pHead;
		pNode pfree = NULL;
		while(ptmp->next!=pHead)
		{
				if(ptmp->next->data==data)
				{
						pfree = ptmp->next;
						ptmp->next->next->prev = ptmp;
						ptmp->next = ptmp->next->next;
						free_Node(&pfree);
						ptmp = ptmp->prev;
				}
				ptmp = ptmp->next;
		}
}

void compare_delete(pNode pHeadA,pNode pHeadB)
{
		pNode ptmpA = pHeadA->next;
		while(ptmpA!=pHeadA)
		{
				pNode ptmpB = pHeadB->next;
				while(ptmpB!=pHeadB)
				{
					if(ptmpA->data==ptmpB->data)
					{
							delete_same(pHeadA,ptmpA->data);
							delete_same(pHeadB,ptmpB->data);
							ptmpA = ptmpA->prev;
							ptmpB = ptmpB->prev;
					}
					ptmpB = ptmpB->next;
				}
				ptmpA = ptmpA->next;
		}
}

void destroy(pNode *pHead)
{
		pNode ptmp= *pHead;
		while(ptmp!=*pHead)
		{
				if(ptmp->next->next==*pHead)
				{
						free_Node(&ptmp->next);
						ptmp=ptmp->prev;
				}
				ptmp = ptmp->next;
		}
		free_Node(pHead);
}

int main()
{
	pNode pHeadA = NULL;
	pNode pHeadB = NULL;
	init_Node(&pHeadA);
	init_Node(&pHeadB);
	creat_chain(pHeadA);
	creat_chain(pHeadB);
	compare_delete(pHeadA,pHeadB);
	show_chain(pHeadA);
	show_chain(pHeadB);
	destroy(&pHeadA);
	destroy(&pHeadB);
	return 0;
}
