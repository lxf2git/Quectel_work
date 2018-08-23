#include<stdio.h>

int main()
{
   int year,month,day,a,b;
   printf("please input the year\n");
   scanf("%d",&year);
   if(year%400==0)
    {
      printf("this is the leap year\n");
      b=1;
    }
    else  if (year%4==0&&year%100!=0)
    {
        printf("this is leap year\n");b=1;
    } 
      else
             {
              printf ("this is not leap year\n");b=0;
              }
   printf("pleas input the month\n");
             
    scanf("%d",&month);
    printf("please input the day\n");
    scanf("%d",&day);

           switch(month)
        {
         case 1:a=day;break;
         case 2:a=31+day;break;
         case 3:a=31+28+day;break;
         case 4:a=31*2+28+day;break;
         case 5:a=31*2+28+30+day;break;     
         case 6:a=31*3+28+30+day;break;
         case 7:a=31*3+28+30*2+day;break;
         case 8:a=31*4+28+30*2+day;break;
         case 9:a=31*5+28+30*2+day;break;
         case 10:a=31*5+28+30*3+day;break;
         case 11:a=31*6+28+30*3+day;break;
         case 12:a=31*6+28+30*4+day;break;
       }
       
      if(b==0)
      {
        printf("%d\n",a);
      }
      else 
      {  a=a+1;
        printf ("%d\n",a);
      }



  }
                     
