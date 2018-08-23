#include<stdio.h>

void search(int *a,int x);
void input(int *a);

#define N 4

int main()
{
	int x;
	int a[N];
	input(a);
	scanf("%d",&x);
	search(a,x);

	return 0;
}

void input(int *a)
{
	int i;

	printf("input numbers please:\n");
	
	for(i = 0;i < N;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Input The number you want:");
}

void search(int *a,int x)
{
	int i;
	for(i = 0;i < N;i++)
	{
		if(x == a[i])
		{
			printf("a[%d]=%d\n",i,x);
			return ;
		}
	}
	printf("sorry,not found !\n");
}

