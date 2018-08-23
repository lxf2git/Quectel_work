#include<stdio.h>

int main()
{
	int hour,minute,minute1;
	float minute2,a,second;
	while(1)
	{
    scanf("%d:%d:%f",&hour,&minute,&second); 
	if(((hour<0||hour>24)||(minute<0||minute>60)||(second<0||second>60))&&printf("error\n"))
	{
	   break;
	}
	else	
	{  minute1=hour*60;
	     minute2=second/60.0;
	     a=minute+minute1+minute2;

	     printf("分钟为:%f\n",a);
		 break;
    }		 
   }
	return 0;
}
