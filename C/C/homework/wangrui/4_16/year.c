#include"year.h"

void year()
{	
	int i,y,yback;
	printf("请输入年份:");
	scanf("%d",&y);
	
	if(y>=1900)
	{
		yback=y-1900;
		for(i=y;i>1900;i--)
		{
			if((i%4 == 0 && i%100 != 0) || i%400 == 0)
			{
				yback++;
			}
		}
		if(y%400==0||(y%4==0&&y%100!=0))
		{	
			a=1;
			yback=yback-1;
		}

		yback=yback%7+1;
	}
	else
	{
		yback=1900-y;

		yback=yback*(-1);
		for(i=y;i<1900;i++)
		{
			if(i%400==0||(i%4==0&&i%100!=0))
			{
				yback--;
			}
		}
			if(y%400==0||(y%4==0&&y%100!=0))
		{	
			a=1;
			yback=yback+1;
		}
		
		yback=yback*(-1);
		yback=7-(yback%7-1);
		if(yback==7)
		{
			yback=0;
		}
		if(yback==8)
		{
			yback=1;
		}
	}

	month(yback);

}

void month(int yback)
{	
	int m;
	printf("请输入月份:");
	scanf("%d",&m);
	switch(m)
	{
		case 1:mback=yback;break;
		case 2:mback=(yback+31)%7;break;
		case 3:mback=(yback+59+a)%7;break;
		case 4:mback=(yback+90+a)%7;break;
		case 5:mback=(yback+120+a)%7;break;
		case 6:mback=(yback+151+a)%7;break;
		case 7:mback=(yback+181+a)%7;break;
		case 8:mback=(yback+212+a)%7;break;
		case 9:mback=(yback+243+a)%7;break;
		case 10:mback=(yback+273+a)%7;break;
		case 11:mback=(yback+304+a)%7;break;
		case 12:mback=(yback+334+a)%7;break;

	}
	day(m);
	
}


void day(int m)
{
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	{
		d=31;
	}
	else if(m==4||m==6||m==9||m==11)
	{
		d=30;
	}
	else if(m==2)
	{
if(a==1)
		{
			d=29;
		}
		else
		{
			d=28;
		}
	}
	else
	{
		printf("error!\n");
	}	
}
