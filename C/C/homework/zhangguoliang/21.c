#include<stdio.h>
int main()
{
	int a,i;
	char b[50]={};
	printf("输入数字:\n");
	scanf("%d",&a);
	if(a<0)
	{
		printf("-");
		a=-a;
	}
	for(i=0;a!=0;i++)
	{
		b[i]=a%10+48;
		a=a/10;
	}
	for(;i>=0;i--)
	{
		printf("%c",b[i]);
	}
	printf("\n");
	return 0;
}
