#include<stdio.h>
#define swap(n,m) n>m?n:m
int main()
{
	int a,b;
	printf("请输入两个数:\n");
	scanf("%d %d",&a,&b);
	printf("max:%d\n",swap(a,b));

	return 0;

}
