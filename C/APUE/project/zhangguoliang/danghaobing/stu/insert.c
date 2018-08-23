#include"insert.h"

int stu_in(struct student *p)
{
		printf("please input id age\n");
		scanf("%d%d",&p->num,&p->age);
		return 1;
}

pStu Insert_pnew()
{

		pStu pnew = NULL;
		init_Node(&pnew,sizeof(sStu));
		int ret = pnew->stu_input(pnew);
		if(ret==1)
		printf("recive success!\n");
		return pnew;
}

int IDFind(pStu pHead,pStu pInsert)
{
		pStu ptmp = NULL;
		for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
		{
				if(ptmp->num==pInsert->num)
				{
						return 1;
				}
		}
		return 0;
}

pStu InsertPosition(pStu pHead,pStu pInsert)
{
		pStu ptmp = pHead;
		while(ptmp->next!=NULL)
		{
				if(ptmp->next->num > pInsert->num)
				{
						return ptmp;
				}
				ptmp = ptmp->next;
		}
		return ptmp;
}

int Insert(pStu pHead, pStu pInsert,
				int (*pIDFind)(pStu pHead, pStu pInsert), 
				pStu (*pInsertPosition)(pStu pHead, pStu pInsert) )
{
		int ret = pIDFind(pHead,pInsert);
		pStu pPosit = NULL;
		init_Node(&pPosit,sizeof(sStu));
			   pPosit = pInsertPosition(pHead,pInsert);	
			if(ret==1)
			{
					printf("this id is same as input befor! please input again!\n");
					return 1;
			}
		pInsert->next = pPosit->next;
		pPosit->next = pInsert;
		//printf("%d\n",pPosit->next->num);
		return 0;

}









