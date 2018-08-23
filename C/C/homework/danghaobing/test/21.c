#include<stdio.h>
int main()
{
		int x,s=0;
		scanf("%d",&x);
		int i=0,a[100]={};
		if(x<0)
		{
				x=-x;
				s=1;
		}
		do
		{
				a[i]=x%2;
				i++;
				x/=2;
		}while(x>0);
		a[i]=s;
		for(;i>=0;i--)
		{
				printf("%d",a[i]);
		}
}
