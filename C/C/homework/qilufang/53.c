#include<stdio.h>
#include<stdlib.h>
#define L 5			//最多学校数
#define N 10			//最多班级数
#define M 50			//班级最多学生数
typedef struct student
{
	char *pname;
	int score;
}sStu,*pStu;
typedef struct class
{
	struct student *stu_stu;
}sStuCla,*pStuCla;
typedef struct school
{
	struct class *stu_cla;
}sStuSch,*pStuSch;
void input_number(int sch_nb,int *cla_nb,int(*stu_nb)[M]);
int main()
{
	int x;
	int i,j;
	int class[N];
	int student[N][M];
	printf("输入学校个数：\n");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		printf("输入%c学校的班级数：\n",i+65);
		scanf("%d",&class[i]);
		for(j=0;j<class[i];j++)
		{
			printf("输入%c学校的%c班级的人数：\n",i+65,j+97);
			scanf("%d",&student[i][j]);
		}
	}
	input_number(x,class,student);
	return 0;
}
void input_number(int sch_nb,int *cla_nb,int (*stu_nb)[M])
{
	int i=0,j,k;
	int sum_cla=0,sum_sch=0;
	int *class_aver;
	int *sch_aver;
	pStuSch sch;
	sch=malloc(sch_nb*sizeof(sStuSch));
	sch_aver=malloc(sch_nb*sizeof(int));
	for(i=0;i<sch_nb;i++)
	{
		(sch+i)->stu_cla=malloc(cla_nb[i]*sizeof(sStuCla));
		class_aver=malloc(cla_nb[i]*sizeof(int));
		sum_sch=0;
		for(j=0;j<cla_nb[i];j++)
		{
				sch[i].stu_cla[j].stu_stu=
						malloc(stu_nb[i][j]*sizeof(sStu));
			sum_cla=0;
			for(k=0;k<stu_nb[i][j];k++)
			{
				(sch+i)->stu_cla[j].stu_stu[k].pname=
						malloc(10*sizeof(char));
				printf("输入%c学校 %c班级的 %d学生的Name和Score:\n"
								,i+65,j+97,k+1);
				scanf("%s%d",sch[i].stu_cla[j].stu_stu[k].pname,
							&sch[i].stu_cla[j].stu_stu[k].score);
				sum_cla+=sch[i].stu_cla[j].stu_stu[k].score;
			}
			class_aver[j]=sum_cla/stu_nb[i][j];
			printf("AVER %c学校 %c班级的平均值是：%d\n",
							i+65,j+97,class_aver[j]);
			sum_sch+=class_aver[j];
		}
		sch_aver[i]=sum_sch/cla_nb[i];
		printf("AVER %c学校的平均值是：%d\n",i+65,sch_aver[i]);
	}
	free(sch);
	free(sch_aver);
}
