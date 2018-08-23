#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct student
{
	int data;
	struct student *next;
	struct student *prev;
}sStu,*pStu;

create_memory(pStu *p,int size)
{
	*p=(pStu)malloc(size);
	if(*p==NULL)
	{
		printf("create error!\n");
		exit(-1);
	}
	(*p)->next=*p;
	(*p)->prev=*p;
}

void link_node(pStu pHead,pStu ptmp,pStu pnew)
{
	//pStu ptmp=pHead->;
	pnew->next=pHead;
	pHead->prev=pnew;
	pnew->prev=ptmp;
	ptmp->next=pnew;
	//ptmp=ptmp->next;
	//printf("%d\n",ptmp->data);
	//printf("%d\n",ptmp->prev->data);
}

void del_node(pStu pdel,int del)
{
	pStu str=pdel->next;
	printf("&%d\n",del);
	while(str!=pdel)
	{
		if(str->data==del)
		{
			(str->next)->prev=str->prev;
			(str->prev)->next=str->next;
			//pdel->next=NULL;
			//pdel->prev=NULL;
		}
		str=str->next;
	}
}

void replace_node(pStu pHeadA,pStu pHeadB)
{
	pStu A=pHeadA->next;
	pStu B=pHeadB->next;
	while(A!=pHeadA)
	{
		while(B!=pHeadB)
		{
			if(A->data==B->data)
			{
			printf("*%d\n",A->data);
			printf("=%d\n",B->data);
			del_node(pHeadA,A->data);
			del_node(pHeadB,B->data);
			}
			B=B->next;
		}
		A=A->next;
		B=pHeadB->next;
		printf("==%d\n",A->next->data);
	}
}

void insert_chain(pStu pHeadA,pStu pHeadB)
{
	int i;
	pStu pnew=NULL;
	pStu ptmp=pHeadA;
	for(i=0;i<5;i++)
	{
	create_memory(&pnew,sizeof(sStu));
	printf("please input A's data:\n");
	scanf("%d",&pnew->data);
	link_node(pHeadA,ptmp,pnew);
	ptmp=ptmp->next;
	}//pStu pnew=NULL;
	ptmp=pHeadB;
	for(i=0;i<5;i++)
	{
	create_memory(&pnew,sizeof(sStu));
	printf("please input B's data\n");
	scanf("%d",&pnew->data);
	link_node(pHeadB,ptmp,pnew);
	ptmp=ptmp->next;
	}
}

void show_chain(pStu pHeadA,pStu pHeadB)
{
	pStu A=pHeadA;
	pStu B=pHeadB;
	printf("A: \n");
	while(A->next!=pHeadA)
	{
		printf(" %d ",A->next->data);
		A=A->next;
	}
	printf("\n");
	printf("B: \n");
	while(B->next!=pHeadB)
	{
		printf(" %d ",B->next->data);
		B=B->next;
	}
	printf("\n");
}
int main()
{
	pStu pHeadA=NULL;
	pStu pHeadB=NULL;
	create_memory(&pHeadA,sizeof(sStu));
	create_memory(&pHeadB,sizeof(sStu));
	insert_chain(pHeadA,pHeadB);
	replace_node(pHeadA,pHeadB);
	show_chain(pHeadA,pHeadB);	

}
