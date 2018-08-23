#include<stdio.h>
int main()
{
	int a[10];
	int x,i;
	printf("十个数：\n");
	for(i=0;i<10;i++)
	{scanf("%d",&a[i]);
	}
	printf("一个数:\n");
	scanf("%d",&x);
	for(i=0;i<10;i++)
	{
		if(a[i]==x)
		{
			printf("a[%d]\n",i);
			break;
		}
		if(i==9)
		{
			printf("sorry,not found\n");
		}
	}
return 0;
}
