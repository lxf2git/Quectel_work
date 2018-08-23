#include<stdio.h>
int main()
{
	int i,x;
	for(i=1;i<=9;i++)
	{
		for(x=1;x<=i;x++)
		{
			printf("%d*%d=%d\t",i,x,i*x);
			if(i==x)
			{
				printf("\n");
			}
		}
	}
}
