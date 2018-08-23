#include"insert.h"
void insert(pStu pHead)
{
		pStu pnew;
		pnew=create_node();
		pnew->stu_input(pnew);
		
		if(-1==fun.pInsert(pHead,pnew,idfind,insertposition))
		{
				printf("插入失败！\n");
		}
		else
		{
				printf("插入成功！\n");
		}
}
int insert_node(pStu pHead, pStu pInsert,int (*pIDFind)(pStu pHead, pStu pInsert),pStu (*pInsertPosition)(pStu pHead, pStu pInsert) )
{
		pStu p;
		if(-1==pIDFind(pHead,pInsert))
		{
				printf("ID 重复！\n");
				free_memory(&pInsert);
				return -1;
		}
		else
		{
				p=pInsertPosition(pHead,pInsert);
				pInsert->next=p->next;
				p->next=pInsert;
		}
		return 0;
}

int idfind(pStu pHead,pStu pInsert)
{
		pStu p=pHead->next;
		while(p!=NULL)
		{
				if(p->num == pInsert->num)
				{
						return -1;
				}
				p=p->next;
		}
		return 0;
}

pStu insertposition(pStu pHead,pStu pInsert)
{
		pStu p=pHead;
		while(p->next!=NULL)
		{
				if(p->next->num > pInsert->num)
				{
						return p;
				}
				p=p->next;
		}
		return p;
}
