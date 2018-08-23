#include"yueshu.h"

void yueshu()
{
		int a=2,i,j=0,sum=0;
		printf("输入100～500之间数：");
		scanf("%d",&i);
		if(i>=100&&i<=500)
		{
				while(a<i)
				{
						if(i%a==0)
						{
								j++;
								printf("%d\n",a);
								sum+=a;
						}
						a++;
				}
				printf("一共有约数%d个，何为：%d\n",j,sum);
		}
		else 
		{
				printf("数不对");
		}
}
