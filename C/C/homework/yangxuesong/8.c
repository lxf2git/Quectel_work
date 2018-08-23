#include<stdio.h>
int main()
{	
	float i,y=0,x=100;
	for(i=0;i<12;i++)
	{	
		y=y+x;
		x=x/2;
	}	
	printf("%f\n",y);
	printf("%f\n",x);
	return 0;
}
