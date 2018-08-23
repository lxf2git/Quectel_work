#include<stdio.h>
int main()
{
	int a[10];
	input(a);
	ch(a);
}

int input(int a[])
{	
	int i;
	printf("输入10个数:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
}

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
