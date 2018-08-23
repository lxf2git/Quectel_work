#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b,i,j=0,sum=0;
	printf("输入一个100～500的正数：\n");
	scanf("%d",&a);
	printf("约数为:");
	if(a>100&&a<500)
	{	for(i=2;i<a;i++)
		{
			if(a%i==0)
			{	b=i;
				
				printf("%d ",b);
				sum+=b;
				j++;
			
			}
		}
	}
	printf("\n");
	printf("约数个数为:%d\n",j);
	printf("约数的和为:%d\n",sum);
	return 0;
}
