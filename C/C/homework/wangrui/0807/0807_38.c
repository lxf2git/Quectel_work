#include<stdio.h>

int * input();
int calculate(int * pt);
int main()
{
	int * p=NULL;
	int tail=0;
	p=input();
	tail=calculate(p);
	printf("tail_3:%d\n",tail);
}

int * input()
{
	int arr[2]={};
	int * pt=arr;
	printf("Z:\n");
	scanf("%d",&arr[0]);
	printf("N:\n");
	scanf("%d",&arr[1]);
	return pt;
}

int calculate(int * pt)
{
	int sum,i;
	int x=*pt;
	int n=*(pt+1);
	sum=x;
	for(i=1;i<n;i++)
	{
		sum=sum*x;
	}
	sum=sum%1000;
	return sum;
}
