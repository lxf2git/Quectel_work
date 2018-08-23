#include<stdio.h>
int main()
{
	int hour;
	float  second,minute;
	float total;
	scanf("%d,%f,%f",&hour,&minute,&second);
	if((hour<0 || hour>23 || minute<0 || minute>=60) || second<0 || second>=60)
	{
	
		printf("error\n");			
	}
	else
	{
		while(hour>=0 && hour<=23)
		{
			printf("%d\n",hour*60);break;
		}
		while(minute>=0 && minute<60)
		{
			printf("%f\n",minute);break;
		}
		while(second>=0 && second<60)
		{
			printf("%f\n",second/60);break;
		}
		total=hour*60+minute+second/60;
		printf("%f\n",total);
	}
	return 0;
}
