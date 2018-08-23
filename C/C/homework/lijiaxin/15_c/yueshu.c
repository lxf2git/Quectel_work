#include"app_num.h"

void yueshu(int i)
{
		int j, count=0, sum=0;
		for(j=2;j<=i/2;j++)
		{
				if(0==i%j)
				{
						printf("%d\n",j);
						count++;
						sum+=j;
				}
			
		}
		printf("约束个数:%d,约束总和:%d\n",count,sum);

}
