#include<stdio.h>
int main()
{
	int a,b,c,n,t;
	t=0;
	
		
			for(a=0;a<=100;a++)
			{
				for(b=0;b<=50;b++)
				{
					for(c=0;c<=20;c++)
					{
						n=a+2*b+5*c;
						if(n==100)
						{
							t++;
						}
					}
				}
			}
		
	printf("%d\n",t);
	return 0;
}
