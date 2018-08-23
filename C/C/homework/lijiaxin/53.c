#include<stdio.h>
#include<stdlib.h>

typedef struct student{
		char *pname;
		int score;
}sStu,*pStu;
typedef struct class{
		sStu *stu_stu;
}sStuCla,*pStuCla;
typedef struct school{
		sStuCla *stu_cla;
}sStuSch,*pStuSch;
void get_memory(void **pq,int size)
{
		*pq = malloc (size);
		if(NULL == *pq)
		{
				printf("malloc error!!\n");
				exit(-1);   
		}
}
void myfree(void **pp);

int main()
{
		int i,j,k,x,y,z,count;
		int sum=0,sum1=0;
		pStuSch psch=NULL;
		printf("please input the number of school.\n");
		scanf("%d",&x);
		get_memory((void **)&psch,x*sizeof(sStuSch));
		for(i=0;i<x;i++)
		{
				printf("please input the number of class.\n");
				scanf("%d",&y);
				get_memory((void **)&((psch+i)->stu_cla),y*sizeof(sStuCla));
				sum1 = 0;
				count = 0;
				for(j=0;j<y;j++)
				{
						printf("plase input the number of student.\n");
						scanf("%d",&z);
						get_memory((void **)&((psch+i)->stu_cla+j)->stu_stu,z*sizeof(sStu));
						sum = 0;
						for(k=0;k<z;k++)
						{
								get_memory((void **)&((((psch+i)->stu_cla+j)->stu_stu+k)->pname),20);
								scanf("%s%d",(((psch+i)->stu_cla+j)->stu_stu+k)->pname,
												&(((psch+i)->stu_cla+j)->stu_stu+k)->score);
								
								sum += ((((psch+i)->stu_cla+j)->stu_stu+k)->score);
							count ++;	
						}
						printf("第%d学校第%d班的平均成绩是%d\n",i+1,j+1,sum/z);
                        sum1 += sum ;
				}
				printf("第%d学校的平均成绩%d\n",i+1,sum1/count);
		}
		for(i=0;i<x;i++)
		{
				for(j=0;j<y;j++)
				{
						for(k=0;k<z;k++)
						{
								myfree((void **)&((((psch+i)->stu_cla+j)->stu_stu+k)->pname));
						}
						myfree((void **)&(((psch+i)->stu_cla+j)->stu_stu));
				}
				myfree((void **)&((psch+i)->stu_cla));
		}

		return 0;
}
void myfree(void **pp)
{
		if(NULL!= *pp)
		{
				free(*pp);
				*pp = NULL;
		}
}







