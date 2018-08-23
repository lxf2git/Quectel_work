#include<stdio.h>
#define N (10)
int input(int a[]);
int put(int a[]);
int sort_num(int a[], int n);
int main()
{
		int a[N];
		int n;

		input(a);

		sort_num(a,0);

		put(a);

		printf("please input n(1~10):\n");

		scanf("%d",&n); 

		sort_num(a,n);	//从n倒序排列

		put(a);


		return 0;
}

int input(int a[])
{
		int i;
		printf("please input 10 num:\n");

		for (i =0; i < N; i++ )
		{
				scanf("%d",&a[i]);
		}
		return 0;

}

int put(int a[])
{
		int i;

		for (i = 0; i < N; i++)
		{
				printf("%d ",a[i]); 
		}
		printf("\n");
		return 0;

}
int sort_num(int a[], int n)
{
		int i,j,k,tmp;

		for (i = n; i<N; i++)
		{
				k = i;
				if ( n ==0)
				{
						for (j = i+1; j<N; j++)
						{
								if(a[k]>a[j])
										k = j;
						}
				}
				else
				{
						k = i;
						for (j = i+1; j<N; j++)
						{
								if(a[k]<a[j])
										k = j;
						}
				}
		

		tmp = a[k];
		a[k] =a[i];
		a[i] = tmp;
		}


	return 0;
	
}



