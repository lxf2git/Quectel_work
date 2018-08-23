#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,a,b;
	char t;
	char string[50]={};
	char str[10];
	printf("please input a string\n");
	gets(string);
	a=strlen(string);
	for(i=a;i>0;i--)
	{
		for(j=1;j<i;j++)
		{
			if(string[j-1]>string[j])
			{
				t=string[j-1];
				string[j-1]=string[j];
				string[j]=t;
			}
		}
	}
#if 1
	puts(string);
#endif
	printf("please input a string\n");
	gets(str);
	strcat(string,str);
	b=strlen(string);
	for(i=b;i>0;i--)
	{
		for(j=1;j<i;j++)
		{
			if(string[j-1]>string[j])
			{
				t=string[j-1];
				string[j-1]=string[j];
				string[j]=t;
			}
		}
	}
	puts(string);
	return 0;
}

