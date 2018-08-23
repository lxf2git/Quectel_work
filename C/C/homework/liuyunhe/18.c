#include<stdio.h>
int main()
{
		int a[10]={};
		int i,s=0;
		int max=0,min;
		float m;
		for(i=0;i<10;i++)
		{
			scanf("%d",&a[i]);
			s=s+a[i];
		}
		min=a[i];
		for(i=0;i<10;i++)
		{	
			if(max<a[i])
			{
				max=a[i];
			}
		
			if(min>a[i])
			{
				min=a[i];
			}
		}
	
		s=(s-max-min);
		
		m=s/8.0;
		printf("%f",m);
		return 0;

}
