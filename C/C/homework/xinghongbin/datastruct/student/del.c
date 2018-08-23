#include<stdio.h>
#include"del.h"

void del_chain(pStu pHead,pList plist)
{
		plist->pDel = del_fun;
		plist->pDel(pHead,delpiont);
}

int del_fun(pStu pHead,pDelp pfdel)
{
		pStu pDel;
		pStu pPro;
		int age;
		printf("input you del age:");
		scanf("%d",&age);
		do
		{		
				pPro=pfdel(pHead,age);
				if(pPro != NULL)
				{
						pDel = pPro->next;
						pPro->next = pDel->next;
					    pDel->next = NULL;
						free(pDel);	
				}
		}while(pPro != NULL);

}
pStu delpiont(pStu pNode,int age)
{
		pStu p = NULL;
		
		while(pNode->next != NULL)
		{
				if(pNode->next->age == age)
				{
		printf("de\n");
						return pNode;
				}
			   pNode = pNode->next;	
		}
		return NULL;
}
