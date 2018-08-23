#include<stdio.h>
#include<stdlib.h>

typedef struct Score
{
	int Math_score;
	int Chinese_score;
	int English_score;
	
}sScore,*pScore;

typedef struct Student
{
	char *pname;
	int average;
	sScore *stu_score;

}sStu,*pStu;


int main()
{
	pStu p;
	pScore po;
	int i,j;
	int m;
	int size;
	int student_count;
	int sum_Math = 0;
	int sum_Chinese = 0;
	int	sum_English = 0;
	int sum = 0;
	int k = 0;
	int h,n;
	char *x,*y;
	int average_Math,average_Chinese,average_English;
	p = (pStu)malloc(100);
	po = (pScore)malloc(100);
	p->stu_score = (sScore *)malloc(100);
	printf("请输入空间大小 学生人数:\n");
	scanf("%d%d",&size,&student_count);
	printf("请输入学生姓名 数学成绩 语文成绩 英语成绩：\n");
	for(i=0;i<student_count;i++)
	{

			(p+i)->pname = (char *)malloc(size*sizeof(char));
			scanf("%s%d%d%d",(p+i)->pname,&(po+i)->Math_score,&(po+i)->Chinese_score,&(po+i)->English_score);				sum_Math = sum_Math + (po+i)->Math_score;
			sum_Chinese = sum_Chinese + (po+i)->Chinese_score;
			sum_English = sum_English + (po+i)->English_score;
			sum = (po+i)->Math_score + (po+i)->Chinese_score + (po+i)->English_score;
			(p+i)->average = sum/3;
			printf("第%d个学生总分平均成绩：%d\n",i+1,(p+i)->average);
			sum = 0;

	}
		for(h=0;h<student_count;h++)
			for(i=0;i<student_count-1;i++)
					if((p+i)->average < (p+i+1)->average)
					{
							m = (p+i)->average;
							(p+i)->average = (p+i+1)->average;
							(p+i+1)->average = m;

							m = (po+i)->Math_score;
							(po+i)->Math_score = (po+i+1)->Math_score;
							(po+i+1)->Math_score = m;
					
							m = (po+i)->Chinese_score;
							(po+i)->Chinese_score = (po+i+1)->Chinese_score;
							(po+i+1)->Chinese_score = m;
							
							m = (po+i)->English_score;
							(po+i)->English_score = (po+i+1)->English_score;
							(po+i+1)->English_score = m;

							x = (p+i)->pname;
							y = (p+i+1)->pname;
							(p+i)->pname = y;
							(p+i+1)->pname = x;
					}

	for(i=0;i<student_count;i++)
	printf("%d  ",(p+i)->average);
	printf("\n");
	average_Math = sum_Math/student_count;
	average_Chinese = sum_Chinese/student_count;
	average_English = sum_English/student_count;
	printf("全体同学各科平均成绩是：\n");
	printf("average_Math:%d  average_Chinese:%d  average_English:%d\n",
					average_Math,average_Chinese,average_English);
	
	for(i=student_count*0.7;i<student_count;i++)
	{
		printf("average:%d",(p+i)->average);
		printf("name:%s  Math_score:%d  Chinese_score:%d   English_score:%d\n",
					(p+i)->pname,(po+i)->Math_score,(po+i)->Chinese_score,(po+i)->English_score);
	}
	return 0;

}
