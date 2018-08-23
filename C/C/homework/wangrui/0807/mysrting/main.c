#include"mystring.h"
#define N 20

int main()
{	
	
	char str1[N]={};
	char str2[N]={};
	printf("string1:\n");
	scanf("%s",str1);
	printf("string2:\n");
	scanf("%s",str2);
	
	printf("%d\n",mystrlen(str1));
	printf("%d\n",mystrcmp(str1,str2));
	printf("%s\n",mystrcat(str1,str2));
	printf("%s\n",mystrcpy(str1,str2));
	return 0;
}
#if 0
int mystrcmp(char *dest,char *src)
{
	while(*dest==*src)
	{
		if(*dest==0&&*src==0)	{return 0;}
		dest++;
		src++;
	}
	if(*dest>*src)	{return 1;}
	else	{return -1;}
}

char *mystrcat(char *dest,char *src)
{
	char *pt=dest;
	while(*dest!=0)
	{
		dest++;
	}
	while(1)
	{
		*dest=*src;
		if(*src==0)
		{
			return pt;
		}
		dest++;
		src++;
	}
	
}

char *mystrcpy(char *dest,char *src)
{
	char *pt=dest;
	while(1)
	{
		*dest=*src;
		if(*src==0)//break;
		{
			return pt;
		}
		dest++;
		src++;
	}
}

#endif
