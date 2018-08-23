#include<stdio.h>
#define N 100

int mystrcmp(char *dest,char *scr)
{
	for(;;)
	{
		printf("dest=%c  scr= %c  ",*dest,*scr);
		if(*dest=='\0'&&*scr=='\0')
			return 0;
		if(*dest-*scr!=0)
		{
			printf("%c  %c  \n",*dest,*scr);
			return *dest-*scr;
		}
		*dest++;
		*scr++;
			if(*dest==*scr)
					continue;
	}
}

int main()
{
	int i;
	char str1[N],str2[N];
	printf("请输入字符串a：\n");
	gets(str1);
	printf("请输入字符串b：\n");
	gets(str2);
	i=mystrcmp(str1,str2);
	printf("%d\n",i);
	if(i==0)
			printf("a字符串等于b字符串。\n");
	if(i>0)
			printf("a字符串大于b字符串。\n");
	if(i<0)
			printf("a字符串小于b字符串。\n");

	

	return 0;
}
