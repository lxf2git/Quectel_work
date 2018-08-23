#include<stdio.h>

int main()
{
   int i,a,b;
   for(i=1;;i++)
   {
   		if(i%5==1)
		{
		   a=i/5;
		   b=a*4;
		   if(b%5==1)
		   {
		      a=b/5;
			  b=a*4;
			  if(b%5==1)
			  {
					  a=b/5;
			          b=a*4;
					  if(b%5==1)
					  {
							  a=b/5;
					          b=a*4;
								if(b%5==1)
										{
										  printf("fish%d\n",i);
										  break;
										
										}
							  
							  
                        }
			  }
		   }
		
		}
   
   
   } 
 	return 0;
}
