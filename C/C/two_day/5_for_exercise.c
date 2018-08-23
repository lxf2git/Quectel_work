#include<stdio.h>

int main()
{
	int n;
	for(;;)
	{
		printf("please input a integer:\n");	
		scanf("%d",&n);
		if(n==0)
		{
			break;//出口 switch 循环
		}
		else
		{
			printf("平方：%d\n",n*n);//n^n
		}
	}
	return 0;
}
