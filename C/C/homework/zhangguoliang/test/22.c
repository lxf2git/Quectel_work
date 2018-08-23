#include<stdio.h>
#include<string.h>
int judge_str(char str[]);
int main()
{
	char str[100];
	int a;
	printf("输入字符串:\n");
	scanf("%s",&str);
	a=judge_str(str);
	if(a==0)
		printf("是回文!\n");
	if(a==1)
		printf("不是回文!\n");
	return 0;
}

int judge_str(char str[])
{
	int i,j,x=0;	
	j=(int)strlen(str);
	for(i=0;i<j/2;i++)
	{
		if(str[i]==str[j-i-1])
				x++;
	}
	if(x==j/2)
		return 0;
	if(x<j/2)
		return 1;
}
