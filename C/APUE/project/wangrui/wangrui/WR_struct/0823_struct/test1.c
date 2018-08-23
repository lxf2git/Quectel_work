#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}sNode,*pNode;

void init_node(pNode *p,int size);
void creat_memory(void **p,int size);
void create_chain_head_num(pNode phead,int num);
void Destory_list(pNode phead);
void show_chain(pNode phead);
int main()
{
	pNode phead=NULL;
	init_node(&phead,sizeof(sNode));
	create_chain_head_num(phead,5);
	show_chain(phead);
	Destory_list(phead);
	if(phead!=NULL)			//
	{
		free(phead);
		phead=NULL;
	}						//
	Destory_list(phead);
	return 0;
}
void Destory_list(pNode phead)
{
	pNode pdel=NULL;
	while(phead->next!=NULL)
	{
		pdel=phead->next;
		phead->next=pdel->next;
		pdel->next=NULL;
		if(pdel!=NULL)		//	
		{
			free(pdel);
			pdel=NULL;
		}					//	
	}
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
void create_chain_head_num(pNode phead,int num)			//创建链表
{
	pNode pnew=NULL;
	pNode ptail=phead;	//		尾插临时指针
	int i;
	for(i=0;i<num;i++)
	{
		init_node(&pnew,sizeof(sNode));
		printf("%ddata\n",i);
		scanf("%d",&pnew->data);
#if 1
		ptail->next=pnew;//			尾插
		ptail=pnew;//
#endif
#if 0
		if(i!=0)					头插
		{
			pnew->next=phead->next;
		}
		phead->next=pnew;	
#endif
	}
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
