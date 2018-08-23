#include<stdio.h>
int lei(int i,int n);
int main()
{
		int i,n=0;
		for(i=1;i<=1000;i++)
		{
				if(i%3==2&&i%5==3&&i%7==1)
				{
						n++;
						lei(i,n);
						if(n==6)n=0;
				}

		}
		printf("\n");
}
int lei(int i,int n)
{
				if(n<6)
				printf("%d ",i);
				else
				{		
				printf("%d\n");
				}
}
