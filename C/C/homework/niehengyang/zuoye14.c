#include<stdio.h>
int main()
{
	int i,j;
	printf("请输入整数：");
	scanf("%d",&i);
	if(i>=0&&i<=9)
		printf("该整数有1位！");
		else
		{
	for(j=1;;j++)
	{
		i=i/10;
		if(i>=0&&i<=9)
		{

			printf("该整数有%d位！\n",j+1);
				return 0;
		}

	}
		}
}
