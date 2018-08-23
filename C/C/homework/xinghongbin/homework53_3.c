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
void memoryfree(void *p);

int main()
{

		pStuSch sch;
		int x,y,z;
		int X,Y,Z;
		int clasco=0,schsco=0;
		printf("please input schoolnumber \n");
		scanf("%d",&X);

		creatememory( (void**)&sch ,X* sizeof(struct student) );
		for(x=0;x<X;sch++,x++)
		{
				printf("<-----------This is School%d---------->\n",x+1);
				printf("please input classnumber\n");
				scanf("%d",&Y);
				creatememory((void**)&sch->stu_cla,Y*sizeof(struct class));

				for(y=0;y<Y;sch->stu_cla++,y++)
				{
						printf("\n<--------------Class%d----------------> \n",y+1);
						printf("please input studentnumber\n");
						scanf("%d",&Z);
						creatememory((void **)&sch->stu_cla->stu_stu,Z*sizeof(struct student));
						printf("plesae input name and score for student\n\n");

						for(z=0;z<Z;sch->stu_cla->stu_stu++,z++)
						{
								creatememory((void **)&sch->stu_cla->stu_stu->pname,20*sizeof(char));
								printf("--------->student%d:",z+1);
								scanf("%s%d",sch->stu_cla->stu_stu->pname,&sch->stu_cla->stu_stu->score);
								//								printf("school%dclass%d %s %d\n",x,y,sch->stu_cla->stu_stu->pname,sch->stu_cla->stu_stu->score);
								clasco+=sch->stu_cla->stu_stu->score;
								memoryfree((void *)sch->stu_cla->stu_stu->pname);
						}

						schsco+=clasco;
						printf("\nSchool%d Class%d: Classavaer%d\n\n",x+1,y+1,clasco/z);
						clasco=0;
						memoryfree((void*)(sch->stu_cla->stu_stu-Z));
				}

				 printf("\nSchool%d : Schoolavaer%d\n\n",x+1,schsco/(z*y));
				 schsco=0;
				memoryfree((void*)(sch->stu_cla-Y));
		}
		memoryfree((void*)(sch-x));

		return 0;
}
//void getmemory(pST)
//{
		

//}
void creatememory(void **p,int size)
{
		*p=malloc(size);
		if(NULL==p)
		{
				printf("get %d memory error\n");
				exit(-1);
		}
}

void memoryfree(void *p)
{
		if(NULL != p)
		{
				free(p);
				p=NULL;
		}
		else
				exit(-1);
}
