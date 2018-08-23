#include<stdio.h>
#include<stdlib.h>

#define N 20

typedef struct student
{
	char *pname;
	int score;
}sStu,*pStu;

typedef struct class
{
	sStu *stu_stu;
}sStuCla,*pStuCla;

typedef struct school
{
	sStuCla *stu_cla;
}sStuSch,*pStuSch;

void creat_memory(void **p,int size);
float input_cla(pStuCla p);
float input_stu(pStu p);
void fun(pStuSch p); 
void i_free(void **p);

int main()
{
	pStuSch p=NULL;
	fun(p);
	return 0;
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("mallco error\n");
		exit(-1);
	}
}


void fun(pStuSch p)
{
	int i,m;
	float s=0;
	printf("请输入有多少个学校\n");
	scanf("%d",&m);
	creat_memory((void **)&p,m*sizeof(sStuSch));
	for(i=0;i<m;i++)
	{
		printf("请输入学校有多少班级\n");
		s=s+input_cla(p[i].stu_cla);
	}
	printf("所有人平均分：%.2f\n",s/m);
	i_free((void **)&p);
}

float input_cla(pStuCla p)
{
	int m,i;
	float s=0;
	scanf("%d",&m);
	creat_memory((void **)&p,m*sizeof(sStuCla));
	for(i=0;i<m;i++)
	{
		printf("请输入班级有多少人\n");
		s=s+input_stu(p[i].stu_stu);
	}
	printf("该校平均分：%.2f\n",s/m);
	i_free((void **)&p);
	return s/m;
}

float input_stu(pStu p)
{
	int i,m;
	float s=0;
	scanf("%d",&m);
	creat_memory((void **)&p,m*sizeof(sStu));
	for(i=0;i<m;i++)
	{
		printf("请输入学生姓名 成绩\n");
		creat_memory((void **)&p[i].pname,N*sizeof(char));
		scanf("%s",p[i].pname);
		getchar();
		scanf("%d",&p[i].score);
		s=s+p[i].score;
	}
	printf("该班平均分：%.2f\n",s/m);
	for(i=0;i<m;i++)
	{
		i_free((void **)&p[i].pname);
	}
	i_free((void **)p);
	return s/m;
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
