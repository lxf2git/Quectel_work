#include"main.h"

void create_memory(pMem *p)
{
	(*p)=(pMem)malloc(sizeof(sMem));
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_memory(pMem *p)
{
	create_memory(p);
	(*p)->next=*p;
	(*p)->prev=*p;
}

void create_rec(pRec *p)
{
	(*p)=(pRec)malloc(sizeof(sRec));
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_rec(pRec *p)
{
	create_rec(p);
	(*p)->pdata=(pMem*)malloc(5*sizeof(pMem));
	(*p)->next=*p;
	(*p)->prev=*p;
}

void print(pMem pHead,pMem pfree)
{
	pMem pnew=pHead->next;
	pMem pnewf=pfree->next;
	printf("===primary:\n");
	while(pnew!=pHead)
	{
		printf("index:%d mem_size:%d \n",pnew->index,pnew->mem_size);
		pnew=pnew->next;
	}
	printf("\n===free:\n");
	while(pnewf!=pfree)
	{
		printf("index:%d mem_size:%d \n",pnewf->index,pnewf->mem_size);
		pnewf=pnewf->next;
	}
	printf("\n");
}

void delete_mem(pMem *p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void free_mem(pMem pHead)
{
	
	pMem pnew=pHead->next;
	while(pnew!=pHead)
	{
		pMem pdel=pnew;
		pnew->next->prev=pnew->prev;
		pnew->prev->next=pnew->next;
		pnew=pnew->next;
		delete_mem(&pdel);
	}
	delete_mem(&pHead);
}

void menu(pMem pHead,pMem pfree,pRec pnum)
{
	int choose;
	int i=0;
	for(;;)
	{
		printf("please input your choose\n");
		printf("1 apply  2 free  3 print  0 exit\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case APPLY:
				apply(pHead,pfree,pnum);
				break;
			case FREE:
				num_free(pHead,pfree,pnum);
				break;
			case PRINT:
				print(pHead,pfree);
				break;
			case EXIT:
				free_mem(pHead);
				if(pfree->next!=pfree)
				{
					free_mem(pfree);
				}
				return;
		}
	}
}

int main()
{
	pMem pHead=NULL;
	init_memory(&pHead);
	pHead->index=0;
	pMem pfree=NULL;
	init_memory(&pfree);
	pRec pnum=NULL;
	init_rec(&pnum);
	pnum->pdata=(pMem*)malloc(20*sizeof(pMem));
	int i;
	for(i=0;i<N;i++)
	{
		pMem pnew=NULL;
		init_memory(&pnew);
		pnew->index=i+1;
//		printf("begin: %d ",pnew->index);
		pnew->mem_size=10;

		pnew->next=pHead;
		pHead->prev->next=pnew;
		pnew->prev=pHead->prev;
		pHead->prev=pnew;
	}
	menu(pHead,pfree,pnum);
}
