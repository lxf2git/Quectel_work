#include<stdio.h>
#define N 4

void compare_right(int a[][N])
{
	int	t=a[0][0],k,i,j;
	for(i=0;i<N;i++)
		for(j=i;j<N;j++)
			if(t>a[i][j])
			{
				k=a[i][j];
				a[i][j]=t;
				t=k;
			}
	printf("右上角最小值：min:%d\n",t);
}


void compare_left(int a[][N])
{
	int	t=a[1][0],k,i,j;
	for(i=1;i<N;i++)
		for(j=0;j<i;j++)
			if(t<a[i][j])
			{
				k=a[i][j];
				a[i][j]=t;
				t=k;
			}
	printf("左下角最大值：max:%d\n",t);
}
int main()
{
	int i,j,max,b,t;
	int a[N][N];
	printf("请输入4*4的方阵\n");
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
			getchar();
		}
	compare_right(a);
	compare_left(a);
	return 0;
}
