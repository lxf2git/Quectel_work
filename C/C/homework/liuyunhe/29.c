#include<stdio.h>

int main()
{
		char string[1000]={'\0'};
		int i,character=0,word=0,line=0;
		printf("请输入正文（回车表示完成输入）\n");
		gets(string);
		for(i=0;i<1000;i++)
		{
				if((string[i]>='A'&&string[i]<='Z')||(string[i]>='a'&&string[i]<='z'))
				{
						character++;
				}
				if(string[i]==32||string[i]==46)
				{
						word++;
				}
				if(string[i]==46)
				{
						line++;
				}
		}
		printf("character=%4d,word=%4d,line=%4d\n",character,word,line);
}
