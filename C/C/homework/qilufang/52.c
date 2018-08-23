#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3								//候选人数
#define M 10							//选票人数

/***********结构体声明**************/
typedef struct Xup
{
	char name[20];
	int vote;
}sXup;

/***********函数声明********************/
void output(sXup *p);
void vote_1(sXup *p);
void free_1(void **p);
void input(sXup *p);

/*************开空间函数**************/
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}

/****************主函数*******************/
int main()
{
	int i;
	sXup s[N];
	input(&s[0]);	
	vote_1(&s[0]);
	output(&s[0]);
	return 0;
}

/*******************输入函数****************/
void input(sXup *p)
{
	int i,j;
	printf("分别输入%d个候选人的名字：\n",N);
	for(i=0;i<N;i++)
	{
		scanf("%s",p[i].name);
	}
}

/*****************选票函数*********************/
void vote_1(sXup *p)
{
	int i,l,j,k,vote_1[N]={0},f;
	char *name_1[M];
	for(l=0;l<M;l++)
	{
		getmemory((void **)&name_1[l],sizeof(char)*20);
		printf("请输入要投票的人姓名:\n");
		scanf("%s",name_1[l]);
	}	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(strcmp(p[j].name,name_1[i])==0)		//当选票名和候选人名一
			{										//			样时
				vote_1[j]+=1;
			}
		}
	}
	for(k=0;k<N;k++)
	{
		p[k].vote=vote_1[k];						//将得票数附给结构体中
	}												//	本人得票
	for(f=0;f<N;f++)
	{
		free_1((void **)&name_1[f]);
	}
}

/********************输出函数*******************/
void output(sXup *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("Name:%s vote:%d\n",p[i].name,p[i].vote);
	}
}

/*****************清空间函数**********************/
void free_1(void **p)
{
	if(*p != NULL)
	{
		free(*p);
		*p=NULL;
	}
}
