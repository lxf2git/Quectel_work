#include<stdio.h>
int main() 
{
	int i,n=0; 
	for(i=1;i<=1000;i++)
			if((i%7==1)&&(i%5==3)&&(i%3==2))
			{
			printf("%d ",i);
			n++;
			if(n%6==0)
					printf("\n");
}}
