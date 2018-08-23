#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fun(char **p);
void creat_memory(void **p,int size);
void input(char *p);
void change(char *p);
void i_free(void **p);

int main()
{
	char *p=NULL;
	fun(&p);
	input(p);
	change(p);
	return 0;
}

void fun(char **p)
{
	int n;
	printf("请输入要开的空间字节数\n");
	scanf("%d",&n);
	creat_memory((void **)p,n*sizeof(char));
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void input(char *p)
{
	printf("请输入要输入的字符串\n");
	scanf("%s",p);
}

void change(char *p)
{
	int m=strlen(p);
	//printf("m:%d ",m);
	int n,i,s;
	char *q=NULL;
	creat_memory((void **)&q,(m+1)*sizeof(char));
	printf("请输入右移的步数\n");
	scanf("%d",&n);
	s=n%m;
	for(i=0;i<m;i++)
	{
		if(i<s)
		{
			q[i]=p[m+i-s];
			//printf("q[%d]:%c ",i,q[i]);
		}
		else
		{
			q[i]=p[i-s];
			//printf("q[%d]:%c ",i,q[i]);
		}
	}
	//q[m]='\0';
	puts(q);
	i_free((void **)&p);
	i_free((void **)&q);
}

void i_free(void **p)
{
	if(*p=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
