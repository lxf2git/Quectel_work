#include"student.h"

pStu input()
{
	pStu pIn;
	Init_Stu(&pIn);
	pIn->pstu_input = stu_input;
	(*pIn->pstu_input)(pIn);
	return pIn;
}
int stu_input(struct student *pIn)
{
	printf("input id age\n");
	scanf("%d%d",&pIn->num,&pIn->age);
	return 0;
}


int Insert(pStu pHead,pStu pIn,
				int (*pIDFind)(pStu,pStu),
				pStu (*pInsertPosition)(pStu,pStu))
{
	pStu pPos = NULL;
//	pIDFind = IDFind;	//init-------------
	if(-1 == (pIDFind)(pHead,pIn))
	{
		Destory_Stu(&pIn);
		printf("ID repeat !\n");
		return -1;
	}
//	pInsertPosition = InsertPos;	//init--
	pPos = (pInsertPosition)(pHead,pIn);
	pIn->next = pPos->next;
	pPos->next = pIn;
	return 0;
}

pStu InsertPos(pStu pHead,pStu pIn)
{
	pStu ptmp = pHead;
	while(ptmp->next != NULL)
	{
		if(ptmp->next->num >= pIn->num)
		{
			return ptmp;
		}
		ptmp = ptmp->next;
	}
	return ptmp;
}

int IDFind(pStu pHead,pStu pIn)
{
	pStu ptmp = NULL;
	for(ptmp = pHead->next;ptmp != NULL;ptmp = ptmp->next)
	{
		if(ptmp->num == pIn->num)
		{
			return -1;
		}
	}
	return 0;
}
