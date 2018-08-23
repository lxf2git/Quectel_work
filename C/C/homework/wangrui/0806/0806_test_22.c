#include<stdio.h>
#include<string.h>
#define N 100
int judge_str(char str[N]);
int main()
{
	char s[N]={};
	int a;
	scanf("%s",s);
	a=judge_str(s);
	if(a==0)printf("是回文\n");
	else printf("不是\n");
	return 0;
}
int judge_str(char str[N])
{
	int m,n;
	m=0;
	n=strlen(str);
	while(str[m]==str[n-1])
	{
		if(n-1==0)return 0;
		m++;
		n--;
	}
}

