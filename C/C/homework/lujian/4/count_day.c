#include"main.h"

int count_day(int year, int month)
{
			int Feb;
			Feb=runyear(year);
			arithmetic(Feb,month);
		return arithmetic(Feb,month);
}
int  arithmetic( int Feb, int month )
{	
			int sum;
			switch(month)
			{
				case 1:sum=day;break;
				case 2:sum=31+day;break;
				case 3:sum=31+Feb+day;break;
				case 4:sum=31+Feb+31+day;break;
				case 5:sum=31+Feb+31+30+day;break;
				case 6:sum=31+Feb+31+30+31+day;break;
				case 7:sum=31+Feb+31+30+31+30+day;break;
				case 8:sum=31+Feb+31+30+31+30+31+day;break;
				case 9:sum=31+Feb+31+30+31+30+31+31+day;break;
				case 10:sum=31+Feb+31+30+31+30+31+31+30+day;break;
				case 11:sum=31+Feb+31+30+31+30+31+31+30+31+day;break;
				case 12:sum=31+Feb+31+30+31+30+31+31+30+31+30+day;break;
				default:printf("put error\n");exit(-1);
			}
			return sum;
}

