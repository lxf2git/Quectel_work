#include<stdio.h>

#define N 41
#define M 3
#define R 2

void Joseph(int a[]);
void input(int a[]);
void print(int a[]);

int main()
{
		int a[N];
		input(a);
		Joseph(a);
		printf("\n");
		print(a);
		return 0;
}

void input(int a[])
{
		int i;
		for(i=0;i<N;i++)
		{
				a[i]=i+1;
		}
}

void Joseph(int a[])
{
		int i,j=1,people=N;
		while(1)
		{
				for(i=0;i<N;i++)
				{
						j%=M;
						if(a[i]==0)
						{
								continue;
						}
						if(j==0)
						{
								a[i]=0;
								printf("%d kill ",i+1);
								people--;
						}
						if(people==R)
						{
								return;
						}
						j++;
				}
		}
}

void print(int a[])
{
		int i;
		for(i=0;i<N;i++)
		{
				if(a[i]!=0)
				{
						printf("剩余:%d\n",i+1);
				}
		}
}
