#include<stdio.h>
#include<string.h>
#define  N (100)
int main()
{

	char str1[N]={}, str2[N];

	int i, re;
 
	gets(str1);

	for (i = 0; str1[i] != '\0'; i++)
	{
	
		str2[i] = str1[strlen(str1) -i -1];
	
	}
	str2[i] ='\0';
	puts(str2);

	if (strcmp(str1,str2)==0)
	{
		re = 0;
		printf("%d\n",re); 
	}
	else 
	{
			re = 1;
			printf("%d\n",re); 
	}

	 return 0; 
}
