#include<stdio.h>
int main()
{
int a[10]={1,2,3,4,5,6,7,8,9,10};
int i,k=0,j=0;
	for(i=0;i<30;i++)
	{
		if(i>=10)
		{
			i=i%10;
		}
		if(a[i]!=0)
		{
			k=k+1;		
		if(k%3==0)
		{		
			a[i]=0;
			j=j+1;				
	   		if(j==9)
			{
			break;
			}
		}
		}
	}	
	for(i=0;i<10;i++)
	{
	if(a[i]!=0)
	{
	printf("%d\n",a[i]);
	}
	}
return 0;
}
