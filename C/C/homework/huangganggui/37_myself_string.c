#include<stdio.h>
#include"mystring.h"

int main()
{
	char str[50]="i love you.";
	char str2[50]="do you love me?";
	char str3[50]="i hate you!";
	char str4[50]="yes";

//	printf("%d\n",mystrlen(str));
//	printf("cat:%s\n",mystrcat(str2,str4));

//	printf("copy:%s\n",mystrcpy(str,str2));

	printf("do you love me?\ni hate you\n%d\n",
			mystrcmp(str2,str3));
	return 0;

}
