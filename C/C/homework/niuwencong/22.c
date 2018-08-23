#include<stdio.h>
#include<string.h>
int main()
{
	char string[500];
	char string1[500];
	char t;
	int l,i,j;
	printf("请输入字符串:\n");
	gets(string);
	for(;;)
	{
	printf("请输入字符:\n");
	gets(string1);
	strcat(string,string1);
	l=strlen(string);
	for(j=0;j<l-1;j++)
	{
		for(i=0;i<l-1-j;i++)
		if(string[i]>string[i+1])
			{
			t=string[i];
			string[i]=string[i+1];
			string[i+1]=t;
			}	
				
	}
	printf("%s",string);
	printf("\n");
	}
	return 0;
}
