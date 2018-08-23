#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(int ,int );
int mul(int ,int );
int sum(int ,int );
int div(int ,int );


int main(int argc,int argv[])
{
	int a,b;
	char ch;
	int ret;
	a=scanf("%d",&argv[0]);
	ch=scanf("%c",&argv[1]);
	b=scanf("%d",&argv[2]);
	int *p(int ,int );
	switch(ch)
	{
	case('+'):
		p=add;
		break;
	case('-'):
		p=mul;
		break;
	case('*'):
		p=sum;
		break;
	case('/'):
		p=div;
		break;
	default:
		printf("inut error!\n");
		exit(0);
	
	}
	ret=*p(a,b);
	printf("%d",ret);

}


int add(int a,int b)
{
	return(a+b);
}
int mul(int a,int b)
{
	return(a-b);
}
int sum(int a,int b)
{
	return(a*b);
}
int div(int a,int b)
{
	return(a/b);
}
