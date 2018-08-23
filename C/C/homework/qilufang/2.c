#include<stdio.h>
	
int main()
{
	int year,nian = 0,tues = 0,yue,ri,total = 0; 
	printf("输入一个年 月 日：\n");
	scanf("%d%d%d",&year,&yue,&ri);
	if(year%4==0&&year%100!=0)
	{
		nian = 1;
		tues = 29;
		printf("今年是润年\n");
	}	
	else if(year%400==0)
	{
		nian = 1;
		tues = 29;
		printf("今年是润年\n");
	}
	else 
	{
		printf("今年不是润年\n");
		tues = 28;
	}
	switch(yue)	
	{
		case 1 : total = ri; 
				 break;
		case 2 : total = ri+31;
				 break;
		case 3 : total = ri+31+tues; 
				 break;
		case 4 : total = ri+31+tues+31; 
				 break;
		case 5 : total = ri+31+tues+31+30; 
				 break;
		case 6 : total = ri+31+tues+31+30+31; 
				 break;
		case 7 : total = ri+31+tues+31+30+31+30; 
				 break;
		case 8 : total = ri+31+tues+31+30+31+30+31; 
				 break;
		case 9 : total = ri+31+tues+31+30+31+30+31+31; 
				 break;
		case 10 : total = ri+31+tues+31+30+31+30+31+31+30; 
				 break;
		case 11 : total = ri+31+tues+31+30+31+30+31+31+30+31; 
				 break;
		case 12 : total = ri+31+tues+31+30+31+30+31+31+30+31+30; 
				 break;

	}
	printf("今天是今年的第%d天:\n",total);
			

	return 0;

}
