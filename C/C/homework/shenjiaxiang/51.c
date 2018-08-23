#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	char *name;
	int math;
	int chinese;
	int English;
}*pStu,sStu;

int main()
{
	int i,n,ave_math,ave_ch,ave_Eng,ave_all;
	int math_all,ch_all,Eng_all,all;
	math_all=0; ch_all=0; Eng_all=0; all=0;
	pStu stu;
	printf("请输入要输入学生信息的人数：\n");
	scanf("%d",&n);
	stu = (pStu)malloc(n*sizeof(sStu));
	for(i=0;i<n;i++)
	{
		printf("请输入学生name  math chinese English 成绩：\n");
		(stu+i)->name = (char *)malloc(10*sizeof(char));
		scanf("%s%d%d%d",(stu+i)->name,&(stu+i)->math,&(stu+i)->chinese,&(stu+i)->English);
	}
	
	for(i=0;i<n;i++)   //数学平均成绩
	{
		math_all+=(stu+i)->math;
	}
	printf("math average is :%d\n",math_all/n);

	for(i=0;i<n;i++)     //语文平均成绩
	{
		ch_all+=(stu+i)->chinese;
	}
	printf("chinese average is :%d\n",ch_all/n);
	
	
	for(i=0;i<n;i++)    // 英语平均成绩
	{
		Eng_all+=(stu+i)->English;
	}
	printf("English average is :%d\n",Eng_all/n);
	
	for(i=0;i<n;i++)     //总分平均成绩
	{
		all+=(stu+i)->math+(stu+i)->chinese+(stu+i)->English;
	}
	printf("all average is :%d\n",all/n);   



	
	for(i=0;i<n;i++)
	{
		if(((stu+i)->math+(stu+i)->chinese+(stu+i)->English)<(all/n)*3/10)
		{
				printf("you fail and say you mather.\n");
				printf("%s  %d  %d  %d",(stu+i)->name,(stu+i)->math,(stu+i)->chinese,(stu+i)->English);
		}
	}
	
	return 0;
}
