#include <stdio.h>
int main()
{	
	int year,month,day,a,c=0;
	printf("输入年月日：\n");
	scanf("%d%d%d",&year,&month,&day);
	
	if((year%4==0&&year%100!=0)||(year%400==0))
	{
	 printf("%d是润年\n",year);
		a=1;
	}
	else 
	{
	 printf("%d不是润年\n",year);
	  a=0;
	}	
        if(month>10)	    c=c+6;
	else if(month>8)    c=c+5;
	else if(month>7)    c=c+4;
	else if(month>5)    c=c+3;
	else if(month>3)    c=c+2;
        else if(month>1)    c=c+1;
	if(month>2)
	c=(month-2)*30+day+a+28+c;
	else
	c=(month-1)*30+day+c;
	printf("是今年的第%d天\n",c);
	return 0;				
}

	      













































































































