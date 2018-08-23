#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5
#define M 20

void fun(char **p);
void creat_memory(void **p,int size);
void *input(char **p,int n);
void find(char **p,int *q,int n);
void output(char **p,char **q, int n);
void i_free(void **p);

int main()
{
	char *p[N];
	fun((char **)&p);
	return 0;
}

void fun(char **p)
{
	int n,s,i;
	printf("请输入要比较的字符串数\n");
	scanf("%d",&n);
	//creat_memory((void **)&p,n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		printf("请输入空间长度\n");
		scanf("%d",&s);
		creat_memory((void **)(p+i),s*sizeof(char *));
	}
	input(p,n);
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

void *input(char **p,int n)
{
	int i;
	int *q=NULL;
	creat_memory((void **)&q,n*sizeof(int));	
	for(i=0;i<n;i++)
	{
		printf("请输入字符串\n");
		scanf("%s",p[i]);
		q[i]=strlen(p[i]);
	}
	find(p,q,n);
#if 0
	for(i=0;i<n;i++)
	{
		printf("%d ",q[i]);	
	}
#endif
}

void find(char **p,int *q,int n)
{
	int i,j;
	char **str=NULL;
	creat_memory((void **)&str,n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		creat_memory((void **)(str+i),M*sizeof(char));
	}
	//printf("*");
	for(i=0;i<n;i++)
	{
		for(j=0;j<(q[i]+1)/2;j++)
		{
			str[i][j]=p[i][q[i]-j-1];
		}
	}
	i_free((void **)&q);
	output(p,str,n);
#if 0
	for(i=0;i<n;i++)
	{
		printf("%s\n",str[i]);
	}
#endif
}

void output(char **p,char **q, int n)
{
	int i,j;
	char *str=NULL;
	creat_memory((void **)&str,M*sizeof(char));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(strcmp(q[i],q[j])<0)
			{
				strcpy(str,q[i]);
				strcpy(q[i],q[j]);
				strcpy(q[j],str);
				strcpy(str,p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],str);
			}
		}
	}

	for(i=0;i<n;i++)
	{
		puts(p[i]);
		//puts(q[i]);
	}
	for(i=0;i<n;i++)
	{
		i_free((void **)(p+i));
	}
	//i_free((void **)&p);
	for(i=0;i<n;i++)
	{
		i_free((void **)(q));
	}
	i_free((void **)&q);
	i_free((void **)&str);
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
