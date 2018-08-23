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
	int x,y,z;
	int i,j,k;
	int sum=0,sum_ave=0;
	int ave_cla,ave_sch;
	printf("有几个学校:\n");
	scanf("%d",&x);
	sStuSch *p;
	p=(struct school *)malloc(x*sizeof(struct school));
	for(i=0;i<x;i++)
	{
		printf("第%d个学校有几个班级:\n",i+1);
		scanf("%d",&y);
		p[i].stu_cla=(pStuCla)malloc(y*sizeof(struct class));
		for(j=0;j<y;j++)
		{
			printf("第%d班级有几个人\n",j+1);
			scanf("%d",&z);
			p[i].stu_cla[j].stu_stu=(pStu)malloc(z*sizeof(struct student));
			for(k=0;k<z;k++)
			{
				p[i].stu_cla[j].stu_stu[k].pname=(char *)malloc(10*sizeof(char));
				printf("输入姓名 成绩:\n");
				scanf("%s%d",p[i].stu_cla[j].stu_stu[k].pname,&p[i].stu_cla[j].stu_stu[k].score);
				sum+=p[i].stu_cla[j].stu_stu[k].score;
				if(p[i].stu_cla[j].stu_stu[k].pname != NULL)
				{
					free(p[i].stu_cla[j].stu_stu[k].pname);
				}
			}
			ave_cla=sum/z;
			printf("第%d个班级平均分为:%d\n",j+1,ave_cla);
			sum=0;
			sum_ave+=ave_cla;
			if(p[i].stu_cla[j].stu_stu != NULL)
			{
				free(p[i].stu_cla[j].stu_stu);
				p[i].stu_cla[j].stu_stu=NULL;
			}
		}
		ave_sch=sum_ave/y;
		printf("第%d个学校的平均成绩为:%d\n",i+1,ave_sch);
		sum_ave=0;
		if(p[i].stu_cla != NULL)
		{
			free(p[i].stu_cla);
			p[i].stu_cla=NULL;
		}
	}
	if(p != NULL)
	{
		free(p);
		p=NULL;
	}


	return 0;

}
