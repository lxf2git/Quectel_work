#include<stdio.h>

int main()
{
	int ping=0,i,money;
	printf("please enter money:");
	scanf("%d",&money);
	while(money>=1)
	{
     for(money;money>0;money--)
		{
			ping++;
			if(ping%2==0)
				ping++;

		}
	}
	printf("%d\n",ping);
} 


