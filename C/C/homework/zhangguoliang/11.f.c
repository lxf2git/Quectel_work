#include<stdio.h>
int comp(int a,int b,int c);
int main()
{
	int a,b,c;
	printf("输入3个数\n");
	scanf("%d%d%d",&a,&b,&c);
	comp(a,b,c);
	return 0;
}
int comp(int a,int b,int c)
{
	if(a<b)
	{
		if(b<c)
			printf("最大数%d 最小数%d 差为%d\n",c,a,c-a);
		else
			if(a<c)
			printf("最大数%d 最小数%d 差为%d\n",b,a,b-a);
			else
			printf("最大数%d 最小数%d 差为%d\n",b,c,b-c);
	}
	else
	{
		if(a<c)
			printf("最大数%d 最小数%d 差为%d\n",c,b,c-b);
		else
			if(b<c)
			printf("最大数%d 最小数%d 差为%d\n",a,b,a-b);
			else
			printf("最大数%d 最小数%d 差为%d\n",a,c,a-c);

	}
	
}
