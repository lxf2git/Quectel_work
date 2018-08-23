#include"insert.h"

int pNew_scan(pStu pNew)
{
		printf("请输入学生id，年龄\n");
		scanf("%d%d",&pNew->num,&pNew->age);
}


int pNewid(pStu pHead,pStu pNew)
{
		pStu palit=pHead;
		while(palit->next!=NULL)
		{
				if(palit->next->num==pNew->num)
				{
					return 0;
				}
				palit=palit->next;
		}
		return 1;
}

pStu loction(pStu pHead,pStu pNew)
{
		pStu palit = pHead;
		while(palit->next!=NULL)
		{
				if(palit->next->num > pNew->num)
				{
						return palit;
				}
				palit=palit->next;
		}
		return palit;

}

int insert_scan(pStu pHead,pStu pNew,int (*pIDfind)(pStu pHead,pStu pNew),
			pStu (*pInsertPosition)(pStu pHead,pStu pNew))
{
		int i =	pIDfind(pHead,pNew);
		if(i)
		{
				pStu palit = pInsertPosition(pHead,pNew);
				pNew->next=palit->next;
				palit->next=pNew;
		}
		else
		{
				printf("输入学生的id重复\n");
		}
}

void insert(pStu pHead,sList slist)
{
		pStu pNew;
		init_Node(&pNew,sizeof(sStu));
		pNew->stu_input=pNew_scan;
		pNew->stu_input(pNew);

		slist.pInsert=insert_scan;
		slist.pInsert(pHead,pNew,pNewid,loction);
}



