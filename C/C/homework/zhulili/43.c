#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4

void create_memory(char **q,int size)
{
	*q = (char *)malloc(size);
	if(NULL==*q)
	{
		printf("malloc error");
		exit(-1);
	}
}

int main()
{
	char *p;
	char *q;
	int i,n=0,size,j;
	printf("请输入字符串空间大小:");
	scanf("%d",&size);
	create_memory(&p,size);
	create_memory(&q,size);
	printf("请输入一个字符串\n");\
	scanf("%s",p);
	n=strlen(p);
	for(i=0;i<n;i++)
	{
		printf("%c",*(p+i));
		for(j=0;j<2*i+1;j++)
		{
			if(i==n-1)
			break;
			printf("#");
		}
	}
	printf("\n");
	if(p!=NULL)
	{
		free(p);
		p = NULL;
	}
	if(q!=NULL)
	{
		free(q);
		q = NULL;
	}
	return 0;
}
