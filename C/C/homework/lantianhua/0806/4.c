#include<stdio.h>
#include<string.h>
int judge_str(char str[500]);
int main()
{
	int a;char s[500]={};
	scanf("%s",s);
	a=judge_str(s);
	if(a==1)
	printf("不是回文\n");
	else printf("是回文\n");
}

int judge_str(char str[500])
{
	int b;int m,n;
	b=strlen(str);
	m=0;
	n=b;
	while(str[m]==str[n-1])
	{
		if(n-1==0)
		return 0;
		m++;
		n--;
	}
	return 1;
}
