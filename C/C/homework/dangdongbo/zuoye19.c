#include<stdio.h>
int main()
{
    int a[10],i,x,d;
	for(i=0;i<10;i++)
			scanf("%d",&a[i]);
			scanf("%d",&x);
					
			for(i=0;i<10;i++)
			{
			if(x==a[i])
			{
			d=i;
			break;
			}
			if(i==9&&(x!=a[i]))
			{
				printf("sorry");
		return 0;}	
			}
			
	printf("%d",d);
}
