#include<stdio.h>
int main()
{
	float h,s,t ;
	h = 100;
	s = 0;
	for(t=1;t<=10;t++)
	{
	h=h/2;
	s=s+h*2;
	}
	s=s+100;
	printf("%f\n%f\n",s,h);
	return 0;
	
}
