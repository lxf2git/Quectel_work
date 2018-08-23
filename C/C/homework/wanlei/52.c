#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define M 20

typedef struct people
{
	char *name=NULL;
	int count;
}Peo;

void creat_memory(void **p,int size); 
void input(Peo *p,int x);
void choose(Peo *p,int x,int y);
void max(Peo *p,int x);
void i_free(void **p);

int main()
{
	Peo *p=NULL;
	int m,n;
	printf("请输入备选人和投票人的人数\n");
	scanf("%d%d",&m,&n);
	creat_memory((void **)&p,m*sizeof(Peo));
	input(p,m);
	choose(p,m,n);
	max(p,m);
	return 0;
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void input(Peo *p,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("请输入备选人姓名\n");
		creat_memory((void **)&p[i].name,M*sizeof(char));
		scanf("%s",p[i].name);
		p[i].count=0;
	}
}

void choose(Peo *p,int x,int y)
{
	int i,j;
	char choose_name[M];
	for(i=0;i<y;i++)
	{
		printf("请输入你要选择的人\n");
		scanf("%s",choose_name);
		for(j=0;j<x;j++)
		{
			if(strcmp(p[j].name,choose_name)==0)
			{
				p[j].count++;
			}
		}
	}
	for(i=0;i<x;i++)
	{
		printf("%s你的%d票\n",p[i].name,p[i].count);
	}
}

void max(Peo *p,int x)
{
	int Max=p[0].count;
	int flag=0,i;
	for(i=0;i<x;i++)
	{
		if(Max<p[i].count)
		{
			Max=p[i].count;
			flag=i;
		}
	}
	printf("恭喜你%s,你以%d票成功当选***\n",p[flag].name,p[flag].count);
	for(i=0;i<x;i++)
	{
		i_free((void **)&p[i].name);
	}
	i_free((void **)&p);
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
