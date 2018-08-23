#include<stdio.h>
int add(int ,int );
//int add(int a,int b );//a=2 b=3

int main()
{
	int ret = add(2,3);
	printf("add:%p\n",add);
	printf("ret:%d\n",ret);	

	return 0;
}

int add(int a,int b )//a=2 b=3
{
	return a+b;

}
