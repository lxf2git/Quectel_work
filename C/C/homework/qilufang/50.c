#include<stdio.h>
#include<stdlib.h>
/************结构体声明******************/
typedef struct People
{
	char *name;
	int age;
}sPe;

/***********函数声明*********************/
void input(sPe *p,int m);
void output(int max,sPe *p,int m);
void deal(sPe *p,int m);
void free_1(void **p);

/**************开空间函数***************/
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}	

/***************主函数*******************/
int main()
{
	int nb,i;
	printf("输入要输入的人数：\n");
	scanf("%d",&nb);
	sPe arr[nb];
	input(&arr[nb],nb);
	deal(&arr[nb],nb);
	for(i=0;i<nb;i++)					//释放空间
	{
		free_1((void **)&arr[i]);
		free_1((void **)&arr[i].name);
	}
	return 0;

}

/*************输入函数****************/
void input(sPe *p,int m)
{
	int i;
	for(i=0;i<m;i++)
	{	
		printf("Input Name Age please!\n");
		getmemory((void **)&p[i],sizeof(sPe));
		getmemory((void **)&p[i].name,sizeof(char));
		scanf("%s%d",p[i].name,&p[i].age);
	}
}

/************执行函数********************/
void deal(sPe *p,int m)
{
	int i,max=0;
	for(i=0;i<m;i++)
	{
		if(p[i].age>max)
		{
			max=p[i].age;						//取最大年龄
		}
	}
	output(max,p,m);
}

/************输出函数**********************/
void output(int max,sPe *p,int m)
{
	int	i;
	for(i=0;i<m;i++)
	{
		if(p[i].age==max)
		printf("Name:%s Age:%d\n",p[i].name,p[i].age);
	}
}

/************释放空间函数*********************/
void free_1(void **p)
{
	if(NULL != *p)
	{
		free(*p);
		*p=NULL;
	}
}
