#include"sort.h"

int main()
{
	int num,sum;
	int i;
	pNode pHead = NULL;
	init_node(&pHead,sizeof(sNode));

	pChain pFrist = NULL;
	init_chain(&pFrist,sizeof(sChain));

	creat_chain(pHead);
	creat_chain_chain(pFrist);
	show_chain(pHead);
//	show_chain_chain(pFrist);

	num = judge_num(pHead);
//	printf("num:%d\n",num);

	
	for(i=1;i<=num;i++)
	{
		distribute(pHead,pFrist,num,i);
		collected(pHead,pFrist);
//		i=num;
	}
//	show_chain_chain(pFrist);

//	show_chain(pFrist->next->next->record);
	show_chain(pHead);

	return 0;
}

void creat_chain(pNode pHead)
{
	int i;
	pNode pnew = NULL;
	for(i=0;i<6;i++)
	{
		init_node(&pnew,sizeof(sNode));
		scanf("%d",&pnew->data);
		insert_back(pHead,pnew);	
	}
}
void creat_chain_chain(pChain pFrist)
{
	int i;
	pChain pnew = NULL;
	for(i=0;i<10;i++)
	{
		init_chain(&pnew,sizeof(sChain));
		init_node(&pnew->record,sizeof(sNode));
		pnew->prev = pFrist->prev;
		pFrist->prev->next = pnew;
		pFrist->prev = pnew;
		pnew->next = pFrist;		
	}
}
void insert_back(pNode pHead,pNode pnew)
{
	pnew->prev = pHead->prev;
	pHead->prev->next = pnew;
	pHead->prev = pnew;
	pnew->next = pHead;
}
void show_chain(pNode pHead)
{
	pNode ptmp = pHead;
	for(ptmp = pHead->next;ptmp != pHead;ptmp = ptmp->next)
	{
		printf("%d ",ptmp->data);
	}
	printf("\n");
}

void init_node(pNode *pnode,int size)
{
	creat_memory((void **)pnode,size);
	(*pnode)->next = *pnode;
	(*pnode)->prev = *pnode;
}
void init_chain(pChain *pnode,int size)
{
	creat_memory((void **)pnode,size);
	(*pnode)->next = *pnode;
	(*pnode)->prev = *pnode;
}

void creat_memory(void **p,int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error\n");
		exit(-1);
	}
	bzero(*p,size);
}

void show_chain_chain(pChain pFrist)
{
	pChain ptmp = NULL;
	for(ptmp=pFrist;ptmp!=pFrist;ptmp=ptmp->next)
	{
		printf("%p ",ptmp->record);
	}
	printf("\n");
}

