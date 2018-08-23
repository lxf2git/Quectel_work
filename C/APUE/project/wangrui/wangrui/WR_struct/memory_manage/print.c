#include"memory.h"

void print(pMem pHapp,pMem pHfre)
{
	pMem ptmp = NULL;
	int j = 0;
	ptmp = pHapp->next;
	printf("Free area:\n");
	while(ptmp != pHapp)
	{
		printf("index:%2d size:%2d\n",ptmp->index,ptmp->size);
		ptmp = ptmp->next;
		j++;
	}
	if(j == 0)
	{
		printf("Null\n");
	}
	j = 0;
	ptmp = pHfre->next;
	printf("Apply area:\n");
	while(ptmp != pHfre)
	{
		printf("index:%2d size:%2d\n",ptmp->index,ptmp->size);
		ptmp = ptmp->next;
		j++;
	}
	if(j == 0)
	{
		printf("Null\n");
	}
}
