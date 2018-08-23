#include<stdio.h>
int main()
{
int a[5],i,max=0,min,m,n,d,o;
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
		
	}
	for(i=0;i<5;i++)
	{
      if(max<a[i])
	  {
			  max=a[i];
			  d=i;
	  }
	}	
        m=a[4];
		a[4]=max;
		a[d]=m;
	
	min=a[0];	
	
	for(i=1;i<5;i++)
		{
		if(min>a[i])
		{
				min=a[i];
		o=i;
		}
		}
		n=a[0];
		a[0]=min;
		a[o]=n;
			for(i=0;i<5;i++)
					
		printf("%d\n",a[i]);
}

