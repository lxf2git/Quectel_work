#include<stdio.h>
#include<string.h>

int main()
{
	int i;
	int character=0,word=0,line=0;
	char ch;
	printf("请输入内容：\n");
		for(;;)
		{
			scanf("%c",&ch);
			if(ch>=65 && ch<=90 || ch>=97 && ch<=122)
			{
				character+=1;
			}	
			if(ch=='.')
			{
					line=line+1;
					printf("\n");
			}
			if(ch=='#')
					break;
			if(ch=='.' || ch==32)
			{
				word+=1;
			}
		}
		printf("行数：%d\n",line);
		printf("输出字符的个数：%d\n",character);
		printf("输出单词的个数：%d\n",word);
	
	return 0;

}
