#include<stdio.h> 
#include<stdlib.h> 
#define N 100

typedef struct student  //每个班级里的学生名及成绩，被班级嵌套。
{
	char *pname;
	int score;
}sStu,*pStu;
typedef struct class  //每个学校里的班级，被学校嵌套。
{
	sStu *stu_stu;
}sStuCla,*pStuCla;
typedef struct school
{
	sStuCla *stu_cla;
}sStuSch,*pStuSch;

void print(int scor[][N],int *scor_sch,int sh_nu)
{
	int cla_nu,sch_nu;
	for(sch_nu=0;sch_nu<N;sch_nu++)
	{
		for(cla_nu=0;cla_nu<N;cla_nu++)
		{
			if(scor[sch_nu][cla_nu]!='\0')
				printf("第%d所高校%d班平均分:%d\n",sch_nu+1,cla_nu+1,scor[sch_nu][cla_nu]);			//输出每班平均分
		}
	}
	for(sch_nu=0;sch_nu<sh_nu;sch_nu++)
		printf("第%d所高校平均分:%d\n",sch_nu+1,scor_sch[sch_nu]);							//输出每校平均分
}

int main()
{
	int sh_nu,cla_nu,stu_nu,num,nu,an_stu,scor[N][N]={},scor_sch[N]={};
	pStuSch pschool;
	printf("请问该地区有多少高校？\n");
	scanf("%d",&sh_nu);                                                                    //输入学校数量
	pschool=(pStuSch)malloc(sizeof(sStuSch)*sh_nu);                                        //开学校空间
	for(num=0;num<sh_nu;num++)
	{
		printf("第%d座高校有多少班级？\n",num+1);
		scanf("%d",&cla_nu);								//输入班级数量
		pschool[num].stu_cla=(pStuCla)malloc(sizeof(sStuCla)*cla_nu);                  //开班级空间
		for(nu=0;nu<cla_nu;nu++)
		{	
			printf("第%d座高校的%d班有多少学生？\n",num+1,nu+1);
			scanf("%d",&stu_nu);							//输入学生数量
			pschool[num].stu_cla[nu].stu_stu=(pStu)malloc(sizeof(sStu)*stu_nu);    //开每个学生空间
				for(an_stu=0;an_stu<stu_nu;an_stu++)
				{
					printf("请输入第%d座高中的%d班%d个学生的姓名和成绩\n",num+1,nu+1,an_stu+1);
					pschool[num].stu_cla[nu].stu_stu[an_stu].pname=(char*)malloc(20*sizeof(char));
					scanf("%s%d",pschool[num].stu_cla[nu].stu_stu[an_stu].pname,&pschool[num].stu_cla[nu].stu_stu[an_stu].score);
					scor[num][nu]=scor[num][nu]+pschool[num].stu_cla[nu].stu_stu[an_stu].score;		//计算每班所有学生分数
					if(NULL!=pschool[num].stu_cla[nu].stu_stu[an_stu].pname);                                   //释放名字空间
					{
					free(pschool[num].stu_cla[nu].stu_stu[an_stu].pname);                                   //释放名字空间
					pschool[num].stu_cla[nu].stu_stu[an_stu].pname=NULL;                                   //释放名字空间
					}
				}
				if(NULL!=pschool[num].stu_cla[nu].stu_stu);
				{                                                         //释放学生空间
					free(pschool[num].stu_cla[nu].stu_stu);
					pschool[num].stu_cla[nu].stu_stu=NULL;                                                         //释放学生空间
				}                                                         //释放学生空间
				scor[num][nu]=scor[num][nu]/stu_nu;								//计算每班学生平均分
				scor_sch[num]=scor_sch[num]+scor[num][nu];							//计算学校总分
		}
		free(pschool[num].stu_cla);                                                                                     //释放班级空间
		scor_sch[num]=scor_sch[num]/cla_nu;										//计算学校平均分
	}
	free(pschool);														//释放学校空间
	print(scor,scor_sch,sh_nu);                                                                                             //调用输出函数
}
