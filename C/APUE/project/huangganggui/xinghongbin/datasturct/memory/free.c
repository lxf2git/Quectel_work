#include"main.h"
//void chain_freehead(pRec pHead,pMem pFree,pMem pApply)
//{
//		separate_memory(pApply,size,pHead,pFree);
		
//		output(p->pdata);
		
//}
void record_freechain(pRec pHead,pMem pInsert)
{
		struct Record *p;
		free_init(&p,sizeof(sRec));
		p->pdata = pInsert;

		p->prev = pHead->prev;
		p->next = pHead;
		pHead->prev->next = p;
		pHead->prev = p;

//		pInsert->next = pFhead->next;
//		pInsert->prev = pFhead;
//		pFhead->next->prev = pInsert;
//		pFhead->next = pInsert;
}
void separate_memory(pMem pHead,pRec pFhead,pMem pFree)
{
		int size;
		printf("input size of memory\n");
		scanf("%d",&size);

		struct Memory *pTemp;

		for(;size != 0;)
		{
				if(pHead->next->size >=size)
				{
						pTemp = deal_memory(pHead ,size);
						size = 0;
				}
				else 
				{
						pTemp = pHead->next;
						size-=pTemp->size;
						delete_chain(pHead ,pTemp);
						
				}
				
				record_freechain(pFhead,pTemp);
				connect_free(pFree,pTemp);
				
		}

}
pMem deal_memory(pMem pHead,int size)
{
		pMem p =pHead->next;
		pMem pTemp;
		pMem pFree;
		while(p != pHead)
		{
				if(p->size == size)
				{
						pFree = p;
						delete_chain(pHead ,pFree);
						return pFree;
						
				}
				p = p->next;
		}
		pTemp = pHead->next;	
		delete_chain(pHead ,pTemp);
		pTemp->size-=size;
		Insert_chain(pHead,pTemp);

		chain_init(&pFree,sizeof(struct Memory));
		pFree->size = size;
		pFree->index = pTemp->index;
		return pFree;
	
}
void freefree(pRec *p,pMem pHead,pMem pFree)
{
		int i;
		printf("free number\n");
		scanf("%d",&i);
		pRec pTemp = p[i]->next;
		pRec pDel = p[i];
		pMem ptemp = pHead->next;
		pMem pdel = pHead;
		while(pTemp != p[i])
		{
				ptemp = pHead->next;
				while(ptemp != pHead)
				{
						if(pTemp->pdata->index == ptemp->index)
						{
								delete_chain(pHead,ptemp);
								ptemp->size+=pTemp->pdata->size;
								Insert_chain(pHead,ptemp);
								delete_chain(pFree,pTemp->pdata);
								free(pTemp->pdata);
								delete_free(p[i],pTemp,pTemp->prev);
						printf("aaaa\n");
						//		ptemp = pHead;
						}
			//			pdel = pdel->next;
						ptemp = ptemp->next;
				}
				
				pDel = pDel->next;                    //tiao le liang bu;
				pTemp = pDel->next;
						printf("aaaa\n");
				
		}
		
//		while(pHead->next != pHead)
//		{
				pTemp =p[i]->next;
				pDel =p[i];
				while(pTemp != p[i])
				{
						delete_chain(pFree,pTemp->pdata);
						Insert_chain(pHead,pTemp->pdata);
						delete_free(p[i],pTemp,pTemp->prev);

//						pDel = pDel->next;
						pTemp = pDel->next;
						printf("bbbb\n");

				}
//				pDel = pDel->next;
//				pTemp = pDel->next;

//		}
	
}

