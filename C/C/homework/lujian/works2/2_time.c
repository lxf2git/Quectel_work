#include<stdio.h>

int main()
{
		unsigned int  hour,minute,second,re;
		float total;
		printf("please input time hour:minte:second\n");
		re=scanf("%u%u%u",&hour,&minute,&second);
		if(re==3)
		{
				if(hour>23||minute>59||second>59)
				{
						printf("input error!\n");
						return (-1);
				}
				total=hour*60+minute+second/60.0;
				printf("the total minute:%5.2f\n",total);
		}
		return 0;
}
