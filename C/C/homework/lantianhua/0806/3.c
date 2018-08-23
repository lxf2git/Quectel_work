#include<stdio.h>

int main()
{	int i;
	int x;
	int a[500]={};
	printf("please input a number\n");
	scanf("%d",&x);
	for(i=0;i<500;i++)
	{
		a[i]=x%2;
		   x=x/2;
		printf("%d",a[i]);
		if(x==0)
		break;
		

	}
		return 0;
}	
