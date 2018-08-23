#include<stdio.h>

int main()
{
	char ch;
	int i;
	int num=0;
	int line=0;
	for(i=0;;i++)
	{		
			scanf("%c",&ch);
			if(ch>=65 && ch<=90 || ch>=97 && ch<=122)
			{
				num+=1;
			}
			if(ch=='\n')
			{
				line+=1;
				printf("每行共有字符数：%d\n",num);
				num=0;
			}
			if(ch=='#')
				break;		
	}
	printf("输出的行数：%d\n",line);
	return 0;
}
