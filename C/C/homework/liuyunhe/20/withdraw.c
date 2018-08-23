#include"main.h"

int withdraw(int sum1,int password)
{
		int b;
		int pass;
		printf("请输入密码：\n");
		scanf("%d",&pass);
		if(pass==password)
		{
			printf("输入取款金额\n");
			scanf("%d",&b);

			if(sum1>=b)
			{
				sum1=sum1-b;

			}
			else 
			{
				printf("余额不足");
			}
		}
		else
		{
				printf("密码不对\n");
		}
		return sum1;
}
