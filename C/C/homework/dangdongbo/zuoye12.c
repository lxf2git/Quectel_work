#include<stdio.h>
int main()
{
   int i,a;
   for(a=1;a<=9;a++)
   {
		   for(i=1;i<=a;i++)
		   {
   printf("%d",i);
   printf("*");
   printf("%d",a);
   printf("=%d,",i*a);
   if(a==i)
		   printf("\n");
   
   
		   }
		   
   }


}

