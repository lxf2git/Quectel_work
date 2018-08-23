#include<stdio.h>

void list();
int main()
{
	list();	
	return 0;
}

void list()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%d ",j,i,i*j);
		}
		printf("\n");
	}
}
