#include<stdio.h>

int main()
{
	display();
	return 0;
}

display()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%d ",i,i,i*j);
			if(!(i*j/10))
			    printf(" ");
		}
		printf("\n");
	}
}
