#include"main.h"
void find(pMode pStart)
{
	printf("please input number:\n");
	int x,i,j,k=0;
	scanf("%d",&x);
	i= x%5;
	j=x>>3&7;
	pData ptmp=pStart->mod[i]->and[j];
	while(ptmp->next!=pStart->mod[i]->and[j])
	{
		if(ptmp->next->data==x)
		{
			k++;
  			printf("find number:%d\n",ptmp->next->data);
			//return ;
		}	
		ptmp = ptmp->next;
	}
	if(k==0)
		printf("don't find!\n");
}
