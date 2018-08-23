#include"panduan.h"
int panduan(int a)
{
   int b,j=0,c=10;
   do
	{
	   b=a%c;
	   c=c*10;
	   j++;
	}while(a!=b);
   printf("位数为:%d\n",j);
   return(b);
}
