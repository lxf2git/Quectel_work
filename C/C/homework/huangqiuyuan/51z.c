#include<stdio.h>
#include<stdlib.h>
int nu,i,j;
struct Student
{
	char *name;
	int  math;
	int Chinese;
	int  English;

};

void cmp(struct Student *s)
{

	int math_e=0,Chinese_e=0,English_e=0,everage,stueve[100];
	for(i=0;i<nu;i++)
	{
		stueve[i]=s[i].math+s[i].Chinese+s[i].English;
	}
	for(i=0;i<nu;i++)
	{
	math_e=math_e+s[i].math;
	Chinese_e=Chinese_e+s[i].Chinese;
	English_e=English_e+s[i].English;
	}
	printf("总平均成绩%d\n",everage=(math_e+Chinese_e+English_e)/nu);
	printf("数学平均成绩%d\n",math_e=math_e/nu);
	printf("语文平均成绩%d\n",Chinese_e=Chinese_e/nu);
	printf("英语平均成绩%d\n",English_e=English_e/nu);
	printf("不及格的同学为：\n");
	for(i=0;i<nu;i++)
	{
		if(stueve[i]<everage*3/10)
		{
		printf("%s %d %d %d",s[i].name,s[i].math,s[i].Chinese,s[i].English);
		printf("\n");
		}
	}
			



}

int main()
{
	printf("要比较的学生人数：");
	scanf("%d",&nu);
	printf("输入学生姓名 数学成绩 语文成绩 英语成绩\n");
	struct Student s[nu];
	for(i=0;i<nu;i++)
	{
	s[i].name=(char*)malloc(20*sizeof(char));
	scanf("%s%d%d%d",s[i].name,&s[i].math,&s[i].Chinese,&s[i].English);
	}
	cmp(s);



	return 0;
}
