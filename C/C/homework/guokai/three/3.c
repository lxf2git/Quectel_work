#include<stdio.h>
int main()
{
	int i,j,jieguo;
    for(i=1;i<=9;i++)
	{
	   for(j=1;j<=i;j++)
	   {
		  jieguo=j*i;	   
	      printf(" %d * %d = %d ",j,i,jieguo);
		  
	   }
			
		  printf("\n");
	}
return 0;
}
