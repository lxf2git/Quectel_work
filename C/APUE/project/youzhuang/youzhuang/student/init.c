#include"init.h"
void init(pStu pHead)
{
		fun.head=pHead;
		fun.pInsert=insert_node;
		fun.pDel=del_node;
		fun.pSearch=find;
		fun.pPrint=print;
		fun.pStu_Save=save_stu;
		loading(pHead);
}

pStu create_node()
{
		pStu pnew=NULL;
		create_memory(&pnew);
		pnew->stu_input=input_stu;
		pnew->stu_print=print_stu;
		pnew->next=NULL;
		return pnew;
}

void loading(pStu pHead)
{
		FILE *fp=NULL;
		pStu pnew;
		fp=fopen("student.txt","r");
		if(fp==NULL)
		{
				return;
		}
		while(!feof(fp))
		{
				pnew=create_node();
				fread(pnew,sizeof(sStu),1,fp);
				if(pnew->num!=0)
				{
						fun.pInsert(pHead,pnew,idfind,insertposition);
				}
				else
				{
						free_memory(&pnew);
				}
		}
		fclose(fp);
}

int input_stu(pStu p)
{
		printf("请输入学生的ID和年龄：\n");
		scanf("%d%d",&p->num,&p->age);
		return 0;
}

void print_stu(pStu p)
{
		printf("ID:%d  年龄:%d\n",p->num,p->age);
}

void create_memory(pStu *p)
{
		*p=(pStu)malloc(sizeof(sStu));
		if(*p==NULL)
		{
				printf("create memory error!\n");
		}
}

void free_memory(pStu *p)
{
		if(*p!=NULL)
		{
				free(*p);
				*p=NULL;
		}
}
