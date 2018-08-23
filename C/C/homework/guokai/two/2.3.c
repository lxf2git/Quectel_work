#include<stdio.h>
int main()
{
  char ch;
  int a=0;
  int b=0;
  int c=0;
  int d=0;
  while((ch=getchar())!='\n')
  {
 	if((ch>=65&&ch<=90)||(ch<=122&&ch>=97))
	{
	  a++;
	}	
	else if(ch>=48&&ch<=57)
		{
			b++;	
		}
         else if(ch==32)
		      {
		         c++;
			  }
		      else
			  		{
						d++;	
			  		} 
  }			  
printf("字母的个数是：%d\n",a);
printf("数字的个数是：%d\n",b);
printf("空格的个数是：%d\n",c);
printf("其他的个数是：%d\n",d);
return 0;		 
}           
