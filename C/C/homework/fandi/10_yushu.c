#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x,i;	
	x=0;
	for(i=1;i<=1000;i++)
	{
		if(i%3==2&&i%5==3&&i%7==1)
		{
			x+=1;
			printf("%d\t",i);
			if(x%6==0)
			{
				printf("\n");
			}
		}
	}
	return 0;
}
