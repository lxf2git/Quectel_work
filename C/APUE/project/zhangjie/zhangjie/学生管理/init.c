#include "main.h"
#include "insert.h"
#include "func.h"

void free_m(pStu *p)
{
	if((*p)!=NULL)
	{
		free(*p);
		(*p)=NULL;
	}
}

void free_n(pList *p)
{
	if((*p)!=NULL)
	{
		free(*p);
		(*p)=NULL;
	}
}


void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==(*p))
	{
		printf("malloc error\n");
		exit (-1);
	}
}

void prepare(pStu *p,int size)
{
	getmemory((void **)p,size);
	(*p)->next=NULL;
}

int change(pStu pOs,pStu pIn)
{
	if(pOs==NULL||pIn==NULL)
	{
		return -1;
	}
	pIn->next=pOs->next;
	pOs->next=pIn;
	return 0;
}


void load(pStu p)
{
	FILE *fp=fopen("stu.txt","r+");
	pStu ptemp=NULL;
//	getmemory((void **)&ptemp,sizeof(sStu));
	if(NULL==fp)
	{
		printf("fopen error\n");
		exit (-1);
	}
	while(1)
	{
		prepare(&ptemp,sizeof(sStu));
		fread(ptemp,sizeof(sStu),1,fp);
		if(feof(fp))
		{
			break;
		}
		change(p,ptemp);
		p=ptemp;
		
	}
	fclose(fp);
}

int create(pStu p,pList q)
{
	pStu pnew=NULL;
	getmemory((void **)&pnew,sizeof(sStu));
	pStu ptemp=NULL;
	prepare(&pnew,sizeof(sStu));
//	void (*stu_input)(struct student *p);
	pnew->stu_input=stu_inp;
	printf("please input the student's information\n");
	pnew->stu_input(pnew);
	//scanf("%d%d",&pnew->num,&pnew->age);
	int (*pIDFind)(pStu p,pStu pn);
	pStu (*pInsertPosition)(pStu p,pStu pn);
	int (*pInsert)(pStu pHead, pStu pInsert,int (*pIDFind)(pStu pHead, pStu 		pInsert),pStu (*pInsertPosition)(pStu pHead, pStu pInsert) );	
	q->pInsert=insert;
	q->pInsert(p,pnew,pIDFind,pInsertPosition);
	return 0;
}
