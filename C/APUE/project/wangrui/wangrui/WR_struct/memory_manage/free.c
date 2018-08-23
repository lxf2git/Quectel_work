#include"memory.h"
extern sRec *pHrec[N];
extern int rec;
int free_mem(pMem pHapp,pMem pHfre)
{
	int num;
	printf("Free what time:\n");
	scanf("%d",&num);
	if(pHrec[num] == NULL||pHrec[num] == 0||num<=0||num>N-1)
	{
//		printf("if 1\n");
		return FAIL;
	}
	else
	{
//		printf("else 1\n");
		if(pHrec[num]->next == pHrec[num])
		{
//			printf("if 2\n");
			return FAIL;
		}
		else
		{
//			printf("else 2\n");
			return_mem(pHapp,pHfre,pHrec[num]);
		}
	}
	return SUC;
}
void return_mem(pMem pHapp,pMem pHfre,pRec phrec)
{
	pRec ptmp = phrec;
	for(ptmp=phrec->next;ptmp != phrec;ptmp = phrec->next)
	{
//		printf("a\n");
//		printf("ptmp->pdata:%d\n",ptmp->pdata->size);
		insert_mem_apply(pHapp,ptmp->pdata);
//		printf("b\n");
		ptmp->pdata = NULL;
		ptmp->next->prev = phrec;
		phrec->next = ptmp->next;
		ptmp->next = NULL;
		ptmp->prev = NULL;
//		delete_rec_node(&ptmp);
	}
}
int insert_mem_apply(pMem pHapp,pMem pnew)
{
	pMem ptmp = NULL;
	pnew->next->prev = pnew->prev;
	pnew->prev->next = pnew->next;
	pnew->next = NULL;
	pnew->prev = NULL;
//	printf("x\n");
	for(ptmp = pHapp->next;ptmp != pHapp;ptmp = ptmp->next)
	{
		if(ptmp->index == pnew->index)
		{
			ptmp->size = ptmp->size+pnew->size;
//			delete_mem_node(&pnew);
			return SUC;
		}
	}
//	printf("x\n");
	ptmp = NULL;
	for(ptmp = pHapp->next;ptmp != pHapp;ptmp = ptmp->next)
	{
		if(ptmp->index > pnew->index)
		{
			insert_mem_back(ptmp,pnew);
			return SUC;
		}
	}
//	printf("x\n");
	return FAIL;
}
