#include<stdio.h>
//1900<=rili
int main()
{
	int year,month,a,b,c=0,day,daynumber=0,i,n,e=30,d=1,f,g;
	
	printf("输入年份和月份\n");
	scanf("%d%d",&year,&month);
	if(year>1900)
	a = year-1900-1;						//判断这一年到1900年中间有多少年
	if((year%4==0&&year%100!=0)||(year%400==0))	//判断这一年是否是润年
			b=1;
	else
			b=0;
	if(month>10)	
	c=c+6;
	else if(month>8)	
	c=c+5;
	else if(month>7)	
	c=c+4;
	else if(month>5)      
	c=c+3;
	else if(month>3)
	c=c+2;
	else if(month>1)
	c=c+1;
	
	if(month>2)
	c=(month-2)*30+1+b+28+c;
	else
	c=(month-1)*30+1+c;		//判断month的1是该年的第几天
//	printf("是今年的第%d天\n",c);
	daynumber = c+a*365+a/4+1;
	if(year>2000)
				{													
					daynumber-=(year-2000-1)/100;
					daynumber+=(year-2000-1)/400;
				}
	day=daynumber%7;
//	printf("%d\n",day); 
//格式输出	
	printf("\n");
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	e=e+1;
	else if(month==2)
	e=e-2+b;
/*	for(i=1;i<=7-n;i++)
	{
		printf("%3d",i);
	}
		printf("\n");
*/
//		n=7-day;
//	if(n!=7)
//	{
		for(i=1;i<=day;i++)
		{
			printf("    ");
		}
		for(d=1;d<=e;d++)
		{
			printf("%3d ",d);
			if(d+i>7)
			{
				printf("\n");
				break;
			}
		}
//	}
		d=d+1;
		i=0;
		for(d;d<=e;d++)
		{	
			i++;
			printf("%3d ",d);
			if(i==7)
			{	
				i=0;
				printf("\n");
			}
		}
		printf("\n");
		return 0;
}
