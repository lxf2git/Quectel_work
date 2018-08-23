#include<stdio.h>
#define N 1000

int kill(int a[N]);
int input(int a[N]);
int r;	//人数
int main()
{	
	int lf;//生还者编号
	int arr[N]={};
	input(arr);
	lf=kill(arr);
	printf("最后剩下:%d\n",lf);
	return 0;
}

int input(int a[N])	//给人编号
{
	int i;
	printf("人数:\n");
	scanf("%d",&r);
	for(i=0;i<r;i++)
	{
		a[i]=1+i;
	}
	for(i=0;i<r;i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");
}

int kill(int a[N])
{
	int i,j;
	j=0;
	for(i=0;i<N;i++)
	{
		if((i+1)%3==0)
		{
			a[i]=0;
			j++;	//修正
			printf("kill:%4d%4d\n",i+1,a[i]);
		}
		else
		{
			a[r+i-j]=a[i];
			a[i]=0;
			printf("life:%4d%4d%4d\n",i+1,i+r-j,a[r-1+i-j]);
		}
		if(a[r+i-1-j]==0&&a[r+i+1-j]==0)
		{
			return a[r+i-j];
		}
	}
}
