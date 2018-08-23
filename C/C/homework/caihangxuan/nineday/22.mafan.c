#include<stdio.h> 
#include<string.h> 
int judge_str(char str[])
{
	char str_r[100]={},arr[100]={};
	int size,firs,fina=0,siz;
	size=(int)strlen(str);
	firs=(size-1)/2;
	siz=size-1;
	for(;siz>firs;siz--)
	{
		str_r[fina]=str[siz];
		fina++;
	}
	arr=strcat(str_r,str);
	if(arr=='\0')
		printf("yes\n");
	else
		printf("no\n");
}
int main()
{
	char str[100];
	printf("请输入一串字符，判断是否回环。");
	scanf("%s",str);
	judger_str(str);
}
