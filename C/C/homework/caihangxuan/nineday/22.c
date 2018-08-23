#include<stdio.h> 
#include<string.h> 
int judger_str(char str[])
{
	int sur=0,tra,size;
	size=(int)strlen(str);
	tra=size-1;
	for(;tra!=0;tra--,sur++)
	{
		if(str[sur]!=str[tra])
		{
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
}

int main()
{
	char str[100];
	printf("请输入一串字符，判断是否回环。");
	scanf("%s",str);
	judger_str(str);
}
