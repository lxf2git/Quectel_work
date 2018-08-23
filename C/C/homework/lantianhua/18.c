#include<stdio.h>

int main()
{  
    int a[10];
    int i, j,k,l,m,max=0, min=0;
    int b=0,c=0;
    int sum=0; av=0;
    printf("please input a[10]\n");
    for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	min=a[0];
	for(i=0;i<10;i++)
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
	 max=a[9];
	for(j=9;j>0;j--)
	{
		if(max<a[j])
		{
		       	max=a[j];
                        m=j;
		}
	}
                        c=a[9];		       
                	a[9]=max;
                        a[m]=c;
        for(k=1;k<9;k++)
      {
	sum=sum+a[k];

      }
       av= (sum/8);	
	printf("%d\n",av);
      return 0;
}
