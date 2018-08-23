#include"sort.h"

int judge_num(pNode pHead)
{
	int max = 0;
	int num;
	pNode ptmp = pHead;

	for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
	{
		num = judge_deal(ptmp->data);
		if(num > max)
		{
			max = num;
		}
	}
	return max;
}

int judge_deal(int n)
{
	int i=1,j=0;
	while(n/i != 0)
	{
		i=i*10;
		j++;
	}
	return j;	
}
