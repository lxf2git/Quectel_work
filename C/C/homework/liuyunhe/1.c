#include<stdio.h>
int main()
{
		int nian,yue,ri,a,b,c,d,f=0;
		printf("请输入 年 月 日");
		scanf("%d%d%d",&nian,&yue,&ri);
		a=nian%4;
		b=nian%100;
		c=nian%400;
		if(a==0&&b!=0)
		{
				f=1;
				printf("是润年\n");
		}
		else 
			{
			 if(c==0)
			 {
					 f=1;
				printf("是润年\n");
			 }
		     else
			 {
					 f=0;
			    printf("不是润年\n");
			 }

			}
		switch(yue)
		{
		   case 1:
		   d=ri;
		   break;

		   case 2:
		   d=ri+31;
		   break;

		   case 3:
		   d=ri+31+28;
		   break;

		   case 4:
		   d=ri+31+28+31;
		   break;

		   case 5:
		   d=ri+31+28+31+30;
           break;

		   case 6:
		   d=ri+31+28+31+30+31;
		   break;

		   case 7:
		   d=ri+31+28+31+30+31+30;
		   break;

		   case 8:
		   d=ri+31+28+31+30+31+30+31;
		   break;

		   case 9:
		   d=ri+31+28+31+30+31+30+31+31;
		   break;

		   case 10:
		   d=ri+31+28+31+30+31+30+31+31+30;
		   break;

		   case 11:
		   d=ri+31+28+31+30+31+30+31+31+30+31;
		   break;

		   case 12:
		   d=ri+31+28+31+30+31+30+31+31+30+31+30;
		   break;
		   default:
		   printf("月份不对\n");
		}
		if(f==1)
		{
				if(yue>=2)
				{d=d+1;}

		}
		
		printf("一年中的第%d天\n",d);


return 0;
}
