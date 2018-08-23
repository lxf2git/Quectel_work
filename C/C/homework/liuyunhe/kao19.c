#include<stdio.h>

int main()
{
		int a,m=0,s=0;
		int i=0;
		int j=0;

		do
		{
				scanf("%d",&a);
				if(a%2==0)
				{
						if(a!=0)
						{
						i++;
						m=m+a;
						}
				}
				else
				{
						j++;
						s=s+a;
				}

		}
		while(a!=0);
		printf("偶数个数%d\n",i);
		printf("偶数平均数%d\n",m/i);
		printf("奇数个数%d\n",j);
		printf("奇数平均数%d\n",s/j);
		return 0;
}

