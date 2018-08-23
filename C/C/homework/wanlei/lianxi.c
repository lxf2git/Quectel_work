#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 3

void fun(char **p);
void creat_memory(void **p, int size);
void input(char **p);
void judge(char **p);
int max(int *p);

int main()
{
	char *p[N];
	fun(p);
	//input((char**)&p);
	input(p);
	//judge(p);
	return 0;
}

void fun(char **p)
{
	int i;
	int a;
	for(i=0;i<N;i++)
	{
		printf("请输入要开的空间字节数\n");
		scanf("%d",&a);
		creat_memory((void **)(p+i),a*sizeof(char));
	}
}

void creat_memory(void **p, int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void input(char **p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("请输入字符串\n");
		scanf("%s",*(p+i));
	}
	judge(p);
}

void judge(char **p)
{
	int i;
	int *p1;
	printf("* ");
	for(i=0;i<N;i++)
	{
		p1[i]=strlen(p[i]);//*(p1+i)
		printf("%d ",p1[i]);
	}
	int a=max(p1);
	printf("%s\n",p[a]);
}

int max(int *p)
{
	int i;
	int Max=p[0];
	int flag=0;
	for(i=0;i<N;i++)
	{
		if(Max<p[i])
		{
			Max=p[i];
			flag=i;
		}
	}
	printf("max:%d\n",flag);
	return flag;
}
