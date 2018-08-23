#include"1.11.h"
void choose(int a[10],int b)	
{
		int i;
		for(i=0;i<10;i++)
		{
		   if(a[i]==b)
		   {
				   printf("%d",i);
		   		   break;
		   }
		   if(a[i]!=b&&i==9)
		 		   printf("sorry,not found!");
		}
}
