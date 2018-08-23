#include<stdio.h>
#include<string.h>
#define N 100
int judge_str(char str[])
{
	int x,i,j;
	char arr[N];
	x=strlen(str);
	j=x;
	for(i=0;i<x;i++){
			arr[j-1]=str[i];
			j--;
	}
	return strcmp(arr,str);
}
int main()
{
	int x;
	char str[N];
	scanf("%s",str);
	x=judge_str(str);
	if(x==0)
		printf("字符串是回文\n");
	if(x!=0)
		printf("字符串不是回文\n");
	return 0;
}
