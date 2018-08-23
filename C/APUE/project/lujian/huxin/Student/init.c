#include"init.h"
void create_memory(void **po,int size)
{
	*po = malloc (size);
	if(*po == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}
void init_node(pStu  *p)
{
	create_memory((void**)p,sizeof(sStu));
	(*p)->next = (*p);
}
int stu_in(pStu p)
{
	printf("please input id age \n");
	scanf("%d%d",&p->num,&p->age);
}
void stu_out(pStu p)
{
	printf("%d %d\n",p->num,p->age);
}

