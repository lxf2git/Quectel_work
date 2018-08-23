#include"15_lastmonthday.h"

int lastmonthday(int year,int month,int day)
{
		int i;
		int n=0;
		int run;
		run=bissextile(year);
		if(year<1900)
		{
				printf("暂不支持查询1900年前的日历！\n");
				exit(0);
		}
				
		if(((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day<=31)
        ||((month==4||month==6||month==9||month==11)&&day<=30)
        ||(run==1&&month==2&&day<=29)||(run==0&&month==2&&day<=28))
        {
		        for(i=1;i<month;i++)
		        {
						n=n+31;
						if(i==2&&run==1)
						{
								n=n-2;
						}       
						if(i==2&&run==0)
						{
						        n=n-3;
						}       
						if(i==4||i==6||i==9||i==11)
						{
                                n--;
 						}       
	  			}       
	            return n;
	 			
	    }
		else
		{       
				printf("请输入正确的年月日！\n");
				exit(0);
		}

}
