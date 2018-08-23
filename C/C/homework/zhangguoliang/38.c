#include<stdio.h>
int comp(int *b,int *m);
int main()
{
	int a,n,y;
	printf("输入整数:\n");
	scanf("%d",&a);
	printf("输入幂数\n");
	scanf("%d",&n);
	y=comp(&a,&n);
	printf("结果为:%d\n",y);
	last(y);
	y=last(y);
	printf("后三位:%d\n",y);

	return 0;
}

int comp(int *b,int *m)
{
	if(*m>=1)		
	{
		(*m)--;
		return *b * comp(b,m);
	}
	else
		return 1;
	
}

int last(int y)
{
	int *p;
	*p=y%1000;
	return *p;
}
