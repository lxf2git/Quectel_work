#include"./init.h"

void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}
void init_Stu(pStu *p,int size)
{
	getmemory((void **)p,size);
	(*p)->next=NULL;
}
void make_chain()
{
	pStu pnew=NULL;
	init_Stu(&pnew,sizeof(sStu));
	printf("输入学生的Name Age Id:\n");
	scanf("%s%d%d",pnew->name,&pnew->age,&pnew->id);
	pStu pmax = find_max(pnew);
	inser_back(pnew,pmax);
}
