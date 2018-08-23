#include<stdio.h>
int main()
{
	int year;
	printf("请输入要年份：");
	scanf("%d",&year);
	if(year%4==0&&year%100!=0)
	{
      		printf("%d是润年",year);
	}
	else
		 if (year%100==0&&year%400==0)	
		{	
			printf("%d是润年",year);
		}
	else
		 printf("%d不是润年",year);
	
	return 0;
}
