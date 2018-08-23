#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	char b[100];
	printf("输入字符串:\n");
	scanf("%s",a);
	printf("在输入字符串:\n");
	scanf("%s",b);
	mystrcpy(a,b);
	return 0;
}


int mystrcpy(char *p,char *q)
{
	int m,n;
	m=(int)strlen(p);
	n=(int)strlen(q);
	if(m<n)
	{	printf("错了  段错误!\n");
		return 0;
	}
	if(m>=n)
	{
		while(n>0)
		{
			*p=*q;
			printf("%c",*p);
			q++;
			p++;
			n--;
		}
		printf("\n");
		return 0;
	}
}


