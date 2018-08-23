#include<stdio.h>

int main()
{
		int a[5];
		int i,t,p=0,j=0,max,m,min;
		for(i=0;i<5;i++)
		{
		scanf("%d",&a[i]);
		}
		max=a[0];
		min=a[0];
		for(i=0;i<5;i++)
		{
			if(max<a[i])
			{
					j = i;
					max=a[i];
			}
			
			if(min>a[i])
			{
					min=a[i];
					p=i;
			}
			 
		}
			
		m=a[4];
		t=a[0];
		a[4]=max;
		a[j]=m;
		a[0]=min;
		a[p]=t;
		printf("顺序\n");
		for(i=0;i<5;i++)
		{
		printf("%d\n",a[i]);
		}
		return 0;
}
