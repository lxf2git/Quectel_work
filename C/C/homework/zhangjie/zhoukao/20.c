#include<stdio.h>

void count()
{
	int a,b;
	int i,j;
	char ch;
	char string[100][100];
	printf("输入要打印的字符和两个整数\n");
	scanf("%c%d%d",&ch,&b,&a);
	//printf("输入要打印的字符c\n");
	//ch=getchar();
	for(i=0;i<b;i++)
	{
		for(j=0;j<a;j++)
		{
			string[i][j]=ch;
		}
	}
	for(i=0;i<b;i++)
	{
		for(j=0;j<a;j++)
		{
			printf("%c",string[i][j]);
		}	
			printf("\n");
	}
}

int main()
{
	count();
	return 0;
}
