#include"main.h"


pStu pdelposition(pStu pNode,int age)
{	
	
	while(pNode->next!=NULL)
	{
		if(pNode->next->age==age)
		{
			return pNode;
		}
		else
			pNode=pNode->next;
	}
return pNode;	
}


int pdelete(pStu pHead,pStu (*pDelPosition)(pStu pNode,int age))
{	
	int data;
	printf("输入要删除的年龄!\n");
	scanf("%d",&data);
	pStu ptmp=pHead;
	pStu ptmp2;
	while(ptmp->next!=NULL)
	{
		ptmp=pDelPosition(ptmp,data);
		if(ptmp->next==NULL)
		{
			return 0;
		}
		else
		{
		ptmp2=ptmp->next;
		ptmp->next=ptmp->next->next;
		free(ptmp2);
		ptmp2=NULL;
		}	
	}
return 0;
}

void delete_chain(pStu phead,sList pl)
{

	pl.pDel=pdelete;

	
	pl.pDel(phead,pdelposition);
}
