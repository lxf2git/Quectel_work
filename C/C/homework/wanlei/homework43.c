#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void creat_memory(void **p, int size);
int square(int x);
void input(char *p);
void change(char *p, char *q);
void i_free(void **p);

int main()
{
	char *p=NULL;
	char *q=NULL;
	printf("请输入字符串长度\n");
	int n;
	scanf("%d",&n);
	creat_memory((void **)&p,n*sizeof(char));
	int s=square(n-1);
	creat_memory((void **)&q,(s+n)*sizeof(char));
	input(p);
	change(p,q);
	i_free((void **)&p);
	i_free((void **)&q);
	return 0;
}

void creat_memory(void **p, int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

int square(int x)
{
	int s=2;
	int t=1;
	int i;
	for(i=0;i<x;i++)
	{
		t=t*s;
	}
	return t;
}

void input(char *p)
{
	printf("请输入一个字符串\n");
	scanf("%s",p);
}

void change(char *p, char *q)
{
	int i,j,n,m=strlen(p);
	int k=0;
	//printf("%d\n",m);
	n=square(m-1)+m;
	for(i=0;i<m;i++)
	{
		for(j=k;j<=n;j++)
		{
			k++;
			if(j==i*(i+1))
			{
				q[j]=p[i];
				j=k;
				break;
			}
			else
			{
				q[j]='#';
			}
		}
	}
	printf("变化后的字符串为：");
	puts(q);
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
