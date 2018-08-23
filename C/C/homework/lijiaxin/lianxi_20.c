#include<stdio.h>

int main()
{
		int i,j,count,line;
		char ch;
		printf("请输入需要打印的字符，每行个数和输出的行数:\n");
		scanf("%c%d%d",&ch,&count,&line);
		for(i=0;i<line;i++)
		{
				for(j=0;j<count;j++)
				{
						printf("%c",ch);
				}
				printf("\n");
		}
}
