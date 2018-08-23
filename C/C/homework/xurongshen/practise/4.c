#include<stdio.h>
#include<string.h>
#define N 100
int judge_str(char brr[N]);
int main()
{
	char arr[N];
	int m,n;
	printf("请输入一个字符串：");
	/******************************
	printf("请输入字符:");
	scanf("%c",&ch);
	printf("请打印的行数:");
	scanf("%d",&m);
	printf("请打印的个数:");
	scanf("%d",&n);
	*********************************/
	gets(arr);
	m = judge_str(arr);

	if(m == 0)
	{
		printf("是回文\n");
	}
	if(m == -1)
	{
		printf("不是回文\n");
	}
	return 0;
}

int judge_str(char brr[N])
{
	int i,j,n,a=0;
	n= strlen(brr);
	for(i=0;i<n;i++)
	{
		if(brr[i] != brr[n-1-i])
		{
			a=-1;
		}
//		printf("\n");
	}
	return a;
}
