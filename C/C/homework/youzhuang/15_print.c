#include"15_print.h"

void print(int year,int month,int day)
{
		int n,days,x,i,j,k=0;
		//n:经过多少年 days:到上个月多少天 x从星期几开始打印1 j:当月日期 
		if(year==1900)
		{
				days=lastmonthday(year,month,day);
		}
		else
		{
				n=year-1990;
				days=(365*n+n/4)+lastmonthday(year,month,day);//当年到上个月多少天
		}
		x=days%7;
		printf("-----------------------------\n");
		printf(" %d 月                %d 年 \n",month,year);
		printf(" Sun Mon Tue Wed Thu Fri Sat \n");

		for(i=0;i<=x;i++)
		{
				printf("    ");
		}
		for(j=1;j<7-x;j++)
		{
				if(j==day)
				{
						printf(" [%d]",j);
				}
				else
				{
						printf("  %d ",j);
				}
		}

		printf("\n");

		for(;j<=monthday(year,month,day);j++)//当前月有多少天
		{
				k++;
				if(j<10)
				{
						printf(" ");
				}
				if(j==day)
				{
						printf("[%d]",j);
				}
				else
				{
						printf(" %d ",j);
				}
				if(k%7==0)
				{
						printf("\n");
				}
		}
		printf("\n");
		printf("-----------------------------\n");
}
