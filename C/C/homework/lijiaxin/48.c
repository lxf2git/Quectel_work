#include<stdio.h>
#include<stdlib.h>
void double_t (int *q,int count);
void print(int *qq,int count);
int main()
{
		int n,i;
		void (*pf)(int *,int );
		int *p=NULL;
        printf("please enter diget number:\n");
		scanf("%d",&n);
		p = (int *)malloc(n*sizeof(int));
		printf("please input need oper diget\n");
		for(i=0;i<n;i++)
		{
				scanf("%d",(p+i));
		}
		pf = double_t;
		(*pf)(p,n);
		pf = print;
		(*pf)(p,n);
}
void double_t (int *q,int count)
{
		int i;
		for(i=0;i<count;i++)
		{
				*(q+i) = *(q+i)*2;
		}
}
void print(int *qq,int count)
{
		int i;
		for(i=0;i<count;i++)
				printf("%d ",*(qq+i));	
		printf("\n");
}
