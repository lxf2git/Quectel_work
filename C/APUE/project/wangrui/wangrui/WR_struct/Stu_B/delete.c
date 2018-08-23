#include"student.h"


int Del(pStu pHead,pStu (*pDelPosition)(pStu,int))
{
	int years;
	int ret = -1;
	pStu pPos = NULL;
	pStu pdel = NULL;
	printf("delete student by age:\n");
	scanf("%d",&years);
//	pDelPosition = DelPos;	//init-----
	while(NULL != (pPos=(*pDelPosition)(pHead,years)))
	{
		pdel = pPos->next;
		pPos->next = pdel->next;
		pdel->next = NULL;
		Destory_Stu(&pdel);
		ret = 0;
	}
	return ret;
}

pStu DelPos(pStu pHead,int years)
{
	pStu ptmp = NULL;
	for(ptmp = pHead;ptmp->next != NULL;ptmp = ptmp->next)
	{
		if(ptmp->next->age == years)
		{
			return ptmp;
		}
	}
	return NULL;
}
