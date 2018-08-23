#include<stdio.h>

void print(int n,int d)
{
	int i=0,j,month,a;//a表示是否是润年（1是，0不是）
	int t,m;//n表示该月有N天 d表示1号是星期几

	int p = d;
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n");
	for(t=1;t<=n;t++)
	{
		for(;i<d;i++)
		{
			printf("     ");
		}
		if(p == 7)
		{
			printf("\n");
			p=0;
		}
		printf("%5d",t);
		p++;
		if(t == n)
			printf("\n");
	}
}
