#include"ch.h"
int ch(int a[])
{
	int x,i,n;
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
