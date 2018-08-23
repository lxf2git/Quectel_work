#include<stdio.h>
#include<string.h>
#define N 4

int judge_str(char arr[])
{
	char str[100]={0};
	int n=0,i;
	for(i=N-1;i>=0;i--)	
		{
			str[n]=arr[i];
			n=n+1;
		}
	return strcmp(arr,str);	
}

int main()
{
	int i,n=0,x;
	char string1[5]={'\0'};
	printf("请输入4个字符：\n");
	for(i=0;i<4;i++)
	{
		string1[i]=getchar();		
	}
	x=judge_str(string1);
	if(x==0)
		printf("字符串是回文");
	if(x!=0)
		printf("字符串不是回文");
	return 0;
}
