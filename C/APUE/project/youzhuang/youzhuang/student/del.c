#include"del.h"
void del(pStu pHead)
{
		if(fun.pDel(pHead,DelPosition)==0)
		{
				printf("没有符合条件的学生！\n");
		}
		else
		{
				printf("删除完毕！\n");
		}

}

int del_node(pStu pHead, pStu (*pDelPosition)(pStu pNode, int age))
{
		int age,n=0;
		pStu pNode,pdel;
		printf("请输入删除的年龄:\n");
		scanf("%d",&age);
		pNode=pDelPosition(pHead,age);
		while(pNode!=NULL)
		{
				pdel=pNode->next;
				pNode->next=pdel->next;
				pdel->next=NULL;
				free_memory(&pdel);
				n++;
				pNode=pDelPosition(pHead,age);
		}
		return n;
}

pStu DelPosition(pStu pNode, int age)
{
		pStu p=pNode;
		while(p->next!=NULL)
		{
				if(p->next->age==age)
				{
						return p;
				}
				p=p->next;
		}
		return NULL;
}
