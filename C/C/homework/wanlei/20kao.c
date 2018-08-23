#include<stdio.h>

void output(char ch,int a,int b);

int main()
{
	char ch;
	int a,b;
	output(ch,a,b);
	return 0;
}

void output(char ch,int a,int b)
{
	int i,j;
	printf("请输入要输出的字符和每行字符数和行数\n");
	scanf("%c",&ch);
	getchar();
	scanf("%d%d",&a,&b);
	for(i=1;i<=b;i++)
	{
		for(j=1;j<=a;j++)
		{
			printf("%c ",ch);
		}
		printf("\n");
	}
}
