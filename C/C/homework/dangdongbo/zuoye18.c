#include<stdio.h>
int main()
{
		int a[10],z=0,i,b,c,max=0,min;
		float p;
		for(i=0;i<=9;i++)
		{
		scanf("%d",&a[i]);
		z=z+a[i];
		min=a[0];
		}
		for(b=1;b<=9;b++)
	{
		if(min>a[b])
				min=a[b];
		}
		for(c=0;c<=9;c++)
		{
				if(max<a[c])
				max=a[c];
		}
		p=(z-max-min)/8.0;
		printf("%d,%d,%f,%d",min,max,p,z);
		

}
