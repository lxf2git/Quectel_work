#include"del.h"



pStu pdelposition(pStu pNode,int age)
{
	int flag = 0;
	pStu pd = NULL;
	pStu del_tmp=NULL;
	while(1){
			if(pNode->next == NULL)
					break;
			if(pNode->next->age == age){
					pd = pNode->next;
					pNode->next = pd->next;
					free(pd);
					flag = 1;
					continue;
			}
			pNode = pNode->next;
	}
					printf("$$4$$\n");
	if(flag == 1)
			printf("删除成功!\n");
	if(flag == 0)
			printf("没有找到符合年龄的学生\n");
}

int pDel(pStu pHead,pStu (*pDelPosition)(pStu pNode,int age))
{
	int age;
	printf("按年龄删除学生信息，请输入年龄:\n");
	scanf("%d",&age);
	(*pDelPosition)(pHead,age);
}

void del_chain(pStu pHead)
{
	pStu pNode = pHead;
	pStu (*pDelPosition)(pStu pNode,int age);
	pDelPosition = pdelposition;
	(*pDel)(pNode,pDelPosition);
}
