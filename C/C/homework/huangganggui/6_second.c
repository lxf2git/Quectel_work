#include<stdio.h>

int main()
{
	int h,m,s,i=0;  //hour,minute,second
	float count=0.00;
	printf("Input a time like 23/59/59\n");
	scanf("%d/%d/%d",&h,&m,&s);
	if((h>=0&&h<24)&&(m>=0&&m<60)&&(s>=0&&s<60))
	{
		for(h=h;h>0;h--)
		{
			for(;m>0;m--)
			{
				count=count+1;
				
			}
			count=count+60;
		}
	}else
	{
		printf("ERR!\n");
		return 0;
	}
	count=count+s/60.00;
	printf("There are %f seconds between the \
time you in put and 00/00/00",count);

	return 0;

}
