#include"find.h"
void find(pMode pStart)
{
		printf("please input number:\n");
		int x,i,j;
		scanf("%d",&x);
		i = x%5;
		j = x>>3&7;
		struct data *ptmp = pStart->mod[i]->and[j];
		while(ptmp->next!=pStart->mod[i]->and[j])
		{
			if(ptmp->next->data == x)
			{
					printf("find number:%d\n",ptmp->next->data);
					return ;
			}
			ptmp = ptmp->next;
		}
		printf("don't find!\n");
}
