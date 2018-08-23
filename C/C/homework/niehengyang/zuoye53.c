#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
	char *pname;
	int score;
}sStu,*pStu;
typedef struct Class
{
	sStu *stu_stu;
}sStuCla ,*pStuCla;

typedef struct School
{
	sStuCla *stu_cla;
}sStuCh,*pStuCh;
void input_t(int ,int,int );


int main()
{
	int i,j,k;
	int x,y,z;
	pStuCh *ch;
	int sch_nu;
	printf("please input the number of school:\n");
	 scanf("%d",&x);
	ch=(sStuCh *)malloc(sc*sizeof (sStuCh));
	

}




/*int main()
{
	int i,j,k;
	int x,y,z;
	psStuSch sch;
	printf("shuru x:\n");
	scanf("%d",&x);
	sch->stu_cla=(pStuCla)malloc(x*sizeof(sStuCla));
	printf("please input the number of class:\n");
	for(i=0;i<x;i++)
	{
		scanf("%d",&sch->stu_cla+i);
	}
	
	sch->stu_cla->stu_stu=(pStu)malloc()
	printf("please input the number of student:\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<stu_cla+i;j++)
		{
			scanf("%d",&(sch->stu_cla->stu_stu+i)+j);
		}
	}
	
}

void input_t(int x,int *cla,int **st)
{
		int i,j,k;
		sStuCh *ch;
		for(i=0;i<x;i++)
		{
			//ch=(int *)malloc(x*)
			for(j=0;j<(cla+i);j++)
			{
				printf("%d,school:%d,class:",i,j);
				for(k=0;k<(st+i)+j;k++);
				{
					((ch->stu_cla)->stu_stu)->name=(char *)malloc(20*sizeof(char));
					printf("please input the name,score:\n");
					scanf("%s",((ch->stu_cla)->stu_stu)->name);
					getchar();
					scanf("%d",((ch->stu_cla)->stu_stu)->score);
				}
			}
		}
		for(i=0;i<x;i++)
		{
			for(j=0;j<(cla+i);j++)
			{
				for(k=0;k<(st+i)+j;k++)
				{
					printf("%s %d",((ch->stu_cla)->stu_stu)->name,((ch->stu_cla)->stu_stu)->score);
				}
			}
		}

}*/
