#include"main.h"

void queryMenu()
{
	int b;
	do
	{
		printf("请输入密码\n");
		scanf("%d",&b);
	}while(b!=password());
	printf("你的当前金额为%d\n",sum);
}
