#include"main.h"
void display(int space,int day)
{
       printf(" Sun Mon Tue Wed Thu Fri Sat \n");
	   int i,j,a=0;
	   if(space==6)
	   {
	   		i=0;
	   }
	   else
	   {
	   	  for(i=0;i<=space;i++)
		  {
			printf("    ");
		  }
	   }  
	   for(j=1;j<=day;j++)
	   {
			a++;
			printf(" %3d",j);
			
			if(a+i==7)
			{  
				i = 0;
				a = 0;
				printf("\n");
			}
	   }
}
