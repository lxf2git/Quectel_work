#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char  *malloc_(int n)
{
	char *p;
	p = (char *)malloc(n * sizeof(char));
	if(NULL == p)
	{
		printf("失败");
		exit(-1);
	}
	return p;
}

char in_put(char *p)
{
	printf("请输入一个字符串");
	scanf("%s",p);
	getchar();
	return *p;
}	
void sel_(char *p,char *p1)
{
	int judge; 
	printf("请输入一个数");
	scanf("%d",&judge);
	if(1 == judge)
	{
		strcat(p,p1);
		printf("%s\n",p);
	}
	if(-1 == judge)
	{
		strcat(p1,p);
		printf("%s\n",p1);
	}
	if(judge != 1 || judge != -1)
	{
		p = "NULL";
		printf("%s\n",p);
	}

}


int main()
{
	char *p = NULL, *p1 = NULL;
	int n = 100;
	p =(char *) malloc_(n);
	p1 =(char *) malloc_(n);
	*p = in_put(p);
	*p1 = in_put(p1);
	sel_(p,p1);
	if(p != NULL)
	{
		free(p);
		p = NULL;
	}
	if(NULL != p1)
	{
		free(p1);
		p1 = NULL;
	}
}
