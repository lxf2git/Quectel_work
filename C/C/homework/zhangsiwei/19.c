#include<stdio.h>
int main()
{
	int a[10],x,i,j;
	printf("请输入10个数：\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("请输入x：");
	scanf("%d",&x);
	
	j=0;
	for(i=0;i<10;i++)
	{
		if(x==a[i])
		{
				printf("%d\n",i);
				break;
		}
		if(x!=a[i])
		{
				j++;
		}
		if(j==9)
		{
				printf("sorry,not found！\n");
				break;
		}
	}







	return 0;
}
