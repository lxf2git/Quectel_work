#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10


void input1(char aa1[N])
{
	int i;
	printf("请输入一个字符串：");
	gets(aa1);
#if 0
	for(i=0;i<N;i++)
	{
		scanf("%c",&aa1[i]);
	}
#endif

	puts(aa1);
}

char * strcpy1(char *p1, char *p2)
{
	int i,j;
	char * arr=p1;
	for(i=0;i<N;i++)
	{
		*p1 = *p2;
//		printf("*p1:%c",*p1);
		p1++;
		p2++;
	}
	return arr;
}

char * strcat1(char *p1, char *p2)
{
	int i,j;
	char *prr=p1;
	while(*p1 != 0)
	{
		p1++;
	}
	for(i=0;i<N;i++)
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
//	printf("p1:%s\n",p1);
	return prr;
}

int  strcmp1(char *p1, char *p2)
{
	int i,j;

	for(i=0;i<N;i++)
	{
		if(*p1 == *p2)
		{
			j = 0;
			return j; 
		}
		if(*p1>*p2)
		{
			j=1;
			return j;
		}
		if(*p1<*p2)
		{
			j=-1;
			return j;
		}
		
	}
}

int main()
{
	int i,j;
	char arr[N]={};
	char brr[N]={};
	char crr[N]={};
	char * p=NULL;
	int  m;
	input1(arr);
	input1(brr);
	p = strcat1(arr,brr);
		printf("*p---->strcat:%s\n",p);
	m = strcmp1(arr,brr);
		printf("*m---->strcmp:%d\n",m);
	p = strcpy1(arr,brr);
		printf("*p---->strcpy1:%s\n",p);
		
	p=NULL;
	return 0;

}
