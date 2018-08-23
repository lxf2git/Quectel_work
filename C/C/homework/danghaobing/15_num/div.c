#include"dn.h"
void div()
{
		int x,i,count=0,sum=0;
		printf("请输入一个数:");
		scanf("%d",&x);
		printf("以下是所有约束:\n");
		for(i=2;i<x;i++)
		{
			if(x%i==0)
			{
					count++;
					sum+=i;
					printf("%d\n",i);
			}

		}
		printf("约数的个数为：%d\n约束的和为：%d\n",count,sum);
}
