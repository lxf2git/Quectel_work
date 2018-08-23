#include<stdio.h>
#define X 10
int main()
{
	int i,a[X],find;
	printf("请输入%d个数\n",X);
	for(i=0;i<X;i++)
		scanf("%d",&a[i]);
	printf("请输入要查找的数\n");
	scanf("%d",&find);
	for(i=0;i<X;i++)
	{
		if(find==a[i])
		{
			printf("你要查找的数下标为%d\n",i);
			return 0;
		}
	}
	printf("对不起,并没有找到%d\n",find);
	
}
