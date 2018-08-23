#include<stdio.h>


void calculate();
int main()
{
	calculate();
	return 0;
}

void calculate()
{
	int i,j,k;
	j=1;
	k=1;
	for(i=1;i<5;i++)
	{	
			
		
			if((j*5+1)%4==0)
			{
				j=(j*5+1)/4;
			}
			else
			{
				k++;
				j=k;
				i=0;
			}
		
	}
	j=j*5+1;
	printf("%d\n",j);
}
