#include<stdio.h>


int main()
{
	int i,another,x,flag=0;
	int a[10];
	printf("输入another：");
	scanf("%d",&another);
	printf("输入数组：");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}	
	for(i=0;i<10;i++)
	{
				if(another==a[i])
				{
					another=a[i];
				
					flag=i;
					
					printf("下标：%d\n",flag);	
					return 0;
		  		}			
	}	
    				printf("输出another：%d\n",another);
					printf("Sorry,not found\n");
	return 0;
}
