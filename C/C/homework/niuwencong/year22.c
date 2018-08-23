#include<stdio.h>
int main()
{
	int year,month,day,Two,i;
	int m=0;
	printf("请输入年:");
	scanf("%d",&year);	
	printf("请输入月：");
	scanf("%d",&month);
	printf("请输入日：");
	scanf("%d",&day);
	if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
		Two=1;
	else Two=2;
	for(i=1;i<month;i++)
	{
		m=m+30;
		if(i==2)
		m=m-Two;
		if(i==1||i==3||i==5||i==7||i==8||i==10)
		m=m+1;
	}
	printf("这一天为%d年的第%d天\n",year,day+m);
	return 0;
}
