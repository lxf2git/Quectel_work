#include"./insert.h"
pStu find_max(pStu pnew)
{
	pStu stmp=pHead;
	while(stmp->next != NULL)
	{
			if(stmp->next->id >= pnew->id)
			{
				return stmp;
			}
			stmp=stmp->next;
	}
	return stmp;
}
int inser_back(pStu pIn,pStu pPos)
{
	if(pPos==NULL||pIn==NULL)
	{
		return -1;
	}
	pIn->next=pPos->next;
	pPos->next=pIn;
	return 0;
}

