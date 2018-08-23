#include<stdio.h>
int main ()
{
	int a[10],k=10;
	int i,j=10,x;
	printf("请输入数组：");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
		printf("请输入x查找：");
		scanf("%d",&x);
		for(i=0;i<10;i++)
		{
			k=j;
			if(x==a[i])
			{
				j=i;	
				if(j>k)
				{
				printf("与x相同的元素小标为：%d!\n",k);
					break;
				}
				else
				printf("与x相同的元素小标为：%d!\n",j);
				
			
			}
			
		}
			if(k==10&&j==10)
	printf("sorry,not found!\n");
}
