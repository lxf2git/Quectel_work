#include<stdio.h>
#include<stdlib.h>
//#define X 2
//#define Y 2
//#define Z 2

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
void creatememory(void **p,int size);

pStuSch sch;

int main()
{

		int x,y,z;
		int (*p)(int,int,int);
		int clasco=0,schsco=0;
		for(x=0,p=fun_school;x<X;x++)
		{
				p(x,y,z);

				for(y=0,p=fun_class;y<Y;sch->stu_cla+=y++)
				{
						p(x,y,z);

						for(z=0,p=fun_student;z<Z;sch->stu_cla->stu_stu+=z++)
						{
								p(x,y,z);
						}

						schsco+=clasco;
						printf("\nSchool%d Class%d: Classavaer%d\n\n",x+1,y+1,clasco/z);
						clasco=0;
						free(sch->stu_cla->stu_stu);
				}

				printf("\nSchool%d : Schoolavaer%d\n\n",x+1,schsco/(z*y));
				schsco=0;
				free(sch->stu_cla-y);
		}
		free(sch);

		return 0;
}
int fun_school(int x,int y,int z)
{
		int X;
		printf("please input schoolnumber \n");
		scanf("%d",&X);
		creatememory( (void**)&sch ,X* sizeof(struct student) );


}
int fun_class(int x,int y,int z)
{
		int Y;
		printf("<-----------This is School%d---------->\n",x+1);
		printf("please input classnumber\n");
		scanf("%d",&Y);
		creatememory((void**)&sch->stu_cla,Y*sizeof(struct class));

}
int fun_student(int x,int y,int z)
{
		int Z;
		printf("\n<--------------Class%d----------------> \n",y+1);
		printf("please input  studentnumber\n");
		scanf("%d",&Z);
		creatememory((void **)&((sch+x)->stu_cla+y)->stu_stu,Z*sizeof(struct student));
		printf("plesae input name and score for student\n\n");

}
int fun_name(int x,int y,int z)
{
		creatememory((void **)&(((sch+x)->stu_cla+y)->stu_stu+z)->pname,20*sizeof(char));
		printf("--------->student%d:",z+1);
		scanf("%s%d",(((sch+x)->stu_cla+y)->stu_stu+y)->pname,&(((sch+x)->stu_cla+y)->stu_stu+z)->score);
		//								printf("school%dclass%d %s %d\n",x,y,sch->stu_cla->stu_stu->pname,sch->stu_cla->stu_stu->score);
		clasco+=(((sch+x)->stu_cla+y)->stu_stu+z)->score;
		free((((sch+x)->stu_cla+y)->stu_stu+z)->pname);
		return clasco;

}
int fun_classava(int x,int y,int z)
{


}
int creatememory(void **p,int size)
{
		*p=malloc(size);
}


