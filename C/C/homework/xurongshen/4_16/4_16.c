#include<stdio.h>
void diff(int year,int month);
int day_count();
void print(int,int);

	int m=0,n=0;
	int b=0;//b判断是否为润年 1是，0否
	int h=0;//h判断月份有几天
	int dayyy=0;//该月的天数
int main()
{
	int d, a=0, year, month,day1,brr[2];

	printf("请输入你要显示的年，月（格式：年 月）");
	scanf("%d%d",&year,&month);
	day1 = day_count(year,month);

//	brr[0] = year;
//	brr[1] = 0;
    diff(year,month);
	day1 = day1+m*366+n*365;
	printf("day1=%d\n",day1);
	a = (day1-1)%7;
	if(b == 1)
		a -= 1;
	printf("a=%d\n",a);
	printf("brr[1]=%d\n",n);
	print(dayyy,a);
	return 0;
}

void diff(int year,int month)
{
//	year = brr[0];

	for(;year >= 1900;year--)
	{
		if((year%400 == 0) || ((year%100 != 0) && (year%4 == 0)))
		{
			m++;
		}else 
		{
			n++;
		}
	//	else
	//		n++;
	
	}
//	n = year-1900-m;
//	brr[0] = m;
//	brr[1] = n;
	if(month<2)
	{
		dayyy=31;
	}else
	{
		if(month == 2)
		{
			if(b == 1)
			{
				dayyy=29;
			}
			else
				dayyy=28;
		}
		else
		{
			switch(month)
			{
				case 4:{dayyy=30;break;}
				case 6:{dayyy=30;break;}
				case 9:{dayyy=30;break;}
				case 11:{dayyy=30;break;}
				default:dayyy=31;break;
			}
		}
		
	}
	printf("m=%d\n",m);
	printf("n=%d\n",n);
}
