#include"mystring.h"

int mystrlen(char *s)
{
	int i;
	for(i=0;*s++!=0;i++);
	return i;
}

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
