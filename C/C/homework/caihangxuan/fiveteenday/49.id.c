#include<stdio.h> 
#define N 3

struct Id
{
	int id;
	char name[10];
	int score;
};
void show(struct Id id0[])
{
	int nu=0;
	for(;nu<N;nu++)
	{
	printf("ID:%d  姓名： %s   成绩：%d\n",id0[nu].id,id0[nu].name,id0[nu].score);
	if(id0[nu].score<60)
		printf("come on\n");
	if(id0[nu].score>60)
		printf("good\n");
	}
}
int main()
{
	struct Id id[10];
	int nu=0;
	for(;nu<N;nu++)
	{
		printf("现在输入第%d个,请分别输入 ID 姓名 成绩\n",nu+1);
		scanf("%d%s%d",&id[nu].id,id[nu].name,&id[nu].score);
	}
		show(id);
}
