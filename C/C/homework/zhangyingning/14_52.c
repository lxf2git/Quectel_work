#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	char name[20];
	struct node *prev;
	struct node *next;
}sNode, *pNode;

void _malloc(void **p, int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error");
		exit -1;
	}
}

void init_node(pNode *p,int size)
{
	_malloc((void*)p,size);
	(*p)->prev = (*p);
	(*p)->next = (*p);
}

void insert(pNode phead,int people)
{
	int i;
	pNode pnew;
	for(i = 1; i <= people;i++)
	{
		init_node(&pnew,sizeof(sNode));
		printf("请输入第%d候选人的名字\n",i);
		scanf("%s",pnew->name);
		pnew->next = phead->next;
		phead->next->prev = pnew;
		pnew->prev = phead;
		phead->next = pnew;
		
	}
}
void put_out(pNode phead,int length) //输出投票结果
{
	int j = 0;
	pNode ptmp = NULL;
	for(ptmp = phead->next; ptmp != phead; ptmp = ptmp->next)
	{
		printf("候选人%4s   票数%4d\n",ptmp->name,ptmp->data);
		j += ptmp->data;
	}
	j = length - j;
	printf("%d票弃权\n",j);
}
void election(pNode phead,int length)
{
	pNode ptmp = NULL;
	char name[20] = {'\0'};
	int i;
	printf("请输入下列候选人的名字进行投票\n(任意输入算弃权)\n");
	for(ptmp = phead->next; ptmp != phead;ptmp = ptmp->next)
	{
		printf("候选人%4s\n",ptmp->name);
	}
	for(i = 1;i <= length;i++)
	{
		printf("第%d投票人投票\n",i);
		scanf("%s",name);
		for(ptmp = phead->next; ptmp != phead;ptmp = ptmp->next)
		{
			if(strcmp(ptmp->name,name))		//判断是否有相同字符串，相同data++
			{
				;
			}
			else
			{
				ptmp->data++;
			}
		}
	}
}
int main()
{
	pNode phead;
	int people, length;
	printf("请输入有多少候选人\n");
	scanf("%d",&people);
	printf("请输入有多少投票人\n");
	scanf("%d",&length);
	init_node(&phead,sizeof(sNode));
	insert(phead,people);
	election(phead,length);
	put_out(phead,length);

}
