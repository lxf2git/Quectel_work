/*
 *链表（单 单循环 双循环 排序 栈 队列 树）
   
 *
 * */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

}sNode,*pNode;


void create_memory(pNode *p,int size)
{
	*p = (pNode)malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");	
		exit(-1);
	}
}

void init_node(pNode *p,int size)//开空间 赋值
{
	create_memory(p,size);
	(*p)->next = NULL;	
}

void Create_chain_head_num(pNode pHead,int chain_num)
{
	pNode pnew=NULL;
	int i;
	for(i=0;i<chain_num;i++)
	{
		init_node(&pnew,sizeof(sNode));//pnew
		printf("please input data:\n");
		scanf("%d",&pnew->data);
		pnew->next = pHead->next;
		pHead->next = pnew;
	}
}
void Create_chain_end_num(pNode pHead,int chain_num)
{
	pNode ptail=pHead;	
	pNode pnew = NULL;
	int i;
	for(i=0;i<chain_num;i++)
	{
		init_node(&pnew,sizeof(sNode));//pnew
		printf("please input data:\n");
		scanf("%d",&pnew->data);
		ptail->next = pnew;
		ptail = pnew;
	}
}

void show_chain(pNode pHead)
{
	pNode ptmp=NULL;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		printf("%d ",ptmp->data);
	}
	printf("\n");
}

void Destory_list(pNode pHead)
{
	pNode pdel=NULL;
	while(pHead->next!=NULL)
	{
		pdel = pHead->next;
		pHead->next = pdel->next;
		pdel->next = NULL;
		if(pdel!=NULL)
		{
			free(pdel);
			pdel = NULL;
		}
	}

}

int main()
{
	pNode pHead = NULL;
	init_node(&pHead,sizeof(sNode));//初始化结点(开空间，赋值)
	//create_chain_head_num(pHead,10);
	Create_chain_end_num(pHead,10);
	show_chain(pHead);
	Destory_list(pHead);
	if(pHead!=NULL)
	{
			free(pHead);
			pHead = NULL;
	}

	return 0;

}






