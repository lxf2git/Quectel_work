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
void input(pStuSch p,int x);
void aver(pStuSch p,int x,int *q1,int **q2);
void i_free(void **p);

int main()
{
	pStuSch p=NULL;
	printf("请输入学校数\n");
	int m;
	scanf("%d",&m);
	creat_memory((void **)&p,m*sizeof(sStuSch));
	input(p,m);
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

void input(pStuSch p,int x)
{
	int i,j,k;
	int *q1=NULL;
	int **q2=NULL;
	creat_memory((void **)&q1,x*sizeof(int));
	creat_memory((void **)&q2,x*sizeof(int *));
	for(i=0;i<x;i++)
	{
		printf("第%d所学校有几个班级\n",i+1);
		scanf("%d",&q1[i]);
		creat_memory((void **)&q2[i],q1[i]*sizeof(int));
		creat_memory((void **)&p[i].stu_cla,q1[i]*sizeof(sStuCla));
		for(j=0;j<q1[i];j++)
		{
			printf("请输入%d校%d班有多少学生\n",i+1,j+1);
			scanf("%d",&q2[i][j]);
			creat_memory((void **)&p[i].stu_cla[j].stu_stu,
							q2[i][j]*sizeof(sStu));
			for(k=0;k<q2[i][j];k++)
			{
				creat_memory((void **)&p[i].stu_cla[j].stu_stu[k].pname,
								N*sizeof(char));
				printf("请输入%d校%d班学生姓名 成绩\n",i+1,j+1);
				scanf("%s",p[i].stu_cla[j].stu_stu[k].pname);
				getchar();
				scanf("%d",&p[i].stu_cla[j].stu_stu[k].score);
			}
		}
	}
	aver(p,x,q1,q2);
}

void aver(pStuSch p,int x,int *q1,int **q2)
{
	int i,j,k;
	float all_cla=0;
	float all_sch=0;
	for(i=0;i<x;i++)
	{
		all_sch=0;
		for(j=0;j<q1[i];j++)
		{
			all_cla=0;
			for(k=0;k<q2[i][j];k++)
			{
				all_cla=all_cla+p[i].stu_cla[j].stu_stu[k].score;
				i_free((void **)&p[i].stu_cla[j].stu_stu[k].pname);
			}
			printf("%d校%d班平均成绩为：%.2f\n",i+1,j+1,all_cla/q2[i][j]);
			all_sch=all_sch+all_cla/q2[i][j];
			i_free((void **)&p[i].stu_cla[j].stu_stu);
		}
		//printf("%d校 all_sch:%.2f \n",i+1,all_sch);
		printf("%d校的平均成绩为：%.2f\n",i+1,all_sch/q1[i]);
		i_free((void **)&p[i].stu_cla);
		i_free((void **)&q2[i]);
	}
	i_free((void **)&p);
	i_free((void **)&q2);
	i_free((void **)&q1);
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
