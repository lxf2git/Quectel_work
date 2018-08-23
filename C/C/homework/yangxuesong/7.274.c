#include<stdio.h>
int main()
{
	char a,b;
	int data1,data2;
	scanf("%d%c%d",&data1,&a,&data2);
	if(a=='+')
	b=data1+data2;
	if(a=='-')
	b=data1-data2;
	if(a=='*')
	b=data1*data2;
	if(a=='/')
	b=data1/data2;
	printf("%d",b);
	return 0;
}
