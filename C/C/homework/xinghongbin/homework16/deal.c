#include"main.h"
int deal_year(int y)                                  //输入年算出闰年返回1 非闰年返回0
{
		if(y%4==0&&y%100!=0||y%400==0)     
				return 1;
		return 0;
}
int deal_mon(int a,int m)                            
{		int i,day;                                   //输入年月算出当月天数
		if(2==m)
				switch(deal_year(a))
				{
						case 0:
								day=28;
								break;          //28
						case 1:
								day=29;
								break;		    //29
				}

		else
		{
				int a[]={1,3,5,7,8,10,12};
				for(i=0;i<7;i++)
						if(m==a[i])         
							return day=31;               //31
			 day=30;                           //30  
		}
		return day;
}
int deal_day(int a,int b)                           //输入年与月算出这年这月多少天
{
		int day;
		day=deal_mon(a,b);
		return day;
}
	



int deal_week(int a,int b)                        //输入年月 算出 这年这月到1990年1月的总天数 对7取余求出 空格数
{
		int y,m,day=0,space;
	
				
			if(b==1)
			{
				a=a-1;
				b=13;
			}
		for(y=1990;y<=a;y++)
				if(a==y)	
				for(m=1;m<b;m++)
						day=day+deal_day(y,m);
				else 
				for(m=1;m<13;m++)
						day=day+deal_day(y,m);
		space=day%7;
		return space;

}
