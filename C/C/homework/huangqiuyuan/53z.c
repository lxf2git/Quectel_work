#include<stdio.h>
#include<stdlib.h>
typedef struct stdent
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
	int i,j,m,n,cla,stu,stusco,clasco;
	pStuSch Sch;
	printf("输入学校个数：");
	scanf("%d",&i);
	Sch=(pStuSch)malloc(i*sizeof(sStuSch));
	for(j=0;j<i;j++)
	{
		printf("第%d所学校有几个班级：",j+1);
		clasco=0;
		scanf("%d",&cla);
		Sch->stu_cla=(pStuCla)malloc(cla*sizeof(sStuCla));
			for(m=0;m<cla;m++)
			{
				printf("第%d个班级有多少个学生：",m+1);
				scanf("%d",&stu);
					Sch->stu_cla->stu_stu=(pStu)malloc(stu*sizeof(sStu));
					stusco=0;
					for(n=0;n<stu;n++)
					{
						printf("输入第%d个学生姓名和成绩用回车分开：",n+1);
						Sch->stu_cla->stu_stu->pname=(char*)malloc(20*sizeof(char));			
						scanf("%s%d",Sch->stu_cla->stu_stu->pname,&Sch->stu_cla->stu_stu->score);
						stusco=Sch->stu_cla->stu_stu->score+stusco;
					}
						printf("这个班的平均成绩为：%d\n",stusco/stu);
							clasco=clasco+stusco/stu;
			}
						printf("这个学校的平均成绩为：%d\n",clasco/cla);

	}

		//printf()



	return 0;
}
