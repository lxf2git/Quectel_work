#include<stdio.h>
int main()
{
		int year,mount,day,a;
printf("year mount day\n");
 scanf("%d%d%d",&year,&mount,&day);
 //scanf("%d",mount);
 //scanf("%d",day);
 if(year%4==0&&year%100!=0)
 {
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
		 case 11:
			a=305;
			break;
		 case 12:
			a=335;
			break;
		 default:
			break;
 }
	a=a+day;
	printf("是第%d天",a);

 }
 else 
		 if(year%400==0)
		 {
		 
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
		 case 11:
			a=305;
			break;
		 case 12:
			a=335;
			break;
		 default:
			break;
 }
	a=a+day;
	printf("是第%d天",a);
		 }
 	else
	{
 	switch(mount)
	{
		 case 1:
			a=0;	 
			break;
		 case 2:
			a=31;
			break;
		 case 3:
			a=59;
			break;
		 case 4:
			a=90;
			break;
		 case 5:
			a=120;
			break;
		 case 6:
			a=151;
			break;
		 case 7:
			a=181;
			break;
		 case 8:
			a=212;
			break;
		 case 9:
			a=243;
			break;
		 case 10:
			a=273;
			break;
		 case 11:
			a=304;
			break;
		 case 12:
			a=334;
			break;
		 default:
			break;
	 }
	a=a+day;
	printf("是第%d天",a);
	}
return 0;
}
