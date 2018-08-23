#include<stdio.h>
int main()
{
    int i,j;
	scanf("%d",&i);
	if(i<501||i>99)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
					printf("%d  ",j);
		
		}
	}
	else
	{
			printf("error");
			main();
	}
	
	
	
	return 0;
}

