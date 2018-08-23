#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main()
{
	char first[500],second[500];
	int flag;
	printf("请输入第一个字符串。\n");
	scanf("%s",first);
	printf("请输入第二个字符串。\n");
	scanf("%s",second);
	printf("请输入flag\n");
	scanf("%d",&flag);
	if(flag==0)
	{
		strcat(first,second);
		printf("%s\n",first);
	}
	else if(flag==1)
	{
		strcat(second,first);
		printf("%s\n",second);
	}
	else
		printf("(NULL)");
}
