#include<stdio.h>
#include<stdlib.h>
#define N 10
typedef struct Data
{
	int data;
	struct Data *prev;
	struct Data *next;
}sData,*pData;
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}
void init_data(pData *pnode,int size)
{
	getmemory((void **)pnode,size);
	(*pnode)->prev=(*pnode);
	(*pnode)->next=(*pnode);
}
void make_chain(pData pHead,int nb)
{
	int i;
	pData pnew=NULL;
	for(i=0;i<nb;i++)
	{
		init_data(&pnew,sizeof(sData));
		scanf("%d",&pnew->data);
		pHead->prev->next=pnew;
		pnew->prev=pHead->prev;
		pHead->prev=pnew;
		pnew->next=pHead;
	}
}
void output(pData *pHead)
{
	pData ptmp=(*pHead);
	if((*pHead)->next==(*pHead))
	{
		printf("小心了，此链表没数了！\n");
	}
	while(ptmp->next !=(*pHead))
	{
		ptmp=ptmp->next;
		printf("%d ",ptmp->data);
	}
	printf("\n");
}
void destory(pData *p)
{
	if(*p!=NULL)		
	{
				(*p)->next=NULL;
				(*p)->prev=NULL;
		free(*p);
		(*p)=NULL;
	}
}
void del(pData *pHead,int *same,int nb)
{
	int i=0;
	pData ptmp;
	pData pdel=NULL;
	for(i=0;i<nb;i++)
	{
		ptmp=(*pHead)->next;
		while(ptmp != (*pHead))
		{
			if(ptmp->data==same[i])
			{
				pdel=ptmp;
				ptmp->next->prev=ptmp->prev;
				ptmp->prev->next=ptmp->next;
				ptmp = ptmp->next;
				destory(&pdel);
				continue;
			}
			ptmp = ptmp->next;
		}
	}
}
void del_same(pData *pHeadA,pData *pHeadB)
{
	int same[N]={0};
	int i=0,nb=0;
	pData ptmp_1=NULL;
	pData ptmp_2=NULL;
	for(ptmp_1=(*pHeadA)->next;ptmp_1 != (*pHeadA);ptmp_1=ptmp_1->next)
	{
		for(ptmp_2=(*pHeadB)->next;ptmp_2 != (*pHeadB);ptmp_2=ptmp_2->next)
		{
			if(ptmp_1->data==ptmp_2->data)
			{
				same[i]=ptmp_1->data;	
				i++;  nb=i;
			}
		}
	}
	if(i==0)
	{
		printf("没有相同数字！\n");
		exit(0);
	}
	 del(pHeadA,same,nb);
	 del(pHeadB,same,nb);
}
int main()
{
	int nb=0,na=0;
	pData pHeadA=NULL;
	pData pHeadB=NULL;
	printf("分别输入每条连各存数的数目A B：\n");
	scanf("%d%d",&na,&nb);
	init_data(&pHeadA,sizeof(sData));
	init_data(&pHeadB,sizeof(sData));
	printf("请输入A链表中的数：\n");
	make_chain(pHeadA,na);
	printf("请输入B链表中的数：\n");
	make_chain(pHeadB,nb);
	del_same(&pHeadA,&pHeadB);
	printf("输出A链表剩余数字：\n");
	output(&pHeadA);
	printf("输出B链表剩余数字：\n");
	output(&pHeadB);
	return 0;

}
