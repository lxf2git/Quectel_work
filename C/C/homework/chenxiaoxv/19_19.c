
#include<stdio.h>
int main()
{
	int a[10];
	int i=0,j=0;
	int f[10];
	printf("input十个数:");
	printf("input一个数:");
	scanf("%d",&j);
	for(i=0;i<10;i++)
		{
			int g=0;	
			scanf("%d",&a[i]);
		}		
	for(i=0;i<10;i++)
      	{
		int g=0;
		if(0==a[i]-j)
		{
			g=i;
			printf("%d\n",g);
			return 0;
		}
	}    
				
	printf("sorry,not found!");
			
		
				
return 0;
}







