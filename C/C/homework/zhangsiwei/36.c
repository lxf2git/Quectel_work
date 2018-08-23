#include<stdio.h>
#include<string.h>

void judge_str(char str[])
{
	int n,i,k,a,m;
	char str1[100];
	n=strlen(str);
	printf("%d\n",n);
	m=n/2;
	strcpy(str1,str);
	puts(str1);
	for(i=0;i<m;i++)
	{
		k=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=k;
	}
	puts(str);
	a=strcmp(str1,str);
	printf("%d\n",a);
	switch(a)
	{
		case 0:
				printf("是回文\n");
				break;
		default:
				printf("不是回文\n");
				break;
	}
}

int main()
{
	char str[100];
	printf("请输入一个字符串：\n");
	gets(str);
	judge_str(str);

	return 0;
}
