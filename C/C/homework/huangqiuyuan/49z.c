#include<stdio.h>
#include<stdlib.h>
#define N 3

struct Student
{
	int ID;
	char *name;
	int math_score;
};

void print(struct Student *p )
{
	int i;
	for(i=0;i<N;i++)
	{
printf("ID:%d name:%s math_score:%d",p[i].ID,p[i].name,p[i].math_score);
	p[i].math_score>60?printf("Good!\n"):printf("加油！\n");
	}

}

int main()
{
	//char *p;
	struct Student p[N];
	int i;
	for(i=0;i<N;i++)
	{
		p[i].name=malloc(20*sizeof(char));
		printf("请输入学生的ID号 姓名 数学成绩\n");
		scanf("%d%s%d",&p[i].ID,p[i].name,&p[i].math_score);
	}

	print(p);


	return 0;

}
