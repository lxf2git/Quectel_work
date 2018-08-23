#include"main.h"

void withdrawMenu()
{
	int a,b;
	do
	{
		printf("请输入密码\n");
		scanf("%d",&a);
	}while(a!=password());
	printf("请输入取出金额\n");
	scanf("%d",&b);
	sum=sum-b;
}
