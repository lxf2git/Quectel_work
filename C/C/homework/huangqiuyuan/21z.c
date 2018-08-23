#include<stdio.h>
int main()
{
	int i,n,x;
	char a[50]={' '};
	scanf("%d",&n);
	if(n>=0)
{	for(i=0;i<50;i++)
	{
		x=n%10;
		n=n/10;
		a[i]=x+48;
		if(n==0)
		break;
	}
		for(;i>=0;i--)
		printf("%c",a[i]);
		printf("\n");
}	

	else
{
	n=-n;
	printf("-");
	for(i=0;i<50;i++)
	{
		x=n%10;
		n=n/10;
		a[i]=x+48;
		if(n==0)
		break;
	}
		for(;i>=0;i--)
		printf("%c",a[i]);
		printf("\n");
	return 0;
}
}
