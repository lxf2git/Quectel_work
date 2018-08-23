#include<stdio.h>
int main()
{
		int a,s=0,sum=0,i=0,j=0;
		scanf("%d",&a);
		while(a!=0)
		{
				if(a%2==0)
				{
						s=s+a;
						i++;
				}
				if(a%2==1)
				{
						sum=sum+a;
						j++;

				}
				
				scanf("%d",&a);
		}
		if(i!=0)
				s/=i;
		if(j!=0)
				sum/=j;
		printf("偶数%d个 平均值%d,奇数%d个 平均值%d",i,s,j,sum);
		return 0;
		
}
