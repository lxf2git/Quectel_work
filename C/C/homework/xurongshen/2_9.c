#include<stdio.h>

int main()
{
	int money,num=0,a=0,m;
	printf("请输入要买的钱数：");
	scanf("%d",&money);
	//printf("\n请输入个m空瓶可兑换一个瓶子：");
	//scanf("%d",&m);
	//num = money;

	while(money>=1)
	{
		a = money%2;
		//money = money/2;
		num += money+a;
		money = money/2;
		
	}
	printf("最多可喝到%d瓶汽水\n",num);
	return 0;
}
