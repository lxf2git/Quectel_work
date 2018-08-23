#include"student.h"

int Search(pStu pHead,int (*pFun_Search[2])(pStu,int))
{
	int i;		//choose
	int num;
	int Se_sus;
	pFun_Search[0] = Age_Search;
	pFun_Search[1] = ID_Search;

	printf("Search (num) by (1:age) or (2:ID)\n");
	scanf("%d%d",&num,&i);
	i=i-1;
	if(i!=0&&i!=1)
	{
		return -1;
	}
	Se_sus=pFun_Search[i](pHead,num);
	return Se_sus;
}		

int Age_Search(pStu pHead,int years)
{
	int Se_sus = -1;
	pStu ptmp = pHead;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		if(ptmp->age == years)
		{
			printf("ID:%d\n",ptmp->num);
			Se_sus = 0;
		}
	}
	if(Se_sus != 0)
	{
		printf("have no this age\n");
	}
	return Se_sus;
}

int ID_Search(pStu pHead,int id)
{
	int Se_sus = -1;
	pStu ptmp = pHead;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		if(ptmp->num == id)
		{
			printf("Age:%d\n",ptmp->age);
			return 0;
		}
	}
	printf("have no this id\n");
	return -1;
}
