#include<stdio.h>
#define r 3
#define c 3
int main()
{
	int i,j,a[r][c]={0},b[r][c]={0},m;
	printf("%d",sizeof(a));
	printf("输入二维数组:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
			printf("a[%d][%d]:%d\n",i,j,a[i][j]);
			if(a[0][0]<a[i][j])
			{
				a[0][0]=a[i][j];

			}
		}


	}
	printf("a[0][0]:%d",a[0][0]);
	printf("再输入二维数组:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&b[i][j]);
			printf("b[%d][%d]:%d\n",i,j,b[i][j]);
			if(b[0][0]<b[i][j])
			{
				b[0][0]=b[i][j];
			}
		}


	}
	printf("b[0][0]:%d",b[0][0]);
	m=a[0][0]-b[0][0];
	printf("m:%d",m);
}

