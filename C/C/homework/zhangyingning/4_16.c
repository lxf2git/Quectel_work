#include<stdio.h>

int month_1 = 0;    //定义全局变量来存当月天数

int put_year(year)
{
	int year_19 = 1900, leapyear_day = 0;
	for(year_19;year_19 <= year - 1;year_19++)//年减去一不求今年是否为润年
	{
		if(year_19 % 400 == 0 || year_19 % 4 == 0 && year_19 % 100 != 0 )
		{
			leapyear_day++;    //求出1900至今润月数
		}
	}
	return leapyear_day ;		//将润月数传回main
}

int put_month(int year, int month)
{
	int month_[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int month_for;
	int day_1 = 0;
	month_1 = month_[month - 1];    //定义全局变量来存当月天数
	for(month_for = 1;month_for < month;month_for++)
	{
		day_1 += month_[month_for - 1];//求今年的天数
	}
	if(year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
	{
		if(month >= 2)
		{
			++day_1;    //如润月加一
		}
	}
	day_1 = day_1 + 365 * (year - 1900 );//求1900至今月天数（今年加润月）
	return day_1;
}

void put(int day, int day_,int day_1)
{
	int xun = 0, yu, month_xun;
	yu = (day_ + day_1) % 7;//算出本月需要的空位
	for(;xun <= yu;xun++)
	{
		printf("     ");//空位循环输出
	}
	for(month_xun = 1;month_xun <= month_1;month_xun++ )
	{
		if(day == month_xun)	//判断是否为今天
		{
			printf("|%3d|",month_xun);
		}
		else 
		{
			printf("%5d",month_xun);
		}
		if((yu + month_xun + 1) % 7 == 0)//格式换行输出
		{
			printf("\n");
		}
	}
	printf("\n");
}

int main()
{
	int year, month, day, leapyear_day, day_1;
	printf("请输入年份以空格间隔");
	scanf("%d %d %d",&year,&month,&day);
	leapyear_day = put_year(year);//求润月数
	day_1 = put_month(year,month);//求天数
	put(day,leapyear_day,day_1);//输出
	return 0;
}



