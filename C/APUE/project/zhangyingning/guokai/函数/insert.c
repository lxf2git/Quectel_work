#include"insert.h"
int insert(pStu p,pStu pn,int (*pIDFind)(pStu pHead,pStu pInsert),pStu (*pInsertPosition)(pStu pHead,pStu pInsert));

pStu max2(pStu pHead, pStu pInsert)	
{
	pStu pTrav = pHead;
	while(pTrav->next!=NULL)
	{
		if(pTrav->next->id > pInsert->id)
			return pTrav;
		pTrav = pTrav->next;	
	}
	return pTrav;	
}		

int max1(pStu pHead, pStu pInsert)
{		
	while(pHead!=NULL)
	{
		if(pInsert->id==pHead->next->id)
		{
//			pInsert->next=pHead->next;
//			pHead->next = pInsert;   	
		}
		pHead=pHead->next;	
	}
//   while(pHead!=NULL)
  // {
   	//		printf("%d%d",pHead->next->id,pHead->next->age);
	//		pHead=pHead->next;			
   //	}
}		

int max(pStu pHead, pStu pInsert,int (*pIDFind)(pStu pHead, pStu pInsert), 
						pStu (*pInsertPosition)(pStu pHead, pStu pInsert))
{
		printf("please input id \n");	
		scanf("%d%d",&pInsert->id,&pInsert->age);		
//	printf("2222222");	
//		pIDFind = max1;
//		pIDFind(pHead, pInsert);	
	pInsertPosition = max2;	
	pStu pmax = pInsertPosition(pHead, pInsert);
	pInsert->next = pmax->next;
    pmax->next = pInsert;		
	return 0;
}
