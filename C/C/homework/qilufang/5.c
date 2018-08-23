#include<stdio.h>
 
int main()
{
	int a,b,c;
	int n=0;
	for(a=0;a<=20;a++)
	{
		for(b=0;b<=50;b++)
		{
			for(c=0;c<=100;c++)
			{
				if(5*a+2*b+c==100)
				{
					n+=1;
				}
			}
		}
	
	}
	printf("n=%d\n",n);
	return 0;
}
