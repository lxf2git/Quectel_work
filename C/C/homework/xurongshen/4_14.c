#include<stdio.h>

void print(int a);

int main()
{
	int d;
	printf("请输入一个正整数：");
	scanf("%d",&d);

	print(d);

	return 0;
}

void print(int a)
{
	int b=1,num=0;
	for(;b>0;)
	{
		b = a/10;
	//	c = a%10;
	    a = b;
		num++;
	}
	printf("num=%d\n",num);

}
