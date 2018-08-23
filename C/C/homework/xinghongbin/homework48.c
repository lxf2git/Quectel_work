#include<stdio.h>
#include<stdlib.h>
#define N 3
void input(int *a);
void dou(int *a);
void output(int *a);
void com(void (*p)(int *),int **a);
int main()
{
		int *a;
		a=(int *)malloc(N*sizeof(int *));
		void (*p)(int *);
		
		com(input,&a);
		com(dou,&a);
		com(output,&a);
}
void input(int *p)
{
		int i;
		for(i=0;i<N;i++)
		{
				scanf("%d",p+i);
				
		}

}

void dou(int *p)
{
		int i;
		for(i=0;i<N;i++)
		{
				*(p+i)*=2;
		}
}
void output(int *p)
{
		int i;
		for(i=0;i<N;i++)
		{
				printf("%d\n",*(p+i));
				
		}
		
}

void com(void (*p)(int *),int **a)
{
		(*p)(*a);
}

