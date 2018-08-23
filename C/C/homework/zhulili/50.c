#include<stdio.h>
#include<stdlib.h>
#define N 3

typedef struct Student
{
	char *name;
	int age;
}sStu;

void compare(sStu *q)
{
	int max,i,k=0;
	int t;
	for(i=0;i<N;i++)
	{
		if((q+i)->age > (q+k)->age)
		{
			max = (q+i)->age;
			k = i;
		}
	}
	printf("age_max:%d  age_max_name:%s\n",max,(q+k)->name);
	if(q->name!=NULL)
	{
		for(i=0;i<N;i++)
		{
			free((q+i)->name);
			(q+i)->name = NULL;
		}
	}
	free(q);
	q = NULL;
}

int main()
{
	sStu *p;
	int size;
	int i;
	p = (sStu *)malloc(50);
	printf("请输入空间大小：\n");
	scanf("%d",&size);
	for(i=0;i<N;i++)
		(p+i)->name = (char *)malloc(size);
	for(i=0;i<N;i++)
	{
		printf("请输入姓名 年龄：\n");
		scanf("%s%d",(p+i)->name,&(p+i)->age);
	}
	compare(p);
	return 0;
}
