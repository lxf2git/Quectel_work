#include<stdio.h>
#include<stdlib.h>

void fun(void (*pf)(int ,int *),int m,int *n)
{
		(*pf)(m,n);
}
void double_1(int N,int *p)
{
		int i;
		for(i=0;i<N;i++)
		{
				printf("输入第%d个数\n",i+1);
				scanf("%d",(p+i));
				*(p+i)=2*(*(p+i));
		}
}
void print(int N,int *p)
{
		int i;
		
		for(i=0;i<N;i++)
		{
				printf("%4d",*(p+i));
		}
		printf("\n");
}
struct Stt
{
		int N;
		int *p;
}Liu;
int main()
{
		printf("输入数的个数\n");
		scanf("%d",&Liu.N);
		Liu.p=(int *)malloc(Liu.N*sizeof(int));
		fun(double_1,Liu.N,Liu.p);
		fun(print,Liu.N,Liu.p);
		free(Liu.p);
		Liu.p=NULL;
		return 0;
}
