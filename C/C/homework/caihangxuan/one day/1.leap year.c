#include<stdio.h>
int main()
{
int year;	
scanf("%d",&year);	
	if(year%400==0||year%4==0&&year%100!=0)
		printf("这是瑞年\n");
	else
		printf("这不是润年\n");

}
