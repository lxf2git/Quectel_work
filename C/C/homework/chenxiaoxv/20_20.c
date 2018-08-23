#include<stdio.h>

int main()
{
	int a,temp,i=0,j=1,m=0;
	char b[50]={};
	char c[50]={};
	printf("input:");
	scanf("%d",&a);
	if(a<0)
	{
		temp=0-a;
		b[0]='-';
	for(m=0;temp!=0;m++)
	{
		j=temp%10;
		temp=temp/10;
	
		c[m]=j;
	//	printf("%d\n",c[m]);
	}
		for(;m>=0;m--)
		{
			i=i+1;
			b[i-1]=c[m]+48;
		}
	
	
	}
	
	else 
	{
		for(m=0;a!=0;m++)
		{
			j=a%10;
			a=a/10;
		
			c[m]=j;
		}
	
		for(;m>=0;m--)
		{
		
			
			b[i-1]=c[m]+48;  //为啥减一个1 才好使。
			i++;
		}

	}
	
	puts(b);
	
return 0;

	
}




