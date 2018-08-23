#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}sNode,*pNode;

void init_node(pNode *p,int size);
void creat_memory(void **p,int size);
void Destory_Node(void **p);
void Destory_list(pNode phead);
void show_chain(pNode phead);

void Insert_chain(pNode phead)			//插
{
	pNode ptrav = pHead;
	pNode pPos = find_max(phead,pnew);
}
pNode find_max(pNode phead,pNode pnew)
{
	pNode pTrav = phead;
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
int main()
{
	pNode phead=NULL;
	init_node(&phead,sizeof(sNode));
	Insert_chain(phead);
	show_chain(phead);
	Destory_list(&phead);
	return 0;
}
void Destory_list(pNode *phead)
{
	pNode pdel=NULL;
	while((*phead)->next!=NULL)
	{
		pdel=(*phead)->next;
		(*phead)->next=pdel->next;
		pdel->next=NULL;
		Destory_Node((void **)&pdel);					//	
	}
	Destory_Node((void **)phead);					//	
}
void show_chain(pNode phead)		//打印
{
	pNode ptmp;
	for(ptmp=phead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		printf("%d ",ptmp->data);
	}
	printf("\n");
}
void init_node(pNode *p,int size)		//开空间 初始化
{
	creat_memory((void **)p,size);
	(*p)->next=NULL;
}
void creat_memory(void **p,int size)
{
	*p=malloc(size);
}
void Destory_Node(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
