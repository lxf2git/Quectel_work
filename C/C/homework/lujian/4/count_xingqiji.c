#include"main.h"

void count_xingqiji(int year ,int month)
{

	int c, s;
	c=count_day( year,month);
	s=(year-1)+((year-1)/4)-((year-1)/100)+((year-1)/400)+c;
	switch (s%7)
	{
		case 0:print_print(month,0);break;
		case 1:print_print(month,1);break;
		case 2:print_print(month,2);break;
		case 3:print_print(month,3);break;
		case 4:print_print(month,4);break;
		case 5:print_print(month,5);break;
		case 6:print_print(month,6);break;	
	}
	

}
