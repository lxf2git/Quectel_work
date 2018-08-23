#include"14_main.h"

int main()
{
		int x;
		printf("请输入一个100～500之间的整数\n");
		scanf("%d",&x);
		if(x>=100&&x<=500)
		{
				divisors(x);
		}
		else
		{
				printf("不按套路出牌！请重新运行！\n");
		}
		return 0;
}
