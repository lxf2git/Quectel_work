#include<stdio.h>
#include<stdlib.h>

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
}sDC,*pDC;

void free_node(pNode *p)
{
		(*p)->next=NULL;
		(*p)->prev=NULL;
		if(*p!=NULL)
		{
				free(*p);
				*p=NULL;
		}
}

void create_memory(void **p,int size)
{
		*p = malloc(size);
		if(*p==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}

void init_Node(pNode *pNode,int size)
{
	create_memory((void **)pNode,size);
	(*pNode)->prev = (*pNode);
	(*pNode)->next = (*pNode);
}

void init_chain(pDC *p,int size)
{
		create_memory((void **)p,size);
		init_Node(&(*p)->record,sizeof(sNode));
		(*p)->next=(*p);
		(*p)->prev=(*p);
}

void creat_pNode(pNode pHead,int n)
{
		pNode pnew = NULL;
		init_Node(&pnew,sizeof(sNode));
		pnew->data = n;
		pnew->next=pHead;
		pnew->prev=pHead->prev;
		pHead->prev->next=pnew;
		pHead->prev=pnew;

}

void creat_chain(pNode pHead)
{
	printf("please tell me how many num you'll input\n");
	int x,i,n;
	scanf("%d",&x);
	printf("please input number!\n");
	for(i=0;i<x;i++)
	{
		scanf("%d",&n);
		creat_pNode(pHead,n);
	}

}

int judge_time(pNode pHead)
{
		pNode ptmp = pHead->next;
		int sum=0;
		while(ptmp!=pHead)
		{
				if(sum <= ptmp->data)
				{
						sum = ptmp->data;
				}
				ptmp = ptmp->next;
		}
		int i=0;
		while(1)
		{
				i++;
				sum=sum/10;
				if(sum==0)
				{
						break;
				}
		}
		return i;
}

int back(int i)
{
		if(i>1)
				return 10*back(--i);
		else
				return 1;
}

void distribute(pNode pHead,pDC pheadC,int i)
{
		pDC pnewC = NULL;
		int j;//j是0-9
		for(j=0;j<10;j++)
		{
				init_chain(&pnewC,sizeof(sDC));
				pNode ptmp = pHead;
				while(ptmp->prev!=pHead)
				{
						if(((ptmp->prev->data/back(i))%10)==j)
						{
							creat_pNode(pnewC->record,ptmp->prev->data);
						}
						ptmp=ptmp->prev;
				}
				pheadC->prev->next=pnewC;
				pnewC->next=pheadC;
				pnewC->prev=pheadC->prev;
				pheadC->prev=pnewC;
		}
}

void show_chain(pNode pHead)
{
		pNode ptmp = pHead;
		while(ptmp->next!=pHead)
		{
				printf("%d ",ptmp->next->data);
				pNode del= ptmp;
				ptmp=ptmp->next;
				free_node(&del);

		}
		printf("\n");
}

void collected(pNode pHead,pDC pheadC)
{
		pNode ptmp = pHead->next;
		pDC ptmpC = pheadC->next;
	while(ptmpC!=pheadC)
	{
			while(ptmpC->record->prev!=ptmpC->record)
			{
							pNode pdel = ptmpC->record->prev;
							ptmp->data=ptmpC->record->prev->data;
				 			
							ptmp=ptmp->next;
							ptmpC->record->prev->prev->next=ptmpC->record;
							ptmpC->record->prev=ptmpC->record->prev->prev;
							
							free_node(&pdel);
			}
			
		ptmpC=ptmpC->next;
				
	}
}

void compare(pNode pHead,pDC pheadC)
{
		int time = judge_time(pHead);

		int i;
		for(i=1;i<=time;i++)
		{
				distribute(pHead,pheadC,i);
				collected(pHead,pheadC);
		}
}


int main()
{
	pNode pHead = NULL;
	init_Node(&pHead,sizeof(sNode));
	pDC pheadC = NULL;
	init_chain(&pheadC,sizeof(sDC));
	creat_chain(pHead);
	compare(pHead,pheadC);
	show_chain(pHead);
}
















