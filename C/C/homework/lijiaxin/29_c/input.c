#include"main.h"

void  input(char str[])
//	printf("string:%s\n",string1);				
{
	//	printf("")	
		printf("请输入你要统计的文字:\n");
		for(;;)
		{
				gets(str);
				arithmetic(str);
				if(str[0]=='\0')
					break;
		}
		printf("character:%d word:%d line:%d",character,word,line);
		puts(str);
}
