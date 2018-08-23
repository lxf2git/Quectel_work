#include<stdio.h>

int time_power(int a, int b)
{
	if(b == 1)
	{
		return a;
	}
	return a*time_power(a,b-1);
}

int loop(int * pa)
{
	int i,r,w,sum;
	r = *pa;
	sum = 1;
	pa++;
	w = *pa;
	for(i=0;i<w;i++)
	{
		sum =sum*r;
	}
	return sum;
}

int main()
{
	int m,n;//m是一个整数，n是该整数的n次幂
	int * p;
	int arr[2];
	printf("请输入一个整数：");
	scanf("%d",&m);
	arr[0]=m;
	printf("请输入整数的次幂：");
	scanf("%d",&n);
	arr[1]=n;
	p=&arr;

	int num=0;
	int t;//是最后三位的余数
	num = time_power(m,n);
	t = num%1000;
	printf("递归：余数是：%d\n",t);

	num = loop(p);
	t = num%1000;
	printf("指针：余数是：%d\n",t);
	return 0;

}
