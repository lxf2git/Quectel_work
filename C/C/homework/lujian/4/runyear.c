#include"main.h"
int runyear(int year)
{
	if((year%4==0&&year%100!=0)||year%400==0)
			return 29;
	else 
			return 28;

}



