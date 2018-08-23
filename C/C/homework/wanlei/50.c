#include<stdio.h>
#include<stdlib.h>

#define N 20

typedef struct people
{
	char *name;
	int age;
}*Peo;

void creat_memory(void **p,int size);
void input(Peo p,int x);
void max(Peo p,int x);
void i_free(void **p);

int main()
{
	Peo p;
	int n;
	printf("请输入参与比较的人数\n");
	scanf("%d",&n);
	creat_memory((void **)&p,n*sizeof(struct people));
	input(p,n);
	max(p,n);
	return 0;
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

void input(Peo p,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		creat_memory((void **)&p[i].name,N*sizeof(char));
		printf("请输入姓名 年龄\n");
		scanf("%s%d",p[i].name,&p[i].age);
	}
}

void max(Peo p,int x)
{
	int i;
	int m=p[0].age;
	int flag=0;
	for(i=0;i<x;i++)
	{
		if(m<p[i].age)
		{
			m=p[i].age;
			flag=i;
		}
	}
	printf("最大年龄的名字：%s年龄：%d\n",p[flag].name,p[flag].age);
	for(i=0;i<x;i++)
	{
		if(p[i].name!=NULL)
		{
			free(p[i].name);
			p[i].name=NULL;
		}
	}
	if(p!=NULL)
	{
		free(p);
		p=NULL;
	}
}
void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
