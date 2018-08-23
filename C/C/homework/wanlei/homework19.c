#include<stdio.h>

int main()
{
	int x,n,i;
	int a[10];
	printf("please input ten number\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("please input x\n");
		scanf("%d",&x);
		n=10;
	for(i=0;i<10;i++)
	{
		if(x==a[i])
		{
			n=i;	
		    printf("%d\n",n);
			break;
		}
		else if(i==9&&n==10)
			printf("sorry,not found\n");
	}
	return 0;
}
