#include<stdio.h>
int main()
{
	int i,m=0,n=0,ou=0,j=0;
	int a[100]={ };
         printf("输入一串整数以0结束：\n");
	for(i=0;i<100;i++)
	{
		scanf("%d",&a[i]);
			if(a[i]==0)
			break;
				if(a[i]%2==0)
				{
				m++;
				ou=ou+a[i];	
				}
				if(a[i]%2!=0)
				{
				n++;
				j=j+a[i];	
				}
	}

	printf("偶数有%d个\n",m);
	printf("奇数有%d个\n",n);
	printf("偶数平均值%d ",ou/m);
	printf("奇数平均值%d ",j/n);




	return 0;
}
