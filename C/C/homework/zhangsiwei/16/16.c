#include"main.h"
#include"tianshu.h"
int main()
{
	int year,mount;
	int xingqi,m,n;
	int t1,t2,t;
	int i,r,a;
	printf("请输入年  月  \n");
	scanf("%d%d",&year,&mount);
	t1=tianshu(year,mount,1);
	printf("t1=%d\n",t1);
	m=year-1900;
	t2=0;
	for(n=1990;n<year;n++)
	{	
		if(n%4==0&&n%100!=0)	
			t2+=366;
		else 
				if(n%400==0)
						t2+=366;
				else
						t2+=365;	
			 
	}
	printf("%d\n",t2);
	t=t1+t2;
	printf("%d\n",t);
	xingqi=t%7;
	printf("%d\n",xingqi);
	printf(" 日 一 二 三 四 五 六\n");
	a=xingqi;
	for(;xingqi>0;xingqi--)
	{
		printf("   ");
	}
	if(mount==1||mount==3||mount==5||mount==7||mount==8||mount==10||mount==12)
	{
		for(r=1;r<32;r++)
		{	
			
			printf(" %2d",r);	
			if((a+r)%7==0)
				printf("\n");	
				
		}
	}
	if(mount==4||mount==6||mount==9||mount==11)
	{
		for(r=1;r<31;r++)
		{
			printf(" %2d",r);
			if((a+r)%7==0)
					printf("\n");
		}
	}
	if(mount==2)
	if(year%4==0&&year%100!=0)
	{
		for(r=1;r<30;r++)
		{
			printf(" %2d",r);
			if((a+r)%7==0)
					printf("\n");
		}
		
	}
	else if(year%400==0)
		{
			for(r=1;r<30;r++)
			{
				printf(" %2d",r);
				if((a+r)%7==0)
					printf("\n");
			}
	
		}
	else 
	{
			for(r=1;r<29;r++)
			{
				printf(" %2d",r);
				if((a+r)%7==0)
					printf("\n");
			}
	
	}
	
	
	
	printf("\n");
	return 0;	
}
