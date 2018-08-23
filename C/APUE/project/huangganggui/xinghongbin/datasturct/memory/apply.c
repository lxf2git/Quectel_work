#include"main.h"
void create_apply(pMem pHead)
{
		int i;
		pMem p;
		for(i=0;i<10;i++)
		{
				chain_init(&p,sizeof(struct Memory));
//				scanf("%d%d", &p->index ,&p->size);
				p->index =i+1 ;
				p->size = 10;

				
//				p->next = pHead;
//				p->prev = pHead->prev;
//				pHead->prev->next = p;
//				pHead->prev = p;		
				Insert_chain(pHead,p);
		}
}
void Insert_chain(pMem pHead,pMem pInsert)
{
		pMem p = pHead;
		while(p->next != pHead)
		{
				if(p->next->size < pInsert->size)
				{
						break;
				}
				p = p->next;
		}
		pInsert->next = p->next;
		pInsert->prev = p;
		p->next->prev = pInsert;
		p->next = pInsert;
}
void delete_chain(pMem pHead,pMem pDel)
{
		pDel->next->prev = pDel->prev;
		pDel->prev->next = pDel->next;
//						printf("del\n");
		
		
//		pHead->next = pDel->next;
//		pDel->next->prev = pHead;
		pDel->next = pDel;
		pDel->prev = pDel;

}
void delete_free(pRec pHead,pRec pDel,pRec prev)
{
		pDel->next->prev = pDel->prev;
		pDel->prev->next = pDel->next;
//						printf("del\n");
		
		
//		pHead->next = pDel->next;
//		pDel->next->prev = pHead;
		pDel->next = pDel;
		pDel->prev = pDel;
		free(pDel);

}



void connect_free(pMem pHead,pMem pInsert)
{
		pMem p = pHead;
		while(p->next != pHead)
		{
				if(p->next->size > pInsert->size)
				{
						break;
				}
				p = p->next;
		}
		pInsert->next = p->next;
		pInsert->prev = p;
		p->next->prev = pInsert;
		p->next = pInsert;
}
