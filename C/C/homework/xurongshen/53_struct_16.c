#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

typedef struct Student
{
	char *pname;
	int score;
}sStu,*pStu;

typedef struct Class
{
	sStu *stu_stu;
}sStuCla,*pStuCla;

typedef struct School
{
	sStuCla *stu_cla;
}sStuSch,*pStuSch;

void create_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL == *p)
	{
		printf("malloc error!\n");
		error(-1);
	}
}

float input3(pStu *p,int t)
{
	int i,sum_cla=0;
	float avg_cla=0;
	char *pname;
	create_memory((void **)p,t*sizeof(sStu));
	create_memory((void **)&pname, 20*sizeof(char));
	for(i=0;i<t;i++)
	{
		printf("please input name:");
		scanf("%s",((*p)+i)->pname);
		getchar();
		getchar();
		printf("please input score:");
		scanf("%d",&(((*p)+i)->score));
		sum_cla = sum_cla + ((*p)+i)->score;
//		printf("input 3--->%d score:%d\n",i+1,sum_cla);
	}
	avg_cla = 1.0*sum_cla/t;
//	printf("t:%d\n",t);
	printf("每个班级的平均成绩是avg_cla:%f\n",avg_cla);
	return avg_cla;
}

float input2(pStuCla *p,int m,int t)
{
//	printf("input 2----->\n");
	int i;
	float avg_sch=0;
	float sum_sch=0;
	pStu pstu;
	create_memory((void **)p,m*sizeof(sStuCla));
	for(i=0;i<m;i++)
	{
		sum_sch =sum_sch+ input3(&pstu,t);
	}
		avg_sch = sum_sch/m;
	printf("每个学校的平均成绩是 avg_sch:%f\n",avg_sch);
	return avg_sch;
}

void input1(pStuSch *p,int n,int m,int t)
{
	printf("input 1----->\n");
	int i,avg_sch[N]={};
	float avg,sum_sch;
	pStuCla pCla;
	create_memory((void **)p,n*sizeof(sStuSch));
	for(i=0;i<n;i++)
	{
		avg_sch[i] = input2(&pCla,m,t);
		sum_sch = sum_sch+avg_sch[i];
	}
		avg = 1.0*sum_sch/n;
	printf("%d个学校的平均成绩是 avg:%f\n",n,avg);
}

int main()
{
	int x,y,z;
	pStuSch ptr1;
//	pStuCla ptr2;
//	pStu ptr3;
	printf("please input the num of school,class,student:");
	scanf("%d%d%d",&x,&y,&z);
	input1(&ptr1,x,y,z);
	return 0;

}
