#include<stdio.h>//shuru ten number find same
int main()
{
	int a[10],i,n=0;
	for(i=0;i<10;i++)
	{
	scanf("%d",&a[i]);
	}
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if(n==a[i])
		{
			printf("%d\n",i);
			break;
		}
		if(i==9)
		printf("sorry,not found\n");
	}
}
