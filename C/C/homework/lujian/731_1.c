#include<stdio.h>
#define N (5)
void swap_num(int a[]);
int main()
{
	int a[N], i; 

	printf("please input N number:\n");

	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);

	swap_num(a);
	
	for (i = 0; i < N; i++)
		   printf("%d ", a[i]);	

	printf("\n");


}

void swap_num(int a[])
{
	int i,  k, l, temp;
	for (i = 0, k = i; i < N; i++)
	{
			if (a[k] < a[i])	
				a[k] = a[i];	
					
	}
	temp = a [k];
	a[k] =  a[N-1];
	a[N-1] = temp;
	
	for (i = 0, l = i; i < N; i++ )
	{
	
		if (a[l] > a[i])
				a[l] = a[i];

	}	
	
	temp = a[l];
	a[l] = a[0];
	a[0] = temp;

}

















