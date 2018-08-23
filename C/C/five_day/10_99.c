#include<stdio.h>

int main()
{
	int i,j;
	for(i=1,j=1;i<=9&&j<=9;i++)
	{
		printf("  %d*%d",i,j);
		printf(i*j<10?"= ":"=");
		printf("%d",i*j);
		if(i==j)
		{
			printf("\n");
			j++;
			i = 0;
		}
	}	
	return 0;
}
