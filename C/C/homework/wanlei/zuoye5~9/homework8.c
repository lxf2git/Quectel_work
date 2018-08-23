#include<stdio.h>

int main()
{
	int h=100;
	int i;
	float k,s,m;
	s=100;
	k=1;
	for(i=1;i<=9;i++)
	{
		k=k*0.5;
		s=s+(h*k)*2;	
	}
	m=h*k*0.5;
	printf("%f\n",m);
	printf("%f\n",s);
	return 0;	
}
