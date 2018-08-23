#include<stdio.h>
void add(int ,int );
//int add(int a,int b );//a=2 b=3

int main()
{
	int m=2,n=3;	
	add(m,n);
	printf("add:%p\n",add);

	return 0;
}

void  add(int a,int b )//a=2 b=3
{
	printf("result:%d",a+b);
	//return a+b;
}





