#include<stdio.h>
#include<string.h>

int judge_str(char str[])
{
	int a, b, c;
	c = strlen(str);
	for(a = 0;a < c / 2 + 1;a++)
	{
		if(str[a] == str[c - a -1])
		{
			b = 1;
		}
		else
		{
			b = 0;
			return b; 
		}
	}
	return b;
}
int main()
{
	char str[20];
	int b;
	printf("请输入一个字符串");
	gets(str);
	b = judge_str(str);
	printf("%d\n",b);

}
