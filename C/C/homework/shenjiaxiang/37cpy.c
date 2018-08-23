#include<stdio.h>
char *mystrcpy(char *dest,char *scr)
{	
	char *sb=dest;
	while((*dest++=*scr++)!='\0');
	return sb;
}


int main()
{
	char str1[10],str2[10];
	printf("请输入字符串a：\n");
	gets(str1);
	printf("请输入字符串b：\n");
	gets(str2);
	mystrcpy(str1,str2);
	puts(str1);
	return 0;
}
