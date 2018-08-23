#include<stdio.h>
#include<string.h>

#define N 100

void statistics(char ch[N]);
int Character(char x);
int Word(char x);
int Line(char x);

int main()
{
		char ch[N];
		printf("请输入:\n");
		gets(ch);
		statistics(ch);
		return 0;
}

void statistics(char ch[N])
{
		int i;
		int character=0,word=0,line=0;
		for(i=0;i<strlen(ch);i++)
		{
				character+=Character(ch[i]);
				word+=Word(ch[i]);
				line+=Line(ch[i]);
		}
		printf("character:%d\n",character);
		printf("word:%d\n",word);
		printf("line:%d\n",line);
}

int Character(char x)
{
		int character=0;
		if((x>='A'&&x<='Z')||(x>='a'&&x<='z'))
		{
				character++;
		}
		return character;		
}
int Word(char x)
{
		int word=0;
		if(x==' '||x=='.')
		{
				word++;
		}
		return word;
}

int Line(char x)
{
		int line=0;
		if(x=='.')
		{
				line++;
		}
		return line;
}
