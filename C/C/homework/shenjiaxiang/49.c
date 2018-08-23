#include<stdio.h>
#include<stdlib.h>
#define N 3
typedef struct Student
{
	char *number;
	char *name;
	int chengji;
}sStu,*pStu;

void show(pStu p)
{
	int i;
	for(i=0; i<N; i++)
	{
		printf("name:%s number:%s ",p[i].name,p[i].number);
		if(p[i].chengji<60)
		printf("chengji: %d,加油\n",p[i].chengji);
		else
		printf("chengji: %d,棒棒哒\n",p[i].chengji);
	}
}
int main()
{
	sStu a[N];	
	int i;
	for(i=0;i<3;i++)
	{
			(a+i)->name = (char*)malloc(20*sizeof(char));//(a+i)->name=a[i].name
			(a+i)->number = (char*)malloc(20*sizeof(char));//(a+i)->number=a[i].number//a[i].name的值为地址。
			printf("请输入学生第%d信息，姓名，学号，成绩：\n",i+1);
			scanf("%s%s%d",a[i].name,a[i].number,&a[i].chengji);
	}
	show(a);
	return 0;
}
