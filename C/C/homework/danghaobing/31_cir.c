#include<stdio.h> 
int main() 
{
		int a[10]={1,2,3,4,5,6,7,8,9,10};
		int count=0,man=10,i;
		for(;;)
		{
			for(i=0;i<10;i++)
			{		
				if(man==1&&a[i]!=0)
				{
						printf("%d\n",a[i]);
						return 0;
				}
				if(a[i]!=0)
				{
						count++;
						if(count==3)
						{
								a[i]=0;
								count=0;
								man--;
						}
				}
			}
		}
}
