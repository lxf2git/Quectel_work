#include<stdio.h>
 
int main()
{
	int i;
	float a=100.0,b=0.0;
	for(i=10;i>0;i--)
	{
	b=b+a;
	a=a/2;
	}	
	printf("a=%f b=%f\n",a,b);

	return 0;
}

