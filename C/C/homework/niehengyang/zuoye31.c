#include<stdio.h>
int kill(int a[]);
int main()
{
	int i,j,k;
	int a[10];
	for(i=0;i<10;i++)
	{
		a[i]=i+1;
	}
	kill(a);
}
int kill(int a[])
{
	int i=0,j=0,p=0;	
	for(;;)
	{
		for(i=0;i<10;i++)
		{
		if(a[i]>0)
		{
		p=p+1;
		if(p%3==0)
		{
			a[i]=0;
			j=j+1;
		}

		}
		}
		if(j==9)
		break;
	
		}
		for(i=0;i<10;i++)
		{
         	printf("%d",a[i]);
		}
		printf("\n");
		printf("可见不为零的数就是存活的！");
		printf("\n");
}
