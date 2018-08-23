#include"main.h"

int main()
{
	int i;
	char str1[100]={0},str2[50]={0};
	char *str3;
	gets(str1);
	gets(str2);
	mystrcpy(str1,str2);
	printf("%s\n",str1);
}


