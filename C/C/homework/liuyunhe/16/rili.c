#include"rili.h"
int rili(int nian,int yue)
{
		int ri,a,b,c,d;
		int f=0;
		printf("Sun Mon Tue wed Thu Fri Set \n");

		int ni=1900;
		int sc=365*(nian-1900);
	
	while(ni<nian)
	{
		a=ni%4;
		b=ni%100;
		c=ni%400;
		ni++;
		if(a==0&&b!=0)
			{
				f=1;
			
			}
		else 
			{
			 if(c==0)
				 {
					 f=1;
			 	 }
		     else
			 	{
					 f=0;
			 	}
			}	
	sc+=f;
			
	}
		switch(yue)
		{
		   case 1:
		   d=0;
		   break;

		   case 2:
		   d=31;
		   break;

		   case 3:
		   d=31+28;
		   break;

		   case 4:
		   d=31+28+31;
		   break;

		   case 5:
		   d=31+28+31+30;
           break;

		   case 6:
		   d=31+28+31+30+31;
		   break;

		   case 7:
		   d=31+28+31+30+31+30;
		   break;

		   case 8:
		   d=31+28+31+30+31+30+31;
		   break;

		   case 9:
		   d=31+28+31+30+31+30+31+31;
		   break;

		   case 10:
		   d=31+28+31+30+31+30+31+31+30;
		   break;

		   case 11:
		   d=31+28+31+30+31+30+31+31+30+31;
		   break;

		   case 12:
		   d=31+28+31+30+31+30+31+31+30+31+30;
		   break;
		   default:
		   printf("月份不对\n");
		}
		sc+=d;       //加上月份
	

return sc;
}
