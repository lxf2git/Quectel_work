#include<stdio.h>
#include<stdlib.h>
#define N 3
/*********结构体声明***************/
typedef struct student
{
	int id;
	char *name;
	int score;
}sStu;
void free_1(void **p);
void input(sStu *p);
void output(sStu *p);

/**********创建空间函数************/
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemoty_error!\n");
		exit(-1);
	}
}

/************主函数*************/
int main()
{
	int i;
	sStu p[N];
	input(&p[0]);
	output(&p[0]);
	return 0;

}

/**********输入函数*************/
void input(sStu *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("please input (id name score):\n");
		p[i].name=(char *)malloc(20*sizeof(char));
		scanf("%d%s%d",&p[i].id,p[i].name,&p[i].score);
	}
}

/**************输出函数*******************/
void output(sStu *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("Id:%d Name:%s Score:%d\n",p[i].id,p[i].name,p[i].score);
		if(p[i].score<60)
		{
			printf("加油！\n");
		}
		else
		{
			printf("Good!\n");
		}
	}
}

/************清空间函数************************/
void free_1(void **p)
{
	if(*p != NULL)
	{
		free(*p);
		*p=NULL;
	}
}
