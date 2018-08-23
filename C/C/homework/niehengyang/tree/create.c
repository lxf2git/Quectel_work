#include"main.h"


void build_tree(pTr ptmp,pTr pHead)
{	
	if(ptmp->data<=pHead->data)
	{
		if(pHead->lc==NULL)
		{
			pHead->lc=ptmp;
			ptmp->parent=pHead;
		}
		else
		{
			build_tree(ptmp,pHead);
		}
	}
	else
	{
		if(pHead->rc==NULL)
		{
			pHead->rc=ptmp;
			ptmp->parent=pHead;
		}
		else
		{
			build_tree(ptmp,pHead);
		}
	}
		
}

void min_tree(pTr p_min)
{
	if(p_min->lc!=NULL)
	{
		min_tree(p_min->lc);
	}
	printf("%d",p_min->data);
	if(p_min->rc!=NULL)
	{
		min_tree(p_min->rc);
	}
	
}

void show_tree(pTr pHead)
{
	pTr p_min=pHead;
	min_tree(p_min);
}

void create_tree(pTr pHead)
{
	int count;
	int i;
	pTr ptmp=pHead;
	//create memory(pnew_tree,sizeof(sTr));
	printf("plese input how much data you need\n");
	scanf("%d",&count);
	int a[count];
	printf("please input the data\n");
	for(i=0;i<count;i++)
	{
		scanf("%d",&a[i]);
	}
	pHead->data=a[0];
	for(i=1;i<count;i++)
	{
		ptmp->data=a[i];
		build_tree(ptmp,pHead);
	}
	show_tree(pHead);
}
