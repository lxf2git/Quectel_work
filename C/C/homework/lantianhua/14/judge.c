#include"judge.h"

void judge()
{

  int i,n,c,b=1;
   do {
          printf("please input number:\n");
           scanf ("%d",&n);
      } while((n<=0)&&(printf("input again!\n")));
       
       for(i=1;;i++)
      {    b=b*10;
           c=b; 
          if(n%c==n)
          break;
           
      } 
        printf("位数是：%d\n",i);
}
