#include<stdio.h>
#include<math.h>

void output(int  integer,int pow)
{	
	int i,m;
	int *p;
	int  k=1;
	for(i=0;i<pow;i++)
	{
		k=k*integer;
	}
	printf("输出%d的%d次方的值是:%d\n",integer,pow,k);

	m = k%1000;
	*(p+0)=m/100;
	*(p+1)=m%100/10;
	*(p+2)=m%100%10;
	printf("%d的%d次方的最后3位数是:",integer,pow);
	for(i=0;i<3;i++)
		printf("%d",*(p+i));
}

int main()
{
	int i,pow;
	int integer;
	printf("请输入整数和幂：");
	scanf("%d,%d",&integer,&pow);
	output(integer,pow);
	return 0;
}
