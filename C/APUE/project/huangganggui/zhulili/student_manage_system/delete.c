#include"delete.h"

void delete_node_age(pStu pHead,int Age)
{
	pStu ptmp = pHead;
	pStu pdel = NULL;	
	int flag = 0,n=0;
while(ptmp != NULL)
{	
	if(ptmp->next->age == Age)
	{	
		flag = 1;
		if(flag == 1)
		{		
			pdel = ptmp->next;
			ptmp->next = pdel->next;
			pdel->next = NULL;
			ptmp = ptmp->next;	
		}
					
	}			
}	
	if(flag == 0)
		printf("没有符合的年龄,无法删除!\n");		
}

pStu pDelposition(pStu pHead, int age) 
{
	delete_node_age(pHead,age);
}

int pdel(pStu pHead, pStu (*pDelPosition)(pStu pHead, int age) )
{
	int Age;
	printf("请输入要删除的年龄:");
	scanf("%d",&Age);
	pDelposition(pHead,Age);	
}

void delete_node(pStu pHead)
{
	pStu (*pDelPosition)(pStu pNode, int age);
	pDelPosition = pDelposition;
	pdel(pHead,pDelposition);	
}
