#include"free.h"
void myfree(pMem pHead,pMem pHead_app,pRec pHead_rec)
{
	int nb;
	printf("请输入要清楚的空间序列：\n");
	scanf("%d",&nb);
	pMem ptmp_1=pHead_app->next;
	pRec ptmp=pHead_rec->next;
	pMem del_1;
	pRec del;
	while(ptmp_1!=pHead_app&ptmp!=pHead_rec)
	{
		if(ptmp_1->index==nb)
		{
			del_1=ptmp_1;
			ptmp->pdata->mem_size+=ptmp_1->mem_size;
			del=ptmp;
			ptmp=ptmp->next;
			ptmp_1=ptmp_1->next;
			del_1->prev->next=del_1->next;
			del_1->next->prev=del_1->prev;
			del->prev->next=del->next;
			del->next->prev=del->prev;			
			destory(&del_1);
			destory_rec(&del);
			while(ptmp_1->mem_size==10)
			{
				del_1=ptmp_1;
				del=ptmp;
				ptmp_1=ptmp_1->next;
				ptmp=ptmp->next;
				del->prev->next=del->next;
				del->next->prev=del->prev;			
				destory_rec(&del);
				change(del_1,pHead);
			}
		}
		ptmp=ptmp->next;
		ptmp_1=ptmp_1->next;
	}
}
void My_free(pMem *pHead)
{
	pMem ptmp=(*pHead)->next;
	pMem pdel;
	while(ptmp!=(*pHead))
	{
		pdel=ptmp;
		ptmp=ptmp->next;
		pdel->prev->next=pdel->next;
		pdel->next->prev=pdel->prev;
		destory(&pdel);
	}
}
void My_free_rec(pRec *pHead)
{
	pRec ptmp=(*pHead)->next;
	pRec pdel;
	while(ptmp!=(*pHead))
	{
		pdel=ptmp;
		ptmp=ptmp->next;
		pdel->prev->next=pdel->next;
		pdel->next->prev=pdel->prev;
		destory_rec(&pdel);
	}
}