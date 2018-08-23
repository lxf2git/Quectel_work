#include"insert.h"


void scanf_chain(pStu pnew)
{
	printf("请输入学生信息:id,年龄\n");
	scanf("%d%d",&pnew->num,&pnew->age);
}


int idfind(pStu pHead,pStu pnew)
{
	pStu pd = NULL;
	pStu pf = pHead;
	int flag = 0;
	while(pf!= NULL){
			if(pf->num == pnew->num){
					flag=1;
			}
			pf = pf->next;
	}
	return flag;
}

pStu insertposition(pStu pHead,pStu pnew)
{
	pStu pTrav = pHead;
	while(pTrav->next != NULL){
			if(pTrav->next->num>pnew->num)
					return pTrav;
			pTrav = pTrav->next;
	}
	return pTrav;
}

int pInsert(pStu pHead,pStu pnew,int (*pIDFind)(pStu pHead,pStu pnew),pStu (*pInsertposition)(pStu pHead,pStu pnew))
{
	int flag;
	pStu pTrav = NULL;
	flag = pIDFind(pHead,pnew);
	if(flag == 1){
			printf("输入的id已存在,请重新输入!\n");
			scanf_chain(pnew);
	}
	pTrav = pInsertposition(pHead,pnew);
	if(pTrav == NULL){
			printf("定位出错\n");
			return -1;
	}
	pnew->next = pTrav->next;
	pTrav->next = pnew;
}


int stu_input(struct student * pHead)
{
	int (*pIDFind)(pStu pHead,pStu pnew);
	pStu (*pInsertposition)(pStu pHead,pStu pnew);
	pIDFind = idfind;
	pInsertposition = insertposition;
	pStu pnew = NULL;
	init_node(&pnew,sizeof(sStu));
	scanf_chain(pnew);
	pInsert(pHead,pnew,pIDFind,pInsertposition);
}


