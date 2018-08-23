#include<stdio.h>
#define N 100

char mystrcat(char *dest,char *scr)
{
	int n=0;
	while(*dest!='\0')
	{
		dest++;
		n++;
	}
	
	while(*scr!='\0')
	{
		*dest=*scr;
		dest++;
		scr++;	
		n++;
	}
	*dest='\0';
	return *(dest-n);
}

int main()
{
	char str1[N],str2[N];
	printf("请输入字符串a：\n");
	gets(str1);
	printf("请输入字符串b：\n");
	gets(str2);
	mystrcat(str1,str2);
	printf("%s\n",str1);

	return 0;
}
