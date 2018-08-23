#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int i,j=0,man=10;
	for(;;)
	{		
		for(i=0;i<10;i++)
		{
			if(a[i]!=0)
			{		
				j++;
				if(j==3)
				{	a[i]=0;
					j=0;
					man--;
				}
			}
			if(man==1&&a[i]!=0)
			{	printf("%d\n",a[i]);
				exit(0);
			}
		}
	}
}
