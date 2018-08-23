#include<stdio.h>
int double_t(int a)
{
	return 2*a;
}
int print(int r)
{
	printf("数字*2为:%d\n",r);
}
int fun(int(*p)(int),int m)
{
	int ret;
	ret=(*p)(m);
	return ret;
}
int main()
{
	int a,ret,i,n;
	printf("请输入数字个数:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("输入数字:\n");
		scanf("%d",&a);
		int (*pf[2])(int)={double_t,print};
		ret=fun(pf[0],a);
		fun(pf[1],ret);
	}	
	return 0;
}
