#include<stdio.h>

int main()
{
	int d,m,y,days=0;

	printf("请输入日期(e.g. 2012 12 30 ):\n");
	scanf("%d%d%d",&y,&m,&d);

#if 0
		if ((d<=0||d>31)&&1==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>29)&&2==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>31)&&3==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>30)&&4==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>31)&&5==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>30)&&6==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>30)&&7==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>31)&&8==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>30)&&9==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>31)&&10==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>30)&&11==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}
		if ((d<=0||d>31)&&12==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}		
	switch (m)
	{
		case 1:days=d;
			break;
		case 2:days=30+d;
			break;
		case 3:days=30+28+d;
			break;
		case 4:days=30+28+31+d;
			break;
		case 5:days=30+28+31+30+d;
			break;
		case 6:days=30+28+31+30+31+d;
			break;
		case 7:days=30+28+31+30+31+30+d;
			break;
		case 8:days=30+28+31+30+31+30+31+d;
			break;
		case 9:days=30+28+31+30+31+30+31+31+d;
			break;
		case 10:days=30+28+31+30+31+30+31+31+30+d;
			break;
		case 11:days=30+28+31+30+31+30+31+31+30+31+d;
			break;
		case 12:days=30+28+31+30+31+30+31+31+30+31+30+d;
			break;
		default:printf("err!");
			break;
	}
	if(((0==y%4&&0!=y%100)||0==y%400)&&m>=2)
	{
		days++;
		printf("%d 是闰年。\n",y);
	}
	else if(29==d&&2==m)
		{
			printf("The date is ERR !\n");
			return 0;
		}

	printf("%d年的%d月%d日是%d年的第%d天\n",y,m,d,y,days);

#endif
	



	return 0;
}

