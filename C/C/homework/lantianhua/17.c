#include<stdio.h>

int main()
{  
    int a[5];
    int i, j,k,l,m,max=0, min=0;
    int b=0,c=0;
    printf("please input a[5]\n");
    for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	min=a[0];
	for(i=0;i<5;i++)
	{
		if(min>a[i])
		{
		      	min=a[i];
                        l=i;
		}
	}
	               b=a[0];
                       a[0]=min;
                       a[l]=b;
	 max=a[4];
	for(j=4;j>0;j--)
	{
		if(max<a[j])
		{
		       	max=a[j];
                        m=j;
		}
	}
                        c=a[4];		       
                	a[4]=max;
                        a[m]=c;
        for(k=0;k<5;k++)
      {
	printf("%d\n",a[k]);
      }	
      return 0;
}
