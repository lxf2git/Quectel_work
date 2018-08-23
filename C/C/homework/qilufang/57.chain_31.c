#include<stdio.h>
#include<stdlib.h>

/**************结构体声明**********/
typedef struct Node
{
	int data;
	struct Node *next;
}sNode,*pNode;

/*********开空间函数***********/
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}

/************逐个链表开空间*********/
void init_node(pNode *p,int size)
{
	getmemory((void **)p,size);
	(*p)->next=(*p);
}

/********创建链表*************/
void creat_chain(pNode pHead,int nb)
{
	int i;
	pNode pnew;
	for(i=nb;i>1;i--)
	{
		init_node(&pnew,sizeof(sNode));
		pnew->data = i;
		pnew->next = pHead->next;
		pHead->next = pnew; 
	}
}

/*************去除满足条件的链表********/
void deal(pNode pHead)
{
	pNode pdel;
	pNode ptmp;
	int i=0;
	for(ptmp=pHead;;ptmp=ptmp->next)
	{
		i++;
		if(i%2==0)
		{
			i=0;
			pdel=ptmp->next;			//去除第三个
			ptmp->next=pdel->next;
			pdel->next=NULL;
			free(pdel);
			pdel=NULL;
			if(ptmp->next==ptmp)		//判断是否剩一个
			{
				printf("剩余的是%d号\n",ptmp->data);
				ptmp->next=NULL;
				free(ptmp);
				exit(0);
			}

		}
	}
}

/************主函数**************/
int main()
{
	int in;
	pNode pHead;
	printf("输入多少人围成约瑟夫圈:\n");
	scanf("%d",&in);
	init_node(&pHead,sizeof(sNode));
	pHead->data=1;
	creat_chain(pHead,in);
	deal(pHead);
	return 0;

}
