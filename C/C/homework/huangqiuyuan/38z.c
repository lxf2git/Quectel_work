#include<stdio.h>

int main()
{
	int n,m,x,i,f;
	printf("输入一个整数：");
	scanf("%d",&n);
	printf("你想让它乘几次方：");
	scanf("%d",&m);
	x=n;
	for(i=0;i<m-1;i++)
	{
	
	n=x*n;
	}
	if(i==0)
	n=1;
	printf("结果是：%d\n",n);

	f=n%1000;
	printf("后三位是:%d\n",f);

	return 0;
}
