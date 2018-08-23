#include<stdio.h>
	int y,m,d;
	int a,b,c;
	int error();
int main()
{
	printf("输入年 月 日:");
	scanf("%d%d%d",&y,&m,&d);

	if(y%400==0)
	{
		a=1;
		printf("闰年\n");
	}
	else if(y%4==0&&y%100!=0)
	{
		a=1;
		printf("闰年\n");
	}
	else
	{
		a=0;
		printf("普通年\n");
	}

	b=error();

	switch(m*b)
		{
			case 0	:printf("error!\n");break;
			case 1	:c=d;printf("今年的第%d天\n",c);break;
			case 2	:c=31+d;printf("今年的第%d天\n",c);break;
			case 3	:c=59+a+d;printf("今年的第%d天\n",c);break;
			case 4	:c=90+a+d;printf("今年的第%d天\n",c);break;
			case 5	:c=120+a+d;printf("今年的第%d天\n",c);break;
			case 6	:c=151+a+d;printf("今年的第%d天\n",c);break;
			case 7	:c=181+a+d;printf("今年的第%d天\n",c);break;
			case 8	:c=212+a+d;printf("今年的第%d天\n",c);break;
			case 9	:c=243+a+d;printf("今年的第%d天\n",c);break;
			case 10	:c=273+a+d;printf("今年的第%d天\n",c);break;
			case 11	:c=304+a+d;printf("今年的第%d天\n",c);break;
			case 12	:c=334+a+d;printf("今年的第%d天\n",c);break;
			default	:printf("error!\n");break;
		}
	return 0;
}

int error()
{
	b=1;

	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d<1||d>31)
					b=0;
		}
	else if(m==4||m==6||m==9||m==11) 
		{
			if(d<1||d>30)
					b=0;
		}
	else if(m==2)
		{
			if(a==1)
				{
					if(d<1||d>29)
							b=0;
				}
			else
				{
					if(d<1||d>28)
							b=0;
				}
		}
	else b=0;

	return b;
}
