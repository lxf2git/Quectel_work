#include<stdio.h>
int main()
{
 	int a,b,c,d=0,n=0;
    for(a=0;a<=100;a++)
	{			
	  for(b=0;b<=50;b++)
	     {		
		 for(c=0;c<=20;c++)	 
			{		
				d=a*1+(b*2)+(c*5);
			     if(d==100)
					n++;	 
			}
		 }
	}
printf("兑换方法总数为：%d\n",n);	
return 0;
}	
