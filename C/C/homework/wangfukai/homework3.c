#include<stdio.h>
int main()
{
	int a;
	printf("输入数字：");
	scanf("%d",&a);
	if(a==1)
		printf("monday");
	else if(a==2)
			printf("tuesday");
	else if(a==3)
			printf("wednesday");
	else if(a==4)
			printf("星期四");
	else if(a==5)
			printf("friday");
	else if(a==6)
			printf("星期六");
	else if(a==7)
			printf("sunday");
	else printf("输入数字错误");

	return 0;
}
