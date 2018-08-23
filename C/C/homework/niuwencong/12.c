#include<stdio.h>
int main()
{
	int i,j;
	for(i=0;i<=9;i++)
	{
		if(i==0)
			printf("   ");
		else
			printf("%-7d",i);
	}
	printf("\n\n");
	for(i=1;i<=9;i++)
	{
		printf("%-3d",i);
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%-3d",j,i,i*j);
			if(i==j)
			printf("\n");
		}
	}







	return 0;
}
