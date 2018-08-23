#include<stdio.h>
void math();
void print(int a,int b);

int main()
{
	math();
	return 0;
}

void math()
{
	int i,a,b,max=0,min=0;
	printf("请输入三个数：（空格隔开）");
	scanf("%d %d %d",&i,&a,&b);
	if(i>a)
	{
		max = i;
		min = a;
	}
	else{
		max =a;
		min = i;
	}

	if(b>max)
			max=b;
	if(b<min)
			min=b;
	print(max,min);
}

void print(int a,int b)
{
	printf("最大值是%d\n",a);
	printf("最小值是%d\n",b);
	printf("差值是%d\n",a-b);
}
