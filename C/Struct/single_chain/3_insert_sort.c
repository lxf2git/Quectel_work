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

pNode  find_max(pNode pHead,pNode pnew)
{
	pNode pTrav=pHead;
	while(pTrav->next!=NULL)
	{
		if(pTrav->next->data >= pnew->data)
		{
			return pTrav;
		}
		pTrav = pTrav->next;
	}
	return pTrav;

}

int Insert_back(pNode pPos,pNode pIn)//pIn 待插入的结点 将pIn插到pPos后
{
    if(pPos==NULL||pIn==NULL)
    {
        return -1;
    }
    pIn->next = pPos->next;
    pPos->next = pIn;

    return 0;   
}


void Insert_chain(pNode pHead)
{
	//处理方法：插到第一个数据域比它大的结点前
	//1 没有比它大---插到最后
	//2 找到第一个比它大的结点 并插入其前面
	//int data
	pNode pnew=NULL;
	int i;
	for(i=0;i<5;i++)
	{	
		init_node(&pnew,sizeof(sNode));
		printf("please input message: data ");
		scanf("%d",&pnew->data);
	 	pNode pmax = find_max(pHead,pnew);
	 	Insert_back(pmax,pnew);
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
void Destroy_Node(pNode *p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p = NULL;
	}
}
void Destory_list(pNode *pHead)
{
	pNode pdel=NULL;
	while((*pHead)->next!=NULL)
	{
		pdel = (*pHead)->next;
		(*pHead)->next = pdel->next;
		pdel->next = NULL;
		Destroy_Node(&pdel);
	}
	Destroy_Node(pHead);
}

int main()
{
	pNode pHead = NULL;
	init_node(&pHead,sizeof(sNode));//初始化结点(开空间，赋值)
	Insert_chain(pHead);
	show_chain(pHead);
	//Destory_list(&pHead);

	return 0;

}






