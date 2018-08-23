#include"main.h"

int put(int a[][N]);
int re_max, re_min;

int main() 
{
		int a[N][N];
		int i, j;
		char ch;
		printf("please \'\\n\' <enter>\nother ksys exit!");
	   	ch = getchar();	
	    while(ch == '\n')
		{	
				input(a);
				re_max = count_max(a);
				re_min = count_min(a);
				put(a);
				div_a(a);
				printf("please \'\\n\' <go on>\n other exit!\n");
				ch = getchar();
		}
		return 0; 
}

/*********输入5*5的方阵***************/

int input(int a[][N])
{
		int i, j, ch;

		srand(time(NULL));
		printf("please input random 5*5:num\n");
		
		
				for (i =0; i<N; i++)
				{
						for (j =0; j<N; j++)
						{
								//scanf("%d",&a[i][j]); 
								a[i][j] = rand()%100;
						}
				}
		
}
/***********将a数组分成两个数组*********/

int div_a(int a[][N])
{
		int max[N][N], min[N][N];
		int i, j;
		for (i = 0; i<N; i++)
		{
			for (j = 0; j<N; j++)
			{
				max[i][j] = a[i][j];
				min[i][j] = a[i][j];
			}
		
		}
		for (i = 0; i<N; i++)
			{
				for (j=i; j<N; j++)
				{
					max[i][j] = re_min;
				}
			
			
			}
		for (i = 1; i<N; i++)
		{
		
			for (j =0; j<i; j++)
			{
				min[i][j] = re_max;
			}
		
		}
/************ 分别求出最大值和最小值******/
	
	printf("max =%d\n" ,count_max(max));
	printf("min = %d\n", count_min(min));
	
	return 0; 
}
int put(int a[][N])
{
	int i, j;
	for (i = 0; i<N; i++)
	{
		for (j =0; j<N; j++)
			printf("%4d",a[i][j]);
	printf("\n"); 
	}
	



}


