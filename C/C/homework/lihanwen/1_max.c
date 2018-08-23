#include<stdio.h>	
#include<stdlib.h>
#include<string.h>
#define N 2
void shuru(char *p[]);
void kaikongjian(char **p,int size);
void luru(char **p);
void bijiao(char *p);

int main()
{
	int i;
	int *ptr[N];
	shuru(ptr);	
//	shuchu(ptr);
	bijiao(ptr);

	return 0;
}

void shuru(char *p[])
{
	int i,size;
	for(i=0;i<N;i++)
	{
		printf("请输入第%d个字符串长度:\n",i+1);
		scanf("%d",&size);
		kaikongjian(&p[i],size);
	}
	luru(p);
}

void kaikongjian(char **p,int size)
{
	*p=(char *)malloc(size);
	if(NULL==*p)
	{
		printf("malloc error");
		exit(-1);
	}
}

void luru(char **p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("请输入字符串:\n");
		scanf("%s",*(p+i));
	}
}

void bijiao(char *p)
{
	int i,j;
	char t;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(strcmp(p[i],p[j])<0)
			{
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%s\n",p[i]);
	}
}
/*
void shuchu(char **p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%s\n",p[i]);
	}
}*/
