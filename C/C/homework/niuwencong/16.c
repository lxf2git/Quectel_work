#include<stdio.h>
int main()
{	
	int year,month,i,p,N,d;
	int day,n=0,f;
	for(;;)
	{
	printf("请输入您要查询的年份：\n");
	scanf("%d",&year);
	if(year<1899)
	printf("您输入的信息有误，请重新输入!\n");
	else break;
	}
	for(;;)
	{
	printf("请输入您要查询的月份\n");
	scanf("%d",&month);
	if(month>12||month<=0)
	printf("您输入的信息有误，请重新输入!\n");
	else break;
	}
	printf("\n");
	printf("  <  %d  >         <   %d   >\n",month,year);
	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n");
	for(i=1899;i<year;i++)
	{
		if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
			n++;
	}
	day=(year-1899)*365+n;
	if(month==1)
	{
		N=1;
	}
	else 
	for(i=1;i<month;i++)
	{
		day=day+30;
		if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
		{
			if(i==1)
			{
				day=day+1;
				N=-1;
				continue;
			}
		}
		else
		{
			if(i==1)
			{
				day=day+1;
				N=-2;
				continue;
			}
		}
		if(i==3||i==5||i==8||i==10)
		{
			day=day+1;
			N=0;
		}
		else if(i==7)
		{
			day=day+1;
			N=1;
		}
		else if(i==2)
		{
			if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
			{
				day=day-1;
				N=1;
			}
			else
			{
				day=day-2;
				N=1;
			}
		}
		else
		{
			day=day;
			N=1;
		}
	}
	p=day%7;
	f=day%7;
	for(i=1;i<=30+N+p;i++)
	{ 	
		if(f!=0)
		{
			printf("     ");
			f--;
			continue ;
		}
		else
			printf("%-5d",i-p);
		if(i%7==0)
			printf("\n");
	}
			printf("\n");
return 0;		
}
