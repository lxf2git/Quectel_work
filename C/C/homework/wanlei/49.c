#include<stdio.h>
#include<stdlib.h>

#define N 3
#define M 20

typedef struct Student
{
	int id;
	char *name;
	int math_score;
}*sStu2,Stu[N];

void input(sStu2 p);
void creat_memory(void **p,int size);
void judge(sStu2 p);

int main()
{
		Stu stu;
		input(stu);
		judge(stu);
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

void input(sStu2 p)
{
	int i;
	for(i=0;i<N;i++)
	{
		creat_memory((void **)&p[i].name,M*sizeof(char));
		do
		{
		printf("请输入学号 姓名 数学\n");
		scanf("%d",&p[i].id);
		getchar();
		scanf("%s",p[i].name);
		scanf("%d",&p[i].math_score);
		}while((p[i].math_score>100||p[i].math_score<0)&&printf("重新"));
	}
}

void judge(sStu2 p)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(p[i].math_score>60)
		{
			printf("%sgood\n",p[i].name);
		}
		else
		{
			printf("%s加油\n",p[i].name);
		}
	}
	for(i=0;i<N;i++)
	{
		if(p[i].name=NULL)
		{
			free(p[i].name);
			p[i].name=NULL;
		}
	}
}
