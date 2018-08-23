#include<stdio.h>
int main()
{
int year,i,mounth,day,nu;
   printf("input years\n");
   scanf("%d",&year);
   printf("input mounth\n");
   scanf("%d",&mounth);
   printf("input day\n");
   scanf("%d",&day);
	if(mounth<=7)
		{	
			        i=mounth%2;
			if(i==0)
				nu=((mounth-1)/2)*30+((mounth-1)/2+1)*31+day;
			else
				nu=((mounth-1)/2)*30*2+day;
		}
	else
		{
			i=mounth%2;
			if(i==0)
				nu=((mounth-8)/2)*2*30*2+day+214;
			else
				nu=((mounth-8)/2)*30+((mounth-8)/2)*31+day+214;
			
		}
	if(mounth<=2)
		printf("这是这年的%d天\n",nu);
	else
		{
		if((year%400==0)||(year%4==0)&&(year%100!=0))
		
			nu=nu-1;
		else
			nu=nu-2;
		}
 	printf("这是这年的%d天\n",nu); 
	return 0;
}
