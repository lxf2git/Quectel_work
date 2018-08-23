#include<stdio.h>
int main()
{
	int a[10];
	int i,n,x;
	printf("输入10个数:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("输入数:\n");
	scanf("%d",&x);
	for(i=0;i<10;i++)
	{
		
		if(x==a[i])
		{	n=i;
			printf("下标:%d\n",n);
			return 0;
		}
	}
	printf("sorry,not found!\n");
}
