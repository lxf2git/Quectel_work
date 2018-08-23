#include<stdio.h>
#include<stdlib.h>

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


int main()
{
    int school_count,class_count,student_count;
	int i,j,k;
	int sum = 0;
	int sum_total = 0;
	int student_total = 0;
	int average;
	int average_school;
	int m = 0;
	pStuSch p;
	pStuCla po;
	pStu poi;
	p = (pStuSch)malloc(20);
	po = (pStuCla)malloc(20);
	poi = (pStu)malloc(20);

	printf("请输入学校的个数：");
	scanf("%d",&school_count);
	for(i=1;i<=school_count;i++)
	{
			printf("请输入第%d个学校的班级个数：",i);
			scanf("%d",&class_count);
			(p+i)->stu_cla = (sStuCla *)malloc(100);
			for(j=0;j<class_count;j++)
			{

					(po+j)->stu_stu = (sStu *)malloc(100);
					printf("请输入第%d个学校第%d个班级的学生人数：",i,j+1);
					scanf("%d",&student_count);
					student_total = student_total + student_count;
					printf("请输入每个学生的名字 成绩：\n");

					for(k=0;k<student_count;k++)
					{
							(poi+k)->pname = (char *)malloc(100);
							scanf("%s%d",(poi+k)->pname,&(poi+k)->score);
							sum = sum+(poi+k)->score;
					}

					average = sum/student_count;
					printf("第%d个学校第%d个班级的平均成绩：%d\n",i,j+1,average);
					sum_total = sum_total +sum;
					sum = 0;

			}

	printf("第%d个学校 有%d个班 \n",i,class_count);
	average_school = sum_total/student_total;
	printf("第%d个学校的平均成绩：%d\n",i,average_school);
	printf("\n");
	student_total = 0;
	sum_total = 0;

	}

	return 0;
}
