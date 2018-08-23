#include<stdio.h>
#include<string.h>
int judge_str(char str[])
{
		int i,j;
		j=strlen(str)-1;
		for(i=0;i<=(strlen(str)/2);i++,j--)
		{
				if(str[i]!=str[j])
				{
						return 1;
				}
		}
		return 0;
}
int main()
{
	char str[100]={};
	gets(str);
	int a=judge_str(str);
	if(a==0)
	{
			printf("yes!\n");
	}
	else
	{
			printf("no!\n");
	}
	
}
