#include<stdio.h>
#include<stdlib.h>

typedef struct score_list
{
	char name[20];
	int math;
	int chinese;
	int english;
}Scor;

void creat_memory(void **p,int size);
void input(Scor *p,int x);
void av(Scor *p,int x);
void select_(Scor *p,int *q,int y);
void i_free(void **p);

int main()
{
	int n;
	Scor *p=NULL;
	printf("请输入本次测试的总人数\n");
	scanf("%d",&n);
	creat_memory((void **)&p,n*sizeof(Scor));
	input(p,n);
	av(p,n);
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

void input(Scor *p,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("请输入姓名 语文 数学 英语成绩\n");
		scanf("%s%d%d%d",p[i].name,&p[i].math,&p[i].chinese,&p[i].english);
	}
}

void av(Scor *p,int x)
{
	int s_math=0,s_chinese=0,s_english=0,i;
	int aver_math,aver_chinese,aver_english,aver;
	int *all;
	creat_memory((void **)&all,x*sizeof(int));
	for(i=0;i<x;i++)
	{
		s_math=s_math+p[i].math;
		s_chinese=s_chinese+p[i].chinese;
		s_english=s_english+p[i].english;
		all[i]=p[i].math+p[i].chinese+p[i].english;
	}
	aver_math=s_math/x;
	aver_chinese=s_chinese/x;
	aver_english=s_english/x;
	aver=aver_math+aver_chinese+aver_english;
	printf("math:%d chinese:%d english:%d all:%d\n",aver_math,aver_chinese,aver_english,aver);
	select_(p,all,x);
}

void select_(Scor *p,int *q,int y)
{
	int i,j;
	Scor *p1;
	creat_memory((void **)&p1,sizeof(Scor));
	int ex;
	for(i=0;i<y;i++)
	{
		for(j=0;j<i;j++)
		{
			if(q[i]<q[j])
			{
				ex=q[i];
				q[i]=q[j];
				q[j]=ex;
				*p1=p[i];
				p[i]=p[j];
				p[j]=*p1;
			}
		}
	}
	for(i=0;i<y*0.3;i++)
	{
			printf("name:%s math:%d chinese:%d endlish:%d\n",p[i].name,p[i].math,p[i].chinese,p[i].english);
	}
	i_free((void **)&p);
	i_free((void **)&q);
	i_free((void **)&p1);
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
