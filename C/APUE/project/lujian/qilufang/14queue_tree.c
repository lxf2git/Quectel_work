#include<stdio.h>
#include<stdlib.h>
#define N 10
#define FULL -1
#define EMPTY -2
#define SUC 0
#define SIZE 10
typedef struct Tree
{
	int data;
	struct Tree *lc;
	struct Tree *rc;
}sTree,*pTree;
typedef struct Queue
{
	pTree num[N];
	int qr;
	int qw;
}sQue,*pQue;
int push(pQue que,pTree data)
{
	if(que->qr==(que->qw+1)%SIZE)
	{
		printf("queue_full!\n");
		return FULL;
	}
	que->num[que->qw]=data;
	que->qw=(que->qw+1)%SIZE;
	return SUC;
}
int pop(pQue que,pTree *data)
{
	if(que->qw==que->qr)
	{
		printf("queue_empty!\n");
		return EMPTY;
	}
	*data=que->num[que->qr];
	que->qr=(que->qr+1)%SIZE;
	return SUC;
}
void init_tr(pTree *p)
{
	*p=malloc(sizeof(sTree));
	if(*p==NULL)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
	(*p)->lc=NULL;
	(*p)->rc=NULL;
}	
void init_que(pQue que)
{
	que->qr=0;
	que->qw=0;
}
void creat_tr(pTree root,int *arr,int nb)
{
	if(arr[nb]<=root->data)
	{
		if(root->lc!=NULL)
		{
			creat_tr(root->lc,arr,nb);
		}
		else
		{
			init_tr(&root->lc);
			root->lc->data=arr[nb];
		}
	}
	else
	{
		if(root->rc!=NULL)
		{
			creat_tr(root->rc,arr,nb);
		}
		else
		{
			init_tr(&root->rc);
			root->rc->data=arr[nb];
		}
	}
}	
void queue_tr(pTree root,pQue que)
{
	pTree ptmp;
	push(que,root);
	while(!pop(que,&ptmp))
	{
		printf("%d\n",ptmp->data);
		if(ptmp->lc!=NULL)
		{
			push(que,ptmp->lc);
		}
		if(ptmp->rc!=NULL)
		{
			push(que,ptmp->rc);
		}
	}
}
int main()
{
	sQue que;
	init_que(&que);
	int i;
	int arr[]={22,7,12,34,30,45,23,27};
	pTree root;
	init_tr(&root);
	root->data=arr[0];
	for(i=1;i<8;i++)
	{
		creat_tr(root,arr,i);
	}
	queue_tr(root,&que);
	return 0;

}
