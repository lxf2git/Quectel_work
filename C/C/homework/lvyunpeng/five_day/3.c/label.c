#include"label.h"
int label()
{

	int a[10],i,n;
	printf("请输入10个数:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("请在输入一个数:\n");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if(n==a[i])
		{
			n=i;
			printf("下标:%d\n",n);
			return 0;
		}
		
	}

	printf("sorry,not found!\n");
	return 0;
}
