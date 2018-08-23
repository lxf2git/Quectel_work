#include<stdio.h>

void output(char,int,int);
int main()
{
	int i,j;
	char ch;
	printf("输入一个字母:\n");
	scanf("%c",&ch);
	printf("输出行数:\n");
	scanf("%d",&i);
	printf("每行字数:\n");
	scanf("%d",&j);
   	output(ch,i,j);
	
	return 0;
}

void output(char ch,int i,int j)
{	
	int m;
	m=j;
	for(;i>0;i--)
	{
		for(j=m;j>0;j--)
		{
			printf("%c",ch,ch);
		}
		printf("\n");
	}
}
