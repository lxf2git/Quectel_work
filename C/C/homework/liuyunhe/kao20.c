#include<stdio.h>

void str(char ch,int a,int b);
int main()
{
		int a,b;
		char ch;
		printf("输入一个字符\n");
		scanf("%c",&ch);
		printf("输入个数 行数 \n");
		scanf("%d%d",&a,&b);
		str(ch,a,b);
}
void str(char ch,int a,int b)
{
		int i,j;
		for(i=0;i<b;i++)
		{
				for(j=0;j<a;j++)
				{
						printf("%c",ch);
				}
				printf("\n");
		}
}

