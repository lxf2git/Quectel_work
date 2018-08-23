#include<stdio.h>

int main()
{
	int a,b,c,max,min;
	printf("请输入三个数：");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
	{max=a,min=b;}
	else
	{max=b,min=a;}
	if(c>max)
	max=c;
	if (c<min)
	min=c;
	printf("%d",max-min);
	return 0;
	
}
