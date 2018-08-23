#include"save.h"

int pStu_Save(pStu pHead,FILE *fd)
{
	pStu ps = pHead;
	while(ps!=NULL){
			fwrite(ps,sizeof(sStu),1,fd);
			ps = ps->next;
	}
	fclose(fd);
	printf("保存成功\n");
}

void save_chain(pStu pHead)
{
	FILE *fp = NULL;
	fp = fopen("student.txt","w+");
	if(fp == NULL){
			printf("fopen error\n");
			exit(-1);
	}
	pStu_Save(pHead,fp);
}

void stu_print(struct student *pp)
{
	int i;
	pStu ptmp = NULL;
	FILE *fp =NULL;
	fp = fopen("student.txt","r");
	if(fp == NULL){
			printf("fopen error\n");
			exit(-1);
	}
	while(1){
			init_node(&ptmp,sizeof(sStu));
			i = fread(ptmp,sizeof(sStu),1,fp);
			if(i<=0)
					break;
			printf("学生id:%d,学生年龄:%d\n",ptmp->num,ptmp->age);
	}
	fclose(fp);
}

void pPrint(pStu pHead)
{
	stu_print(pHead);
}
