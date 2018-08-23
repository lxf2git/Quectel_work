
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
		int number;

		sStu *stu_stu;
}sStuCla,*pStuCla;

typedef struct school
{
		int number;
		sStuCla *stu_cla;

}sStuSch,*pStuSch;

void creatememory(void **p,int size);
struct school *getmemory();
void io(pStuSch sch);
void memoryfree(pStuSch sch);


		int X,Y,Z;
int main()
{
	

		pStuSch sch;
		sch=getmemory();
//		printf("%p  %p  %p\n",sch,sch->stu_cla,sch->stu_cla->stu_stu);
		io(sch);
//		printf("%p  %p  %p\n",sch,sch->stu_cla,sch->stu_cla->stu_stu);
		memoryfree(sch);


		return 0;
}
struct school *getmemory()
{
		pStuSch sch;
		int x,y,z;
//		int X,Y,Z;
		
		printf("please input schoolnumber\n");
		scanf("%d",&X);
		creatememory( (void**)&sch ,X* sizeof(struct student) );

		for(x=0;x<X;x++,sch++)
		{
				printf("input information\n");
				printf("School%d :",x+1);
				printf("input classnumber\n");
				scanf("%d",&Y);
				sch->number=Y;
				

				creatememory((void**) & sch->stu_cla  ,  Y*sizeof(struct class));
				for(y=0;y<Y;y++,sch->stu_cla++)
				{
						printf("Class%d :",y+1);
						printf("input studentnumber\n");
						scanf("%d",&Z);
						sch->stu_cla->number=Z;
				

						creatememory( (void **) & sch->stu_cla->stu_stu  , Z*sizeof(struct student) );
						for(z=0;z<Z;z++,sch->stu_cla->stu_stu++)
						{
								creatememory( (void **) & sch-> stu_cla-> stu_stu->pname ,  20*sizeof(char) );
						}
						sch->stu_cla->stu_stu-=z;
				}
				sch->stu_cla-=y;
		}
		sch-=x;
		
			
		return sch;


}
void creatememory(void **p,int size)
{
		*p=malloc(size);
		if(NULL==*p)	
		{
				printf("get %d memory error\n",size);
				exit(-1);
		}
}
void io(pStuSch sch)
{
		int x,y,z;
		float clasco=0;
		float schsco=0;
		for(x=0;x<X;x++,sch++)
		{
				printf("<-----------This is School%d---------->\n",x+1);
				for(y=0;y<sch->number;y++,sch->stu_cla++)
				{
						printf("\n<--------------Class%d----------------> \n",y+1);
						printf("plesae input name and score for student\n\n");

						for(z=0;z<sch->stu_cla->number;z++,sch->stu_cla->stu_stu++)
						{
								printf("--------->student%d:",z+1);
								scanf("%s%d",sch->stu_cla->stu_stu->pname,&sch->stu_cla->stu_stu->score);
								clasco+=sch->stu_cla->stu_stu->score;
						}

						schsco+=clasco;
						printf("\nSchool%d Class%d: Classavaer%f\n\n",x,y,clasco/(z));
						clasco=0;
						sch->stu_cla->stu_stu-=z;

				}

				printf("\nSchool%d : Schoolavaer%f\n\n",x,schsco/(z*y));
				sch->stu_cla-=y;
		}


}
void memoryfree(pStuSch sch)
{
		int x,y,z;
		
		for(x=0;x<X;x++)
		{
				for(y=0;y<sch->number;y++)
				{
						for(z=0;z<sch->stu_cla->number;z++)	
								free((((sch+x)-> stu_cla+y)-> stu_stu+z)->pname);
						free(((sch+x)->stu_cla+y)->stu_stu);
				}
				free((sch+x)->stu_cla);
		}
		free(sch);			

}
