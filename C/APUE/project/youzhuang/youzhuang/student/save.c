#include"save.h"
void save(pStu pHead)
{
		FILE *fp=NULL;
		fp=fopen("student.txt","w");
		if(fp==NULL)
		{
				printf("文件打开失败！\n");
				return;
		}
		if(fun.pStu_Save(pHead,fp)==0)
		{
				printf("保存成功!\n");
		}
		fclose(fp);
}

int save_stu(pStu pHead, FILE*fd)
{
		pStu p=pHead->next;
		while(p!=NULL)
		{
				fwrite(p,sizeof(sStu),1,fd);
				p=p->next;
		}
		return 0;
}
