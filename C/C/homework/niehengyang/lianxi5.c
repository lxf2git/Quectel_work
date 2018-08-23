#include<stdio.h>
int main()
{
	int i,j;
	char n;
	scanf("%d%c%d",&i,&n,&j);
	if(n=='+')
	{
	printf("%d\n",i+j);
	}
	if(n=='-')
	{
	printf("%d\n",i-j);
	}
	if(n=='*')
	{
	printf("%d\n",i*j);
	}
	if(n=='/')
	{
	printf("%d\n",i/j);
	}
	
}
