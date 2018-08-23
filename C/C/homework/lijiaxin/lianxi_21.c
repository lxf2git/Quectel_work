#include<stdio.h>

int main()
{
		int j,int_number;
		int a[100]={0},i=0;
		printf("请输入一个正整数:\n");
		scanf("%d",&int_number);
		while(1)
		{
				if(int_number/2 == 0)
						break;
				else
				{
						a[i]=int_number%2;
					//	printf("a[%d]:%d\n",i,a[i]);
						int_number/=2;
					//	printf("%d\n",int_number);
						i++;
				}
		}
		printf("1 ");
		for(j=i-1;j>=0;j--)
				printf("%d ",a[j]);

}
