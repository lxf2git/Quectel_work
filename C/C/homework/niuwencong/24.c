#include<stdio.h>
int main()
{
	char string[500];
	char string1;
	int i;
	printf("输入字符串:\n");
	gets(string);
	printf("输入要删除的字符:\n");
	string1=getchar();
	for(i=0;;i++)
	{
		if(string[i]==string1)
			continue;
		if(string[i]=='\0')
			break;
		printf("%c",string[i]);
	}
	printf("\n");
	return 0;
}
