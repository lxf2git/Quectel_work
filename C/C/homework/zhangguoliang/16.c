#include<stdio.h>
int main()
{
	int i,y,m,d;
	int day,a,n,b,c;
	int x=0;
	int j=0;
	printf("输入年 月 :\n");
	scanf("%d %d",&y,&m);
	if((y%4==0&y%100!=0)||y%400==0)
	{
		printf("润年\n");
		a=1;
	}
	else
	{	printf("普通年\n");
		a=0;
	}
	for(i=1900;i<y;i++)
	{	
		if((i%4==0&i%100!=0)||i%400==0)
			j++;
	}
//	printf("%d\n",j);
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");
	if(a==1)
	{
		switch(m)
		{	case 1: x=0;d=31;break;
			case 2: x=31;d=29;break;
			case 3: x=60;d=31;break;
			case 4: x=91;d=30;break;
			case 5: x=121;d=31;break;
			case 6: x=152;d=30;break;
			case 7: x=182;d=31;break;
			case 8: x=213;d=31;break;
			case 9: x=244;d=30;break;
			case 10: x=274;d=31;break;
			case 11: x=315;d=30;break;
			case 12: x=335;d=31;break;
		}
		day=(y-1900)*365+j+x;
		n=day%7+1;
		c=n;
		for(;n>0;n--)
		{
		printf("    ");
		}
		for(b=1;b<=d;b++)
		{
			printf("  %2d",b);
			if((b+c)%7==0)
				printf("\n");
			if(b==d)
				printf("\n");
		}
	}
	if(a==0)
	{
		switch(m)
		{	case 1: x=0;d=31;break;
			case 2: x=31;d=28;break;
			case 3: x=59;d=31;break;
			case 4: x=90;d=30;break;
			case 5: x=120;d=31;break;
			case 6: x=151;d=30;break;
			case 7: x=181;d=31;break;
			case 8: x=212;d=31;break;
			case 9: x=243;d=30;break;
			case 10: x=273;d=31;break;
			case 11: x=314;d=30;break;
			case 12: x=334;d=31;break;
		}
		day=(y-1900)*365+j+x;
		n=day%7+1;
		c=n;
		for(;n>0;n--)
		{
		printf("    ");
		}
		for(b=1;b<=d;b++)
		{
			printf("  %2d",b);
			if((b+c)%7==0)
				printf("\n");
		if(b==d)
			printf("\n");
		}
	}
	return 0;
}
