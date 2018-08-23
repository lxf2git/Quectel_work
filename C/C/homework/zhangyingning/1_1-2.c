#include <stdio.h>

int main()
{
	int year, month, day, day_1 = 0, run = 0;
    printf("请输入年月日，年月日输入完毕后分别以控格隔开\n");
	scanf("%d %d %d",&year,&month,&day);
	while (1 >  year)
	{
		 printf("请重新输入年:");
         scanf("%d",&year);
	}
	if((0 ==  year % 400) || (year % 100 != 0 && year % 4 == 0))
	{
		run = 1;
	}
	while(1 > month || month > 12)
	{
		 printf("请重新输入月:");
		 scanf("%d",&month);
	}
	
	while(1 > day || day > 31)
	{
		 printf("请重新输入日:");
		 scanf("%d",&day);
	}
	switch(month - 1)
	{
        case 1 :  day_1 = 31;  break;
		case 2 :  day_1 = 59;  break;
		case 3 :  day_1 = 90;  break;
		case 4 :  day_1 = 120; break;
		case 5 :  day_1 = 151; break;
		case 6 :  day_1 = 181; break;
		case 7 :  day_1 = 212; break;
		case 8 :  day_1 = 243; break;
		case 9 :  day_1 = 273; break;
		case 10 : day_1 = 304; break;
		case 11 : day_1 = 334; break;
		default : break;
	}
	day_1 += day;
	if(month > 2)
	{
		day_1 += run;
	}
	printf("这天是%d年的第%d天\n%d",year,day_1,run);
	return 0;
}
