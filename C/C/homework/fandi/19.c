#include<stdio.h>
int main()
{
	int a[10],x,i,z;
	printf("输入数字:\n");
	scanf("%d",&x);
	printf("输入数组:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		if(a[i]==x)
		{
			z=i;
			printf("下标为:%d\n",z);
			return 0;
		}
	}
	printf("sorry,not found\n");
	return 0;
}
