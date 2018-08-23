#include<stdio.h>
int main()
{
	int i,j,k,money,s=0;
	printf("请输入需要兑换的钱数：");
	scanf("%d",&money);
	for(i=0;i<=money;i++)
	{
	for(j=0;j<=money/2;j++)
	{
	for(k=0;k<=money/5;k++)
	{
		if(i+2*j+5*k==money)
		{
			s=s++;
		}
	//	printf("总共有%d种兑换方法！\n",s);
	}
	}
	}
	printf("总共需要%d种兑换方法！\n",s);
}
