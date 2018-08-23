#include<stdio.h>
int main()
{
	int i,y,l,n,min=0,max=0;
	int	a[5];
	int p;
	for(i=0;i<5;i++)
	{	
    	scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{		
	  	  if(a[i]>max)	
		{
				max=a[i];
		         y=i;
		}
	}		      	   
	        l=a[y];
	        a[y]=a[4];
	        a[4]=l;	
	min=a[0];		
	for(i=0;i<5;i++)
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
      printf("最大%d最小%d\n",max,min);
       for(i=0;i<5;i++)
	  printf("%d",a[i]);
	  printf("\n");
return 0;
}
