#include<stdio.h>
void fun(int b[]);

int main()

{
	int a[5];
	
	printf("input:");
	fun(a);
}
	void fun(int b[])
	{
		int max=0;
		int i=0;
		int j=0;
		int min;
		int a[5];
		 min=a[0];
		for(i=0;i<5;i++)
		{
			scanf("%d",&b[i]);
			if(max<b[i])
			{
				max=b[i];
			}
	
			 else if(0<=min-b[i])
				min=b[i];
				
		}
	
		printf("a[0]=%d\n",min);
		printf("a[4]=%d\n",max);
	}


















