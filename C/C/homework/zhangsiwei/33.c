#include<stdio.h>
#include<stdlib.h>
int main()
{
		int i,j,m,n,k;
		int a[100];
		m=0;n=0;j=0;k=0;
			printf("请输入整数\n");
		for(i=0;i<100;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0)
					break;
			if(a[i]!=0&&a[i]%2==0)
			{
				m++;
				k+=a[i];
				printf("偶数个数%d\n",m);
			}
			if(a[i]%2==1)
			{
				n++;
				j+=a[i];
				printf("奇数个数%d\n",n);
			}
		}

		printf("偶数个数：%d\n",m);
		printf("偶数平均数：%d\n",k/m);
		printf("奇数个数：%d\n",n);
		printf("奇数平均数：%d\n",j/n);
		return 0;
}
