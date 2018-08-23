#include<stdio.h>
#include<stdlib.h>
#define N 15
typedef struct Tree
{
	int data;
	struct Tree *lc;
	struct Tree *rc;
}sTree,*pTree;
typedef struct Stack
{
	int top;
	pTree *bottom;
}sStack,*pStack;
void push(pStack ps,pTree mod)
{
	if(ps->top==N)
	{
		printf("full Stack!\n");
		exit(-1);
	}
	(ps->top)++;
	*(ps->bottom+(ps->top))=mod;
}
void pop(pStack ps,pTree *data)
{
	if(ps->top==0)
	{
		printf("stack empty!\n");
		exit(-1);
	}
	*data=*(ps->bottom+(ps->top));
	(ps->top)--;
}
void init_stack(pStack ps)
{
	ps->bottom=malloc(sizeof(pTree)*N);
	ps->top=0;
}
void init_tr(pTree *p)
{
	*p=malloc(sizeof(sTree));
	if(NULL==*p)
	{
		printf("malloc_error!\n");
		exit(-1);
	}
	(*p)->lc=NULL;
	(*p)->rc=NULL;
	(*p)->data=0;
}
void mid_sort(pTree *root,int *arr,int i)
{
	if(arr[i]<=(*root)->data)
	{
		if((*root)->lc!=NULL)
		{
			mid_sort(&(*root)->lc,arr,i);
		}
		else
		{
			init_tr(&(*root)->lc);
			(*root)->lc->data=arr[i];
		}
	}
	else
	{
		if((*root)->rc!=NULL)
		{
			mid_sort(&(*root)->rc,arr,i);
		}
		else
		{
			init_tr(&(*root)->rc);
			(*root)->rc->data=arr[i];
		}
	}
}
void create_tr(pTree *root,int *arr,int num)
{
	int i;
	for(i=1;i<num;i++)
	{
		mid_sort(root,arr,i);
	}

}
void show_stack_mid(pStack sta,pTree root)
{
	pTree pdata;
	pTree ptmp;
#if 0
	pTree ptmp_1;
	while(root!=NULL)
	{
		push(sta,root);
		root=root->lc;
	}
	while(sta->top!=0)
	{
		pop(sta,&pdata);
		printf("%d ",pdata->data);
		ptmp=pdata;
		if(ptmp->rc!=NULL)
		{
			push(sta,ptmp->rc);
			ptmp_1=ptmp->rc;
			while(ptmp_1->lc!=NULL)
			{
				push(sta,ptmp_1->lc);
				ptmp_1=ptmp_1->lc;
			}	
		}
	}
#endif
#if 1
	ptmp=root;
	while(ptmp!=NULL||sta->top!=0)
	{
		while(ptmp!=NULL)
		{
			push(sta,ptmp);
			ptmp=ptmp->lc;
		}
		pop(sta,&pdata);
		printf("%d ",pdata->data);
		ptmp=pdata;
		ptmp=ptmp->rc;
	}
#endif
}
void show_stack_prev(pStack sta,pTree root)
{
	pTree pdata;
	pTree ptmp;
#if 0
	push(sta,root);
	while(sta->top!=0)
	{
		pop(sta,&pdata);
		printf("%d ",pdata->data);
		ptmp=pdata;
		if(ptmp->rc!=NULL)
		{
			push(sta,ptmp->rc);
		}
		if(ptmp->lc!=NULL)
		{
			push(sta,ptmp->lc);
		}
	}
#endif
#if 1
	ptmp=root;
	while(ptmp!=NULL||sta->top!=0)
	{
		while(ptmp!=NULL)
		{
			printf("%d ",ptmp->data);
			push(sta,ptmp);
			ptmp=ptmp->lc;
		}
		pop(sta,&pdata);
		ptmp=pdata;
		ptmp=ptmp->rc;
	}
#endif
}
void show_stack_last(pStack sta,pTree root)
{
	pTree pdata;
	pTree ptmp;
	pTree visited=NULL;
	ptmp=root;
	while(sta->top!=0||ptmp!=NULL)
	{
		while(ptmp!=NULL)
		{
				push(sta,ptmp);
				ptmp=ptmp->lc;
		}
		ptmp=*(sta->bottom+sta->top);
		if(ptmp->rc==NULL||visited==ptmp->rc)
		{
			pop(sta,&pdata);
			printf("%d ",pdata->data);
			visited=pdata;
			ptmp=NULL;
		}
		else
		{
			ptmp=ptmp->rc;
		}
	}
}
void show_mid(pTree root)
{
	if(root->lc!=NULL)
	{
		show_mid(root->lc);
	}
	if(root->rc!=NULL)
	{
		show_mid(root->rc);
	}
	printf("%d ",root->data);
}
void show(pTree root,pStack sta)
{
	printf("show_stack_mid\n");
	show_stack_mid(sta,root);
	printf("\n");
	printf("show_stack_prev\n");
	show_stack_prev(sta,root);
	printf("\n");
	printf("show_stack_last\n");
	show_stack_last(sta,root);
	printf("\n");
/*	printf("show_digui\n");
	show_mid(root);
	printf("\n");*/

}
int main()
{
	int arr[]={22,7,12,34,30,45,23,27};
	sStack sta;
	init_stack(&sta);
	pTree root;
	init_tr(&root);
	root->data=arr[0];
	create_tr(&root,arr,8);
	show(root,&sta);
	return 0;
}
