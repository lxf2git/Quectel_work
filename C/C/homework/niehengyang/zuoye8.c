#include<stdio.h>
int main()
{
	int i,k;
	float j=50;
	float n=100;
	printf("请输入查询的落地次数：");
	scanf("%d",&k);
	for(i=2;i<=k;i++)
	{
	n=n+2*j;
	j=j/2;
	}
	printf("跳跃%d次后的高度为%f第%d次落地共经过了%f米！\n",k,j,k,n);


}
