#include<stdio.h>
int main()
{
	int i,n=0,x;
	int a[10];
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	scanf("%d",&x);
	for(i=0;i<10;i++)
	{
		n=i;
		if(x==a[i])
		break;
		if(i==9&&x!=a[i])
		{
			n=-1;
			printf("sorry,not found");
		}
	}
		if(n>=0)
		printf("%d",n);
	return 0;
}
