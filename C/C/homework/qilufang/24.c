#include<stdio.h>

int main()
{
	int i,j=0;
	char string[100]={0},string_1[100]={0};	
	printf("输入一个字符串：\n");
	gets(string);
	for(i=0;i<100;i++)
	{
		if(string[i]=='c')
		{
			continue;
		}
		else
		{	
			string_1[j]=string[i];
			j++;
		}
	}
	printf("去c后得到：\n");
	puts(string_1);
	return 0;

}


