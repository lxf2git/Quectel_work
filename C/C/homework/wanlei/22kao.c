#include<stdio.h>
#include<string.h>

#define N 100

int judge_str(char str[]);

int main()
{
	int a;
	char ch[N];
	gets(ch);
	a=judge_str(ch);
	printf("%d\n",a);
	return 0;
}

int judge_str(char str[])
{
	char a[N],b[N];
	int m,n,i;
	m=strlen(str);
	for(i=0;i<m/2;i++)
	{
		a[i]=str[i];
		b[i]=str[m-1-i];
	}
#if 0
	for(i=0;i<m/2;i++)
	{
		printf("%c ",a[i]);	
	}
	printf("\n");
	for(i=0;i<m/2;i++)
	{
		printf("%c ",b[i]);	
	}
	printf("\n");
#endif
	a[m/2]='\0';
	b[m/2]='\0';
	n=strcmp(a,b);
	if(n==0)
		return 0;
	else
		return -1;
}
