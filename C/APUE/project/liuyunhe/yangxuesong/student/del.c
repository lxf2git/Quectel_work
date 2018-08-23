#include"del.h"

pStu pdel(pStu pNode,int age)
{
	pStu pdel =pNode;
	while(pdel->next!=NULL)
	{
	if(pdel->next->age == age)
	{
		return pdel;
	}
		pdel= pdel->next;
	}
	return NULL;
}

int delet(pStu pHead,pStu(*pDelPosition)(pStu pNode,int age))
{
	int i;
	pStu pdel=NULL;
	pStu p=NULL;
	printf("请输入年龄\n");
	scanf("%d",&i);
	pdel = pDelPosition(pHead,i);
	if(pdel==NULL)
	{
		printf("**");
	}
	while(pdel!=NULL)
	{
		p=pdel->next;
		pdel->next = pdel->next->next;
		if(p!=NULL)
		{
		free(p);
		p==NULL;
		}	
		pdel = pDelPosition(pHead,i);
	}
}

void Del(sList slist,pStu pHead)
{
	slist.pDel = delet;
	slist.pDel(pHead,pdel);
}

