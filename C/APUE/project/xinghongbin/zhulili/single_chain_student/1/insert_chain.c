#include"insert_chain.h"

void create_memory(pNode *p,int size)
{
	*p = (pNode)malloc(size);
	if(*p == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

void init_node(pNode *p,int size)
{
	create_memory(p,size);
	(*p)->next = NULL;
}

int insert_back(pNode pPos,pNode pIn)  //pPin 插到 pPos后面
{
	pNode pTrav = NULL;
	if(pPos == NULL || pIn == NULL )
	{
		return -1;
	}
	pIn->next = pPos->next;
	pPos->next = pIn; 
	return 0;
}

pNode find_front(pNode pHead,pNode pnew)
{
	pNode ptmp = pHead;
	while(ptmp->next!=NULL )  
	{
		if(ptmp->next->id >= pnew->id )
		{
			return ptmp;
		}
		ptmp = ptmp->next;
	}
	return ptmp;
	
}

pNode insert_chain(pNode pHead)
{
	pNode pnew = NULL;
	pNode pmax_front = NULL;
	printf("请输入id 姓名 年龄：\n");	
	init_node(&pnew,sizeof(sNode));
	scanf("%d%s%d",&pnew->id,pnew->name,&pnew->age);
	pmax_front = find_front(pHead,pnew);
	insert_back(pmax_front,pnew);
	return  pnew;
	
}
