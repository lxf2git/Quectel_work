#include<stdio.h>
int main()
	{
	int a,b,c,p,x,y,z;
	  x=1,y=2,z=5,p=0;
	for(a=0;a<=100;a++)
		
		for(b=0;b<=50;b++)
			
			for(c=0;c<=20;c++)
		{	
			if (100==a*x+b*y+c*z)
			p=p+1;	
		}
			
		
		printf("p=%d\n",p);
	return 0;
	}
