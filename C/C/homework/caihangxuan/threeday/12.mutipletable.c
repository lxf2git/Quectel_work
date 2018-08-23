#include<stdio.h>
void huanhang(int first,int second);

int main()
{	
	int first,second;
	for(second=0;second<=9;second++)
	{
		
		for(first=1;first<=second;first++)
		{
	
			huanhang(first,second);
		}
	}
		
}

void huanhang(int first,int second)
{
	if(first==second)
		printf("%d*%d=%d\n",first,second,first*second);
	else
		printf("%d*%d=%d ",first,second,first*second);
		
}
