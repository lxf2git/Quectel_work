#include<stdio.h>
int main()
{
int a,i,j=0;
for(i=1;i<=1000;i++)
	{
		if(i%3==2&&i%5==3&&i%7==1)
		    {
					printf("%d ",i);
					j++;
					
					if(j%6==0)
					{
					 	printf("\n");
					}
			}
	}	
return 0;
}
