#include<stdio.h>
int main()
{
int year,i;

scanf("%d",&year);
i=year%100;
	if(i!=0)
	{
		i=year%4;
		if(i==0)
			printf("这是瑞年");
		else
			printf("这不是润年");
	}
	else
	{
		i=year%400;
			
		if(i==0)
			printf("这是瑞年");
		else
			printf("这不是润年");
	}

}
