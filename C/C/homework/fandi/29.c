#include<stdio.h>
#include<string.h>
int num(char ch)
{
	int character=0,word=0,line=0;
	for(;;){
	scanf("%c",&ch);
	if(ch==46)
		line+=1;
	if(ch==46||ch==32)
		word+=1;
	if(ch>=65&&ch<=90||ch>=97&&ch<=122)
		character+=1;
	if(ch=='\n')
		break;
	}
	printf("共输入字母:%d\n",character);
	printf("共输入单词:%d\n",word);
	printf("共输入行数:%d\n",line);
	return 0;
}
int main()
{	
	char ch;
	num(ch);
	return 0;
}
