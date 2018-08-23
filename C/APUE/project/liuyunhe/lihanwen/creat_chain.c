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

void create_chain_head_num(pNode pHead,int chain_num)
{
	pNode pnew=NULL;
	int i;
	for(i=0;i<chain_num;i++)
	{
		init_node(&pnew,10);//pnew
		printf("please input data:\n");
		scanf("%d",&pnew->data);
		
		pnew->next=pHead->next;
		printf("pnew->next:%p,&(*pHead)->next:%p\n",pnew->next,pHead->next);
		pHead->next=pnew;
		printf("pHead->next:%p,pnew->data:%p\n",pHead->next,pnew->data);
	}
}

int main()
{
	pNode pHead = NULL;
	init_node(&pHead,sizeof(sNode));//初始化结点(开空间，赋值)
	create_chain_head_num(pHead,10);
		
	return 0;

}






