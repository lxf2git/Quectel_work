#include<stdio.h>

int main()
{
	float i,b,a;
	int t;
	a=0;
	i=100.0;
	b=100.0;
	for(t=0;t<10;t++)
	{
		a=i+i/2+a;
		i=i/2;	
		b=b/2;

	}
	printf("共下落%f米。\n",a);
	printf("第10次反弹%f米。\n",b);
	return 0;
}
