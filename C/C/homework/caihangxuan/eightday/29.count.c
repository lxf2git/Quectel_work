#include<stdio.h> 
int main()
{
	int character=0,word=0,line=0;
	char number;
	printf("请输入文段并以～号结束");
	for(;;)
	{
		scanf("%c",&number);
		 if(number=='~')
			break;
//		printf("%c",number);
		else if(number>='A'&&number<='Z'||number>='a'&&number<='z')
			character++;
		else if(number=='.')
		{
			line++;
			word++;
		}
		else if(number==' ')
			word++;
	}
	printf("character:%d word:%d line:%d \n ",character,word,line);
}
