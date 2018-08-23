#include<stdio.h>

int main()
{
	int a,year;
	printf("please enter year:");
	scanf("%d",&year);
	
	if(year%4==0)
		{
			if(year%100==0)
				printf("bu shi run nian\n");
			else
				printf("shi ru nian\n");
		}
	else if(year%400==0)
			printf("shi run nian\n");
	else
			printf("bu shi ru nian\n");
	return 0;
}
