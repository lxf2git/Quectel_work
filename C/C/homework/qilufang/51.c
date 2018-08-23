#include<stdio.h>
#include<stdlib.h>
#define M 3
#define N 3

/**********结构体声明*********************/
typedef struct Student
{
	char name[20];
	int math;
	int chin;
	int eng;	
}sStu;

/***************函数声明**********************/
void average(sStu *p);
void free_1(void **p);
void input(sStu *p);
void deal(sStu *p,int aver);

/****************开空间函数**********************/
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}

/*************主函数********************/
int main()
{
	int i;
	printf("输入%d个学生信息：\n",N);
	sStu arr[N];
	input(&arr[0]);
	average(&arr[0]);
	return 0;

}

/**************输入函数****************/
void input(sStu *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("input Name Math Chin Eng\n");
		scanf("%s%d%d%d",p[i].name,&p[i].math,&p[i].chin,&p[i].eng);
	}
}

/**************执行函数1*****************/
void average(sStu *p)
{
	int i,j,k,sum=0;
	int *num=NULL;
	int *aver=NULL;
	getmemory((void **)&num,sizeof(int)*M);
	getmemory((void **)&aver,sizeof(int)*M);
	for(j=0;j<M;j++)
	{
		for(i=0;i<N;i++)
		{	
			if(j==0)
			{
				*(num+j)+=p[i].math;
			}
			else if(j==1)
			{
				*(num+j)+=p[i].chin;
			}
			else if(j==2)
			{
				*(num+j)+=p[i].eng;
			}
		}	
	}
	for(k=0;k<M;k++)
	{
		sum+=*(num+k);
	}
	printf("AveMath:%d AveChin:%d AveEng:%d AVETotal:%d\n",
				*(num)/N,*(num+1)/N,*(num+2)/N,sum/N);
	deal(p,sum/N);
	free_1((void **)&num);
	free_1((void **)&aver);
}

/**************执行函数2*************************/
void deal(sStu *p,int aver)
{
	int i,j;
	int aver_1[N];
	for(i=0;i<N;i++)
	{
		aver_1[i]=(p[i].math+p[i].chin+p[i].eng)/3;
		printf("学生：%s 平均成绩是：%d\n",p[i].name,aver_1[i]);
	}
	printf("输出不及格的学生：\n");
	for(j=0;j<N;j++)
	{
		if(aver_1[j]<(aver*3)/10)
		{
			printf("Name:%s Math:%d Chin:%d Eng:%d\n",
							p[j].name,p[j].math,p[j].chin,p[j].eng);
		}
	}
}

/****************清开辟空间函数********************/
void free_1(void **p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
