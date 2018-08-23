#include<stdio.h>


void ass();
int main()
{
   ass(); 
  return 0;
}
void ass()
{
   int i,a;
    a=1;
   for (i=1;i<=5;i++)
      {
      
             a=a*5+1;
        }
      printf("%d\n",a);
}
