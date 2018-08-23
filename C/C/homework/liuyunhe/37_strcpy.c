#include<stdio.h>
char my_strcpy(char *dest,char *src)
{
		int i=0;
	while(*(src+i)!='\0')
	{
		*(dest+i) = *(src+i);
		i++;
	}
		*(dest+i) = '\0';

}
int main()
{
		char str1[10];
		char str2[10];
		printf("输入字符串1\n");
		gets(str1);
		printf("输入字符串2\n");
		gets(str2);
		my_strcpy(str1,str2);
		puts(str1);

}
