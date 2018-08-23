#include<stdio.h>
#include<stdlib.h>

//基数排序
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}sNode,*pNode;

typedef struct dis_chain
{
	pNode record;
	struct dis_chain *next;
	struct dis_chain *prev;
}sDis,*pDis;


void create_memory(pNode *p)
{
	*p=(pNode)malloc(sizeof(sNode));
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_node(pNode *p)
{
	create_memory(p);
	(*p)->next=(*p);
	(*p)->prev=(*p);
}

int judge_num(int m)
{
	int i=1;
	for(;;)
	{
		if(m/10!=0)
		{
			i++;
			m=m/10;
		}
		if(m/10==0)
		{
			return i;
		}
	}
}

void create_memory_dis(pDis *p)
{
	*p=(pDis)malloc(sizeof(sDis));
	init_node(&(*p)->record);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_dis(pDis *p)
{
	create_memory_dis(p);
	(*p)->next=(*p);
	(*p)->prev=(*p);
}

int back(int i)
{
	if(i>1)
	{
		return 10*back(--i);
	}
	else
	{
		return 1;
	}
}

void chain_tail(pNode pHead,pNode pnew)
{
		pnew->next=pHead;
		pnew->prev=pHead->prev;
		pHead->prev->next=pnew;
		pHead->prev=pnew;
}

void chain_tail_dis(pDis pHead,pDis pnew)
{
		pnew->next=pHead;
		pnew->prev=pHead->prev;
		pHead->prev->next=pnew;
		pHead->prev=pnew;
}

void free_node(pNode *p)
{
	(*p)->next=NULL;
	(*p)->prev=NULL;
	if((*p)!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void show_chain(pNode pHead)
{
	pNode pnew=pHead->next;
	while(pnew!=pHead)
	{
		printf("%d ",pnew->data);
		pNode pdel=pnew;
		pnew=pnew->next;
		free_node(&pdel);
	}
	free_node(&pHead);
	printf("\n");
}

void collected(pNode pHead,pDis pHead1)
{
	pNode pnew=pHead->next;
	pDis pnew1=pHead1->next;
	while(pnew1!=pHead1)
	{
	/*	while(pnew1->record!=pnew1->record->prev)
		{
			pNode pdel=pnew1->record->prev;
			pnew->data=pnew1->record->prev->data;
			pnew=pnew->next;
			pnew1->record->prev->prev->next=pnew1->record;
			pnew1->record->prev=pnew1->record->prev->prev;
			free_node(&pdel);
		}
	*/
		while(pnew1->record!=pnew1->record->next)
		{
			pNode pdel=pnew1->record->next;
			pnew->data=pnew1->record->next->data;
			pnew1->record->next->next->prev=pnew1->record;
			pnew1->record->next=pnew1->record->next->next;
			pnew=pnew->next;
			free_node(&pdel);
		}
		pnew1=pnew1->next;
	}
}

void distribute(pNode pHead,int i)
{
	int a;
	a=back(i);
	pNode pHeada=NULL;
	init_node(&pHeada);
	pNode pnew = pHead->next;
	pDis pHead1=NULL;
	init_dis(&pHead1);
	int j;
	for(j=0;j<10;j++)
	{
		pDis pnew1=NULL;
		init_dis(&pnew1);
		chain_tail_dis(pHead1,pnew1);
		while(pnew!=pHead)
		{
			if(j==((pnew->data)%(a*10)/a))
			{
				pNode pnewa=NULL;
				init_node(&pnewa);
				pnewa->data=pnew->data;

				pnewa->next=pnew1->record;
				pnewa->prev=pnew1->record->prev;
				pnew1->record->prev->next=pnewa;
				pnew1->record->prev=pnewa;//尾插 配合collect头删

			/*	pnew1->record->next->prev=pnewa;
				pnewa->prev=pnew1->record;
				pnewa->next=pnew1->record->next;
				pnew1->record->next=pnewa;//头删 配合collect尾删
				*/
			}
			pnew=pnew->next;
		}
		pnew=pHead->next;
	}
	collected(pHead,pHead1);
//	show_chain(pHead);
}


void input_number(pNode pHead)
{
	pNode pnew=NULL;
	int max=0,num;
	for(;;)
	{
		init_node(&pnew);
		printf("please input number:\n");
		printf("if you want to stop please input '-1'\n");
		scanf("%d",&pnew->data);
		if(pnew->data<=0)
		{
			break ;
		}
		if(max<pnew->data)
		{
			max=pnew->data;
		}
		num=judge_num(max);
		chain_tail(pHead,pnew);
	}
//	printf("%d\n",num);
	pDis pHead1=NULL;
	init_dis(&pHead1);
//	show_chain(pHead);
	int i;
	for(i=1;i<num+1;i++)
	{
//		printf("i:%d ",i);
		distribute(pHead,i);
	//	collected(pHead,pHead1);
	}
}


int main()
{
	pNode pHead=NULL;
	init_node(&pHead);
	input_number(pHead);
	show_chain(pHead);
	return 0;
}
