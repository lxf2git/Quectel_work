#include<stdio.h>
#define N 8
void func(int a[N]);
int judge(int arr[N]);
int main()
{
	int i,k;
	int abb[N]={0};
	printf("%d个数围成一个圈：\n",N);
	for(i=1;i<=N;i++)
	{
		abb[i]=i;
		if(i==N-1)
		{
			abb[N]=N;
			break;
		}	
	}
/*	for(k=1;k<=N;k++)
	{
		printf("abb[%d]:%d\n",k,abb[k]);
	}			*/
	func(abb);
	return 0;

}
void func(int a[N])
{
		int i=0,j,k,b=0,m;
/*		for(k=1;k<=N;k++)
		{
				printf("add:%d\n",a[k]);
		}
*/	
		for(m=0;m<=N;m++)	
		for(j=1;j<=N;j++)
		{	
				if(a[j]!=0)
						i++;
				 if(i%3==0&&i!=0)
				{
						a[j] = 0;
						i=0;

				}
				b=judge(a);			//判断是否剩一个数
				if(b==1)	break;
		}
		printf("最后留的数：");
		for(k=1;k<=N;k++)
		{
				if(a[k]!=0)
				printf("add[%d]:%d\n",k,a[k]);
		}	
}
int judge(int arr[N])
{
	int i,b=0;
	for(i=1;i<=N;i++)
	{
		if(arr[i]!=0)
		{
			b++;
		}
	}
	return b;
}
