#include<stdio.h>

int main()
{  int i,j;
   float l,a,n;
   l=100;
   n=100;
   a=0;
  for (i=1;i<=10;i++)
   {
        n=n+a*2;

       a=l/2;
       l=a;
    
  }
   printf("the height is %f\n",l);
   printf("the journey is %f\n",n);
    return 0;
}
