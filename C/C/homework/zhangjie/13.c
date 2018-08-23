#include<stdio.h>

int main()
{
	int sum=6,i=0,j=0;
	while(j<4)
	{
		
		if(sum%4==0&&(sum-1)%5==0)
		{
			sum=sum/4*5+1;
			j++;
		}
		else
		{
			i++;
			sum=i;
			j=0;
		}
	}
	printf("%d\n",sum);	
	return 0;
}

