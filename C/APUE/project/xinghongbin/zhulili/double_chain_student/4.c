#include<stdlib.h>
#include<stdio.h>

enum node
{
	input = 1,
	print,
	quit
};

typedef struct st
{
	char *name;
	int id;
	struct st *prev;
	struct st *next;
}sStu,*pStu;

void create_memory(pStu *pHead,int size)
{
	*pHead = (pStu)malloc(size);
	if(*pHead == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

void init_node(pStu *pHead)
{
	create_memory(pHead,sizeof(sStu));
	(*pHead)->next = *pHead;
	(*pHead)->prev = *pHead;

}

pStu  find_max_front(pStu pHead,pStu pnew)
{
	pStu pTrav = pHead;
	while(1)
	{
		if(pTrav->next->id >= pnew->id )
		{	
			 return pTrav;
		}
		pTrav = pTrav->next;
		if(pTrav->next == pHead)    //双循环链表的判断条件
			break;
	}
	return pTrav;
}

int  insert_back(pStu pmax,pStu pnew)
{
	pmax->next->prev = pnew;
	pnew->prev = pmax;		
	pnew->next = pmax->next;
	pmax->next = pnew;	
}

void create_chain(pStu pHead)
{	
	pStu pnew = NULL;
	pStu pmax_front = NULL;
	init_node(&pnew);
	pnew->name = (char *)malloc(sizeof(sStu));
	printf("请输入学生姓名 id\n");
	scanf("%s%d",pnew->name,&pnew->id);
	pmax_front = find_max_front(pHead,pnew);
	insert_back(pmax_front,pnew);
}

void show_chain(pStu pHead)
{
	pStu ptmp = NULL;
	int i;
	for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
		printf("name:%s  id:%d\n",ptmp->name,ptmp->id);	
	printf("\n");
}

int main()
{
	pStu pHead;
	int choose;
	init_node(&pHead);	
	for(;;)
	{	
		printf("请选择：\n");
		printf("1------------输入\n");
		printf("2------------打印\n");
		printf("3------------退出\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case input:
					create_chain(pHead);
					break;
			case print:	
					show_chain(pHead);
					break;
			case quit:
					return 0;
			default:
					printf("error");
					break;
		}
	}
	return 0;
}
