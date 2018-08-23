#include<stdio.h>

int main()
{
	int i, flag = 0;

	for(i = 1 ;i <= 1000 ;i++)
	{
			if(i%3 == 2 && i%5 == 3&&i%7 == 1)
			{
					printf(" %5d ",i);
					flag++;
					if(flag%6 == 0)
							printf("\n");
			}
	}

	printf("\n");
}
