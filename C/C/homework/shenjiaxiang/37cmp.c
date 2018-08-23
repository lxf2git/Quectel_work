#include<stdio.h>

int mystrcmp(char *dest,char *scr)
{
	while(1)
	{
	//	printf("dest=%c  scr= %c  ",*dest,*scr);
		if(*dest=='\0'&&*scr=='\0')
			return 0;
		if(*dest-*scr>0)
			return 1;
		else if(*dest-*scr<0)
			return -1;
		dest++;
		scr++;
	}
}

int main()
{
	int i;
	char str1[100],str2[100];
	printf("请输入字符串a：\n");
	gets(str1);
	printf("请输入字符串b：\n");
	gets(str2);
//	i=strcmp(str1,str2);
	i=mystrcmp(str1,str2);
	printf("%d\n",i);
	return 0;
}
