#include<stdio.h>
int main()
{
	int i=1,n=0;
	for(i=1;i<=10000;i++)
	{
		if(i%3==2&&i%5==3&&i%7==1)
		{
			printf("%-8d",i);
			n++;
			if(n==6)
			{
				printf("\n");
				n=0;
			}
		}
	}
return 0;
}
