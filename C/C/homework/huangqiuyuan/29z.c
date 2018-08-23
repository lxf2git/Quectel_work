#include<stdio.h>
int main()
{
	char i,character=0,word=0,line=0;
	printf("请输入一个文本：\n");
	for(;;)
	{
	scanf("%c",&i);
	character++;
			if(i==' ')
			{word++;character--;}
				if(i=='.')
				{line++;character--,word++;}
					if(i=='\n')
					{
							break;
					}
	}
		printf("character=%d word=%d line=%d",character-1,word,line);
	return 0;
}
