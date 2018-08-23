#include<stdio.h>
int main()
{
		int year,mount,day,a;
		printf("year mount day\n");
		scanf("%d%d%d",&year,&mount,&day);
 	switch(mount)
	{
		 case 1:
			a=0;	 
			break;
		 case 2:
			a=31;
			break;
		 case 3:
			a=60;
			break;
		 case 4:
			a=91;
			break;
		 case 5:
			a=121;
			break;
		 case 6:
			a=152;
			break;
		 case 7:
			a=182;
			break;
		 case 8:
			a=213;
			break;
		 case 9:
			a=244;
			break;
		 case 10:
			a=274;
			break;
	}
	if(year%4==0&&a%100!=0)
	{
			a=a+day;
			printf("%d天\n",a);
	}
	else
			if(a%400==0)
			{
					a=a+day;
					printf("%d天\n",a);
			}
			else
					if(mount>2)
					{
							a=a+day-1;
			
					printf("%d天\n",a);
					}
					else
					{
					
							a=a+day;
							printf("%d天\n",a);
					}




return 0;
}
