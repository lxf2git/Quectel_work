#include"save.h"

int pStu_Save(pStu pHead,FILE *fd)
{
	fd  = fopen("student.txt","w");
	if(fd == NULL)
	{
		printf("fopen error");
		exit(-1);
	}
	fwrite(pHead,sizeof(sStu),1,fd);
	fclose(fd);
	printf("保存成功！");
}

void save_list(pStu pHead)
{
	FILE *fd;
	pStu_Save(pHead,fd);	
}

void pPrint(pStu pHead)
{	
	pStu ptmp = pHead;
	if(pHead != NULL)
	{
		for(ptmp=ptmp->next;ptmp!=NULL;ptmp=ptmp->next)
		printf("num:%d   age:%d\n",ptmp->num,ptmp->age);
	}
}

void stu_print(struct student *pHead)
{	
	pPrint(pHead);
}
