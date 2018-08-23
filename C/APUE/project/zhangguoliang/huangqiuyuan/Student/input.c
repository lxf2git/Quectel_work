#include"main.h"

void init_node(pStu *p,int size)
{
	*p=(pStu)malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	(*p)->next=NULL;
}
void Insert_chain(pStu pHead)
{
	pStu pnew;
	
	init_node(&pnew,sizeof(Stu));
	printf("输入ID：");
	scanf("%d",&pnew->id);
	printf("输入名字：");
	scanf("%s",pnew->name);
	printf("输入年龄：");
	scanf("%d",&pnew->age);
	pnew->next=pHead->next;
	pHead->next=pnew;
}

void write_chain(pStu pHead)
{
	pStu ptmp=NULL;
	FILE *fp=NULL;
	fp=fopen("message.txt","w+");
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		fwrite(ptmp,sizeof(struct student),1,fp);
	}
		fclose(fp);
	printf(" 保存成功！\n");
}








