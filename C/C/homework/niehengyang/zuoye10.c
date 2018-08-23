#include<stdio.h>
int main()
{
//	int a,b,c;
	int i=0,k,j,n=0;
	printf("请输入需计算的数：");
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		j=i;
	if(j%3==2)
	{
		if(j%5==3)
		{
			if(j%7==1)
			{
				n=n+1;
			printf("%d,",i);	
				if(n%6==0)
				{
					printf("\n");
				}
			}
		}
	}
	}
}
