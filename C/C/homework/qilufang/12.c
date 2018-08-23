#include<stdio.h>
void biao();

int main()
{	
	biao();
	return 0;
}
void biao()
{
	int j=0,i,ji;
	for(i=1;i<10;i++)
	{
        j=0;
		while(j<i)
		{	j++;	
			ji=i*j;
			printf("%d*%d=%d  ",j,i,ji);
		}
			if(i==j)
			printf("\n");
	}
}
