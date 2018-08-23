#include"main.h"
int judge_year(int y)                  //判断是否是闰年
{
	if(y%4==0&&y%100!=0||y%400==0)
	{
	    return 1;                      //是返回 1 
	}
    else
	{
		return 0;                     //不是返回2
	
	}

}
int judge_mon(int a,int m)             //判定这个月为多少天！
{
	int i,day;
	if(m==2)
	{
		switch(judge_year(a))
		{
		 	case 0:
					day=28;
					break;
			case 1:
			        day=29;         
	                break;
		}
	}
	else
	  {
	    /* int a[]={1,3,5,7,8,10,12};
		 for(i=0;i<7;i++)
		 {
		  	if(m==a[i])
			{
				return day=31;
                break;
			}
		 */
		if(m==4||m==6||m==9||m==11)
		{
		 	day=30;
		}
		else
		{
		 	day=31;
		}
	  }
	return day;	 
}

int judge_space(int a,int b)               //判定这个月第一天星期几   
{
	int y,m,day=0,space;
	 if(b==1)
	 {
	 	a=a-1;
		b=13;
	 }
     for(y=1900;y<=a;y++)
	 {
	 	if(a==y)
		{
			for(m=1;m<b;m++)
			{
				day=day+judge_mon(y,m);
			}
		}	
		else
			{
				for(m=1;m<13;m++)
				{
					day = day + judge_mon(y,m);
	            }
			}
		
	 }
	 space=day%7;
	 return(space);
}
