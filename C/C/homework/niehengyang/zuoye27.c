#include<stdio.h>
int main()
{
	int a,b;
	int c;
	int m,m1,n,n1;
	printf("please input a:");
	scanf("%d",&a);
	printf("please input b:");
	scanf("%d",&b);
	if(a<100||b<100)
		{
			m=b/10;
			m1=b%10;
			n=a/10;
			n1=a%10;
			c=m*10+m1*1000+n*100+n1;
	printf("%d\n",c);	
		}
	else
	{
		printf("输入错误！\n");
	}
}

