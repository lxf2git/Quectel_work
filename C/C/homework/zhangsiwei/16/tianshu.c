#include"tianshu.h"

int tianshu(int year,int mount,int day)
{
		int a;
		
		
 	switch(mount)
	{
		 case 1:
			a=0;	 
			break;
		 case 2:
			a=31;
			break;
		 case 3:
			a=60;
			break;
		 case 4:
			a=91;
			break;
		 case 5:
			a=121;
			break;
		 case 6:
			a=152;
			break;
		 case 7:
			a=182;
			break;
		 case 8:
			a=213;
			break;
		 case 9:
			a=244;
			break;
		 case 10:
			a=274;
			break;
		 case 11:
			a=305;
			break;
		 case 12:
			a=335;
			break;
	}
	if(year%4==0&&a%100!=0)
	{
			a=a+day;
			return a;
	}
	else
			if(a%400==0)
			{
					a=a+day;
					return a;
			}
			else
					if(mount>2)
					{
							a=a+day-1;
			
							return a;
					}
					else
					{
					
							a=a+day;
							return a;
					}




return 0;
}
