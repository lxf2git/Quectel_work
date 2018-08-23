#include<stdio.h>

int main ()
{
	int i,j,x,m,a[10];
	j=0;
	printf("请输入十组数据");
	for(i=0;i<10;i++)
	{		
	scanf("%d",&a[i]);
	}
	printf("请输入X:");
	scanf("%d",&x);
	for(i=0;i<10;i++)
	{
	if(x==a[i]&&j==0)//查找数据是否相等
	{	
	m=i;
	printf("%d\n",m);
	j=j+1;
	}
	}
	if(j==0)
	{
	printf("sorry,not found\n");
	}
return 0;
}
