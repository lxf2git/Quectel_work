#include"insert.h"

void input(pStu pnew)
{
	scanf("%d%d",&pnew->num,&pnew->age); 
}

pStu pInsertposition(pStu pHead,pStu pnew)
{
	/**/pStu pTrav = pHead;
	while(pTrav->next!=NULL)
	{
		if(pTrav->next->num >= pnew->num)
		{
			return pTrav;
		}
		pTrav = pTrav->next;
	}
	return pTrav;
}

void  insert_back(pStu pmax_front,pStu pnew)
{
/**/	pnew->next = pmax_front->next;
	pmax_front->next = pnew;
}

int pidFind(pStu pHead,pStu pnew)
{
	pStu ptmp = pHead;
	pStu pmax_front = NULL;
	if(pHead == NULL || pnew == NULL)
	{
		return -1;
	}
	else
	{
		if(pHead->next == NULL)
		{
			insert_back(pHead,pnew);
			return 0;		
		}
		for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
		{
			if(ptmp->num == pnew->num)
			{
				printf("输入的id重复，请重新输入！\n");
				input(pnew);	
			}										
		}
		pmax_front = pInsertposition(pHead,pnew);
		insert_back(pmax_front,pnew);			
	}	
	return 0;
}
int pinsert(pStu pHead,  pStu pnew,
		        int (*pidFind)(pStu pHead,pStu pInsert),
		        pStu (*pInsertposition)(pStu pHead,pStu pInsert) )
{
	pidFind(pHead,pnew);
}

int stu_input(struct student *pHead)
{
	pStu  pnew = NULL;
	init_node_pstu(&pnew,sizeof(sStu));
	int (*pInsert)( pStu pHead,  pStu pInsert,
		        int (*pIDFind)(pStu pHead,pStu pInsert),
		        pStu (*pInsertPosition)(pStu pHead,pStu pInsert) );
	pInsert = pinsert;
	int (*pIDFind)(pStu pHead,pStu pInsert);
	pIDFind = pidFind;
	pStu (*pInsertPosition)(pStu pHead,pStu pInsert);
	pInsertPosition = pInsertposition;
	printf("请输入学生信息 num age\n");
	input(pnew);	
	pinsert(pHead,pnew,pidFind,pInsertposition);
}






