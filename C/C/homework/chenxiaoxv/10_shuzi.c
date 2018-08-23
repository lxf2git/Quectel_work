#include<stdio.h>

int main()
{
	int i,j;
	j=0;
	for(i=0;i<1000;i++)
	{
		if(2==i%3&&3==i%5&&1==i%7)
		{
			printf("%d ",i);
			j++;
		if(j%6==0)
		
			printf("\n");
	
		}	
	}
	
return 0;


}
