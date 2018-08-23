#include<stdio.h>
#include<stdlib.h>

int main()
{
	char str[100];
	int i;
	int ch,word,line;
	ch=0;
	word=0;
	line=0;
   	for(i=0;i<100;i++)
	{
		scanf("%c",&str[i]);
		if(str[i]==10)
			break;
		else if(str[i]!=10&&str[i]!=32&&str[i]!=46)
		{
			ch++;
		}
		else if(str[i]==32||str[i]==46)
		{
			word++;
			if(str[i]==46)
			{
			line++;
			}
		}
	}
	printf("字符%d单词%d句子%d\n",ch,word,line);
	return 0;
}
