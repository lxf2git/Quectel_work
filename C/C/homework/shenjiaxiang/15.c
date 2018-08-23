#include<stdio.h>
int main()
{
	int count=0,sum=0,a,n;
  printf("输入100到500的数\n");
	scanf("%d",&a);
	for(n=2;n<a;n++)
	{
						
		if(a%n==0)
		{
			printf("%-3d",n);
			sum=sum+n;
		}
	}
		printf("\n");
	if(sum>0)
	{
		printf("约数和为%d",sum);
	}
	else
	{ 
		printf("%d没有约数",a);
	}
	return 0;
}
