#include<stdio.h>
#include<stdlib.h>

int make(int a,int b)
{
	int **p;
	int c;
	p = (int **)malloc(a * sizeof(int*));
		for(c = 0;c < b;c++)
		{
			*(p + c) = (int *)malloc(c * sizeof(int));
		}
	return p;
}

void in_put(int **p, int a,int b)
{
	int c, d;
	for(c = 0;c < a;c++)
	{
		for(d = 0;d < b;d++)
		{
			scanf(" %d ",*(p + c) + d);
		}
	}
}
void put_out(int **p, int a,int b)
{
	int c, d;
	for(c = 0;c < a;c++)
	{
		printf("\n");
		for(d = 0;d < b;d++)
		{
			printf(" %d ",*(*(p + c) + d));
		}
	}
	printf("\n");
}
void compare(int **p,int a,int b)
{
	int c, d, min,min2 = 0, m, f = 0;
	min = *(*(p));//给min赋初值
	for(c = 0;c < a;c++)
	{
		for(d = 1;d < b;d++)
		{
			if(min > *(*(p + c) + d))
			{
				min = *(*(p + c) + d);
			}
		}
	}
	for(c = 0;c < a;c++)
	{
		for(d = 1;d < b;d++)
		{
			if(0 == f)//此语句只执行一次
			{		
				if(min < *(*(p + c) + d))//判断不是最小数
				{
					min2 = *(*(p + c) + d);//给min2赋初值
					f++;//决定语句执行一次
				}
			}
			if(min < *(*(p + c) +d ))
			{
				if(min2 > *(*(p + c) + d))
				{
					min2 = *(*(p + c) +d);
				}
			}
		}
	}
	if(0 == min2)
	{
		printf("无第二小，最小是%d\n",min);
	}
	else
	{
		printf("第二小为%d\n",min2);
	}
}
int main()
{
	int **p = NULL;
	int a, b, c,d;
	printf("请输入数组长度\n");
	scanf("%d",&a);
	printf("请输入数组宽度\n");
	scanf("%d",&b);
	p = make(a,b);
	in_put(p,a,b);
	put_out(p,a,b);
	compare(p,a,b);
	return 0;

}
