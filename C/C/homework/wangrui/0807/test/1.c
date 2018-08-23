#include<stdio.h>

int main()
{
	int *point;
	int a=100;
	point = &a;
	printf("*&a:%d point:%p\n",*&a,point);

	return 0;
}
