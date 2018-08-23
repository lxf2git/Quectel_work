#include<stdio.h>

int main()
{
	int x,i;
	for(i=1;i<10;i++)
	{
		for(x=1;x<=i;x++)
		{
			
			printf("%d*%d=%d  ",i,x,i*x);
		}

			printf("\n");
	}
		return 0;
}
