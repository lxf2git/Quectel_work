#include<stdio.h>
#include<stdlib.h>
#define EMPTY -1
enum Node 
{
	CREAT=1,
	DELETE,
	PRINT,
	EXIT,
};
typedef struct Tree
{
	int data;
	struct Tree *next;
	struct Tree *parent;
	struct Tree *prev;
}sTree,*pTree;
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}
void init_tr(pTree *tr_arr,int size)
{
	getmemory((void **)tr_arr,size);
	(*tr_arr)->next=NULL;
	(*tr_arr)->prev=NULL;
	(*tr_arr)->parent=NULL;
	(*tr_arr)->data=0;
}
void chain_prev(pTree pHead,pTree pnew)
{
	pnew->parent=pHead;
	pHead->prev=pnew;
}
void chain_next(pTree pHead,pTree pnew)
{
	pnew->parent=pHead;
	pHead->next=pnew;
}
void tree_cmp(pTree pHead,pTree pnew)
{

		if(pnew->data<=pHead->data)
		{
			if(pHead->prev==NULL)
			{
				chain_prev(pHead,pnew);
			}
			else
			tree_cmp(pHead->prev,pnew);
		}
		else
		{
			if(pHead->next==NULL)
			{
				chain_next(pHead,pnew);
			}
			else
			tree_cmp(pHead->next,pnew);
		}	
}	
void creat_tree(pTree pHead)
{
	int i,in;
	pTree pnew;
	init_tr(&pnew,sizeof(sTree));
	printf("请输入要插入的数：\n");
	scanf("%d",&in);
	pnew->data=in;
	if(pHead->next==NULL)
	tree_cmp(pHead,pnew);
	else
	tree_cmp(pHead->next,pnew);
}
int mid(pTree ptmp)
{
	if(ptmp->prev!=NULL)
	{
		mid(ptmp->prev);
	}
	printf("%d\n",ptmp->data);
	if(ptmp->next==NULL&&ptmp->prev==NULL)
	{
		return;
	}
#if 1	
	if(ptmp->next!=NULL)
	{
		mid(ptmp->next);
	}
#endif
}
void show(pTree pHead)
{
	printf("输出数据：\n");
	mid(pHead);
}
void destory(pTree *del)
{
	if(del!=NULL)
	{
		free(*del);
		*del=NULL;
	}
}	
void del_2(pTree ptmp)
{
	pTree pdel;
	if(ptmp->next==NULL&&ptmp->prev==NULL)
	{
		if(ptmp->parent->prev!=NULL&&ptmp->parent->prev->data==ptmp->data)
		{
			ptmp->parent->prev=NULL;
			ptmp->parent=NULL;
			destory(&ptmp);
		}
		else
		{
			ptmp->parent->next=NULL;
			destory(&ptmp);
		}
	}
	else if(ptmp->next==NULL&&ptmp->prev!=NULL)
	{
		if(ptmp->parent->prev->data==ptmp->data)
		{
			ptmp->parent->prev=ptmp->prev;
			ptmp->prev->parent=ptmp->parent;
			ptmp->prev=NULL;
			ptmp->parent=NULL;
			destory(&ptmp);
		}
		else
		{
			ptmp->parent->next=ptmp->prev;
			ptmp->prev->parent=ptmp->parent;
			ptmp->prev=NULL;
			ptmp->parent=NULL;
			destory(&ptmp);
		}
	}
	else if(ptmp->next!=NULL&&ptmp->prev==NULL)
	{
		if(ptmp->parent->prev!=NULL&&ptmp->parent->prev->data==ptmp->data)
		{
			ptmp->parent->prev=ptmp->next;
			ptmp->next->parent=ptmp->parent;
			ptmp->next=NULL;
			ptmp->parent=NULL;
			destory(&ptmp);
		}
		else
		{
			ptmp->parent->next=ptmp->next;
			ptmp->next->parent=ptmp->parent;
			ptmp->next=NULL;
			ptmp->parent=NULL;
			destory(&ptmp);
		}
	}
	else if(ptmp->next!=NULL&&ptmp->prev!=NULL)
	{
		if(ptmp->parent->prev->data==ptmp->data)
		{
			pdel=ptmp->prev;
			while(pdel->next!=NULL)
			{
				pdel=pdel->next;
			}
			ptmp->next->parent=pdel;
			pdel->next=ptmp->next;
			ptmp->parent->prev=ptmp->prev;
			ptmp->prev->parent=ptmp->parent;
			ptmp->prev=NULL;		
			ptmp->next=NULL;
			ptmp->parent=NULL;
			destory(&ptmp);
		}
		else
		{
			pdel=ptmp->prev;
			while(pdel->next!=NULL)
			{
				pdel=pdel->next;
			}
			ptmp->next->parent=pdel;
			pdel->next=ptmp->next;
			ptmp->parent->next=ptmp->prev;
			ptmp->prev->parent=ptmp->parent;
			ptmp->prev=NULL;		
			ptmp->next=NULL;
			ptmp->parent=NULL;
			destory(&ptmp);
		}
	}
}
int del_1(pTree ptmp,int num)
{
		if(ptmp!=NULL)
		{
			if(ptmp->data==num)
			{
				del_2(ptmp);
			}
			else
			del_1(ptmp->prev,num);
		}
		if(ptmp!=NULL)
		{
			if(ptmp->data==num)
			{
				del_2(ptmp);
			}
			else
			del_1(ptmp->next,num);
		}
		if(ptmp==NULL)
		{
				return ;
		}	
}
void del(pTree pHead)
{
	int in;
	pTree pdel;
	pTree ptmp=pHead->next;
	printf("请输入你要删除的数：\n");
	scanf("%d",&in);
	if(in==pHead->next->data)
	{
			pdel=pHead->next->prev;
			while(pdel->next!=NULL)
			{
					pdel=pdel->next;
			}
			pHead->next->next->parent=pdel;
			pdel->next=pHead->next->next;
			pHead->next=pHead->next->prev;
			pHead->next->parent=pHead;
			ptmp->prev=NULL;		
			ptmp->next=NULL;
			ptmp->parent=NULL;
			destory(&ptmp);

	}
	else
	del_1(pHead,in);
}
int main()
{
	pTree pHead;
   	init_tr(&pHead,sizeof(sTree));
	int in;
	while(1)
	{
		printf("/*********<1>************creat**************/\n");
		printf("/*********<2>************delete**************/\n");
		printf("/*********<3>************printf**************/\n");
		printf("/*********<4>************exit**************/\n");
		printf("请输入选项：\n");
		scanf("%d",&in);
		switch(in)
		{
			case CREAT : creat_tree(pHead); break;
			case DELETE : del(pHead); break;
			case PRINT : show(pHead->next);  break;
			case EXIT :	 exit(0);
			default : printf("输入错误，请重新输入！\n"); break;

		}
	}
	return 0;

}
