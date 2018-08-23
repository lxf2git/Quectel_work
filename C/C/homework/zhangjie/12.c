#include<stdio.h>
void chen();
int main()
{
	chen();
	return 0;
}

void chen()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		printf("%d*%d=%2d ",i,j,i*j);
		printf("\n");
	}
}
