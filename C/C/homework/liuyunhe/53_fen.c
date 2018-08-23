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
void great_memory(void **p,int size)
{
		*p=malloc(size);
}
int main ()
{
		int x,y,z;
		int i,j,k;
		int *school_sum;
		int *school_class;
		int class=0;
		int sum=0;
	    printf("一共有多少个学校\n");
		scanf("%d",&x);
		int *class_sum[x];
		int *a[x];
   		pStuSch stu_sch;
	//	stu_sch=malloc(x*sizeof(struct school));
	//	school_sum=malloc(x*sizeof(int));
	//	school_class=malloc(x*sizeof(int));
		great_memory((void **)&stu_sch,x*sizeof(struct school));
		great_memory((void **)&school_class,x*sizeof(int));
		great_memory((void **)&school_sum,x*sizeof(int));
		for(i=0;i<x;i++)
		{
				printf("输入第 %d 所学校有多少个班级\n",i+1);
				scanf("%d",&y);
		//		(stu_sch+i)->stu_cla=malloc(y*sizeof(sStuCla));
		//		class_sum[i]=malloc(y*sizeof(int));
				great_memory((void **)&((stu_sch+i)->stu_cla),y*sizeof(sStuCla));
				great_memory((void **)&class_sum[i],y*sizeof(int));
				great_memory((void **)&a[i],y*sizeof(int));
				*(school_class+i)=y;
				for(j=0;j<y;j++)
				{
						printf("输入第 %d 所学校第 %d 个班级人数\n",i+1,j+1);
						scanf("%d",&z);
						a[i][j]=z;
					//	(stu_sch+i)->stu_cla[j].stu_stu=malloc
					//			(z*sizeof(struct student));
						great_memory((void **)&((stu_sch+i)->stu_cla[j].
												stu_stu),z*sizeof(struct student));
						for(k=0;k<z;k++)
						{
								printf("输入第 %d 个学生的名字 成绩\n",k+1);
					//			(stu_sch+i)->stu_cla[j].stu_stu[k].pname=
					//					malloc(10*sizeof(char));
								great_memory((void **)&((stu_sch+i)->stu_cla[j].stu_stu[k].pname),10*sizeof(char));
								scanf("%s%d",(stu_sch+i)->stu_cla[j].
												stu_stu[k].pname,&stu_sch[i]
												.stu_cla[j].stu_stu[k]
												.score);	
								sum=sum+stu_sch[i].stu_cla[j].
										stu_stu[k].score;

						}
						class_sum[i][j]=sum/z;
						sum=0;
			//			printf("第%d所学校第%d个班级平均分=%d\n",
			//							i+1,j+1,class_sum[i][j]);	
						class=class+class_sum[i][j];
				}
				school_sum[i]=class/y;
				class=0;
			//	printf("第%d所学校平均分=%d\n",i+1,school_sum[i]);
		}


		for(i=0;i<x;i++)
		{
				for(j=0;j<school_class[i];j++)
				{
						printf("第%d所学校第%d个班级平均分=%d\n",
										i+1,j+1,class_sum[i][j]);	
				}
				printf("第%d所学校平均分=%d\n",i+1,school_sum[i]);
		}
#if 1
		for(i=0;i<x;i++)
		{
				for(j=0;j<school_class[i];j++)
				{
						for(k=0;k<a[i][j];k++)
						{
								free((stu_sch+i)->stu_cla[j].stu_stu[k].pname);
								(stu_sch+i)->stu_cla[j].stu_stu[k].pname=NULL;
						}
		 				free((stu_sch+i)->stu_cla[j].stu_stu);
						(stu_sch+i)->stu_cla[j].stu_stu=NULL;
				}
				free(class_sum[i]);
				class_sum[i]=NULL;
				free(a[i]);
				a[i]=NULL;
				free((stu_sch+i)->stu_cla);
				(stu_sch+i)->stu_cla=NULL;
		}
				free(school_sum);
				school_sum=NULL;
		free(stu_sch);
		stu_sch=NULL;
		free(school_class);
		school_class=NULL;
#endif
		return 0;
		

}
