#include<stdio.h>

char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
int strcmp(char *dest, const char *src);

int main()
{
		char a1[50],a2[50];
		char *p;
		int n;
		printf("please input string a1:\n");
		scanf("%s",a1);
		printf("please input string a2:\n");
		scanf("%s",a2);

		n=strcmp(a1,a2);
		printf("strcmp:%d\n",n);

		p=strcpy(a1,a2);
		printf("strcpy:%s\n",p);

		p=strcat(a1,a2);
		printf("strcat:%s\n",p);
		return 0;
}

char *strcpy(char *dest, const char *src)
{
		char *head=dest;
		while(*src!='\0')
		{
				*dest=*src;
				dest++;
				src++;
		}
		*dest='\0';
		return head;
}

char *strcat(char *dest, const char *src)
{
		char *head=dest;
		while(*dest!='\0')
		{
				dest++;
		}
		while(*src!='\0')
		{
				*dest=*src;
				dest++;
				src++;
		}
		*dest='\0';
		return head;
}

int strcmp(char *dest, const char *src)
{
		if(*dest=='\0'&&*dest=='\0')
		{
				return 0;
		}
		else
		{
				if(*dest==*src)
				{
						dest++;
						src++;
						return strcmp(dest,src);
				}
				else
				{
						return *dest-*src;
				}
		}
}
