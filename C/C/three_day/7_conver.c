#include<stdio.h>

int main()
{
	int a=2;
	float b=3.5;
	printf("a:%d b:%f\n",a,b);	
	a = (float)b;
	printf("a:%f\n",(float)a);
	//printf("b:%f\n",b);	
	return 0;
}
