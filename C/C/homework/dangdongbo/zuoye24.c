#include<stdio.h>
int main()
{
		int i,n=0,m;
		char a[100]={};
		scanf("%s",a);
		
		for(i=0;i<100;i++)
		{
				if(a[i]=='c')
				{
				
				n++;
				for(m=i;m<100;m++)
				a[m]=a[m+1];
		i--;		
			
		}
		}
				
	
		for(i=0;i<100-n;i++)
				putchar(a[i]);
}

