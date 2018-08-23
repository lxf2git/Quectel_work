#include"delete.h"
#include"print.h"

int  del(pStu phead, pStu(*pdelsite)(pStu pnode, int age))
{

	pStu p=NULL;
	int age;
	printf("please input age you delete:");
	scanf("%d",&age);
	p=phead;
	pStu pdel,pnn;
	pnn = phead;
	pdelsite = del_age;
	while(NULL != (pdel=(*pdelsite)(phead,age)))
	{
		while(pnn->next != pdel)
		{
			pnn = pnn->next;
		}
		pnn->next = pdel->next;
		pdel->next = NULL;
		destory_node(&pdel);
	}
//	printf("被删除的\n");
//	print(phead);
	return SUC;
}

pStu del_age(pStu phead, int age)
{
	pStu ptmp=NULL;
	ptmp = phead;
	while(ptmp->next != NULL)
	{
		if(ptmp->age == age)
		{
			printf("delete node:id:%d age:%d \n",ptmp->num,ptmp->age);
			return ptmp;
		}
		ptmp = ptmp->next;
	}
	return NULL;
}
