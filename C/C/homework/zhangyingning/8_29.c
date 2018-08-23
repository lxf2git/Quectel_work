#include<stdio.h>
int main()
{
	char c;
	int character = 0,word = 0,line = 0;
    printf("请输入你你要录入的句子,输入1结束\n");
	for(;;)
	{
		scanf("%c",&c);
		if((int)c == 49)
		{
			break;
		}
		if((c >= 'a' || c <= 'z') || (c >= 'A' || c <= 'Z'))
		{
			character++;
		}
		if(c == ' ')
		{
			word++;
		}
		if(c == '.')
		{
			line++;
		}
	}
	printf("character = %d word = %d line = %d\n",character,word + line,line);
	return 0;
}
