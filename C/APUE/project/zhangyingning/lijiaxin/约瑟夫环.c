#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
		int data;
		struct node *next;
}sNode,*pNode;

get_memory(void **q,int size)
{
		*q = malloc(size);
		if(*q ==NULL)
		{
				printf("malloc error.\n");
				exit(-1);
		}
}

void my_free(void **q)
{
		if(NULL!=*q)
		{
				free(*q);
				*q = NULL;
		}
}

void init_n(pNode *pHead)
{
		get_memory((void **)pHead,sizeof(sNode));
		(*pHead)->next = NULL;
}

void create_chain(pNode phead)
{
		int i,n;
		pNode ptail=phead;
		pNode pnew=NULL;
		printf("please input the number of people.\n");
		scanf("%d",&n);
		for(i=0;i<n-1;i++)
		{
				init_n(&pnew);
				ptail->data = i+1;
				ptail->next = pnew;
				pnew->next = phead;
				ptail = pnew;
		}
		ptail->data = 10;
}

void  input(pNode *pHead)
{
		init_n(pHead);
		create_chain(*pHead);
}
void destory_link(pNode *pdel)
{
		pNode ptmp = (*pdel)->next;
		(*pdel)->next = (*pdel)->next->next;
		my_free((void **)&ptmp);
}
void deal(pNode *phead)
{
		int i=0;
		pNode ptmp;
		while((*phead)->next!=(*phead))
		{
			i++;
			if(i%3==0)
			{
					destory_link(&ptmp);
			}
			ptmp = (*phead);
			*phead = (*phead)->next;
		}	
}
void print(pNode p)
{
		printf("%d\n",p->data);
}
int main()
{
		pNode pnew = NULL;
		input(&pnew);
		deal(&pnew);
		print(pnew);
		return 0;
}
	
