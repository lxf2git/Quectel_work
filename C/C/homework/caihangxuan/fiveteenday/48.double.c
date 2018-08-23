#include<stdio.h> 
#include<stdlib.h> 

void print(int *point,int sum)
{
	int nu=0;
	for(;nu<sum;nu++)
		printf("两倍为：%d\n",*(point+nu));
}
void double_t(int *point,int sum)
{
	int nu=0;
	for(;nu<sum;nu++)
	{
		*(point+nu)=*(point+nu)*2;
	}
	void (*pf)(int*,int)=print;
	pf(point,sum);
}
int main()
{
	int *number=NULL,nu=0,sum;
	printf("请输入输入数字个数。\n");
	scanf("%d",&sum);
	number=(int*)malloc(sum*sizeof(int));
	for(;nu<sum;nu++)
	{
		printf("请输入数字。\n");
		scanf("%d",number+nu);
	}
	void (*pf)(int*,int)=double_t;
	pf(number,sum);
}
