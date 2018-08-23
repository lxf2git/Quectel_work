#include"display.h"

void display(int year,int mon)
{
	
	int week=0;//the first day 
	int days=0;//how much days this month has
	int i=1990,j=0;
	int total=1;
	for(i=1990;i<year;i++)
	{
		total += 365%7;
		if(((0 == i % 4)&&(0 != i % 100))
			||(0 == i % 400))  //leap year
		{
			total += 1;
			printf("leap year:%d\n",i);
			if(2 == mon)
			{
				days += 1;
			}
			if(mon > 2)
			{
				total += 1;   //   >>1        february  29 days
			}
		}
	}
	total = total % 7;
	printf("total1:%d\n",total);
	int a[7]={1,3,5,7,8,10,12};
	for(i=0;i<7;i++)
	{
		if(mon == a[i])
		{
			days += 31;
		}
		if(mon > a[i])
		{
	//		printf("total1.5 %d\n",total);
			total += 31;
		}
	}
	 int b[4] = {4,6,9,11};
	for(i = 0;i < 4;i++)
	{
		if(mon == b[i])
		{
			days += 30;
		}
		if(mon > b[i])
		{
			total += 30;
		}
	}
	if(2 == mon)
		days += 28;
	if(mon > 2 )
		printf("total:%d\n",total);
		total += 29;
	week += total%7;
	printf("total2:%d\n",total);
	printf("week2:%d\n",week);
	printf("sun mon tue wes thu fri sat\n");
	
	for(i = 1;i <= days;i++)
	{
		
		for(;week > 0;week--)
		{
			printf("    ");
			j++;
		}
		printf("%-3d ",i);
		j++;
		if(0 == j % 7)
			printf("\n");
		
	}
	printf("\n");
}
