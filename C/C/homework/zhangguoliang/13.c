#include<stdio.h>
#include<stdlib.h>
int main()
{
	int y;
	int i,j;

	for(i=0;;)
	{
		i++;
		y=i;
		j=0;
		while((y*5/4+1)%5==1)
		{	y=y/4*5+1;
			j++;
		
		
		if(j==5)
		{
		printf("至少%d条鱼\n",y);
					
		exit(0);
		}
		}
	}
	return 0;
}
