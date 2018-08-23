#include<stdio.h>
#include<stdlib.h>
	
int main()
{
	int i,j;
	int sum=0;
	for(i=1;;i++)
	{
		j=0;
		sum=i;
		while((sum*5/4+1)%5==1)
		{
			sum=sum/4*5+1;
			j++;
			if(j==5)
			{
				printf("至少%d条鱼\n",sum);
				return 0;
			}
		}
	}
}

