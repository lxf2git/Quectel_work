#include<stdio.h>
int main()
{
	int *p;
	char str[]="hello";
	char *q=str;
	p = (int *)q;
	q++;//p++;   //不同类型的指针决定步长


	printf("*p:%c\n",*p);
	printf("*q:%c\n",*q);
	

		
	return 0;

}
