#include<stdio.h>
int main()
{
		int b,i;
		char a[100]={};
		scanf("%d",&b);
		if(b<0)
		{		
				printf("-");
				b=-b;
		}
		for(i=0;b!=0;i++)
		{
				
				a[i]=b%10+48;
				b=b/10;
				

		}
		for(;i>=0;i--)
		{
				printf("%c",a[i]);
			
		}
}
