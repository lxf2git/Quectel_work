#include "count.h"

void count()
{
	int i,j;
	do
	{
		j=0;
		printf("请输入正数\n");
		scanf("%d",&i);
			while(i/10!=0)
			{
				i=i/10;
				j++;
			}
				printf("%d\n",j+1);	
	}while(i>0);
}
