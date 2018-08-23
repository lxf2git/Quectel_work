#include<stdio.h>
#include<stdlib.h>
#define N 2

typedef struct Student
{
	int id;
	char *name;
	int score;
}sStu;

void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}

void put_in(sStu *p)
{
	printf("please input the id,name,score of student:");
	scanf("%d%s%d",&p->id,p->name,&p->score);
}

void show(sStu *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(p[i].score < 60)
		{
			printf("id:%d name:%s 加油！\n",p[i].id,p[i].name);
		}
		else
		{
			printf("id:%d name:%s score:%d\n",p[i].id,p[i].name,p[i].score);
		}
	}
}

int main()
{
	sStu stu[N];
	sStu *ptr;
//	printf("main------->a1\n");
	ptr = &stu[0];
	ptr->name = (char *)malloc(30);
	create_memory((void **)ptr,sizeof(sStu));
//	printf("main------->aaaa\n");
	int a,i;
	for(i=0;i<N;i++)
	{
		ptr = &stu[i];
		ptr->name = (char *)malloc(30);
//		printf("main------->bbb\n");
		put_in(ptr);
	}
	show(stu);
	return 0;
}
