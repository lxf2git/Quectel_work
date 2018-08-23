#include<stdio.h>
#include<stdlib.h>
#define N 3
typedef struct Student
{
		int id;
		char *name;
		int grade;
}*sSt;
void compare(sSt s)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%d %s %d ",s[i].id,s[i].name,s[i].grade);
		printf(s[i].grade>=60?"good\n":"加油\n");
	}
}
int main() 
{
	sSt s;
	s = malloc(N*sizeof(struct Student));
	int i;
	printf("请输入3个学生学号，姓名和数学成绩\n");
	for(i=0;i<N;i++)
	{
			s[i].name = (char *)malloc(20*sizeof(char)); 
			scanf("%d%s%d",&s[i].id,s[i].name,&s[i].grade);
	}
			compare(s);
}
