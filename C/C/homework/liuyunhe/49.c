#include<stdio.h>
#include<stdlib.h>
#define N 3
struct Student
{
		int id;
		char *name;
		int score;
}Stu[N];

int main()
{
		int i;
		for(i=0;i<N;i++)
		{
				Stu[i].name=(char*)malloc(10*sizeof(char));
		}
		for(i=0;i<N;i++)
		{
				printf("输入第%d个人同学的学号 姓名 成绩\n",i+1);
				scanf("%d%s%d",&Stu[i].id,Stu[i].name,&Stu[i].score);
		}
		for(i=0;i<N;i++)
		{

				printf("id=%d ,name=%s score=%d \n",
								Stu[i].id,Stu[i].name,Stu[i].score);
				if(Stu[i].score<=60)
				{
						printf("加油\n");
				}
				else
				{
						printf("good\n");
				}
		}

		for(i=0;i<N;i++)
		{
				free(Stu[i].name);
				Stu[i].name=NULL;
		}

}
