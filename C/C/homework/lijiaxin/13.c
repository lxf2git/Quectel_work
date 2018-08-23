#include<stdio.h>

int SUM();
int main()
{
	int sum;
	sum=SUM();
	printf("%d",sum);
	
	return 0;
}
int SUM()
{
	int j=0,count=1,i;
	for(;;count++)
	{
		for(i=j;i<4;i++)
		{
				
			if((5*count)%4==0)
			{
					count=(5*count)+1;
					j++;
					//printf("%d",count);
			}
			else
					break;
		}
		if(4==i)
			{
					return count;	
			}	
	}	
}
