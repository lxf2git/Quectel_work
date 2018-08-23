#include<stdio.h>
#include<stdlib.h>
void arithmetic(unsigned int Feb,unsigned int month);
unsigned  year,day,month,day,Feb;
int main()
{
	//unsigned month ,day;
	printf("please input year,month,day:\n");
	scanf("%u%u%u",&year,&month,&day);
	unsigned int  array[12]={0};
	if(month%2==0)
			array[month-1]=day;
	if(day>31||array[1]>29||array[month-1]>30)
	{
			printf("in put error\n");
			exit(-1);
	}
	if((year%4==0&&year%100!=0)||year%400==0)
	{	
			Feb=29;
			arithmetic(Feb,month);
	}
	else
	{
			if(month==2&&day>=29)
			{
			printf("error \n");
			exit(-1);
			}
			Feb=28;	
			arithmetic(Feb,month);
	}
	exit(0);
}
void arithmetic(unsigned int Feb,unsigned int month )
{	
		unsigned int sum;
			switch(month)
			{
				case 1:sum=day;break;
				case 2:sum=31+day;break;
				case 3:sum=31+Feb+31+day;break;
				case 4:sum=31+Feb+31+30+day;break;
				case 5:sum=30+Feb+31+30+31+day;break;
				case 6:sum=30+Feb+31+30+31+30+day;break;
				case 7:sum=30+Feb+31+30+31+30+31+day;break;
				case 8:sum=30+Feb+31+30+31+30+31+31+day;break;
				case 9:sum=30+Feb+31+30+31+30+31+31+30+day;break;
				case 10:sum=30+Feb+31+30+31+30+31+31+30+30+day;break;
				case 11:sum=30+Feb+31+30+31+30+31+31+30+30+31+day;break;
				case 12:sum=30+Feb+31+30+31+30+31+31+30+30+31+31+day;break;
				default:printf("put error\n");exit(-1);
			}
		printf("the is day:%u of %u year\n",sum,year);
}

