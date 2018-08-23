#include<stdio.h>
#include<stdlib.h>
#define N 5
void print(int *p);
/**********运算函数*******************/

int doubl(int ret)
{
	return ret*2;

}
/**********主函数***********************/

int main()
{
	int i;
	int *pnb=(int *)malloc(sizeof(int)*N);
	for(i=0;i<N;i++)
	{
		printf("Input a int: ");
		scanf("%d",(pnb+i));
	}
	print(pnb);
	return 0;

}
/***************输出函数****************/

void print(int *p)
{
	int i;
	int (*p_t)(int);							//定义函数指针
	int *pnb_1=(int *)malloc(sizeof(int)*N);
	for(i=0;i<N;i++)
	{
		p_t=doubl;								//函数指针赋值
		*(p+i)=p_t(*(p+i));						//函数指针调用
		printf("Double: %d\n",*(p+i));
	}
}
