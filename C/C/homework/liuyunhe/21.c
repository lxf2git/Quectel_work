#include<stdio.h>
int main()
{
		int integer;
		int i,m;
		int n=0;
		int a[10]={};
		char b[10]={};
		scanf("%d",&integer);
		if(integer<0)
		{
				printf("-");
				integer=-integer;
		}
		m=integer;
		while(m!=0)
		{
		m=m/10;
		n++;
		}
		for(i=0;i<n;i++)
		{
				
				a[i]=integer%10;
				integer=integer/10;
		}
	
		for(i=0;i<n;i++)
		{
				b[i]=a[i]+48;
		}
		for(i=n;i>=0;i--)
		printf("%c",b[i]);
		
		//char m=a+48;
		//printf("%c",m);
}
