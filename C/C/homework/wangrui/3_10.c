#include<stdio.h>

void math();
void judge(int i);
void type(int n);
int i,n;
int main()
{
	math();
	printf("\n");
	return 0;
}

void math()
{	
	n=0;
	for(i=1;i<=1000;i++)
	{
		judge(i);
	}
}

void judge(int i)
{
	if((i%3==2)&&(i%5==3)&&(i%7==1))
	{	
		n++;
		type(n);
	}
}

void type(int n)
{
	printf("%d ",i);
	if(n==6)printf("\n");
}
