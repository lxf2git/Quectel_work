#include<stdio.h>
int main ()
{
	int n=1,i;
	while((n-1)%5!=0)
	{				
	 n++;
	}
	for(i=1;i<=5;i++)
		{
			n=(n*5+1);			 
		}
printf("%d\n",n);    
return 0;
}
