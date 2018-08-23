#include<stdio.h>

int main()
{
	int *point;//int a,char b int a1[5]  char fun(int);	
	int a=100;
	point = &a;
	//printf("&a:%p point:%p &point:%p\n",
	//				&a,point,&point);
	printf("a:%d *point:%d\n",a,*point);
	return 0;

}
