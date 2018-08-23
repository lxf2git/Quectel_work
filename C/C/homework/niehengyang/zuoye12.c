#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{	
			k=i*j;
			if(k<10)
			printf("%d*%d=0%d,",j,i,k);
			else	
			printf("%d*%d=%d,",j,i,k);
			if(i==j)
			{
				printf("\n");
			}
		}
	}

}
