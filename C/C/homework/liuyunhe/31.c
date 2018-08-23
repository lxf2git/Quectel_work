#include<stdio.h>
int main()
{
		int a[10]={1,2,3,4,5,6,7,8,9,10};
		int i,j=1,n=0;
		for(i=0;i<10;i++)
		{
				if(a[i]==0)
				{
						;
				}
				else if(j==3)
				{
						a[i]=0;
						j=1;
						n++;
						if(n==9)
						{
								break;
						}
				}
				else if(j<3)
				{
						j++;
				}
				if(i==9)
				{
						i=-1;
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
