#include"del.h"

pStu pDel_palit(pStu pHead, int age)
{
		pStu palit = pHead;
		while(palit->next!=NULL)
		{
				if(palit->next->age==age)
				{
						return palit;
				}
				palit=palit->next;
		}
		return NULL;
}

int pDel_(pStu pHead, pStu (*pDelPosition)(pStu pHead, int age))
{
		int Age;
		pStu paar;
		printf("请输入要删除的年龄\n");
		scanf("%d",&Age);
		pStu palit = pDelPosition(pHead,Age);
		if(palit==NULL)
		{
				printf("没有删除的年龄\n");
		}
		while(palit!=NULL)
		{
				paar = palit->next;
				printf("del=%d  %d \n",paar->num,paar->age);
				palit->next = palit->next->next;
				Deatory_deat(&paar);
				palit = pDelPosition(pHead,Age);
		}

}

void del(pStu pHead,sList slist)
{
		slist.pDel=pDel_;
		slist.pDel(pHead,pDel_palit);
}
