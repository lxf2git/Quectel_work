#include<stdio.h>
int main()
{
	int i,a[10],q=-1,x;
	for(i=1;i<=10;i++)
	{
	printf("输入10个数，第%d个数是：",i);
	scanf("%d",&a[i]);
	}	
	printf("输入其中一个数：\n");
	scanf("%d",&x);
	for(i=0;i<10;i++)
	{
		if(x==a[i])
		{ 	 printf("这是第个%d数\n",i);
	  			q=i;
	   			break;
		}
	}

		if(q==-1)
		printf("sorry,not found!\n");
	
		return 0;
}
