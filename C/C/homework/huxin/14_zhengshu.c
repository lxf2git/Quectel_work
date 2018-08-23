#include<stdio.h>

int main()
{
   int a,b,j=0,n=10;
   printf("please input in:\n");
   scanf("%d",&a);
   do
   {
      b=a%n;
      n=n*10;
      j++;
    
  
    }while(a!=b);
     printf("位数为:%d\n",j);
	return 0;	
}
