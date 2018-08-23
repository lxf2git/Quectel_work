#include<stdio.h>
int main()
{
	int i,y,l,n,j,s=0,min=0,max=0;
	int	a[10];
	for(i=0;i<10;i++)
	{	
    	scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{		
	  	  if(a[i]>max)	
		{
				max=a[i];
		         y=i;
		}
	}		      	   
	        l=a[y];
	        a[y]=a[9];
	        a[9]=l;	
	min=a[0];		
	for(i=0;i<10;i++)
	{
	    if(min>a[i])
		  {
		     min=a[i];
			 n=i;
		  }
	}
          l=a[0];
          a[0]=min;
		  a[n]=l;

		 for(i=1;i<=8;i++)
		   s=s+a[i];
             		        
	  printf("%f",s/8.0);
return 0;
}
