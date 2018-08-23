#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10

typedef struct Node
{
		int data;
		struct Node *next;
}sNode,*pNode;

inti_Node(pNode *p)
{
		(*p)=malloc(sizeof(sNode));
		(*p)->next=(*p);
}

void new_scan(pNode pHead)
{
		int i;
		pNode palit=pHead;
		for(i=1;i<N;i++)
		{
		pNode pNew;
		inti_Node(&pNew);
		palit->data = i;
		printf("%d==%d\n",i,palit->data);
		palit->next=pNew;
		palit=pNew;
		palit->next=pHead;
		}
		palit->data=N;
		printf("%d==%d\n",i,palit->data);
}

free_Node(pNode *p)
{
		(*p)->next=NULL;
		if((*p)!=NULL)
		{
		free(*p);
		*p=NULL;
		}
}
ju_dit(pNode pHead)
{
		int i=0;
		pNode palit=pHead;
		pNode paat;
		for(;palit->next!=palit;)
		{
		printf("nnnnn%d\n",palit->data);
				i++;
				if(i==2)
				{
						paat=palit->next;
						palit->next=paat->next;
						printf("dit*****%d\n",paat->data);
						i=0;
						free_Node(&paat);
				}
				palit=palit->next;
		}
		printf("*****%d\n",palit->data);
		free_Node(&palit);
}
int main()
{
		pNode pHead;
		inti_Node(&pHead);
		new_scan(pHead);
		ju_dit(pHead);
		return 0;
}
