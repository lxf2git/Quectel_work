#include<stdio.h>
#include<stdlib.h>
#define N 3
typedef struct Student
{
	int id;
	char *name;
	int math_score;
}sStu;

void show(sStu *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		if((p+i)->math_score>=60 )
		{
			printf("id:%d  name:%s  math_score:%d    good！\n",(p+i)->id,(p+i)->name,(p+i)->math_score);
		}
		if((p+i)->math_score<60 )
		{
			printf("id:%d  name:%s  math_score:%d    加油！\n",(p+i)->id,(p+i)->name,(p+i)->math_score);
		}
	}
	if(p!=NULL)
	{
		free(p);
		p=NULL;	
	}
}

int main()
{
	int i;
	sStu *p;
	p = (sStu *)malloc(100);
	for(i=0;i<N;i++)
	{
		(p+i)->name = (char *)malloc(20);
		printf("Please input id name math_score\n");
		scanf("%d%s%d",&(p+i)->id,(p+i)->name,&(p+i)->math_score);
	}
		show(p);
	return 0;
}
