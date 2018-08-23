#include<stdio.h>

int main()
{
	int year;
	printf("please input year:\n");
	scanf("%d",&year);
	if((year%4==0&&year%100!=0)||year%400==0)
			printf("the year %d is yunnian\n",year);
	else 
			printf("the year %d is not runnian\n",year);


}



