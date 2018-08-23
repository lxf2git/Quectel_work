#include "main.h"

int main()
{
	int year,month;
	int a,b,day,zhou;
	int i,j;
	j=0;
	printf("please input year month\n");
	scanf("%d%d",&year,&month);
	a=choose(year);
	b=tian(year,month,a);
	day=yue(month,a);
	printf("sun mon tue wen thu fri sat\n");
	zhou=b%7;
	for(j=1;j<=(zhou+1);j++)
		printf("    ");
	for(i=1;i<=day;i++)
	{
		printf(" %2d ",i);
		if((i+zhou+1)%7==0)
		printf("\n");
	}
	printf("\n");
}
