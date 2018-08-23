#include"insert.h"
int find(pStu pHead,pStu pInsert)
{
	pStu pfind = pHead;
	while(pfind->next!=NULL)
	{
		if(pfind->next->num == pInsert->num)
		{
			return 1;
		}
		pfind = pfind->next;
	}
			return 0;
}

pStu max_(pStu pHead,pStu pInsert)
{
	pStu pfind = pHead;
	while(pfind->next!=NULL)
	{
		if(pfind->next->num >= pInsert->num)
		{
			return pfind;
		}
		pfind = pfind->next;
	}
		return pfind;
}

int insert_w(pStu pHead,pStu pInsert,
			int (*pIDFind)(pStu pHead,pStu pInsert),
			pStu (*pInsertPosition)(pStu pHead,pStu pInsert))
{
	int i;
	i = pIDFind(pHead,pInsert);
	if(i)
	{
		printf("ID已存在\n");		
	}
	else
	{
		pStu pmax = pInsertPosition(pHead,pInsert);
		pInsert->next = pmax->next;
		pmax->next = pInsert;
	}
}

int stuinput(pStu p)
{
	printf("请输入ID\n");
	scanf("%d",&p->num);
	printf("请输入age\n");
	scanf("%d",&p->age);
}

void Insert(sList slist,pStu pHead)
{
	pStu pnew=NULL;
	init_node(&pnew,sizeof(pStu));
	//printf("***");
	pnew->stu_input =stuinput;
	pnew->stu_input(pnew);
	slist.pInsert = insert_w; 
	slist.pInsert(pHead,pnew,find,max_);
}
