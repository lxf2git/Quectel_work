#include<stdio.h>

;int main()
{
		int N,i,j;
		printf("请输入阶数\n");
		scanf("%d",&N);
		int a[N][N];
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						if(j>=i)
						{
								a[i][j]=1;
						}
						else
						{
								a[i][j]=i-j+1;
						}
						printf("%4d",a[i][j]);
				}
				printf("\n");
		}


		return 0;
}
