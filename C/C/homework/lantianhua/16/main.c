#include<stdio.h>
int leap(int i);

int main()

{  int year,day,month,bday,week;
   int a,c=0,d=0,i,m;
   int t=1,h=0;
   printf("please input the year:\n");
   scanf("%d",&year);
    m=leap(year);
	if(m==1)
         printf("the year is a leap year\n");
	else
	printf("the year is not a leap year\n");
      

   for(i=1900;i<year;i++)
   {
     a=leap(i);
      if(a==1)
	c++;
	else d++;
    
   }
	
     day=c*366+d*365;

    printf("please input the month\n");
    scanf("%d",&month);
    switch (month)
	{
		case 1:day=day;break;
		case 2:day=day+31;break;
		case 3:day=day+31+28+m;break;
		case 4:day=day+31*2+28+m;break;
		case 5:day=day+31*2+28+m+30;break;
		case 6:day=day+31*3+28+m+30;break;
		case 7:day=day+31*3+28+m+30*2;break;
		case 8:day=day+31*4+28+m+30*2;break;
		case 9:day=day+31*5+28+m+30*2;break;
		case 10:day=day+31*5+28+m+30*3;break;
		case 11:day=day+31*6+28+m+30*3;break;
		case 12:day=day+31*6+28+m+30*4;break;
		default :printf("error!\n");
	}     
	        week=(day+1)%7;
	switch (month)
	{
		case 1: bday=31;break;
		case 2:	bday=28+m;break;
		case 3: bday=31;break;
		case 4: bday=30;break;
		case 5: bday=31;break;
		case 6: bday=30;break;
		case 7: bday=31;break;
		case 8: bday=31;break;
		case 9: bday=30;break;
                case 10: bday=31;break;
		case 11: bday=30;break;
		case 12: bday=31;break;
		default:("error!\n");break;
	}
        printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
	
	if(week!=0)
	{
		while(week!=0)
		{
			printf("      ");
			week--;
			h++;
		}
	}
	
	for(; bday>0;bday--)
	{
		printf("%6d",t);
		t++;
		h++;
		if(h==7)
		{
			printf("\n");
			h=0;
		}
	}
	printf("\n");

	 
       return 0;
}
 int leap( int i)
{  int b;
  if((i%400==0)||(i%4==0&&i%100!=0))
    {
	b=1;
	

    } 
   else {
		b=0;
	
	}


		return b;
}

