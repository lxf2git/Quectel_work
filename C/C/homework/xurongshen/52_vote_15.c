#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 20

typedef struct Candidate
{
	char name1[20];
	int num1;
	char name2[20];
	int num2;
	char name3[20];
	int num3;
}sCan;

void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error");
		exit(-1);
	}
}

void input(sCan **ptr, int n)
{
	int i;
	char ch[20];
	create_memory((void **)ptr,sizeof(sCan));
	printf("please input names of vote:\nname 1:");
	scanf("%s",(*ptr)->name1);
//	(*ptr)->num1 = 0;
	printf("\nname 2:");
	scanf("%s",(*ptr)->name2);
//	(*ptr)->num2 = 0;
	printf("\nname 3:");
	scanf("%s",(*ptr)->name3);
//	(*ptr)->num3 = 0;
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("please input your vote name:");
		scanf("%s",ch);
	//	printf("input (*ptr)->name1---->%s\n",(*ptr)->name1);
		if(!strcmp(ch, (*ptr)->name1))
		{
			((*ptr)->num1)++;
		}
		if(!strcmp(ch, (*ptr)->name2))
		{
			((*ptr)->num2)++;
		}
		if(!strcmp(ch, (*ptr)->name3))
		{
			((*ptr)->num3)++;
		}
	}
}

void output(sCan *ptr, int n)
{
		printf("%s的选举人的票数是%d\n",ptr->name1,ptr->num1);
		printf("%s的选举人的票数是%d\n",ptr->name2,ptr->num2);
		printf("%s的选举人的票数是%d\n",ptr->name3,ptr->num3);
}

int main()
{
	int num;
	sCan *p;
	printf("please input num of vote:");
	scanf("%d",&num);
	input(&p,num);
	output(p,num);
	return 0;
}
