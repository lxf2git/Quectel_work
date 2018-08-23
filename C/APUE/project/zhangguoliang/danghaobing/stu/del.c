#include"del.h"

pStu DelPosition(pStu pNode,int age)
{
		pStu pTra = pNode;
		while(pTra->next!=NULL)
		{
				if(pTra->next->age==age)
				{
						return pTra;
				}
				pTra = pTra->next;
		}
		return pNode;
}

int Del(pStu pHead,pStu (*pDelPosition)(pStu pNode,int age))
{
		printf("please input age whose you want delete!\n");
		int age;
		scanf("%d",&age);
		while(1)
		{
			pStu pdel = pDelPosition(pHead,age);
			if(pdel->age==0&&pdel->next->age!=age)
			{
				printf("student delete complex! \n");
				break;
			}
			pStu ptmp = pdel->next;
			pdel->next=pdel->next->next;
			if(ptmp!=NULL)
			{
					free(ptmp);
					ptmp=NULL;
			}

		}
		return 0;
}

