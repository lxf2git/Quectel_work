#include<stdio.h>
extern int b;
extern int h;
	int a=0,sum=0;

	abc(year)
	{
		if(year%400 == 0)
		{
			a=1;
			b=1;
		}	
		else if(year%100 != 0)
		{
			if(year%4 == 0) {a=1;b=1;}
		}
		else
		{
			a =0;
			b=0;
		}
	}

int day_count(int year, int month)
{
//	int year,month,day=1;
		
//	printf("请输入您要判断的年 月 日：");
//	scanf("%d %d",&year,&month);
	int day=1;
        abc(year);

	if(a == 1)
	{
		printf("%d是润年！",year);
	}else
	{
		printf("%d不是润年！",year);
	}

	if(month>2)
	{
		switch(month%12)
		{
			case 3:sum = 59 +day;break;
			case 4:sum = 90 +day;break;
			case 5:sum = 120+day;break;
			case 6:sum = 151+day;break;
			case 7:sum = 181+day;break;
			case 8:sum = 212 +day;break;
			case 9:sum = 243+day;break;
			case 10:sum = 273 +day;break;
			case 11:sum = 304 +day;break;
			case 0:sum = 335 +day;break;
			
		}
		if(a)
		{
			sum = sum; 
			printf("sum = %d\n",sum);
		}
	}else
	{
		switch(month%12)
		{
			case 1:sum = day;break;
			case 2:sum =31 + day;break;
		}
	}
	h=month;
	printf("%d年%d月%d日 是第%d天！\n",year,month,day,sum);
	return sum;
}
